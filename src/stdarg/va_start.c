#include "_safety.h"

void va_start()
{
	UNDEFINED("The va_start() macro has been suppressed to access an actual function");
}

/*
SIGNAL_SAFE(0)
STDC(0)
*/