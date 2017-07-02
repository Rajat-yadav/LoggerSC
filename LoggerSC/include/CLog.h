#ifndef _CLOG_H
#define _CLOG_H

//Some defines includes
#ifndef _DLL_H
	#include "Defines/Dll.h"
#endif // _DLL_H

#ifndef _WINDOWS_
	#include <Windows.h>
#endif // _WINDOWS_

// Additional includes files
#include "Logger.h"
#include "WLog.h"

#ifndef _NULLDEFINES_H_
	#include "Defines/NullItems/NullDefines.h"
#endif // _NULLDEFINES_H

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

class API CLog : public Logger
{
public:
	CLog();
    ~CLog();

	//************************************
	// Method:    Initialize
	// FullName:  CLog::Initialize
	// Access:    public 
	// Returns:   bool
	// Qualifier:
	//************************************
	bool Initialize();

	//************************************
	// Method:    ShutDown
	// FullName:  CLog::ShutDown
	// Access:    public 
	// Returns:   bool
	// Qualifier:
	//************************************
	bool ShutDown();

	//************************************
	// Method:    WinLog
	// FullName:  CLog::WinLog
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: char * LogObject
	// Parameter: char * LogFunctionName
	// Parameter: char * LogFilename
	// Parameter: int ln
	// Parameter: char * LogMessage
	// Parameter: LogType logtype
	//************************************
	void WinLog(std::tstring LogObject, std::tstring LogFunctionName, std::tstring LogFilename, int ln, std::tstring LogMessage, LogType logtype);

protected:
	 
};

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _CLOG_H