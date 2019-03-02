#include <ctype.h>
#include "limits.h"
#include "nonstd/assert.h"
#include "nonstd/ctype.h"

/** test whether a character is punctuation **/

int ispunct(int c)
{
	unsigned int *map = __libc(CTYPE);

	ASSERT_REPRESENTABLE(c, 0, UCHAR_MAX, unsigned char, EOF);

	return map[c] & CT_PUNCT;
}

/***
tests whether ARGUMENT(c) is a character in the class CHARACTER_CLASS(punct)
in the current locale.
***/

/*
RETURN(NONZERO, ARGUMENT(c) is a punctuation character)
RETURN(0, ARGUMENT(c) is not a punctuation character)
LC_CTYPE
C_LOCALE(`THIS() is true for printing characters for which neither FUNCTION(isspace) nor FUNCTION(isalnum) is true')
STDC(1)
*/
