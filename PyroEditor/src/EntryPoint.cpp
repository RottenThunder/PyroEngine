#include <PyroEngine.h>

class MainProgram : public PyroEngine::Program
{
private:
	PyroEngine::VertexArray* m_VertexArray = nullptr;
	PyroEngine::VertexBuffer* m_VertexBuffer = nullptr;
	PyroEngine::IndexBuffer* m_IndexBuffer = nullptr;
	PyroEngine::Shader* m_Shader = nullptr;
	PyroEngine::Texture* m_Texture = nullptr;
public:
	MainProgram()
		: Program() {}

	virtual void OnProgramAttach() override
	{
		m_VertexArray = PyroEngine::VertexArray::Create();

		float SquareVertices[4 * 8] =
		{
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,//Bottom-Left
			0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,//Bottom-Right
			0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,//Top-Right
			-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //Top-Left
		};

		m_VertexBuffer = PyroEngine::VertexBuffer::Create(SquareVertices, sizeof(SquareVertices));

		m_VertexBuffer->SetLayout({
			{ PyroEngine::ShaderDataType::Float2, "i_Position" },
			{ PyroEngine::ShaderDataType::Float2, "i_TexCoord" },
			{ PyroEngine::ShaderDataType::Float4, "i_Colour" }
			});

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		m_IndexBuffer = PyroEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
			layout(location = 1) in vec2 i_TexCoord;
            layout(location = 2) in vec4 i_Colour;
			out vec2 v_TexCoord;
            out vec4 v_Colour;
			void main()
			{
				v_TexCoord = i_TexCoord;
                v_Colour = i_Colour;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 Colour;
			in vec2 v_TexCoord;
            in vec4 v_Colour;
			uniform sampler2D u_Texture;
			void main()
			{
				Colour = texture(u_Texture, v_TexCoord) * v_Colour;
			}
		)";

		m_Shader = PyroEngine::Shader::Create(vertexSrc, fragmentSrc);

		m_Texture = PyroEngine::Texture::Create(2, 2);
		uint8_t textureData[16] = { 0xFF, 0x00, 0x00, 0xFF,
									0x00, 0xFF, 0x00, 0xFF,
									0x00, 0x00, 0xFF, 0xFF,
									0xFF, 0xFF, 0x00, 0xFF };
		m_Texture->SetData(textureData, 16);

		p_VertexArray = m_VertexArray;
		p_Shader = m_Shader;
		p_Texture = m_Texture;
	}

	virtual void OnProgramDetach() override
	{
		delete m_VertexArray;
		delete m_VertexBuffer;
		delete m_IndexBuffer;
		delete m_Shader;
		delete m_Texture;
	}

	virtual void OnProgramUpdate() override
	{
	}

	virtual void OnProgramEvent(PyroEngine::Event& e) override
	{
	}
};

int main(int argc, char** argv)
{
	PyroEngine::GlobalSettings::s_GraphicsAPI = PyroEngine::GraphicsAPI::OpenGL;
	PyroEngine::Engine::Init();
	MainProgram* mainProgram = new MainProgram();
	PyroEngine::Engine::AddProgram(mainProgram);
	PyroEngine::Engine::Run();
	PyroEngine::Engine::Terminate();
	delete mainProgram;
	return 0;
}

#if defined PYRO_PLATFORM_WINDOWS && PYRO_CONFIG_RELEASE

#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	int argc = 0;
	char** argv = nullptr;

	std::vector<size_t> argSizes;
	size_t currentArgSize = 0;
	size_t cmdLineSize = std::strlen(lpCmdLine);

	char* cmdLine = nullptr;

	if (cmdLineSize == 0)
	{
		const char* baseStr = "PyroEngine";
		cmdLine = (char*)::operator new((std::strlen(baseStr) + 1) * sizeof(char));
		std::strcpy(cmdLine, baseStr);
		cmdLineSize = std::strlen(cmdLine);
	}
	else
	{
		cmdLine = (char*)::operator new((cmdLineSize + 1) * sizeof(char));
		std::strcpy(cmdLine, lpCmdLine);
	}

	for (size_t i = 0; i < cmdLineSize; i++)
	{
		if (cmdLine[i] == ' ')
		{
			argc++;
			argSizes.push_back(currentArgSize);
			currentArgSize = 0;
		}
		else
			currentArgSize++;
	}
	argc++;
	argSizes.push_back(currentArgSize);

	argv = (char**)::operator new(argSizes.size() * sizeof(char*));
	for (size_t i = 0; i < argSizes.size(); i++)
		argv[i] = (char*)::operator new((argSizes[i] + 1) * sizeof(char));

	size_t currentCharIndex = 0;
	for (size_t i = 0; i < argSizes.size(); i++)
	{
		for (size_t j = 0; j < argSizes[i]; j++)
		{
			argv[i][j] = cmdLine[currentCharIndex];
			currentCharIndex++;
		}

		argv[i][argSizes[i]] = '\0';
		currentCharIndex++;
	}

	int exit_code = main(argc, argv);

	for (size_t i = 0; i < argSizes.size(); i++)
		::operator delete(argv[i], (argSizes[i] + 1) * sizeof(char));

	::operator delete(argv, argSizes.size() * sizeof(char*));

	::operator delete(cmdLine, (cmdLineSize + 1) * sizeof(char));

	return exit_code;
}

#endif