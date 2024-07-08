#pragma once
#include <stdint.h>

namespace PyroEngine
{
	//Object that can be used to read from files on the host system
	class FileReader
	{
	private:
		std::filesystem::path m_FilePath; //The path to where the currently open file is on the host system
		uint8_t* m_FileContents; //The file's contents, loaded into memory
		size_t m_FileContentSize; //Size of the file contents (in bytes), this will be equal to the maxMemorySize variable that was given when opening the file OR the file's size. Whichever is lower.
		size_t m_FileContentMaxUsableSize; //Amount of bytes that are in the file contents that exist within the actual file
		size_t m_FileContentPositionIndicator; //Index of the current position within the file contents
		size_t m_FileStreamPositionIndicator; //Index of which Index 0 of the file contents is within the actual file

		//Loads the next part of the file (if there is one) into memory. Returns whether it was successful
		bool LoadNextPartOfFile();
		//Loads the previous part of the file (if there is one) into memory. Returns whether it was successful
		bool LoadPrevPartOfFile();

		//Retrives the next byte from the file and increments the position within if it can
		uint8_t ExtractByte();
	public:
		//Default constructor
		FileReader();
		//Default destructor
		~FileReader();

		//Returns the file path of the currently open file. If no file is open, then it will return the current working directory
		std::filesystem::path GetFilePath();
		//Returns the size of the currently open file (in bytes) on the host system. If no file is open, then it will return 0
		size_t GetFileSize();

		//Sets the position of the indicator such that the next retrieved byte is from that position. Returns whether it was successful
		bool SeekPosition(size_t pos);
		//Returns the current position of the indicator within the currently open file. If no file is open, then it will return 0
		size_t GetPosition();

		//Increments the position of the indicator such that the next retrieved byte is from the next position within the file. Returns whether it was successful
		bool IncrementPosition();
		//Decrements the position of the indicator such that the next retrieved byte is from the previous position within the file. Returns whether it was successful
		bool DecrementPosition();

		//Opens a file that is on the host system. An optional maximum amount of memory may be set for the reader to use. Returns whether it was successful. If it was successful and if there was a currently open file already, then that file will be closed and the new one will be opened
		bool Open(const std::filesystem::path& path, size_t maxMemorySize = UINT64_MAX);
		//Closes the currently open file, if there is no currently open file then this function will not do anything
		void Close();

		//Retrieves the next 8-bit signed integer (little-endian) from the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		int8_t ReadInt8LE();
		//Retrieves the next 16-bit signed integer (little-endian) from the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		int16_t ReadInt16LE();
		//Retrieves the next 32-bit signed integer (little-endian) from the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		int32_t ReadInt32LE();
		//Retrieves the next 64-bit signed integer (little-endian) from the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		int64_t ReadInt64LE();

		//Retrieves the next 8-bit unsigned integer (little-endian) from the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		uint8_t ReadUInt8LE();
		//Retrieves the next 16-bit unsigned integer (little-endian) from the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		uint16_t ReadUInt16LE();
		//Retrieves the next 32-bit unsigned integer (little-endian) from the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		uint32_t ReadUInt32LE();
		//Retrieves the next 64-bit unsigned integer (little-endian) from the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		uint64_t ReadUInt64LE();

		//Retrieves the next 8-bit signed integer (big-endian) from the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		int8_t ReadInt8BE();
		//Retrieves the next 16-bit signed integer (big-endian) from the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		int16_t ReadInt16BE();
		//Retrieves the next 32-bit signed integer (big-endian) from the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		int32_t ReadInt32BE();
		//Retrieves the next 64-bit signed integer (big-endian) from the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		int64_t ReadInt64BE();

		//Retrieves the next 8-bit unsigned integer (big-endian) from the current position within the file and increments said position by 1 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 1
		uint8_t ReadUInt8BE();
		//Retrieves the next 16-bit unsigned integer (big-endian) from the current position within the file and increments said position by 2 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 2
		uint16_t ReadUInt16BE();
		//Retrieves the next 32-bit unsigned integer (big-endian) from the current position within the file and increments said position by 4 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 4
		uint32_t ReadUInt32BE();
		//Retrieves the next 64-bit unsigned integer (big-endian) from the current position within the file and increments said position by 8 if it can. If it can't then it will increment by as much as it possibly can up to a maximum of 8
		uint64_t ReadUInt64BE();

		//Retrives the next string of the length specified starting from the current position within the file and increments said position by the length specified if it can. If it can't then it will increment by as much as it possibly can up to a maximum of the length specified
		std::string ReadString(size_t length);
		//Retrieves the next string from the current position within the file. This function will stop as soon as the end of the file is reached or until a null character has been reached. It will increment the current position within the file by the amount of characters retrieved
		std::string ReadStringUntilNull();
	};
}