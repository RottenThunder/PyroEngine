#include "PyroEnginePCH.h"
#include "FileReader.h"

namespace PyroEngine
{
	FileReader::FileReader()
		: m_FilePath(std::filesystem::current_path()), m_FileContents(nullptr), m_FileContentSize(0), m_FileContentMaxUsableSize(0), m_FileContentPositionIndicator(0), m_FileStreamPositionIndicator(0)
	{
	}

	FileReader::~FileReader()
	{
		::operator delete(m_FileContents, m_FileContentSize);
	}

	bool FileReader::LoadNextPartOfFile()
	{
		if (m_FileStreamPositionIndicator + m_FileContentMaxUsableSize >= GetFileSize())
			return false;

		std::ifstream stream;
		stream.open(m_FilePath, std::ios::in | std::ios::binary);
		m_FileStreamPositionIndicator += m_FileContentMaxUsableSize;
		stream.seekg(m_FileStreamPositionIndicator, std::ios::beg);
		stream.read(reinterpret_cast<char*>(m_FileContents), m_FileContentSize);
		m_FileContentMaxUsableSize = stream.gcount();
		m_FileContentPositionIndicator = 0;
		stream.close();
		return true;
	}

	bool FileReader::LoadPrevPartOfFile()
	{
		if (m_FileStreamPositionIndicator == 0)
			return false;

		std::ifstream stream;
		stream.open(m_FilePath, std::ios::in | std::ios::binary);
		m_FileStreamPositionIndicator -= m_FileContentSize;
		stream.seekg(m_FileStreamPositionIndicator , std::ios::beg);
		stream.read(reinterpret_cast<char*>(m_FileContents), m_FileContentSize);
		m_FileContentMaxUsableSize = stream.gcount();
		m_FileContentPositionIndicator = m_FileContentMaxUsableSize - 1;
		stream.close();
		return true;
	}

	uint8_t FileReader::ExtractByte()
	{
		uint8_t output = m_FileContents[m_FileContentPositionIndicator];
		m_FileContentPositionIndicator++;
		if (m_FileContentPositionIndicator >= m_FileContentMaxUsableSize)
		{
			bool isThereANextPart = LoadNextPartOfFile();
			if (!isThereANextPart)
				m_FileContentPositionIndicator--;
		}
		return output;
	}

	std::filesystem::path FileReader::GetFilePath()
	{
		return m_FilePath;
	}

	size_t FileReader::GetFileSize()
	{
		return std::filesystem::file_size(m_FilePath);
	}

	bool FileReader::SeekPosition(size_t pos)
	{
		if (m_FilePath == std::filesystem::current_path())
			return false;

		if (pos >= GetFileSize())
			return false;

		size_t block = pos / m_FileContentSize;
		size_t indexWithinBlock = pos % m_FileContentSize;

		if (block * m_FileContentSize == m_FileStreamPositionIndicator)
		{
			m_FileContentPositionIndicator = indexWithinBlock;
			return true;
		}

		m_FileStreamPositionIndicator = block * m_FileContentSize;
		m_FileContentPositionIndicator = indexWithinBlock;

		std::ifstream stream;
		stream.open(m_FilePath, std::ios::in | std::ios::binary);
		stream.seekg(m_FileStreamPositionIndicator, std::ios::beg);
		stream.read(reinterpret_cast<char*>(m_FileContents), m_FileContentSize);
		m_FileContentMaxUsableSize = stream.gcount();
		stream.close();
		return true;
	}

	size_t FileReader::GetPosition()
	{
		return m_FileContentPositionIndicator + m_FileStreamPositionIndicator;
	}

	bool FileReader::IncrementPosition()
	{
		if (m_FilePath == std::filesystem::current_path())
			return false;

		m_FileContentPositionIndicator++;
		if (m_FileContentPositionIndicator >= m_FileContentMaxUsableSize)
		{
			bool isThereANextPart = LoadNextPartOfFile();
			if (!isThereANextPart)
			{
				m_FileContentPositionIndicator--;
				return false;
			}
		}
		return true;
	}

	bool FileReader::DecrementPosition()
	{
		if (m_FilePath == std::filesystem::current_path())
			return false;

		m_FileContentPositionIndicator--;
		if (m_FileContentPositionIndicator == UINT64_MAX)
		{
			bool isThereAPrevPart = LoadPrevPartOfFile();
			if (!isThereAPrevPart)
			{
				m_FileContentPositionIndicator++;
				return false;
			}
		}
		return true;
	}

	bool FileReader::Open(const std::filesystem::path& path, size_t maxMemorySize)
	{
		std::ifstream stream;
		stream.open(path, std::ios::in | std::ios::binary);
		if (stream.is_open())
		{
			::operator delete(m_FileContents, m_FileContentSize);
			m_FilePath = path;
			m_FileContents = nullptr;
			m_FileContentSize = 0;
			m_FileContentMaxUsableSize = 0;
			m_FileContentPositionIndicator = 0;
			m_FileStreamPositionIndicator = 0;

			size_t fileSize = GetFileSize();
			if (maxMemorySize < fileSize)
				m_FileContentSize = maxMemorySize;
			else
				m_FileContentSize = fileSize;

			m_FileContentMaxUsableSize = m_FileContentSize;
			m_FileContents = new uint8_t[m_FileContentSize];
			stream.read(reinterpret_cast<char*>(m_FileContents), m_FileContentSize);
			stream.close();
			return true;
		}
		else
		{
			return false;
		}
	}

	void FileReader::Close()
	{
		::operator delete(m_FileContents, m_FileContentSize);
		m_FilePath = std::filesystem::current_path();
		m_FileContents = nullptr;
		m_FileContentSize = 0;
		m_FileContentMaxUsableSize = 0;
		m_FileContentPositionIndicator = 0;
		m_FileStreamPositionIndicator = 0;
	}

	int8_t FileReader::ReadInt8LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		bytes[0] = ExtractByte();
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	int16_t FileReader::ReadInt16LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		integer |= (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
		return integer;
	}

	int32_t FileReader::ReadInt32LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		integer |= (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
		return integer;
	}

	int64_t FileReader::ReadInt64LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		bytes[4] = ExtractByte();
		bytes[5] = ExtractByte();
		bytes[6] = ExtractByte();
		bytes[7] = ExtractByte();
		integer |= (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) | ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
		return integer;
	}

	uint8_t FileReader::ReadUInt8LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		bytes[0] = ExtractByte();
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	uint16_t FileReader::ReadUInt16LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		integer |= (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
		return integer;
	}

	uint32_t FileReader::ReadUInt32LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		integer |= (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
		return integer;
	}

	uint64_t FileReader::ReadUInt64LE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		bytes[4] = ExtractByte();
		bytes[5] = ExtractByte();
		bytes[6] = ExtractByte();
		bytes[7] = ExtractByte();
		integer |= (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) | ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
		return integer;
	}

	int8_t FileReader::ReadInt8BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		bytes[0] = ExtractByte();
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	int16_t FileReader::ReadInt16BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		integer |= (uint16_t)bytes[1] | ((uint16_t)bytes[0] << 8);
		return integer;
	}

	int32_t FileReader::ReadInt32BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		integer |= (uint32_t)bytes[3] | ((uint32_t)bytes[2] << 8) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[0] << 24);
		return integer;
	}

	int64_t FileReader::ReadInt64BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		int64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		bytes[4] = ExtractByte();
		bytes[5] = ExtractByte();
		bytes[6] = ExtractByte();
		bytes[7] = ExtractByte();
		integer |= (uint64_t)bytes[7] | ((uint64_t)bytes[6] << 8) | ((uint64_t)bytes[5] << 16) | ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[3] << 32) | ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[1] << 48) | ((uint64_t)bytes[0] << 56);
		return integer;
	}

	uint8_t FileReader::ReadUInt8BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint8_t integer = 0;
		uint8_t bytes[1] = { 0 };
		bytes[0] = ExtractByte();
		integer |= (uint8_t)bytes[0];
		return integer;
	}

	uint16_t FileReader::ReadUInt16BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint16_t integer = 0;
		uint8_t bytes[2] = { 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		integer |= (uint16_t)bytes[1] | ((uint16_t)bytes[0] << 8);
		return integer;
	}

	uint32_t FileReader::ReadUInt32BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint32_t integer = 0;
		uint8_t bytes[4] = { 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		integer |= (uint32_t)bytes[3] | ((uint32_t)bytes[2] << 8) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[0] << 24);
		return integer;
	}

	uint64_t FileReader::ReadUInt64BE()
	{
		if (m_FilePath == std::filesystem::current_path())
			return 0;

		uint64_t integer = 0;
		uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		bytes[0] = ExtractByte();
		bytes[1] = ExtractByte();
		bytes[2] = ExtractByte();
		bytes[3] = ExtractByte();
		bytes[4] = ExtractByte();
		bytes[5] = ExtractByte();
		bytes[6] = ExtractByte();
		bytes[7] = ExtractByte();
		integer |= (uint64_t)bytes[7] | ((uint64_t)bytes[6] << 8) | ((uint64_t)bytes[5] << 16) | ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[3] << 32) | ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[1] << 48) | ((uint64_t)bytes[0] << 56);
		return integer;
	}

	std::string FileReader::ReadString(size_t length)
	{
		std::string output;

		if (m_FilePath == std::filesystem::current_path())
			return output;

		for (size_t i = 0; i < length; i++)
		{
			uint8_t byte = ExtractByte();
			output.push_back((reinterpret_cast<char*>(&byte))[0]);
		}

		return output;
	}

	std::string FileReader::ReadStringUntilNull()
	{
		std::string output;

		if (m_FilePath == std::filesystem::current_path())
			return output;

		uint8_t byte = ExtractByte();
		while (byte != 0)
		{
			output.push_back((reinterpret_cast<char*>(&byte))[0]);
			size_t currentPosition = m_FileContentPositionIndicator;
			byte = ExtractByte();
			if (currentPosition == m_FileContentPositionIndicator)
				byte = 0;
		}
		return output;
	}
}