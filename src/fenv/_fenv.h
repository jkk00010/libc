#include <fenv.h>
#include "_safety.h"

#ifdef NDEBUG
#define ASSERT_VALID_EXCEPTION_MASK(_n) (void)(_n)
#define ASSERT_PREVIOUS_FEXCEPT(_f, _e) (void)(_f)
#define ASSERT_PREVIOUS_FENV(_f) (void)(_f)
#else
#define ASSERT_VALID_EXCEPTION_MASK(_n) do { \
	if (((_n) & ~(FE_ALL_EXCEPT)) != 0) { \
		__undefined("In call to %s(), exception mask 0x(%jx) is not valid", __func__, (uintmax_t)(_n)); \
	} \
} while (0)

/* TODO!!! */
#define ASSERT_PREVIOUS_FEXCEPT(_f, _e) (void)(_f)
#define ASSERT_PREVIOUS_FENV(_f) (void)(_f)
#endif
