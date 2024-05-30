#pragma once
#include <fstream>
#include <filesystem>

#define PYRO_LOG_TYPE_CHANNEL unsigned char

namespace PyroEngine
{
	class Logger
	{
	private:
		static std::fstream s_LoggerStream;
		static std::filesystem::path s_LoggerFilePath;
		static size_t s_LoggerFilesPrinted;
		static size_t s_MaxLogFileSize;
		static PYRO_LOG_TYPE_CHANNEL s_MinLogChannel;

		template<typename T>
		static std::string DecodeLogArgument(T type);

		template<>
		static std::string DecodeLogArgument<bool>(bool type);

		template<>
		static std::string DecodeLogArgument<char>(char type);

		template<>
		static std::string DecodeLogArgument<short>(short type);

		template<>
		static std::string DecodeLogArgument<int>(int type);

		template<>
		static std::string DecodeLogArgument<long long>(long long type);

		template<>
		static std::string DecodeLogArgument<unsigned char>(unsigned char type);

		template<>
		static std::string DecodeLogArgument<unsigned short>(unsigned short type);

		template<>
		static std::string DecodeLogArgument<unsigned int>(unsigned int type);

		template<>
		static std::string DecodeLogArgument<unsigned long long>(unsigned long long type);

		template<>
		static std::string DecodeLogArgument<float>(float type);

		template<>
		static std::string DecodeLogArgument<double>(double type);

		template<>
		static std::string DecodeLogArgument<void*>(void* type);

		template<>
		static std::string DecodeLogArgument<bool*>(bool* type);

		template<>
		static std::string DecodeLogArgument<char*>(char* type);

		template<>
		static std::string DecodeLogArgument<short*>(short* type);

		template<>
		static std::string DecodeLogArgument<int*>(int* type);

		template<>
		static std::string DecodeLogArgument<long long*>(long long* type);

		template<>
		static std::string DecodeLogArgument<unsigned char*>(unsigned char* type);

		template<>
		static std::string DecodeLogArgument<unsigned short*>(unsigned short* type);

		template<>
		static std::string DecodeLogArgument<unsigned int*>(unsigned int* type);

		template<>
		static std::string DecodeLogArgument<unsigned long long*>(unsigned long long* type);

		template<>
		static std::string DecodeLogArgument<float*>(float* type);

		template<>
		static std::string DecodeLogArgument<double*>(double* type);

		template<>
		static std::string DecodeLogArgument<const char*>(const char* type);

		template<>
		static std::string DecodeLogArgument<std::string>(std::string type);

		static void DecodeAndAppendLogArgument(std::vector<std::string>& strings);

		template<typename T>
		static void DecodeAndAppendLogArgument(std::vector<std::string>& strings, T arg);

		template<typename T, typename... Args>
		static void DecodeAndAppendLogArgument(std::vector<std::string>& strings, T firstArg, Args... args);
	public:
		static void Init();
		static void Terminate();

		static void SetMaximumLogFileSize(size_t fileSize);
		static void SetMinimumLogChannel(PYRO_LOG_TYPE_CHANNEL minLogChannel);

		template<typename... Args>
		static std::string Log(PYRO_LOG_TYPE_CHANNEL logChannel, const std::string& msg, Args... args);
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
	inline std::string Logger::DecodeLogArgument(char type)
	{
		return std::string(1, type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(short type)
	{
		return std::to_string((int)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(long long type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned char type)
	{
		return std::to_string((unsigned int)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned short type)
	{
		return std::to_string((unsigned int)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned int type)
	{
		return std::to_string(type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned long long type)
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
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(bool* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(char* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(short* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(int* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(long long* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned char* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned short* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned int* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(unsigned long long* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(float* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
	}

	template<>
	inline std::string Logger::DecodeLogArgument(double* type)
	{
		return std::format("{:#018x}", (unsigned long long)type);
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
	inline std::string Logger::Log(PYRO_LOG_TYPE_CHANNEL logChannel, const std::string& msg, Args ...args)
	{
		std::string output;

		if (logChannel < s_MinLogChannel)
			return output;

		output = msg;

		std::vector<std::string> argStrings;
		DecodeAndAppendLogArgument(argStrings, args...);

		for (size_t i = 0; i < argStrings.size(); i++)
		{
			std::string eraseString = "{" + std::to_string(i) + "}";
			size_t eraseIndex = output.find(eraseString);
			if (eraseIndex != std::string::npos)
			{
				output.erase(eraseIndex, eraseString.size());
				output.insert(eraseIndex, argStrings[i]);
			}
			else
				i = argStrings.size();
		}

		size_t fileSize = std::filesystem::file_size(s_LoggerFilePath);
		if (fileSize + output.size() < s_MaxLogFileSize)
		{
			s_LoggerStream.write(output.c_str(), output.size());
			s_LoggerStream.write("\n", 1);
		}
		else if (fileSize + output.size() == s_MaxLogFileSize)
		{
			s_LoggerStream.write(output.c_str(), output.size());
		}
		else
		{
			s_LoggerStream.close();

			s_LoggerFilesPrinted++;
			s_LoggerFilePath = "Logs/Log" + std::to_string(s_LoggerFilesPrinted) + ".txt";
			s_LoggerStream.open(s_LoggerFilePath, std::ios::out | std::ios::binary);

			s_LoggerStream.write(output.c_str(), output.size());
			s_LoggerStream.write("\n", 1);
		}

		

#if defined PYRO_CONFIG_DEBUG
		std::cout << output << "\n";
#endif

		return output;
	}
}

#define PYRO_LOG_CHANNEL_TRACE (PYRO_LOG_TYPE_CHANNEL)0
#define PYRO_LOG_CHANNEL_INFO (PYRO_LOG_TYPE_CHANNEL)100
#define PYRO_LOG_CHANNEL_WARNING (PYRO_LOG_TYPE_CHANNEL)200
#define PYRO_LOG_CHANNEL_ERROR (PYRO_LOG_TYPE_CHANNEL)255

#define PYRO_LOG_SET_FILE_SIZE(x) PyroEngine::Logger::SetMaximumLogFileSize(x)
#define PYRO_LOG_SET_CHANNEL_BASE(x) PyroEngine::Logger::SetMinimumLogChannel(x)

#define PYRO_LOG_TRACE(msg) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_TRACE, (std::string)"[TRACE] " + msg)
#define PYRO_LOG_INFO(msg) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_INFO, (std::string)"[INFO] " + msg)
#define PYRO_LOG_WARNING(msg) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_WARNING, (std::string)"[WARNING] " + msg)
#define PYRO_LOG_ERROR(msg) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_ERROR, (std::string)"[ERROR] " + msg)

#define PYRO_LOG_ARGS_TRACE(msg, ...) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_TRACE, (std::string)"[TRACE] " + msg, __VA_ARGS__)
#define PYRO_LOG_ARGS_INFO(msg, ...) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_INFO, (std::string)"[INFO] " + msg, __VA_ARGS__)
#define PYRO_LOG_ARGS_WARNING(msg, ...) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_WARNING, (std::string)"[WARNING] " + msg, __VA_ARGS__)
#define PYRO_LOG_ARGS_ERROR(msg, ...) PyroEngine::Logger::Log(PYRO_LOG_CHANNEL_ERROR, (std::string)"[ERROR] " + msg, __VA_ARGS__)