#include "PyroEnginePCH.h"
#include "FileReader.h"

namespace PyroEngine
{
    FileReader::FileReader()
        : m_FilePath(std::filesystem::current_path()), m_FileStream()
    {
    }

    FileReader::~FileReader()
    {
        m_FileStream.close();
    }

    std::filesystem::path FileReader::GetFilePath() const
    {
        return m_FilePath;
    }

    size_t FileReader::GetFileSize() const noexcept
    {
        std::error_code ec;
        size_t output = std::filesystem::file_size(m_FilePath, ec);
        if (ec)
            output = 0;

        return output;
    }

    bool FileReader::SeekPosition(size_t pos)
    {
        bool success = true;
        try
        {
            m_FileStream.seekg(pos, std::ios::beg);
        }
        catch (std::exception& e)
        {
            success = false;
        }
        return success;
    }

    size_t FileReader::GetPosition()
    {
        size_t output = 0;
        try
        {
            output = m_FileStream.tellg();
        }
        catch (std::exception& e)
        {
            output = 0;
        }

        return output;
    }

    bool FileReader::Open(const std::filesystem::path& path)
    {
        m_FileStream.close();
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

    void FileReader::Close()
    {
        m_FileStream.close();
        m_FilePath = std::filesystem::current_path();
    }

    bool FileReader::IsOpen() const noexcept
    {
        return m_FileStream.is_open();
    }

    int8_t FileReader::ReadInt8LE()
    {
        int8_t integer = 0;
        uint8_t bytes[1] = { 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
        integer |= (uint8_t)bytes[0];
        return integer;
    }

    int16_t FileReader::ReadInt16LE()
    {
        int16_t integer = 0;
        uint8_t bytes[2] = { 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
        integer |= (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
        return integer;
    }

    int32_t FileReader::ReadInt32LE()
    {
        int32_t integer = 0;
        uint8_t bytes[4] = { 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
        integer |= (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
        return integer;
    }

    int64_t FileReader::ReadInt64LE()
    {
        int64_t integer = 0;
        uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
        integer |= (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) | ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
        return integer;
    }

    uint8_t FileReader::ReadUInt8LE()
    {
        uint8_t integer = 0;
        uint8_t bytes[1] = { 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
        integer |= (uint8_t)bytes[0];
        return integer;
    }

    uint16_t FileReader::ReadUInt16LE()
    {
        uint16_t integer = 0;
        uint8_t bytes[2] = { 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
        integer |= (uint16_t)bytes[0] | ((uint16_t)bytes[1] << 8);
        return integer;
    }

    uint32_t FileReader::ReadUInt32LE()
    {
        uint32_t integer = 0;
        uint8_t bytes[4] = { 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
        integer |= (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8) | ((uint32_t)bytes[2] << 16) | ((uint32_t)bytes[3] << 24);
        return integer;
    }

    uint64_t FileReader::ReadUInt64LE()
    {
        uint64_t integer = 0;
        uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
        integer |= (uint64_t)bytes[0] | ((uint64_t)bytes[1] << 8) | ((uint64_t)bytes[2] << 16) | ((uint64_t)bytes[3] << 24) | ((uint64_t)bytes[4] << 32) | ((uint64_t)bytes[5] << 40) | ((uint64_t)bytes[6] << 48) | ((uint64_t)bytes[7] << 56);
        return integer;
    }

    int8_t FileReader::ReadInt8BE()
    {
        int8_t integer = 0;
        uint8_t bytes[1] = { 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
        integer |= (uint8_t)bytes[0];
        return integer;
    }

    int16_t FileReader::ReadInt16BE()
    {
        int16_t integer = 0;
        uint8_t bytes[2] = { 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
        integer |= (uint16_t)bytes[1] | ((uint16_t)bytes[0] << 8);
        return integer;
    }

    int32_t FileReader::ReadInt32BE()
    {
        int32_t integer = 0;
        uint8_t bytes[4] = { 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
        integer |= (uint32_t)bytes[3] | ((uint32_t)bytes[2] << 8) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[0] << 24);
        return integer;
    }

    int64_t FileReader::ReadInt64BE()
    {
        int64_t integer = 0;
        uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
        integer |= (uint64_t)bytes[7] | ((uint64_t)bytes[6] << 8) | ((uint64_t)bytes[5] << 16) | ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[3] << 32) | ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[1] << 48) | ((uint64_t)bytes[0] << 56);
        return integer;
    }

    uint8_t FileReader::ReadUInt8BE()
    {
        uint8_t integer = 0;
        uint8_t bytes[1] = { 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 1);
        integer |= (uint8_t)bytes[0];
        return integer;
    }

    uint16_t FileReader::ReadUInt16BE()
    {
        uint16_t integer = 0;
        uint8_t bytes[2] = { 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 2);
        integer |= (uint16_t)bytes[1] | ((uint16_t)bytes[0] << 8);
        return integer;
    }

    uint32_t FileReader::ReadUInt32BE()
    {
        uint32_t integer = 0;
        uint8_t bytes[4] = { 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 4);
        integer |= (uint32_t)bytes[3] | ((uint32_t)bytes[2] << 8) | ((uint32_t)bytes[1] << 16) | ((uint32_t)bytes[0] << 24);
        return integer;
    }

    uint64_t FileReader::ReadUInt64BE()
    {
        uint64_t integer = 0;
        uint8_t bytes[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
        m_FileStream.read(reinterpret_cast<char*>(bytes), 8);
        integer |= (uint64_t)bytes[7] | ((uint64_t)bytes[6] << 8) | ((uint64_t)bytes[5] << 16) | ((uint64_t)bytes[4] << 24) | ((uint64_t)bytes[3] << 32) | ((uint64_t)bytes[2] << 40) | ((uint64_t)bytes[1] << 48) | ((uint64_t)bytes[0] << 56);
        return integer;
    }

    std::string FileReader::ReadString(size_t length)
    {
        std::string output;
        char character = 0;
        for (size_t i = 0; i < length; i++)
        {
            m_FileStream >> character;
            output.push_back(character);
        }
        return output;
    }

    std::string FileReader::ReadStringUntilNull()
    {
        std::string output;
        char character = 0;
        m_FileStream >> character;
        while (character != 0)
        {
            output.push_back(character);
            m_FileStream >> character;
        }
        return output;
    }
}