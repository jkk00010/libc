#include <stdlib.h>
#include "_stdlib.h"

/** allocate memory **/
void * malloc(size_t size)
{
	SIGNAL_SAFE(0);

	if (size == 0) {
		return NULL;
	}

	return realloc(NULL, size);
}

/***
allocates ARGUMENT(size) bytes of memory.
***/

/*
UNSPECIFIED(The order and contiguity of space allocated by success calls)
IMPLEMENTATION(What is returned if ARGUMENT(size) is 0)
RETURN_FAILURE(CONSTANT(NULL))
RETURN_SUCCESS(a pointer to the allocated space)
STDC(1)
*/
