#include <strings.h>

char *index(const char *s, int c)
{
	return strchr(s, c);
}

/*
XOPEN(400,700)
*/
