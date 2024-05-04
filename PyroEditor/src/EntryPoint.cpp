#include <PyroEngine.h>

class MainApplication : public PyroEngine::WindowApplication
{
private:
	PyroEngine::VertexArray* m_VertexArray = nullptr;
	PyroEngine::VertexBuffer* m_VertexBuffer = nullptr;
	PyroEngine::IndexBuffer* m_IndexBuffer = nullptr;
	PyroEngine::Shader* m_Shader = nullptr;
public:
	MainApplication()
		: WindowApplication() {}

	virtual void OnWindowAttach() override
	{
		m_VertexArray = PyroEngine::VertexArray::Create();

		float SquareVertices[4 * 6] =
		{
			-0.75f, -0.75f, 1.0f, 0.0f, 0.0f, 1.0f,//Bottom-Left
			0.75f, -0.75f, 1.0f, 1.0f, 0.0f, 1.0f,//Bottom-Right
			0.75f, 0.75f, 1.0f, 1.0f, 1.0f, 1.0f,//Top-Right
			-0.75f, 0.75f, 0.0f, 1.0f, 1.0f, 1.0f, //Top-Left
		};

		m_VertexBuffer = PyroEngine::VertexBuffer::Create(SquareVertices, sizeof(SquareVertices));

		m_VertexBuffer->SetLayout({
			{ PyroEngine::ShaderDataType::Float2, "i_Position" },
			{ PyroEngine::ShaderDataType::Float4, "i_Colour" }
			});

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		m_IndexBuffer = PyroEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
			#version 330 core
			layout(location = 0) in vec2 i_Position;
            layout(location = 1) in vec4 i_Colour;
			out vec2 v_Position;
            out vec4 v_Colour;
			void main()
			{
				v_Position = i_Position;
                v_Colour = i_Colour;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 Colour;
			in vec2 v_Position;
            in vec4 v_Colour;
			void main()
			{
				Colour = v_Colour;
			}
		)";

		m_Shader = PyroEngine::Shader::Create(vertexSrc, fragmentSrc);

		p_VertexArray = m_VertexArray;
		p_Shader = m_Shader;
	}

	virtual void OnWindowDetach() override
	{
		delete m_VertexArray;
		delete m_VertexBuffer;
		delete m_IndexBuffer;
		delete m_Shader;
	}

	virtual void OnWindowUpdate() override
	{
	}

	virtual void OnWindowEvent(PyroEngine::Event& e) override
	{
	}
};

int main()
{
	PyroEngine::Engine::GetGlobalSettings().globalAPI = PyroEngine::GraphicsAPI::OpenGL;
	PyroEngine::Engine::Init();
	MainApplication* mainApp = new MainApplication();
	PyroEngine::Engine::AddApplication(mainApp);
	PyroEngine::Engine::Run();
	PyroEngine::Engine::Terminate();
	delete mainApp;
}