#include "PyroEnginePCH.h"
#include "OpenGLCommand.h"
#include "glad/glad.h"

namespace PyroEngine
{
	void OpenGLCommand::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLCommand::SetClearColour(float red, float green, float blue)
	{
		glClearColor(red, green, blue, 1.0f);
	}

	void OpenGLCommand::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	int OpenGLCommand::GetTextureSlots()
	{
		int textureSlots;
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &textureSlots);
		return textureSlots;
	}

	void OpenGLCommand::SetViewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLCommand::Draw(VertexArray* vertexArray, uint32_t indexCount)
	{
		uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}