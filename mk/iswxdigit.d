libc_C.199409: libc.a(iswxdigit.o)
libc.a(iswxdigit.o): $(OBJDIR)/iswxdigit.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/iswxdigit.o: src/wctype/iswxdigit.c
$(OBJDIR)/iswxdigit.o: src/_safety.h
$(OBJDIR)/iswxdigit.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/wctype/iswxdigit.c
