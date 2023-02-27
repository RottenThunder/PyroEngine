#include "PyroEnginePCH.h"
#include "Layer.h"

namespace PyroEngine
{
	Layer::Layer()
		: m_LayerID(0), m_LayerEnabled(true)
	{
		//TODO: Generate a random number to be the LayerID

#if defined PYRO_CONFIG_DEBUG
		m_LayerDebugDescription = "A Standard Layer";
#endif
	}

#if defined PYRO_CONFIG_DEBUG
	Layer::Layer(const std::string& debugDescription)
		: m_LayerDebugDescription(debugDescription), m_LayerID(0), m_LayerEnabled(true)
	{
		//TODO: Generate a random number to be the LayerID
	}
#endif

	Layer::~Layer()
	{
	}
}