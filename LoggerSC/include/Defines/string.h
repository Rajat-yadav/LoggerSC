#ifndef _STRING_H
#define _STRING_H

#include <string>
#include <tchar.h>

#if UNICODE
	#define tstring wstring
	#define Totstring to_wstring();
#else
	#define tstring string
	#define Totstring to_string();
#endif // UNICODE

#endif // _STRING_H
