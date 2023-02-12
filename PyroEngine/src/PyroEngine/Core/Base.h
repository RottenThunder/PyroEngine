#pragma once

#if defined PYRO_CONFIG_DEBUG
#define PYRO_ASSERTS_ENABLED
#else
#define PYRO_ASSERTS_DISABLED
#endif

#if defined PYRO_ASSERTS_ENABLED
#define PYRO_ASSERT(x, message) { if(!(x)) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#define PYRO_REVERSE_ASSERT(x, message) { if(x) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#else
#define PYRO_ASSERT(x, message) 
#define PYRO_REVERSE_ASSERT(x, message) 
#endif