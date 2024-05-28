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
			PYRO_ASSERT(false, "A Texture is about to be created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLTexture(filePath);
		default:
			break;
		}

		PYRO_ASSERT(false, "A Texture is about to be created with an unknown Graphics API");
		return nullptr;
	}

	Texture* Texture::Create(uint32_t width, uint32_t height)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			PYRO_ASSERT(false, "A Texture is about to be created with no Graphics API");
			return nullptr;
		case OpenGL:
			return new OpenGLTexture(width, height);
		default:
			break;
		}

		PYRO_ASSERT(false, "A Texture is about to be created with an unknown Graphics API");
		return nullptr;
	}
}