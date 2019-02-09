#include <ctype.h>
#include "limits.h"
#include "nonstd/assert.h"
#include "nonstd/ctype.h"
#include "nonstd/internal.h"

/** test whether a character is graphic **/
int isgraph(int c)
{
	unsigned int *map = __libc(CTYPE);

	ASSERT_REPRESENTABLE(c, 0, UCHAR_MAX, unsigned char, EOF);
	/*
	RETURN(NONZERO, ARGUMENT(c) is a graphic character);
	RETURN(0, ARGUMENT(c) is not a graphic character);
	*/

	return map[c] & ~SPACE;
}

/***
tests whether ARGUMENT(c) is a character in the class CHARACTER_CLASS(graph)
in the current locale.
***/

/*
LC_CTYPE
C_LOCALE(`THIS() is true for all printable characters other than SPACE()')
STDC(1)
*/