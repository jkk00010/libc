#if 0

#include <threads.h>
#include <pthread.h>

void tss_delete(tss_t key)
{
	pthread_key_delete(key);
}

/*
STDC(201112)
*/


#endif
