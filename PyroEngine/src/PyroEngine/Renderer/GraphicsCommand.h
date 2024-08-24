#pragma once
#include "VertexArray.h"

namespace PyroEngine
{
	class GraphicsCommand
	{
	public:
		virtual void Init() = 0;
		virtual void SetClearColour(float red, float green, float blue) = 0;
		virtual void Clear() = 0;
		virtual int GetTextureSlots() = 0;
		virtual void SetViewport(int x, int y, int width, int height) = 0;
		virtual void Draw(VertexArray* vertexArray, uint32_t indexCount = 0) = 0;
	};
}