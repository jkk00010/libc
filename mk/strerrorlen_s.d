libc_C_X1.201112: libc.a(strerrorlen_s.o)
libc.a(strerrorlen_s.o): $(OBJDIR)/strerrorlen_s.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/strerrorlen_s.o: src/string/strerrorlen_s.c
$(OBJDIR)/strerrorlen_s.o: src/_safety.h
$(OBJDIR)/strerrorlen_s.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/string/strerrorlen_s.c
