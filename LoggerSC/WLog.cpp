// Initialization flag
#define _EXPORT_

//Include files
#include "WLog.h"



WLog::WLog(int objectlinenumW,std::tstring objectnameW) :Logger(objectlinenumW,objectnameW)
{

}


WLog::~WLog()
{

}

bool WLog::Initialize()
{
	Logger::Initialize();
	if (LogData_ln == 0 || LogData_LogFilename == NullString || LogData_LogFunctionName == NullString || LogData_LogMessages == NullString || LogData_Logno == NULL || LogData_LogPointNum == NULL || LogData_LogObject == NullString)
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
	return true;
}

bool WLog::ShutDown()
{
	Logger::ShutDown();
	return true;
}

void WLog::WinLog(std::tstring LogObject, std::tstring LogFunctionName, std::tstring LogFilename, int ln, std::tstring LogMessage, LogType logtype)
{
	{
		//  Local tracker variables
		Uint8 LogPointNum = 0;
		LogData_LogObject = LogObject;
		LogData_LogFunctionName = LogFunctionName;
		LogData_LogFilename = LogFilename;
		LogData_ln = ln;
		LogData_LogMessages = LogMessage;


		if (LogData_Logno >= 0)
			LogData_Logno += 184306;
		switch (logtype)
		{
		case LogType::ERRORLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			if (LogFunctionName != NullString)
			{
				if (ln == 0) {
					buffer << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage << std::endl;
				}
			}
			else
			{
				if (ln > 0) {
					buffer << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLON << ln << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << ERRORL << LogFilename << COLONL << LogMessage << std::endl;
				}
			}
			break;
		case LogType::WARINGLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			if (LogFunctionName != NullString)
			{
				if (ln == 0) {
					buffer << TrackInfo << ErrorInfo << WARNL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << WARNL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << WARNL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << WARNL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage << std::endl;
				}
			}
			else
			{
				if (ln > 0) {
					buffer << TrackInfo << ErrorInfo << WARNL << LogFilename << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << WARNL << LogFilename << COLON << ln << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << WARNL << LogFilename << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << WARNL << LogFilename << COLONL << LogMessage << std::endl;
				}
			}
			break;
		case LogType::TODOLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREEN);
			if (LogFunctionName != NullString)
			{
				if (ln == 0) {
					buffer << TrackInfo << ErrorInfo << TODOL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << TODOL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << TODOL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << TODOL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage << std::endl;
				}
			}
			else
			{
				if (ln > 0) {
					buffer << TrackInfo << ErrorInfo << TODOL << LogFilename << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << TODOL << LogFilename << COLON << ln << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << TODOL << LogFilename << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << TODOL << LogFilename << COLONL << LogMessage << std::endl;
				}
			}
			break;
		case LogType::INFOLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGREY);
			if (LogFunctionName != NullString)
			{
				if (ln == 0) {
					buffer << TrackInfo << ErrorInfo << INFOL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << INFOL << LogFilename << COLON << LogFunctionName << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << INFOL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << INFOL << LogFilename << COLON << LogFunctionName << COLON << ln << COLONL << LogMessage << std::endl;
				}
			}
			else
			{
				if (ln > 0) {
					buffer << TrackInfo << ErrorInfo << INFOL << LogFilename << COLON << ln << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << INFOL << LogFilename << COLON << ln << COLONL << LogMessage << std::endl;
				}
				else {
					buffer << TrackInfo << ErrorInfo << INFOL << LogFilename << COLONL << LogMessage;
					std::tcout << TrackInfo << ErrorInfo << INFOL << LogFilename << COLONL << LogMessage << std::endl;
				}
			}
			break;
		}
	}
	LogData_LogPointNum += 1;
}

void WLog::WriteLogToFile(std::tstring filename, WinLogForm winlogform)
{
	std::tofstream LogFile;
	LogFile.open(filename, 2);

}
