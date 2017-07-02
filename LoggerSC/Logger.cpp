//Initilization flag
#define _EXPORT_

// Additional include files 
#include "WLog.h"
#include "Logger.h"



Logger::Logger() :isInitialized(false), isShuttingDown(false),LoggerObjectLineNum(NULL),LoggerObjectFileName(NullString)
{

}

Logger::Logger(int objectlinenum,std::tstring objectfilename) :isInitialized(false),isShuttingDown(false),objectlinenum(objectlinenum),objectfilename(objectfilename)
{

}

Logger::~Logger() 
{
	isInitialized = false, isShuttingDown = true;
}

void Logger::WriteLogToFile(std::tstring filename, WinLogForm winlogform)
{
	// Some f stream objects
	std::tofstream LogFile;
	std::tstringstream buffer;

	switch (winlogform)
	{
	case RY_WinLog_Logger:
		#if UNICODE
			this->Log(_T("Can't use RY_Winlog_Logger logging form"), LogType::ERRORLOG, NullString, NULL, RY_MSGLOG);
		#else
			this->Log("Can't use RY_Winlog_Logger logging form", LogType::ERRORLOG,NullString, NULL, RY_MSGLOG);
		#endif // _UNICODE
		break;
	case RY_WinLog_WLog:
		LogFile.open(filename,std::ios::out|std::ios::in||std::ios::trunc);
		LogFile << buffer.str();
		break;
	case RY_WinLog_CLog:
		break;
	}
}

bool Logger::Initialize()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	isInitialized = true, isShuttingDown = false;
	LoggerObjectFileName = objectfilename;
	LoggerObjectLineNum = objectlinenum;
	return true;
}

bool Logger::ShutDown()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	std::cout << "\n\nShutting Down and deleting Logger's Variables:\n\n";
	isInitialized = false, isShuttingDown = true;
	return true;
}


void Logger::Log(std::tstring Op, LogType logtype, std::tstring fn, int ln, LogFlags logflag)
{
	if (this->IsInitialized()) 
	{
		switch (logtype)
		{
		case LogType::ERRORLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			if (logflag == RY_MSGLOG)
			{
				std::tcout << "ERROR: " << Op << std::endl;
			}
			if (logflag == RY_FLLOG)
			{
				std::tcout << "Found in file: " << fn << std::endl;
			}
			if (logflag == RY_LNLOG)
			{
				std::tcout << "Found at line number: " << ln << std::endl;
			}
			if (logflag == RY_FLLNLOG)
			{
				if (logflag == RY_FULLLOG) {}
				else { std::tcout << "Found in file: " << fn << std::endl;std::tcout << "Found at line number: " << ln << std::endl; }
			}
			if (logflag == RY_MSGFLLOG)
			{
				if (logflag == RY_FULLLOG) {}
				else { std::tcout << "ERROR: " << Op << std::endl;std::tcout << "Found in file: " << fn << std::endl; }
			}
			if (logflag == RY_FULLLOG)
			{
				std::tcout << "ERROR: " << Op << std::endl;std::tcout << "Found in file: " << fn << std::endl; std::tcout << "Found at line number: " << ln << std::endl;
			}
			break;
		case LogType::INFOLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
			if (logflag == RY_MSGLOG) { std::tcout << "Function INFO: " << Op << std::endl; }
			else { std::tcout << "From file: " << fn << std::endl; }
			break;
		case LogType::WARINGLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
			if (logflag == RY_MSGLOG)
			{
				std::tcout << "WARNING: " << Op << std::endl;
			}
			if (logflag == RY_FLLOG)
			{
				std::tcout << "Found in file: " << fn << std::endl;
			}
			if (logflag == RY_LNLOG)
			{
				std::tcout << "Found at line number: " << ln << std::endl;
			}
			if (logflag == RY_MSGFLLOG)
			{
				if (logflag == RY_FULLLOG) {}
				else { std::tcout << "WARNING: " << Op << std::endl;std::tcout << "Found in file: " << fn << std::endl; }
			}
			if (logflag == RY_FULLLOG)
			{
				if (logflag == RY_FULLLOG) {}
				else { std::tcout << "Found in file: " << fn << std::endl;std::tcout << "Found at line number: " << ln << std::endl; }
			}
			if (logflag == RY_FULLLOG)
			{
				std::tcout << "WARNING: " << Op << std::endl;std::tcout << "Found in file: " << fn << std::endl;std::tcout << "Found at line number: " << ln << std::endl;
			}
			break;
		case LogType::TODOLOG:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTCYAN);
			if (logflag == RY_MSGLOG)
			{
				std::tcout << "TODO: " << Op << std::endl;
			}
			if (logflag == RY_FLLOG)
			{
				std::tcout << "Todo in file: " << fn << std::endl;
			}
			if (logflag == RY_LNLOG)
			{
				std::tcout << "Todo at line number: " << ln << std::endl;
			}
			if (logflag == RY_MSGFLLOG)
			{
				if (logflag == RY_FULLLOG) {}
				else { std::tcout << "TODO: " << Op << std::endl;std::tcout << "Todo in file: " << fn << std::endl; }
			}
			if (logflag == RY_FLLNLOG)
			{
				if (logflag == RY_FULLLOG) {}
				else { std::tcout << "Todo in file: " << fn << std::endl;std::tcout << "Todo at line number: " << ln << std::endl; }
			}
			if (logflag == RY_FULLLOG) { std::tcout << "TODO: " << Op << std::endl;std::tcout << "Todo in file: " << fn << std::endl;std::tcout << "Todo at line number: " << ln << std::endl; }
			break;
		}
	}
	else 
	{
        #if UNICODE
			// Basic WLog logging object
			WLog* wlo = new WLog(127,_T("LoggerRY.dll:Logger.cpp"));
			wlo->Initialize();
			wlo->WinLog(_T("Initialization"),NullString,_T("Logger.dll"), NULL, _T("Logger is not Initialized: Initialize Logger: Use function SetLoggerInitialized"), LogType::ERRORLOG);
		#else
			// Basic WLog logging object
			WLog* wlo = new WLog(127, "LoggerRY.dll:Logger.cpp");
			wlo->Initialize();
			wlo->WinLog("Initialization",NullString, "Logger.dll", NULL, "Logger is not Initialized: Initialize Logger: Use function SetLoggerInitialized", LogType::ERRORLOG);
		#endif // _DEBuG
	}
}



std::tstring Logger::GetLoggerObjectFileName() const
{
	return this->objectfilename;
}

void Logger::SetLoggerObjectFileName(std::tstring name)
{
	if (LoggerObjectFileName != NullString)
	this->LoggerObjectFileName = name;
}

int Logger::GetLoggerObjectLineNum() const
{
	return this->objectlinenum;
}

void Logger::SetLoggerObjectLineNum(int LineNum)
{
	if (LoggerObjectLineNum != NULL)
	this->LoggerObjectLineNum = LineNum;
}
