#ifndef _WLOG_H
#define _WLOG_H

// Some defines includes
#ifndef _DLL_H
	#include "Defines/Dll.h"
#endif // _DLL_H

#ifndef _WINDOWS_
	#include <Windows.h>
#endif // _WINDOWS_

//Additional includes files
#include "Logger.h"


class API WLog : public Logger
{
	friend struct LogData;
public:
	//************************************
	// Method:    WLog
	// FullName:  WLog::WLog
	// Access:    public 
	// Returns:   
	// Qualifier:
	//************************************
	WLog(int objectlinenumW, std::tstring objectnameW);


	//************************************
	// Method:    ~WLog
	// FullName:  WLog::~WLog
	// Access:    public 
	// Returns:   
	// Qualifier:
	//************************************
	~WLog();

	//************************************
	// Method:    Initialize
	// FullName:  WLog::Initialize
	// Access:    public 
	// Returns:   bool
	// Qualifier:
	//************************************
	bool Initialize();

	//************************************
	// Method:    ShutDown
	// FullName:  WLog::ShutDown
	// Access:    public 
	// Returns:   bool
	// Qualifier:
	//************************************
	bool ShutDown();

	//************************************
	// Method:    WinLog
	// FullName:  WLog::WinLog
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: VT Logno
	// Parameter: std::wstring LogObject
	// Parameter: std::wstring LogFunctionName
	// Parameter: std::wstring LogFilename
	// Parameter: int ln
	// Parameter: std::wstring LogMessage
	// Parameter: LogType logtype
	//************************************
	void WinLog(std::tstring LogObject, std::tstring LogFunctionName, std::tstring LogFilename, int ln, std::tstring LogMessage, LogType logtype);

	void WriteLogToFile(std::tstring filename, WinLogForm winlogform);

};


#endif // _WLOG_H
