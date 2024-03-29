#if 0

#include <wctype.h>
#include <wchar.h>
#include "_assert.h"

/** test whether a wide character is an uppercase letter **/
int iswupper(wint_t wc)
{
	ASSERT_REPRESENTABLE(wc, WCHAR_MIN, WCHAR_MAX, "wchar_t", WEOF);

	wctype_t upper = wctype("upper");
	return iswctype(wc, upper);
}

/***
The fn(iswupper) function tests whether arg(wc) is a wide character in the class
cclass(upper) in the current locale.
***/

/* RETURN(NZ): arg(wc) is an uppercase letter */
/* RETURN(0): arg(wc) is not an uppercase letter */

/* UNSPECIFIED: - */
/* IMPLEMENTATION: - */
/* LOCALE: LC_CTYPE */


/*
STDC(199409)
*/


#endif
