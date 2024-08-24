#pragma once
#include "PyroEngine/Renderer/GraphicsCommand.h"

namespace PyroEngine
{
	class OpenGLCommand : public GraphicsCommand
	{
	public:
		virtual void Init() override;
		virtual void SetClearColour(float red, float green, float blue) override;
		virtual void Clear() override;
		virtual int GetTextureSlots() override;
		virtual void SetViewport(int x, int y, int width, int height) override;
		virtual void Draw(VertexArray* vertexArray, uint32_t indexCount = 0) override;
	};
}