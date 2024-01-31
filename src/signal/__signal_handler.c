#include <stddef.h>
#include "_signal.h"
#include "_safety.h"

void __signal_handler(int sig)
{
	___signal.current = sig;
	if (___signal.handlers[sig] != NULL) {
		___signal.handlers[sig](sig);
	}

	/* TODO: signal number to name */
	if (sig == SIGFPE || sig == SIGILL || sig == SIGSEGV) {
		___signal.current = 0;
		__undefined("Signal handler for signal %d returned", sig);
	}

	___signal.current = 0;
}

/*
STDC(0)
SIGNAL_SAFE(0)
*/
