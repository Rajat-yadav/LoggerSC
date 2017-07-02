#ifndef _DLL_H
#define _DLL_H

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#ifdef _EXPORT_
	#define API __declspec(dllexport)
#else
	#define API __declspec(dllimport)
#endif // _EXPORT_

#ifdef __cplusplus
}
#endif // __cplusplus


#endif // _DLL_H

