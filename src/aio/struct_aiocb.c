#if 0

#include <aio.h>

struct aiocb {
	int		aio_fildes;
	off_t		aio_offset;
	volatile void *	aio_buf;
	size_t		aio_nbytes;
	int		aio_reqprio;
	struct sigevent	aio_sigevent;
	int		aio_lio_opcode;
};

/*
POSIX(199309)
*/


#endif
