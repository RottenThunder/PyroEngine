#include "PyroEnginePCH.h"
#include "FileWriter.h"

namespace PyroEngine
{
	FileWriter::FileWriter()
		: m_FilePath(std::filesystem::current_path()), m_FileStream(), m_IsAlwaysAppending(false)
	{
	}

	FileWriter::~FileWriter()
	{
		m_FileStream.close();
	}

	std::filesystem::path FileWriter::GetFilePath() const
	{
		return m_FilePath;
	}

	bool FileWriter::GetIsAlwaysAppending() const noexcept
	{
		return m_IsAlwaysAppending;
	}

	bool FileWriter::Open(const std::filesystem::path& path, bool alwaysAppend)
	{
		m_FileStream.close();
		m_IsAlwaysAppending = alwaysAppend;
		if (m_IsAlwaysAppending)
		{
			m_FileStream.open(path, std::ios::binary | std::ios::app);
			if (m_FileStream.is_open())
			{
				m_FilePath = std::filesystem::absolute(path);
				return true;
			}
			else
			{
				m_FilePath = std::filesystem::current_path();
				m_IsAlwaysAppending = false;
				return false;
			}
		}
		else
		{
			size_t sizeOfFile = 0;

			if (std::filesystem::is_directory(path))
			{
				m_FilePath = std::filesystem::current_path();
				return false;
			}

			if (std::filesystem::exists(path))
				sizeOfFile = std::filesystem::file_size(path);

			if (sizeOfFile == 0)
			{
				m_FileStream.open(path, std::ios::binary);
				if (m_FileStream.is_open())
				{
					m_FilePath = std::filesystem::absolute(path);
					return true;
				}
				else
				{
					m_FilePath = std::filesystem::current_path();
					return false;
				}
			}
			else if (sizeOfFile > PYRO_FILE_WRITER_FILE_LIMIT)
			{
				m_FilePath = std::filesystem::current_path();
				return false;
			}
			else
			{
				std::ifstream inputStream;
				inputStream.open(path, std::ios::binary);
				if (inputStream.is_open())
				{
					uint8_t* fileContents = new uint8_t[sizeOfFile];
					inputStream.read(reinterpret_cast<char*>(fileContents), sizeOfFile);
					inputStream.close();
					m_FileStream.open(path, std::ios::binary);
					if (m_FileStream.is_open())
					{
						m_FileStream.write(reinterpret_cast<char*>(fileContents), sizeOfFile);
						m_FileStream.seekp(0, std::ios::beg);
						::operator delete(fileContents, sizeOfFile);
						m_FilePath = std::filesystem::absolute(path);
						return true;
					}
					else
					{
						::operator delete(fileContents, sizeOfFile);
						m_FilePath = std::filesystem::current_path();
						return false;
					}
				}
				else
				{
					m_FilePath = std::filesystem::current_path();
					return false;
				}
			}
		}
	}

	void FileWriter::Close()
	{
		m_FileStream.close();
		m_FilePath = std::filesystem::current_path();
		m_IsAlwaysAppending = false;
	}

	bool FileWriter::IsOpen() const noexcept
	{
		return m_FileStream.is_open();
	}

	bool FileWriter::SeekPosition(size_t pos)
	{
		bool success = true;
		try
		{
			m_FileStream.seekp(pos, std::ios::beg);
		}
		catch (std::exception& e)
		{
			success = false;
		}
		return success;
	}

	size_t FileWriter::GetPosition()
	{
		size_t output;
		try
		{
			output = m_FileStream.tellp();
		}
		catch (std::exception& e)
		{
			output = 0;
		}
		return output;
	}

	void FileWriter::GoToStart()
	{
		m_FileStream.seekp(0, std::ios::beg);
	}

	void FileWriter::GoToEnd()
	{
		m_FileStream.seekp(0, std::ios::end);
	}

	void FileWriter::WriteInt8LE(int8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileWriter::WriteInt16LE(int16_t integer)
	{
		uint8_t bytes[2];
		bytes[0] = integer & 0x00FF;
		bytes[1] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileWriter::WriteInt32LE(int32_t integer)
	{
		uint8_t bytes[4];
		bytes[0] = integer & 0x000000FF;
		bytes[1] = (integer & 0x0000FF00) >> 8;
		bytes[2] = (integer & 0x00FF0000) >> 16;
		bytes[3] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileWriter::WriteInt64LE(int64_t integer)
	{
		uint8_t bytes[8];
		bytes[0] = integer & 0x00000000000000FF;
		bytes[1] = (integer & 0x000000000000FF00) >> 8;
		bytes[2] = (integer & 0x0000000000FF0000) >> 16;
		bytes[3] = (integer & 0x00000000FF000000) >> 24;
		bytes[4] = (integer & 0x000000FF00000000) >> 32;
		bytes[5] = (integer & 0x0000FF0000000000) >> 40;
		bytes[6] = (integer & 0x00FF000000000000) >> 48;
		bytes[7] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileWriter::WriteUInt8LE(uint8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileWriter::WriteUInt16LE(uint16_t integer)
	{
		uint8_t bytes[2];
		bytes[0] = integer & 0x00FF;
		bytes[1] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileWriter::WriteUInt32LE(uint32_t integer)
	{
		uint8_t bytes[4];
		bytes[0] = integer & 0x000000FF;
		bytes[1] = (integer & 0x0000FF00) >> 8;
		bytes[2] = (integer & 0x00FF0000) >> 16;
		bytes[3] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileWriter::WriteUInt64LE(uint64_t integer)
	{
		uint8_t bytes[8];
		bytes[0] = integer & 0x00000000000000FF;
		bytes[1] = (integer & 0x000000000000FF00) >> 8;
		bytes[2] = (integer & 0x0000000000FF0000) >> 16;
		bytes[3] = (integer & 0x00000000FF000000) >> 24;
		bytes[4] = (integer & 0x000000FF00000000) >> 32;
		bytes[5] = (integer & 0x0000FF0000000000) >> 40;
		bytes[6] = (integer & 0x00FF000000000000) >> 48;
		bytes[7] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileWriter::WriteInt8BE(int8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileWriter::WriteInt16BE(int16_t integer)
	{
		uint8_t bytes[2];
		bytes[1] = integer & 0x00FF;
		bytes[0] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileWriter::WriteInt32BE(int32_t integer)
	{
		uint8_t bytes[4];
		bytes[3] = integer & 0x000000FF;
		bytes[2] = (integer & 0x0000FF00) >> 8;
		bytes[1] = (integer & 0x00FF0000) >> 16;
		bytes[0] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileWriter::WriteInt64BE(int64_t integer)
	{
		uint8_t bytes[8];
		bytes[7] = integer & 0x00000000000000FF;
		bytes[6] = (integer & 0x000000000000FF00) >> 8;
		bytes[5] = (integer & 0x0000000000FF0000) >> 16;
		bytes[4] = (integer & 0x00000000FF000000) >> 24;
		bytes[3] = (integer & 0x000000FF00000000) >> 32;
		bytes[2] = (integer & 0x0000FF0000000000) >> 40;
		bytes[1] = (integer & 0x00FF000000000000) >> 48;
		bytes[0] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileWriter::WriteUInt8BE(uint8_t integer)
	{
		uint8_t bytes[1];
		bytes[0] = integer;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 1);
	}

	void FileWriter::WriteUInt16BE(uint16_t integer)
	{
		uint8_t bytes[2];
		bytes[1] = integer & 0x00FF;
		bytes[0] = (integer & 0xFF00) >> 8;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 2);
	}

	void FileWriter::WriteUInt32BE(uint32_t integer)
	{
		uint8_t bytes[4];
		bytes[3] = integer & 0x000000FF;
		bytes[2] = (integer & 0x0000FF00) >> 8;
		bytes[1] = (integer & 0x00FF0000) >> 16;
		bytes[0] = (integer & 0xFF000000) >> 24;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 4);
	}

	void FileWriter::WriteUInt64BE(uint64_t integer)
	{
		uint8_t bytes[8];
		bytes[7] = integer & 0x00000000000000FF;
		bytes[6] = (integer & 0x000000000000FF00) >> 8;
		bytes[5] = (integer & 0x0000000000FF0000) >> 16;
		bytes[4] = (integer & 0x00000000FF000000) >> 24;
		bytes[3] = (integer & 0x000000FF00000000) >> 32;
		bytes[2] = (integer & 0x0000FF0000000000) >> 40;
		bytes[1] = (integer & 0x00FF000000000000) >> 48;
		bytes[0] = (integer & 0xFF00000000000000) >> 56;
		m_FileStream.write(reinterpret_cast<char*>(bytes), 8);
	}

	void FileWriter::WriteString(const std::string& str)
	{
		m_FileStream.write(str.c_str(), str.size());
	}

	void FileWriter::WriteStringWithNull(const std::string& str)
	{
		m_FileStream.write(str.c_str(), str.size() + 1);
	}
}