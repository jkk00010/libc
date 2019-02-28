#include <wchar.h>
#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"
#include "nonstd/io.h"

int vfwprintf(FILE * restrict stream, const wchar_t * restrict format, va_list arg)
{
	int ret = 0;
	struct io_options opt = {0};
	opt.fnname = "vfwprintf";
	opt.stream = stream;
	ret = __printf(&opt, NULL /* format */, arg);
	return ret;
}

/*
STDC(199409)
*/
