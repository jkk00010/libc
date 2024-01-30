libc_X.400: libc.a(srandom.o)
libc.a(srandom.o): $(OBJDIR)/srandom.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/srandom.o: src/stdlib/srandom.c
$(OBJDIR)/srandom.o: src/stdlib/_stdlib.h
$(OBJDIR)/srandom.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/stdlib/srandom.c
