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
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_9_DESC, PYRO_ERROR_9);
			return nullptr;
		case OpenGL:
			return new OpenGLTexture(filePath);
		default:
			break;
		}

		PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_10_DESC, PYRO_ERROR_10);
		return nullptr;
	}

	Texture* Texture::Create(uint32_t width, uint32_t height)
	{
		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_9_DESC, PYRO_ERROR_9);
			return nullptr;
		case OpenGL:
			return new OpenGLTexture(width, height);
		default:
			break;
		}

		PYRO_LOG_ARGS_ERROR("[ENGINE] E{0}: " + PYRO_ERROR_10_DESC, PYRO_ERROR_10);
		return nullptr;
	}
}