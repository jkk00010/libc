#if 0

# define TGSOURCE "fmin.c"
#include "_tgmath.h"
#include <math.h>

TYPE TGFN(fmin)(TYPE x, TYPE y)
{
	if (isnan(x) && !isnan(y)) {
		return y;
	} else if (!isnan(x) && isnan(y)) {
		return x;
	}

	return x < y ? x : y;
}

/*
STDC(199901)
LINK(m)
*/


#endif
