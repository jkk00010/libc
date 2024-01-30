libc_P.1: libc.a(ctermid.o)
libc.a(ctermid.o): $(OBJDIR)/ctermid.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/ctermid.o: src/unistd/ctermid.c
$(OBJDIR)/ctermid.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/unistd/ctermid.c
