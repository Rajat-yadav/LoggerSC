#ifndef _FSTREAM_H
#define _FSTREAM_H

#include <fstream>

#if UNICODE
	#define tofstream wofstream
#else
	#define tofstream ofstream
#endif

#endif // _FSTREAM_H
 