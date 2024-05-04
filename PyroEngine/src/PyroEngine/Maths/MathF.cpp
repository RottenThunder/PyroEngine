#include "PyroEnginePCH.h"
#include "MathF.h"

namespace PyroEngine
{
	void (*MathF::ResetVector2)(float*) = nullptr;
	void (*MathF::ResetVector3)(float*) = nullptr;
	void (*MathF::ResetVector4)(float*) = nullptr;

	void MathF::Init()
	{

	}
}