#include <utime.h>

struct utimbuf {
	time_t actime;
	time_t modtime;
};

/*
POSIX(1)
*/
