#include "sys/types.h"
#include <sys/stat.h>

mode_t umask(mode_t cmask)
{
	return cmask;
}

/*
POSIX(1)
*/
