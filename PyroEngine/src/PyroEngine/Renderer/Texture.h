#pragma once
#include <string>
#include <filesystem>
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual const std::filesystem::path& GetFilePath() const = 0;

		virtual PYRO_TYPE_ERROR SetData(void* data, uint32_t size) = 0;

		static Texture* Create(const std::filesystem::path& filePath);
		static Texture* Create(uint32_t width, uint32_t height);
	};
}