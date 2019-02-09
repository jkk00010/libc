# define TGSOURCE "casin.c"
#include "nonstd/tgmath.h"

#include <complex.h>

TYPE complex TGFN(casin)(TYPE complex z)
{
	return 0;
}

/*d
The casin functions compute the complex arc sine of z, with branch cuts outside the
interval [−1, +1] along the real axis.
d*/

/*r
The casin functions return the complex arc sine value, in the range of a strip
mathematically unbounded along the imaginary axis and in the interval [− π /2, + π /2]
along the real axis.
r*/

/*
STDC(199901)
LINK(m)
*/