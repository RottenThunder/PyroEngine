#include "PyroEnginePCH.h"
#include "Logger.h"

namespace PyroEngine
{
	FileWriter Logger::s_LogFile;
	void (*Logger::s_LoggerFunctionCallback)(LoggerChannel, const std::string&) = nullptr;

	void Logger::DecodeAndAppendLogArgument(std::vector<std::string>& strings)
	{
		//Is supposed to not do anything
	}

	bool Logger::TurnOnFileLogging()
	{
		std::error_code ec;
		std::filesystem::path path = std::filesystem::absolute("PyroLog.txt", ec);
		if (ec)
			return false;
		bool fileAlreadyExists = std::filesystem::exists(path, ec);
		if (ec)
			return false;
		if (fileAlreadyExists)
		{
			std::filesystem::remove(path, ec);
			if (ec)
				return false;
		}
		bool success = s_LogFile.Open(path, true);
		return success;
	}

	void Logger::TurnOffFileLogging()
	{
		s_LogFile.Close();
	}

	bool Logger::GetFileLoggingStatus()
	{
		return s_LogFile.IsOpen();
	}

	void Logger::SetLoggerCallback(void(*callback)(LoggerChannel, const std::string&))
	{
		s_LoggerFunctionCallback = callback;
	}

	void(*Logger::GetLoggerCallback())(LoggerChannel, const std::string&)
	{
		return s_LoggerFunctionCallback;
	}
}