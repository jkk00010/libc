#if 0

#include <stdio.h>
#include "_assert.h"
#include "_stdio.h"

/** test for end-of-file **/

int feof(FILE *stream)
{
	ASSERT_NONNULL(stream);
	flockfile(stream);

	if (stream->eof) {
		return 1;
	}
	/* TODO */
	/* system level test */
	funlockfile(stream);
	/*
	RETURN(0, the end-of-file indicator is not set);
	RETURN(NONZERO, the end-of-file indicator is set);
	*/
	return stream->eof;
}

/***
tests for the end-of-file indicator of ARGUMENT(stream).
***/

/*
STDC(1)
*/


#endif
