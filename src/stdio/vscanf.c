#include <stdio.h>

int vscanf(const char * restrict format, va_list arg)
{
	return vfscanf(stdin, format, arg);
}

/*
STDC(199901)
*/
