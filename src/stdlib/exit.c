#include <stdlib.h>
#include <stdio.h>
#include "_stdlib.h"
#include "_syscall.h"

/** cause normal program termination **/
_Noreturn void exit(int status)
{
	long scno = __syscall_lookup(exit);
	struct atexit *ae = &(__stdlib.atexit);

	if (__stdlib.quick_exit_called) {
		__stdlib.constraint_handler("Undefined behavior: exit() called after quick_exit()", NULL, 0);
	}
	if (__stdlib.exit_called) {
		__stdlib.constraint_handler("Undefined behavior: exit() called twice", NULL, 0);
	}
	__stdlib.exit_called = 1;

	/* execute all atexit() registered functions in reverse order */
	while (ae) {
		int i = ae->nfns;
		while (i > 0) {
			ae->fns[--i]();
		}
		ae = ae->prev;
	}

	fflush(NULL);
	
	for (;;) {
		__syscall(scno, status);
	}
}

/***
causes the program to terminate normally, returning the
value ARGUMENT(status) to the host environment.

First, all functions registered by FUNCTION(atexit) are called in the reverse
order in which they were registered.

Then, all open streams with unwritten buffered data are flushed. All open
streams are closed. All temporary files created by FUNCTION(tmpfile) are
removed.
***/

/*
IMPLEMENTATION(The successful termination value returned to the host environment when ARGUMENT(status) is 0 or CONSTANT(EXIT_SUCESS))
IMPLEMENTATION(The unsuccessful termination value returned to the host environment when ARGUMENT(status) is CONSTANT(EXIT_FAILURE))
*/

/*
STDC(1)
*/
