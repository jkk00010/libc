#include <errno.h>
#include "_signal.h"
#include "_safety.h"
#include "_syscall.h"

/** set a signal handler **/

/* TODO: remove this very Linux-specific crap */
	typedef struct __siginfo siginfo_t;
	struct linux_sigaction {   
		void (*sa_handler)(int);
		int sa_flags;
		void (*sa_restorer)(void);
		unsigned char sa_mask[8];
	};
#define sigaction(_sig, _act, _oact, _size) __scall4(sigaction, _sig, _act, _oact, _size)
#define SA_RESTART    0x10000000
#define SA_RESTORER   0x04000000
#undef SIG_DFL
#define SIG_DFL  ((void (*)(int)) 0)

void (*signal(int sig, void (*func)(int)))(int)
{
	if (__signal.current != 0 && __signal.current != sig) {
		/* only safe if resetting the current signal handler */
		SIGNAL_SAFE(0);
	}

	if (sig < 0 || sig > NSIGNALS) {
		/* FIXME: should errno be set? */
		return SIG_ERR;
	}

	/* TODO: install __signal_handler as a hook */

	void (*prev)(int) = __signal.handlers[sig];
	__signal.handlers[sig] = func;

	struct linux_sigaction act = { 0 };
	act.sa_handler = __signal_handler;
	act.sa_flags = SA_RESTART | SA_RESTORER;

	int ret = sigaction(sig, &act, NULL, 8);
	if (ret != 0) {
		errno = -ret;
		return SIG_ERR;
	}
	
	return prev;
}

/***
sets the signal handler for the signal specified by ARGUMENT(sig) to
ARGUMENT(func).

Specifying CONSTANT(SIG_DFL) for ARGUMENT(func) resets the signal handler
to its default behavior.

Specifying CONSTANT(SIG_IGN) for ARGUMENT(func) causes the signal
ARGUMENT(sig) to be ignored.

Otherwise, ARGUMENT(func) must be a pointer to a function which takes a
single TYPE(int) argument and does not return a value. 
***/

/*
UNDEFINED(A signal handler for CONSTANT(SIGFPE) returns)
UNDEFINED(A signal handler calling standard library functions other than THIS() if the signal occurs as other than as a result of calling FUNCTION(abort) or FUNCTION(raise))
UNDEFINED(FIXME: some function calls from signal handlers)
IMPLEMENTATION(Whether signal blocking is performed when a signal occurs)
IMPLEMENTATION(Other signals corresponding to computation exceptions for which signal handlers must not return)
STDC(1)
*/
