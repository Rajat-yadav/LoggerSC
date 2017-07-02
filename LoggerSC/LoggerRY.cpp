//Initialization flag
#define _EXPORT_

#include "LoggerRY.h"


// Entry point for dll 
BOOL APIENTRY DllMain(HANDLE handle, DWORD UL_Reason, LPVOID lpvoid) 
{

	switch (UL_Reason)
	{
	case DLL_PROCESS_ATTACH:
		break; 
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

bool SetLoggerInitialized(Logger* logger)
{
	// Basic WLog logging object
	logger->Initialize();
	if (logger->IsInitialized()) 
	{
			#if UNICODE
				logger->WinLog(_T("Service.Initialize"),_T("Class Logger: Initialize"),logger->GetLoggerObjectFileName(),logger->GetLoggerObjectLineNum(),_T("Initializing class Logger's Object: Calling Function Logger::Initialize From LoggerRY library"), LogType::INFOLOG);
			#else
				logger->WinLog("Service.Initialize", "Class Logger: Initialize", logger->GetLoggerObjectFileName(), logger->GetLoggerObjectLineNum(), "Initializing class Logger's Object: Calling Function Logger::Initialize From LoggerRY library", LogType::INFOLOG);
			#endif // _UNICODE
	}
	return true;
}

bool IsLoggerInitialized(Logger* logger)
{
	// Initialization flag
	bool IsLoggerStateGetted = false;

	if (logger->IsInitialized() == true)
	{
		#if UNICODE
			logger->WinLog(_T("Logger.Service.Check"),_T("Logger::Initialize"), logger->GetLoggerObjectFileName(), logger->GetLoggerObjectLineNum(),_T("Initialization successful: De locking and Initializing all Functions of Logger Class Object"), LogType::INFOLOG);
		#else
			logger->WinLog("Logger.Service.Check", "Logger::Initialize", logger->GetLoggerObjectFileName(), logger->GetLoggerObjectLineNum(),"Initialization successful: De locking and Initializing all Functions of Logger Class Object", LogType::INFOLOG);
		#endif // _UNICODE
		IsLoggerStateGetted = true;
	}
	else
	{
		#if UNICODE
			logger->WinLog(_T("Logger.Service.Check"),_T("Logger::Initialize"), logger->GetLoggerObjectFileName(), logger->GetLoggerObjectLineNum(),_T("Logger class object is not Initialized yet: Call SetLoggerInitialized to Initialize Logger"), LogType::WARINGLOG);
		#else 
			logger->WinLog("Logger.Service.Check","Logger::Initialize",logger->GetLoggerObjectFileName(),logger->GetLoggerObjectLineNum(),"Logger class object is not Initialized yet: Call SetLoggerInitialized to Initialize Logger",LogType::WARINGLOG);
		#endif // _UNICODE
		IsLoggerStateGetted = false;
	}
	return IsLoggerStateGetted;
}
