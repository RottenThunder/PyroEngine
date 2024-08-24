#pragma once
#include "PyroEngine/Renderer/OpenGL/OpenGLCommand.h"
#include "PyroEngine/Maths/Vector.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"

namespace PyroEngine
{
	struct QuadVertex
	{
		Vector2 position;
		Vector2 texCoord;
		float red;
		float green;
		float blue;
		float alpha;
		float texIndex;
	};

	class Renderer
	{
	private:
		static bool s_RendererInitialised;

		static GraphicsCommand* s_GraphicsCommand;

		static const uint32_t s_MaxQuads = 10000;
		static const uint32_t s_MaxVertices = s_MaxQuads * 4;
		static const uint32_t s_MaxIndices = s_MaxQuads * 6;
		static uint32_t s_MaxTextureSlots;
		static VertexArray* s_QuadVertexArray;
		static VertexBuffer* s_QuadVertexBuffer;
		static Shader* s_TextureShader;
		static Texture* s_WhiteTexture;

		static uint32_t s_QuadIndexCount;
		static QuadVertex* s_QuadVertexBufferBase;
		static QuadVertex* s_QuadVertexBufferPtr;

		static std::vector<Texture*> s_TextureSlots;
		static uint32_t s_TextureSlotIndex; //0 = white texture
	public:
		static void Init();
		static void Terminate();

		static void BeginScene(const Camera& camera);
		static void EndScene();
		static void EndSceneAndReset();

		static void DrawQuad(const Vector2& pos, float radians, const Vector2& size, float red, float green, float blue, Texture* texture = nullptr);
	};
}