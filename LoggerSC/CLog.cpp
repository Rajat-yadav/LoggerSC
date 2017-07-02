// Initialization flag
#define _EXPORT_

#include "CLog.h"




CLog::CLog()
{
	
}


CLog::~CLog()
{

}

bool CLog::Initialize()
{
	Logger::Initialize();
	if (LogData_ln == 0 || LogData_LogFilename == NullString || LogData_LogMessages == NullString || LogData_Logno== NULL || LogData_LogPointNum == NULL || LogData_LogObject == NullString)
	{
		LogData_ln = 0;
		LogData_LogFilename = NullString;
		LogData_LogFunctionName = NullString;
		LogData_Logno = 0;
		LogData_LogPointNum = 0;
		LogData_LogObject = NullString;
		return true;
	}
	else
	{
		return false;
	}
}

bool CLog::ShutDown()
{
	return false;
}

void CLog::WinLog(std::tstring LogObject, std::tstring LogFunctionName, std::tstring LogFilename, int ln, std::tstring LogMessage, LogType logtype)
{
	//Initializes Variables
	LogData_LogObject = LogObject;
	LogData_LogFunctionName = LogFunctionName;
	LogData_LogFilename = LogFilename;
	LogData_ln = ln;
	LogData_LogMessages = LogMessage;

	//Defines
	#define LogCode 

	switch (logtype)
	{
	case ERRORLOG:
		std::tcout<<
		break;
	case INFOLOG:
		break;
	case WARINGLOG:
		break;
	case TODOLOG:
		break;
	default:
		break;
	}

}
