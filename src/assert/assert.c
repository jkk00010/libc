#include "_safety.h"

void assert()
{
	UNDEFINED("The assert() macro has been suppressed to access an actual function");
}

/*
SIGNAL_SAFE(0)
STDC(0)
*/
