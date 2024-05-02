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

		double SquareVertices[4 * 6] =
		{
			-0.75, -0.75, 1.0, 0.0, 0.0, 1.0,//Bottom-Left
			0.75, -0.75, 1.0, 0.0, 0.0, 1.0,//Bottom-Right
			0.75, 0.75, 1.0, 0.0, 0.0, 1.0,//Top-Right
			-0.75, 0.75, 1.0, 0.0, 0.0, 1.0, //Top-Left
		};

		m_VertexBuffer = PyroEngine::VertexBuffer::Create(SquareVertices, sizeof(SquareVertices));

		m_VertexBuffer->SetLayout({
			{ PyroEngine::ShaderDataType::Double2, "i_Position" },
			{ PyroEngine::ShaderDataType::Double4, "i_Colour" }
			});

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		m_IndexBuffer = PyroEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));

		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrcSquare = R"(
			#version 410 core
			layout(location = 0) in dvec2 i_Position;
            layout(location = 1) in dvec4 i_Colour;
			out dvec2 v_Position;
            out dvec4 v_Colour;
			void main()
			{
				v_Position = i_Position;
                v_Colour = i_Colour;
				gl_Position = vec4(i_Position, 0.0, 1.0);
			}
		)";

		std::string fragmentSrcSquare = R"(
			#version 410 core
			layout(location = 0) out vec4 Colour;
			flat in dvec2 v_Position;
            flat in dvec4 v_Colour;
			void main()
			{
				Colour = vec4(0.1, v_Position + 0.5, 1.0);
			}
		)";

		m_Shader = PyroEngine::Shader::Create(vertexSrcSquare, fragmentSrcSquare);

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
	PyroEngine::Engine::Init();
	PyroEngine::Engine::GetGlobalSettings().globalAPI = PyroEngine::GraphicsAPI::OpenGL;
	MainApplication* mainApp = new MainApplication();
	PyroEngine::Engine::AddApplication(mainApp);
	PyroEngine::Engine::Run();
	PyroEngine::Engine::Terminate();
	delete mainApp;
}