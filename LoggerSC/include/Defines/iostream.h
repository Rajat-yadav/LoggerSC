#ifndef _IOSTREAM_H
#define _IOSTREAM_H

#include <iostream>

#if UNICODE
	#define tcout wcout
#else
	#define tcout cout
#endif

#endif // _IOSTREAM_H
