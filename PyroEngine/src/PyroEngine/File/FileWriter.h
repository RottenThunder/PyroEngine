#pragma once
#include <stdint.h>

//The limit (in bytes) of which a file can be opened using a FileWriter
#define PYRO_FILE_WRITER_FILE_LIMIT 104857600

namespace PyroEngine
{
	//Object that can be used to write to files on the host system
	class FileWriter
	{
	private:
		std::filesystem::path m_FilePath; //The path to where the currently open file is on the host system
		std::ofstream m_FileStream; //The output stream used to open, close and write to files
		bool m_IsAlwaysAppending; //True if every write operation will append to the end of the file
	public:
		//Default constructor
		FileWriter();
		//Default destructor
		~FileWriter();

		//Returns the absolute path of the currently open file. If no file is open, then it will return the current working directory
		std::filesystem::path GetFilePath() const;
		//Returns whether or not every write operation will append to the end of the file. If no file is open, then it will return false always
		bool GetIsAlwaysAppending() const noexcept;

		//Opens a file on the host system. If a file is already currently open then it will close that file before attempting to open the new one. The writing indicator will be set at the very beginning of the file so that the next written byte is at the very start of the file. An optional flag can be given to specify that every write operation to the new file will append to the end of the file no matter what. This function can not open files that are greater in size than the PYRO_FILE_WRITER_FILE_LIMIT macro except if you are opening the file to append always. Returns whether or not the file has been successfully opened
		bool Open(const std::filesystem::path& path, bool alwaysAppend = false);
		//Closes the currently open file. If no file is open, then this function will not do anything
		void Close();
		//Returns whether or not a file is currently open
		bool IsOpen() const noexcept;

		//Sets the position of the indicator such that the next written byte is from that position. Has no effect if the currently open file is being appended to always. Returns whether it was successful
		bool SeekPosition(size_t pos);
		//Retrieves the current position of the indicator within the currently open file. If no file is open then it will return 0
		size_t GetPosition();

		//Sets the position of the indicator such that the next written byte is at the very start of the currently open file
		void GoToStart();
		//Sets the position of the indicator such that the next written byte is at the very end of the currently open file (any write operations after this will write new bytes to the file, not change the ones that are already there)
		void GoToEnd();

		//Writes an 8-bit signed integer (little-endian) to the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		void WriteInt8LE(int8_t integer);
		//Writes a 16-bit signed integer (little-endian) to the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		void WriteInt16LE(int16_t integer);
		//Writes a 32-bit signed integer (little-endian) to the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		void WriteInt32LE(int32_t integer);
		//Writes a 64-bit signed integer (little-endian) to the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		void WriteInt64LE(int64_t integer);

		//Writes an 8-bit unsigned integer (little-endian) to the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		void WriteUInt8LE(uint8_t integer);
		//Writes a 16-bit unsigned integer (little-endian) to the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		void WriteUInt16LE(uint16_t integer);
		//Writes a 32-bit unsigned integer (little-endian) to the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		void WriteUInt32LE(uint32_t integer);
		//Writes a 64-bit unsigned integer (little-endian) to the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		void WriteUInt64LE(uint64_t integer);

		//Writes an 8-bit signed integer (big-endian) to the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		void WriteInt8BE(int8_t integer);
		//Writes a 16-bit signed integer (big-endian) to the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		void WriteInt16BE(int16_t integer);
		//Writes a 32-bit signed integer (big-endian) to the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		void WriteInt32BE(int32_t integer);
		//Writes a 64-bit signed integer (big-endian) to the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		void WriteInt64BE(int64_t integer);

		//Writes an 8-bit unsigned integer (big-endian) to the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		void WriteUInt8BE(uint8_t integer);
		//Writes a 16-bit unsigned integer (big-endian) to the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		void WriteUInt16BE(uint16_t integer);
		//Writes a 32-bit unsigned integer (big-endian) to the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		void WriteUInt32BE(uint32_t integer);
		//Writes a 64-bit unsigned integer (big-endian) to the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		void WriteUInt64BE(uint64_t integer);

		//Writes a string to the file ignoring the null character at the end, then increments the positional indicator by the string's length
		void WriteString(const std::string& str);
		//Writes a string to the file including the null character at the end, then increments the positional indicator by the string's length
		void WriteStringWithNull(const std::string& str);
	};
}