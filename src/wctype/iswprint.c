#if 0

#include <wctype.h>
#include <wchar.h>
#include "_assert.h"

/** test whether a wide character is printable **/
int iswprint(wint_t wc)
{
	ASSERT_REPRESENTABLE(wc, WCHAR_MIN, WCHAR_MAX, "wchar_t", WEOF);

	wctype_t print = wctype("print");
	return iswctype(wc, print);
}

/***
The fn(iswprint) function tests whether arg(wc) is a character in the class
cclass(print) in the current locale.
***/

/* RETURN(NZ): arg(c) is a printable character */
/* RETURN(0): arg(c) is not a printable character */

/* UNSPECIFIED: - */
/* IMPLEMENTATION: - */
/* LOCALE: LC_CTYPE */

/*
STDC(199409)
*/


#endif
