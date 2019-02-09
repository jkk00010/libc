# define TGSOURCE "cpow.c"
#include "nonstd/tgmath.h"

#include <complex.h>

TYPE complex TGFN(cpow)(TYPE complex x, TYPE complex y)
{
	return 0.0;
}

/*d
The cpow functions compute the complex power function x y , with a branch cut for the
first parameter along the negative real axis.
d*/

/*r
The cpow functions return the complex power function value.
r*/
/*
STDC(199901)
LINK(m)
*/
