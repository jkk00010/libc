#include <threads.h>
#include <pthread.h>

thrd_t thrd_current(void)
{
	return pthread_self();
}
