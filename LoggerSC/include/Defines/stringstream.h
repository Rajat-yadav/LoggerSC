#ifndef _STRINGSTREAM_H
#define _STRINGSTREAM_H

#include <string>

#ifndef _INC_TCHAR
		#include <tchar.h>
#endif // _INC_TCHAR

#include <sstream>

#if defined(_UNICODE) || defined(UNICODE)
	#define tstringstream wstringstream
#else
	#define tstringstream stringstream
#endif



#endif // _STRINGSTREAM_H
