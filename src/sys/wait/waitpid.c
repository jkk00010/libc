#include "sys/types.h"
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *stat_loc, int options)
{
	(void)pid; (void)stat_loc; (void)options;
	return 0;
}
/*
POSIX(1)
*/
