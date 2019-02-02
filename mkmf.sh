#!/bin/sh

. $(dirname $0)/mk.sh

STANDARD=${1-9899-1990}

if [ ! -f .dep/to-build ]; then
	rm -rf .dep .deps.mk .headers.mk
	mkdir -p .dep
	echo ${STANDARD} > .dep/to-build
fi

if [ ! -d src/${STANDARD} ]; then
	printf "Standard %s not found.\n" "${STANDARD}"
	exit 1
fi

if [ -f src/${STANDARD}/DEPS.mk ]; then
	for i in $(grep DEPS src/${STANDARD}/DEPS.mk | cut -d= -f2); do
		sh $0 $i
	done

	if grep -q 'CC' src/${STANDARD}/DEPS.mk; then
		grep 'CC' src/${STANDARD}/DEPS.mk > .cc.mk
	fi

	if grep -q 'CFLAGS' src/${STANDARD}/DEPS.mk; then
		#grep 'CFLAGS' src/${STANDARD}/DEPS.mk > .cflags.mk
		grep 'CFLAGS' src/${STANDARD}/DEPS.mk | sed -e 's/CFLAGS/STD_CFLAGS/' >> .cflags.mk
	fi
fi

rm -f .dep/${STANDARD}.*

for i in $(find src/${STANDARD} -name \*.c) $(find src/${STANDARD} -name \*.ref); do
	printf '%s\t' "$i"

	FILE=$i
	BASE=$i
	if grep -q '^REFERENCE(' $FILE; then
		BASE=$(grep '^REFERENCE(' $i | m4 -DREFERENCE='src/$1')
	fi
	NAME=$(basename $BASE .c)
	TYPE=$(classify_source $BASE)
	HEADER=$(sed -ne 's/.*<\(.*\.h\)>.*/\1/p' $FILE)
	LIB=$(grep '^LINK(' $BASE | m4 -DLINK='lib$1')
	LIB=${LIB:-libc}


	printf ' <%s>\t' "${HEADER}"
	if [ ! -f .dep/${HEADER}.mk ]; then
		mkdir -p $(dirname .dep/${HEADER}.mk)
		printf '%s_SOURCES = ' $(echo ${HEADER} | tr /. _) > .dep/${HEADER}.mk
	fi
	printf ' \\\n\t%s' "$FILE" >> .dep/${HEADER}.mk

	if [ $FILE != $BASE ]; then
		printf ' \\\n\t%s' "$BASE" >> .dep/${HEADER}.mk
		continue
	fi

	printf ' %s.a\n' "${LIB}"
	if [ ${TYPE} = EXTERN -o ${TYPE} = FUNCTION -o ${TYPE} = TGFN ]; then
		printf '$(OBJDIR)/%s.o: %s $(INCDIR)/%s' ${NAME} $i ${HEADER}> .dep/${NAME}.o.mk
		for j in $(grep include $i); do
			: # TODO: add each header to depends file here
		done
		printf '\n\t-@mkdir -p $(OBJDIR)\n\t$(CC) $(CFLAGS) -c %s -o $@\n\n' $i >> .dep/${NAME}.o.mk

		if [ ! -f .dep/${LIB}.a.mk ]; then
			printf '%s_OBJS =' ${LIB} > .dep/${LIB}.a.mk
			if [ ${LIB} = libc ]; then
				printf ' $(OBJDIR)/libc.o $(OBJDIR)/x86-64.o' >> .dep/${LIB}.a.mk
			fi
		fi
		printf ' \\\n\t$(OBJDIR)/%s.o' ${NAME} >> .dep/${LIB}.a.mk
	fi
done

if [ $(cat .dep/to-build) = ${STANDARD} ]; then
	printf '.POSIX:\n\n' > .deps.mk
	printf 'default: all\n\n' >> .deps.mk
	printf 'include .cc.mk\n' >> .deps.mk
	printf 'include .cflags.mk\n' >> .deps.mk
	printf 'include config.mk\n\n' >> .deps.mk
	printf 'INCLUDES=-I$(INCDIR) -I. -Inonstd/stubs\n' >> .deps.mk
	printf 'CFLAGS=$(INCLUDES) $(STD_CFLAGS) -g -fno-builtin -nostdinc -nostdlib -nodefaultlibs -Werror -Wall -Wextra -fPIC\n\n' >> .deps.mk

	for i in .dep/lib*.a.mk; do
		LIB=$(basename $i .a.mk)
		cat $i >> .deps.mk
		printf '\n\n%s.a: $(%s_OBJS)\n\t$(AR) r $@ $?\n\n' $LIB $LIB >> .deps.mk
	done

	printf '.POSIX:\n\ninclude config.mk\n\n' > .headers.mk
	printf 'default: headers\n\n' >> .headers.mk
	for i in $(find .dep -name \*.h.mk); do
		HDR=$(echo $i | sed -e 's#^.*\.dep/##;s#\.mk$##')
		cat $i >> .headers.mk
		printf '\n\n$(INCDIR)/%s: $(%s_SOURCES)\n' ${HDR} $(echo $HDR | tr /. _) >> .headers.mk
		printf '\tsh mkh.sh $@ $(%s_SOURCES)\n\n' $(echo $HDR | tr /. _) >> .headers.mk
		printf ' $(INCDIR)/%s' ${HDR} >> .dep/all_headers.mk
	done
	printf 'headers:' >> .headers.mk
	cat .dep/all_headers.mk >> .headers.mk

	cat .dep/*.o.mk >> .deps.mk

	printf '$(OBJDIR)/libc.o: nonstd/libc.c\n\t-@mkdir -p $(OBJDIR)\n\t$(CC) $(CFLAGS) -c $? -o $@\n\n' >> .deps.mk
	printf '$(OBJDIR)/x86-64.o: nonstd/x86-64.s\n\t-@mkdir -p $(OBJDIR)\n\t$(CC) $(CFLAGS) -c $? -o $@\n\n' >> .deps.mk

	printf 'all:' >> .deps.mk
	for i in  .dep/lib*.a.mk; do
		printf ' %s' $(basename $i .mk) >> .deps.mk
	done
	printf '\n\n' >> .deps.mk

	rm -f .dep/to-build
fi
