#if 0

#include <stdio.h>
#include <stdarg.h>

/** write formatted output to a string **/
int sprintf_s(char * restrict s, rsize_t n, const char * restrict format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret = vsprintf(s, format, ap);
	va_end(ap);
	return ret;
}

/***
The fn(sprintf) function writes a formatted string to the buffer at arg(s). The
format of arg(format) and the variadic arguments is the same as that for
fn(printf).
***/

/* UNSPECIFIED: ??? */
/* UNDEFINED: ??? */
/* IMPLEMENTATION: ??? */
/* LOCALE: ??? */

/* RETURN: the number of characters written, not including the final char(\0) */

/*
CEXT1(201112)
*/


#endif
