#include "sys/types.h"
#include <signal.h>

int sigdelset(sigset_t * set, int signo)
{
	(void)set; (void)signo;
	return 0;
}
/*
POSIX(1)
*/