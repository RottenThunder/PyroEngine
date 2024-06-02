#include "PyroEnginePCH.h"
#include "Logger.h"

namespace PyroEngine
{
	bool Logger::s_LoggerInitialised = false;
	std::fstream Logger::s_LoggerStream;
	std::filesystem::path Logger::s_LoggerFilePath = std::filesystem::current_path();
	size_t Logger::s_LoggerFilesPrinted = 0;
	size_t Logger::s_MaxLogFileSize = 33554432; //32MiB
	PYRO_LOG_TYPE_CHANNEL Logger::s_MinLogChannel = (PYRO_LOG_TYPE_CHANNEL)0;

	void Logger::DecodeAndAppendLogArgument(std::vector<std::string>& strings)
	{
		//Is Supposed to not do anything
	}

	void Logger::Init()
	{
		std::filesystem::remove_all("Logs");
		std::filesystem::create_directory("Logs");

		s_LoggerFilePath = "Logs/Log" + std::to_string(s_LoggerFilesPrinted) + ".txt";
		s_LoggerStream.open(s_LoggerFilePath, std::ios::out | std::ios::binary);

		s_LoggerInitialised = true;
	}

	void Logger::Terminate()
	{
		s_LoggerStream.close();
		s_LoggerInitialised = false;
	}

	void Logger::SetMaximumLogFileSize(size_t fileSize)
	{
		s_MaxLogFileSize = fileSize;
	}

	void Logger::SetMinimumLogChannel(PYRO_LOG_TYPE_CHANNEL minLogChannel)
	{
		s_MinLogChannel = minLogChannel;
	}
}