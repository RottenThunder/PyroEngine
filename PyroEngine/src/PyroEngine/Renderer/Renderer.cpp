#include "PyroEnginePCH.h"
#include "Renderer.h"
#include "PyroEngine/Core/GlobalSettings.h"

namespace PyroEngine
{
	bool Renderer::s_RendererInitialised = false;

	GraphicsCommand* Renderer::s_GraphicsCommand = nullptr;

	uint32_t Renderer::s_MaxTextureSlots = 0;
	VertexArray* Renderer::s_QuadVertexArray = nullptr;
	VertexBuffer* Renderer::s_QuadVertexBuffer = nullptr;
	Shader* Renderer::s_TextureShader = nullptr;
	Texture* Renderer::s_WhiteTexture = nullptr;

	uint32_t Renderer::s_QuadIndexCount = 0;
	QuadVertex* Renderer::s_QuadVertexBufferBase = nullptr;
	QuadVertex* Renderer::s_QuadVertexBufferPtr = nullptr;

	std::vector<Texture*> Renderer::s_TextureSlots;
	uint32_t Renderer::s_TextureSlotIndex = 0;

	void Renderer::Init()
	{
		if (s_RendererInitialised)
			return;

		switch (GlobalSettings::s_GraphicsAPI)
		{
		case GraphicsAPINone:
			break;
		case OpenGL:
			s_GraphicsCommand = new OpenGLCommand();
			break;
		default:
			break;
		}

		s_GraphicsCommand->Init();

		s_MaxTextureSlots = s_GraphicsCommand->GetTextureSlots();
		s_TextureSlots.resize(s_MaxTextureSlots);

		s_QuadVertexArray = VertexArray::Create();
		s_QuadVertexBuffer = VertexBuffer::Create(s_MaxVertices * sizeof(QuadVertex));
		s_QuadVertexBuffer->SetLayout({
			{ ShaderDataType::Float2, "i_Position" },
			{ ShaderDataType::Float2, "i_TexCoord" },
			{ ShaderDataType::Float4, "i_Colour" },
			{ ShaderDataType::Float, "i_TexIndex" },
			});
		s_QuadVertexArray->AddVertexBuffer(s_QuadVertexBuffer);

		s_QuadVertexBufferBase = new QuadVertex[s_MaxVertices];

		uint32_t* quadIndices = new uint32_t[s_MaxIndices];

		uint32_t offset = 0;
		for (uint32_t i = 0; i < s_MaxIndices; i += 6)
		{
			quadIndices[i + 0] = offset + 0;
			quadIndices[i + 1] = offset + 1;
			quadIndices[i + 2] = offset + 2;

			quadIndices[i + 3] = offset + 2;
			quadIndices[i + 4] = offset + 3;
			quadIndices[i + 5] = offset + 0;

			offset += 4;
		}

		IndexBuffer* quadIB = IndexBuffer::Create(quadIndices, s_MaxIndices);
		s_QuadVertexArray->SetIndexBuffer(quadIB);
		delete[] quadIndices;

		s_WhiteTexture = Texture::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		s_WhiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

		std::vector<int> samplers;
		samplers.resize(s_MaxTextureSlots);
		for (uint32_t i = 0; i < s_MaxTextureSlots; i++)
			samplers[i] = i;

		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			layout(location = 1) in vec2 i_TexCoord;
			layout(location = 2) in vec4 i_Colour;
			layout(location = 3) in float i_TexIndex;
			uniform mat4 u_ViewProjection;
			out vec2 v_TexCoord;
			out vec4 v_Colour;
			out float v_TexIndex;
			void main()
			{
				v_TexCoord = i_TexCoord;
				v_Colour = i_Colour;
				v_TexIndex = i_TexIndex;
				gl_Position = u_ViewProjection * vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 colour;
			in vec2 v_TexCoord;
			in vec4 v_Colour;
			in float v_TexIndex;
			uniform sampler2D u_Textures[32];
			void main()
			{
				colour = texture(u_Textures[int(v_TexIndex)], v_TexCoord) * v_Colour;
			}
		)";
		s_TextureShader = Shader::Create(vertexSrc, fragmentSrc);
		s_TextureShader->UploadUniformIntArray("u_Textures", samplers.data(), s_MaxTextureSlots);

		s_TextureSlots[0] = s_WhiteTexture;

		s_RendererInitialised = true;
	}

	void Renderer::Terminate()
	{
		delete[] s_QuadVertexBufferBase;
	}

	void Renderer::BeginScene(const Camera& camera)
	{
		s_GraphicsCommand->SetClearColour(0.0f, 0.0f, 0.0f);
		s_GraphicsCommand->Clear();

		s_TextureShader->UploadUniformMatrix4x4("u_ViewProjection", camera.GetViewProjectionMatrix());

		s_QuadIndexCount = 0;
		s_QuadVertexBufferPtr = s_QuadVertexBufferBase;

		s_TextureSlotIndex = 1;
	}

	void Renderer::EndScene()
	{
		uint32_t dataSize = (uint8_t*)s_QuadVertexBufferPtr - (uint8_t*)s_QuadVertexBufferBase;
		s_QuadVertexBuffer->SetData(s_QuadVertexBufferBase, dataSize);

		for (uint32_t i = 0; i < s_TextureSlotIndex; i++)
			s_TextureSlots[i]->BindToSlot(i);

		s_GraphicsCommand->Draw(s_QuadVertexArray, s_QuadIndexCount);
	}

	void Renderer::EndSceneAndReset()
	{
		EndScene();

		s_QuadIndexCount = 0;
		s_QuadVertexBufferPtr = s_QuadVertexBufferBase;

		s_TextureSlotIndex = 1;
	}

	void Renderer::DrawQuad(const Vector2& pos, float radians, const Vector2& size, float red, float green, float blue, Texture* texture)
	{
		if (s_QuadIndexCount >= s_MaxIndices)
			EndSceneAndReset();

		if (texture == nullptr)
			return;

		float textureIndex = 0.0f;
		for (uint32_t i = 1; i < s_TextureSlotIndex; i++)
		{
			if (s_TextureSlots[i] == texture)
			{
				textureIndex = (float)i;
				break;
			}
		}

		if (textureIndex == 0.0f)
		{
			if (s_TextureSlotIndex >= s_MaxTextureSlots)
				EndSceneAndReset();

			textureIndex = (float)s_TextureSlotIndex;
			s_TextureSlots[s_TextureSlotIndex] = texture;
			s_TextureSlotIndex++;
		}

		float sinAngle = std::sin(radians);
		float cosAngle = std::cos(radians);
		float halfSinSizeX = sinAngle * size.x * 0.5f;
		float halfSinSizeY = sinAngle * size.y * 0.5f;
		float halfCosSizeX = cosAngle * size.x * 0.5f;
		float halfCosSizeY = cosAngle * size.y * 0.5f;

		Vector2 pos1; //BL
		Vector2 pos2; //BR
		Vector2 pos3; //TR
		Vector2 pos4; //TL

		pos1.x = halfSinSizeY - halfCosSizeX;
		pos1.x += pos.x;

		pos1.y = pos.y;
		pos1.y -= halfCosSizeY;
		pos1.y -= halfSinSizeX;

		pos2.x = halfCosSizeX + halfSinSizeY;
		pos2.x += pos.x;

		pos2.y = halfSinSizeX - halfCosSizeY;
		pos2.y += pos.y;

		pos3.x = halfCosSizeX - halfSinSizeY;
		pos3.x += pos.x;

		pos3.y = halfCosSizeY + halfSinSizeX;
		pos3.y += pos.y;

		pos4.x = pos.x;
		pos4.x -= halfCosSizeX;
		pos4.x -= halfSinSizeY;

		pos4.y = halfCosSizeY - halfSinSizeX;
		pos4.y += pos.y;

		s_QuadVertexBufferPtr->position = pos1;
		s_QuadVertexBufferPtr->texCoord = { 0.0f, 0.0f };
		s_QuadVertexBufferPtr->red = red;
		s_QuadVertexBufferPtr->green = green;
		s_QuadVertexBufferPtr->blue = blue;
		s_QuadVertexBufferPtr->alpha = 1.0f;
		s_QuadVertexBufferPtr->texIndex = textureIndex;
		s_QuadVertexBufferPtr++;

		s_QuadVertexBufferPtr->position = pos2;
		s_QuadVertexBufferPtr->texCoord = { 1.0f, 0.0f };
		s_QuadVertexBufferPtr->red = red;
		s_QuadVertexBufferPtr->green = green;
		s_QuadVertexBufferPtr->blue = blue;
		s_QuadVertexBufferPtr->alpha = 1.0f;
		s_QuadVertexBufferPtr->texIndex = textureIndex;
		s_QuadVertexBufferPtr++;

		s_QuadVertexBufferPtr->position = pos3;
		s_QuadVertexBufferPtr->texCoord = { 1.0f, 1.0f };
		s_QuadVertexBufferPtr->red = red;
		s_QuadVertexBufferPtr->green = green;
		s_QuadVertexBufferPtr->blue = blue;
		s_QuadVertexBufferPtr->alpha = 1.0f;
		s_QuadVertexBufferPtr->texIndex = textureIndex;
		s_QuadVertexBufferPtr++;

		s_QuadVertexBufferPtr->position = pos4;
		s_QuadVertexBufferPtr->texCoord = { 0.0f, 1.0f };
		s_QuadVertexBufferPtr->red = red;
		s_QuadVertexBufferPtr->green = green;
		s_QuadVertexBufferPtr->blue = blue;
		s_QuadVertexBufferPtr->alpha = 1.0f;
		s_QuadVertexBufferPtr->texIndex = textureIndex;
		s_QuadVertexBufferPtr++;

		s_QuadIndexCount += 6;
	}
}