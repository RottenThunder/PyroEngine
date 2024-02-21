#pragma once

#define PYRO_VERSION_MAJOR 0
#define PYRO_VERSION_MINOR 0
#define PYRO_VERSION_PATCH 0

#if defined PYRO_CONFIG_DEBUG
#define PYRO_ASSERTS_ENABLED
#else
#define PYRO_ASSERTS_DISABLED
#endif

#if defined PYRO_ASSERTS_ENABLED
#if defined PYRO_PLATFORM_WINDOWS
#define PYRO_ASSERT(x, message) { if(!(x)) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#define PYRO_REVERSE_ASSERT(x, message) { if(x) { std::cout << "Assertion Failed: " << message << "\n"; __debugbreak(); } }
#endif
#if defined PYRO_PLATFORM_LINUX
#define PYRO_ASSERT(x, message) { if(!(x)) { std::cout << "Assertion Failed: " << message << "\n"; std::exit(1); } }
#define PYRO_REVERSE_ASSERT(x, message) { if(x) { std::cout << "Assertion Failed: " << message << "\n"; std::exit(1); } }
#endif
#else
#define PYRO_ASSERT(x, message) 
#define PYRO_REVERSE_ASSERT(x, message) 
#endif