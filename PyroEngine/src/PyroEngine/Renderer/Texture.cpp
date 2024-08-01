#include "PyroEnginePCH.h"
#include "Texture.h"
#include "PyroEngine/Core/GlobalSettings.h"
#include "OpenGL/OpenGLTexture.h"

namespace PyroEngine
{
	Texture* Texture::Create(const std::filesystem::path& filePath)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			Logger::Log(LoggerChannel::Error, "A Texture has been created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLTexture(filePath);
		default:
			break;
		}

		Logger::Log(LoggerChannel::Error, "A Texture has been created with an unknown Graphics API");
		return nullptr;
	}

	Texture* Texture::Create(uint32_t width, uint32_t height)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			Logger::Log(LoggerChannel::Error, "A Texture has been created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLTexture(width, height);
		default:
			break;
		}

		Logger::Log(LoggerChannel::Error, "A Texture has been created with an unknown Graphics API");
		return nullptr;
	}
}