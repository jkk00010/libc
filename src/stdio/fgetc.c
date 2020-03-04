#include <stdio.h>
#include "_stdio.h"

#ifndef _POSIX_C_SOURCE
#define getc_unlocked(...) 0
#endif

/** read a character from a file stream **/
int fgetc(FILE *stream)
{
	flockfile(stream);
	char c = getc_unlocked(stream);
	funlockfile(stream);
	/*
	RETURN_SUCCESS(the next character);
	RETURN_FAILURE(CONSTANT(EOF));
	*/
	return c;
}

/***
reads the next character from ARGUMENT(stream) as an
TYPE(unsigned char) converted to an TYPE(int). The file position indicator
of ARGUMENT(stream) is advanced.
***/
/*
STDC(1)
*/
