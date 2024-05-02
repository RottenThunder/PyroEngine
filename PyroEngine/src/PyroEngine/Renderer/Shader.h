#pragma once
#include "PyroEngine/Core/Core.h"

namespace PyroEngine
{
	class Shader
	{
	public:
		virtual ~Shader() = default;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};
}