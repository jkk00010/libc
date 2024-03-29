#if 0

# define TGSOURCE "frexp.c"
#include <errno.h>
#include <math.h>
#include "_tgmath.h"

/** extract mantissa and exponent **/

TYPE TGFN(frexp)(TYPE value, int *exp)
{
	switch (fpclassify(value)) {
	case FP_ZERO:		*exp = 0; return value;
	case FP_INFINITE:	*exp = /* unspecified */0; return value;
	case FP_NAN:		*exp = /* unspecified */0; return value;
	default:		break;
	}

	if (0) {
		errno = ERANGE; /* The result cannot be represented */
		/* RETURN(CONSTANT(HUGE_VAL), A range error occurred); */
		return TGHUGE;
	}

	/* RETURN(a value in range [1/2``,'' 1``)'', TODO: explain this); */
	/* RETURN(LITERAL(0), ARGUMENT(x) is LITERAL(0)); */
	(void)exp;
	return value;
}

/***
break floating-point numbers into a normalized fraction and an integral power
of 2.

The normalized fraction is a value in the range [1/2, 1) or 0.

The integral exponent of 2 is stored in the TYPE(int) pointed to by
ARGUMENT(exp).

Multiplying the normalized fraction by 2 to the power ARGUMENT(*exp).
***/

/*
IMPLEMENTATION(The value returned on a domain error, CONSTANT(HUGE_VAL))
LINK(m)
STDC(1)
*/


#endif
