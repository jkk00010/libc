libc_C.0: libc.a(__checked_i.o)
libc.a(__checked_i.o): $(OBJDIR)/__checked_i.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/__checked_i.o: src/__checked_i.c
$(OBJDIR)/__checked_i.o: src/_safety.h
$(OBJDIR)/__checked_i.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/__checked_i.c
