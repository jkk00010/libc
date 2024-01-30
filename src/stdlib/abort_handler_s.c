#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <errno.h>
#include "errno/errno_t.h"
#include "_stdlib.h"

void abort_handler_s(const char * restrict msg, void * restrict ptr, errno_t error)
{
	SIGNAL_SAFE(0);

	struct __constraint_info *ci = ptr;

	puts(msg);
	if (ci) {
		if (ci->signal != 0) {
			/* TODO: map numbers to names as well */
			printf("While handling signal %d: ", ci->signal);
		}
		printf("Function %s()", ci->func);
		if (__checked_call.file) {
			printf(" (");
			if (__checked_call.func) {
				printf("in %s(), ", __checked_call.func);
			}
			printf("at %s:%llu)", __checked_call.file, __checked_call.line);
		}
		printf(", value %x\n", ci->value);
	}
	if (error != 0) {
		printf("Provided error: %s (%d)\n", strerror(error), error);
	}
	abort();
}

/*
CEXT1(201112)
*/
