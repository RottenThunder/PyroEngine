#pragma once
#include "Base.h"
#include "PyroEngine/Events/WindowEvent.h"
#include "PyroEngine/Events/KeyEvent.h"
#include "PyroEngine/Events/MouseEvent.h"

namespace PyroEngine
{
	class Layer
	{
	protected:
		uint64_t m_LayerID;
		bool m_LayerEnabled;
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline uint64_t GetID() const { return m_LayerID; }
		inline bool GetEnabledStatus() const { return m_LayerEnabled; }
		inline void SetEnabledStatus(bool enable) { m_LayerEnabled = enable; }

#if defined PYRO_CONFIG_DEBUG
	protected:
		std::string m_LayerDebugDescription;
	public:
		Layer(const std::string& debugDescription);
#endif
	};
}