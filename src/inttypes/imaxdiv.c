#include <inttypes.h>
#include "_safety.h"

/** calculate quotient and remainder **/

imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom)
{
	SIGNAL_SAFE(0);

	if ((denom == 0) || (numer == INTMAX_MIN && denom == -1)) {
		UNDEFINED("In call to imaxdiv(): The result of %jd / %jd is not representable as an intmax_t", numer, denom);
	}

	imaxdiv_t r;
	r.quot = numer / denom;
	r.rem = numer % denom;
	return r;
}

CHECK_2(imaxdiv_t, {0}, imaxdiv, intmax_t, intmax_t)

/***
computes both the quotient and remainder of ARGUMENT(numer)
divided by ARGUMENT(denom).
***/

/*
UNDEFINED(The result cannot be represented)
RETURN_SUCCESS(a TYPEDEF(ldiv_t) containing both the quotient and remainder)
STDC(199901)
*/
