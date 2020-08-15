libc_P.1: libc.a(tcsetpgrp.o)
libc.a(tcsetpgrp.o): $(OBJDIR)/tcsetpgrp.o
	@$(AR) $(ARFLAGS) $@ $(OBJDIR)/$%

$(OBJDIR)/tcsetpgrp.o: src/unistd/tcsetpgrp.c
$(OBJDIR)/tcsetpgrp.o: src/termios/_termios.h
$(OBJDIR)/tcsetpgrp.o:
	@echo "  [CC] $@"
	@mkdir -p $(@D)
	@$(CC) -c -o $@ $(CFLAGS) src/unistd/tcsetpgrp.c
