libc_C.1: libc.a(abort.o)
libc.a(abort.o): $(OBJDIR)/abort.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/abort.o: src/stdlib/abort.c
$(OBJDIR)/abort.o: src/stdlib/_stdlib.h
$(OBJDIR)/abort.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/stdlib/abort.c
