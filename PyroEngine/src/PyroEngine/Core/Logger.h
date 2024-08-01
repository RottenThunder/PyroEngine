#pragma once
#include "PyroEngine/File/FileWriter.h"
#if defined PYRO_CONFIG_DEBUG
#include <iostream>
#endif

namespace PyroEngine
{
	enum LoggerChannel
	{
		None = 0,
		Trace,
		Info,
		Warning,
		Error
	};

	class Logger
	{
	private:
		static FileWriter s_LogFile;
		static void (*s_LoggerFunctionCallback)(LoggerChannel, const std::string&);

		template<typename T>
		static std::string DecodeLogArgument(T type);

		static void DecodeAndAppendLogArgument(std::vector<std::string>& strings);

		template<typename T>
		static void DecodeAndAppendLogArgument(std::vector<std::string>& strings, T arg);

		template<typename T, typename... Args>
		static void DecodeAndAppendLogArgument(std::vector<std::string>& strings, T firstArg, Args... args);
	public:
		static bool TurnOnFileLogging();
		static void TurnOffFileLogging();
		static bool GetFileLoggingStatus();

		static void SetLoggerCallback(void (*callback)(LoggerChannel, const std::string&));
		static void (*GetLoggerCallback())(LoggerChannel, const std::string&);

		template<typename... Args>
		static std::string Log(LoggerChannel channel, const std::string& msg, Args... args);
	};

	template<typename T>
	inline std::string Logger::DecodeLogArgument(T type)
	{
		return std::string();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(bool type)
	{
		return type ? "true" : "false";
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int8_t type)
	{
		return std::string(1, type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int16_t type)
	{
		return std::to_string((int32_t)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int32_t type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int64_t type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint8_t type)
	{
		return std::to_string((uint32_t)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint16_t type)
	{
		return std::to_string((uint32_t)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint32_t type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint64_t type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(float type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(double type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(void* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(bool* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int8_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int16_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int32_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int64_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint8_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint16_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint32_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(uint64_t* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(float* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(double* type)
	{
		std::stringstream stream;
		stream << "0x" << std::setfill('0') << std::setw(16) << std::hex << (uint64_t)type;
		return stream.str();
	}

	template<>
	inline std::string Logger::DecodeLogArgument(const char* type)
	{
		return type;
	}

	template<>
	inline std::string Logger::DecodeLogArgument(std::string type)
	{
		return type;
	}

	template<typename T>
	inline void Logger::DecodeAndAppendLogArgument(std::vector<std::string>& strings, T arg)
	{
		strings.push_back(DecodeLogArgument(arg));
	}

	template<typename T, typename ...Args>
	inline void Logger::DecodeAndAppendLogArgument(std::vector<std::string>& strings, T firstArg, Args ...args)
	{
		strings.push_back(DecodeLogArgument(firstArg));

		DecodeAndAppendLogArgument(strings, args...);
	}

	template<typename ...Args>
	inline std::string Logger::Log(LoggerChannel channel, const std::string& msg, Args ...args)
	{
		std::string output = msg;

		std::vector<std::string> argStrings;
		DecodeAndAppendLogArgument(argStrings, args...);

		for (size_t i = 0; i < argStrings.size(); i++)
		{
			size_t eraseIndex = output.find("{}");
			if (eraseIndex != std::string::npos)
			{
				output.erase(eraseIndex, sizeof("{}") - 1);
				output.insert(eraseIndex, argStrings[i]);
			}
			else
				i = argStrings.size();
		}

#if defined PYRO_CONFIG_DEBUG
		switch (channel)
		{
		case LoggerChannel::None:
			std::cout << output << "\n";
			break;
		case LoggerChannel::Trace:
			std::cout << "[TRACE] " + output << "\n";
			break;
		case LoggerChannel::Info:
			std::cout << "[INFO] " + output << "\n";
			break;
		case LoggerChannel::Warning:
			std::cout << "[WARNING] " + output << "\n";
			break;
		case LoggerChannel::Error:
			std::cout << "[ERROR] " + output << "\n";
			break;
		default:
			std::cout << output << "\n";
			break;
		}
#endif

		if (s_LogFile.IsOpen())
		{
			switch (channel)
			{
			case LoggerChannel::None:
				s_LogFile.WriteString(output + "\n");
				break;
			case LoggerChannel::Trace:
				s_LogFile.WriteString("[TRACE] " + output + "\n");
				break;
			case LoggerChannel::Info:
				s_LogFile.WriteString("[INFO] " + output + "\n");
				break;
			case LoggerChannel::Warning:
				s_LogFile.WriteString("[WARNING] " + output + "\n");
				break;
			case LoggerChannel::Error:
				s_LogFile.WriteString("[ERROR] " + output + "\n");
				break;
			default:
				s_LogFile.WriteString(output + "\n");
				break;
			}
		}

		if (s_LoggerFunctionCallback != nullptr)
			s_LoggerFunctionCallback(channel, output);

		return output;
	}
}