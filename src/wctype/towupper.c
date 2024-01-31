#include <wctype.h>
#include <wchar.h>
#include "_wctype.h"

/** convert a wide lowercase letter to uppercase **/
wint_t towupper(wint_t wc)
{
	SIGNAL_SAFE(0);
	ASSERT_REPRESENTABLE(wc, WCHAR_MIN, WCHAR_MAX, "wchar_t", WEOF);

	if (!iswlower(wc)) {
		return wc;
	}

	wctrans_t trans = wctrans("toupper");
	return towctrans(wc, trans);
}

__check_1(wint_t, 0, towupper, wint_t)

/***
The fn(towupper) function converts a wide lowercase letter to its equivalent
uppercase letter in the current locale.
***/

/* RETURN(arg(c)): arg(wc) was not a wide lowercase letter or it has no equivalent upercase letter */
/* RETURN: arg(c) converted to uppercase */

/* UNSPECIFIED: - */
/* IMPLEMENTATION: - */
/* LOCALE: LC_CTYPE */

/*
STDC(199409)
*/
