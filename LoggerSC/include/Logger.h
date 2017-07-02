#ifndef  _LOGGER_H
#define	 _LOGGER_H

#ifndef _DLL_H
	#include "Defines/Dll.h"
#endif // _DLL_H

#ifndef _WINDOWS_
	#include <Windows.h>
#endif // _WINDOWS_H

#ifndef _STRING_H
	#include "Defines/string.h"
#endif // _STRING_H

#ifndef _IOSTREAM_H
	#include "Defines/iostream.h"
#endif // _IOSTREAM_H

#ifndef _STRINGSTREAM_H
	#include "Defines/stringstream.h"
#endif // _STRINGSTREAM_H

#ifndef _FSTREAM_H
	#include "Defines/fstream.h"
#endif // _FSTREAM_H

#ifndef _NULLDEFINES_H_
#include "Defines/NullItems/NullDefines.h"
#endif // _NULLDEFINES_H

//Some type defines
typedef unsigned int Uint8;

//enum for log output type
enum LogType
{
	ERRORLOG,
	INFOLOG,
	WARINGLOG,
	TODOLOG
};

enum WinLogForm 
{
	RY_WinLog_Logger,
	RY_WinLog_WLog,
	RY_WinLog_CLog
};

//Initialization defines
#define Logwithmessage  1
#define Logwithfilename 2
#define Logwithlinenum 3
#define Logwitheverything 4

//emun type for logger flags
enum LogFlags
{
	logwithmessage = 1,
	logwithfile = 2,
	logwithmessageandfile = 3,
	logwithline = 4,
	logwithlineandfile = 6,
};

//SomeDefines
#define RY_MSGLOG LogFlags::logwithmessage
#define RY_FLLOG LogFlags::logwithfile
#define RY_LNLOG LogFlags::logwithline
#define RY_FLLNLOG (LogFlags::logwithfile|LogFlags::logwithline)
#define RY_MSGFLLOG (LogFlags::logwithmessage|LogFlags::logwithfile)
#define RY_FULLLOG (RY_MSGLOG|RY_FLLOG|RY_LNLOG)



// defines for color
#define BLACK 0
#define BLUE  1
#define GREEN  2
#define CYAN  3
#define	RED  4
#define	MAGENTA  5
#define	BROWN  6
#define	LIGHTGREY  7
#define	DARKGREY 8
#define	LIGHTBLUE  9
#define	LIGHTGREEN  10
#define	LIGHTCYAN  11
#define	LIGHTRED  12
#define	LIGHTMAGENTA 13
#define	YELLOW  14
#define	WHITE 15

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

 class API Logger
	{
	 friend struct LogData;

	protected:

		//Some defines 
		#define ERRORL " <Error> "
		#define WARNL  " <Warning> "
		#define TODOL  " <Todo> "
		#define INFOL  " <Info> "
		#define COLON     ":"
		#define COLONL  ": "


		bool isInitialized;
		bool isShuttingDown;

		Uint8 LogData_Logno;
		Uint8 LogData_LogPointNum;
		std::tstring LogData_LogObject;
		std::tstring LogData_LogFunctionName;
		std::tstring LogData_LogFilename;
		int LogData_ln;
		std::tstring LogData_LogMessages;
		LogType LogData_logtype;

		std::tstringstream buffer;

		// Local string literals
		#define TrackInfo "[  "<<LogData_LogPointNum<<"."<<LogData_Logno<< "]  "
		#define ErrorInfo LogData_LogObject


		//Constructors Variables
		Uint8 objectlinenum;
		std::tstring objectfilename;

		
	public:
		using VT = std::wstring;

		//************************************
		// Method:    Logger
		// FullName:  Logger::Logger
		// Access:    public 
		// Returns:   
		// Qualifier:
		//************************************
		Logger();
		
		//************************************
		// Method:    Logger
		// FullName:  Logger::Logger
		// Access:    public 
		// Returns:   
		// Qualifier:
		//************************************
		Logger(int objectlinenum, std::tstring objectfilename);

		//************************************
		// Method:    WinLog
		// FullName:  Logger::WinLog
		// Access:    virtual public dfvvvvv
		// Returns:   void
		// Qualifier:
		// Parameter: float Logno
		// Parameter: std::wstring LogObject
		// Parameter: std::wstring LogFunctionName
		// Parameter: std::wstring LogFilename
		// Parameter: int ln
		// Parameter: std::wstring LogMessage
		// Parameter: LogType logtype
		//************************************
		virtual void WinLog(std::tstring LogObject, std::tstring LogFunctionName, std::tstring LogFilename, int ln, std::tstring LogMessage, LogType logtype) {};

		//************************************
		// Method:    ~Logger
		// FullName:  Logger::~Logger
		// Access:    virtual public 
		// Returns:   
		// Qualifier:
		//************************************
		virtual ~Logger();

		//************************************
		// Method:    WriteLogToFile
		// FullName:  Logger::WriteLogToFile
		// Access:    virtual public 
		// Returns:   void
		// Qualifier:
		// Parameter: const char * filename
		//************************************
		virtual void WriteLogToFile(std::tstring filename, WinLogForm winlogform);

	    //************************************
	    // Method:    Initialize
	    // FullName:  Logger::Initialize
	    // Access:    virtual public 
	    // Returns:   bool
	    // Description: Initializes Logger library
	    //************************************
		virtual bool Initialize();

		//************************************
		// Method:    ShutDown
		// FullName:  Logger::ShutDown
		// Access:    virtual public 
		// Returns:   bool
		// Description: Shuts down Logger library
		//************************************
		virtual bool ShutDown();

		//************************************
		// Method:    IsInitialized
		// FullName:  Logger::IsInitialized
		// Access:    public 
		// Returns:   bool
		// Description: Checks that the logger is initialized.
		//************************************
		bool IsInitialized() const { return isInitialized; }

		//************************************
		// Method:    IsShutDown
		// FullName:  Logger::IsShutDown
		// Access:    public 
		// Returns:   bool
		// Description: Check that the logger is shut down.
		//************************************
		bool IsShutDown() const { return isShuttingDown; }


		//************************************
		// Method:    GetLoggerObjectFileName
		// FullName:  Logger::GetLoggerObjectFileName
		// Access:    public 
		// Returns:   std::wstring
		// Qualifier: const
		//************************************
		std::tstring GetLoggerObjectFileName() const;

		//************************************
		// Method:    SetLoggerObjectFileName
		// FullName:  Logger::SetLoggerObjectFileName
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: std::wstring name
		//************************************
		void SetLoggerObjectFileName(std::tstring name);

		//************************************
		// Method:    GetLoggerObjectLineNum
		// FullName:  Logger::GetLoggerObjectLineNum
		// Access:    public 
		// Returns:   int
		// Qualifier: const
		//************************************
		int GetLoggerObjectLineNum() const;

		//************************************
		// Method:    SetLoggerObjectLineNum
		// FullName:  Logger::SetLoggerObjectLineNum
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: int LineNum
		//************************************
		void SetLoggerObjectLineNum( int LineNum);


	private:

		std::tstring LoggerObjectFileName;
		int LoggerObjectLineNum;


		//************************************
		// Method:    Log
		// FullName:  Logger::Log
		// Access:    virtual public 
		// Returns:   Nothing
		// Description: 
		// Parameter: The Log message string
		// Parameter: The Log type you want to use. See enum LogType
		// Parameter: The name of the file in your data base and project which you to Logout
		// Parameter: The line number of your file which you want to inform about
		// Parameter: The Log flags which you want to use in Logging. See enum LogFlags
		//************************************
		void Log(std::tstring Op, LogType logtype, std::tstring fn, int ln, LogFlags logflag);

		//************************************
		// Method:    SetLoggerInitialized
		// FullName:  SetLoggerInitialized
		// Access:    public 
		// Returns:   API bool
		// Qualifier:
		// Parameter: The name of your logger object
		//************************************
		friend bool API SetLoggerInitialized(Logger* logger);


		//************************************
		// Method:    IsLoggerInitialized
		// FullName:  IsLoggerInitialized
		// Access:    public 
		// Returns:   if logger is initialized then it will return true otherwise false
		// Qualifier:
		// Parameter: The name of your logger object
		//************************************
		friend bool API IsLoggerInitialized(Logger* logger);


	};

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _LOGGER_H
