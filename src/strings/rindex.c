#include <strings.h>

char *rindex(const char *s, int c)
{
	return strrchr(s, c);
}

/*
XOPEN(400,700)
*/
