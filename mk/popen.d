libc_P.2: libc.a(popen.o)
libc.a(popen.o): $(OBJDIR)/popen.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/popen.o: src/stdio/popen.c
$(OBJDIR)/popen.o: src/stdio/_stdio.h
$(OBJDIR)/popen.o:
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) src/stdio/popen.c
