#if 0

#include <string.h>

void *memccpy(void * restrict s1, const void * restrict s2, int c, size_t n)
{
	unsigned char *dst = s1;
	const unsigned char *src = s2;
	size_t i = 0;

	ASSERT_NOOVERLAP(s1, s2, n);

	for (i = 0; i < n; i++) {
		dst[i] = src[i];
		if (dst[i] == (unsigned char)c) {
			return dst + i + 1;
		}
	}

	return NULL;
}

/*
XOPEN(4)
*/


#endif
