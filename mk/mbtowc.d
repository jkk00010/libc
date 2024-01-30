libc_C.1: libc.a(mbtowc.o)
libc.a(mbtowc.o): $(OBJDIR)/mbtowc.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/mbtowc.o: src/stdlib/mbtowc.c
$(OBJDIR)/mbtowc.o: src/stdlib/_stdlib.h
$(OBJDIR)/mbtowc.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/stdlib/mbtowc.c
