libm_C.199901: libm.a(fegetexceptflag.o)
libm.a(fegetexceptflag.o): $(OBJDIR)/fegetexceptflag.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/fegetexceptflag.o: src/fenv/fegetexceptflag.c
$(OBJDIR)/fegetexceptflag.o: src/_safety.h
$(OBJDIR)/fegetexceptflag.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/fenv/fegetexceptflag.c
