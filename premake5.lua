workspace "PyroEngine"
	architecture "x86_64"
	startproject "PyroEditor"

	configurations
	{
		"Debug",
		"Release"
	}

project "PyroEngine"
	location "PyroEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")

	pchheader "PyroEnginePCH.h"
	pchsource "PyroEngine/src/PyroEnginePCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"GLFW-3.3.9/include"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	links
	{
		"GLFW-3.3.9",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PYRO_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		pic "On"
		systemversion "latest"

		defines
		{
			"PYRO_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "PYRO_CONFIG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PYRO_CONFIG_RELEASE"
		runtime "Release"
		optimize "On"

project "PyroEditor"
	location "PyroEditor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"PyroEngine/src"
	}

	links
	{
		"PyroEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PYRO_PLATFORM_WINDOWS"
		}

	filter "system:linux"
		pic "On"
		systemversion "latest"

		defines
		{
			"PYRO_PLATFORM_LINUX"
		}

	filter "configurations:Debug"
		defines "PYRO_CONFIG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PYRO_CONFIG_RELEASE"
		runtime "Release"
		optimize "On"

project "GLFW-3.3.9"
	location "GLFW-3.3.9"
	kind "StaticLib"
	language "C"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}/%{prj.name}")

	files
	{
		"%{prj.name}/include/GLFW/glfw3.h",
		"%{prj.name}/include/GLFW/glfw3native.h",
		"%{prj.name}/src/glfw_config.h",
		"%{prj.name}/src/context.c",
		"%{prj.name}/src/init.c",
		"%{prj.name}/src/input.c",
		"%{prj.name}/src/monitor.c",
		"%{prj.name}/src/vulkan.c",
		"%{prj.name}/src/window.c"
	}

	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"

		files
		{
			"%{prj.name}/src/x11_init.c",
			"%{prj.name}/src/x11_monitor.c",
			"%{prj.name}/src/x11_window.c",
			"%{prj.name}/src/xkb_unicode.c",
			"%{prj.name}/src/posix_time.c",
			"%{prj.name}/src/posix_thread.c",
			"%{prj.name}/src/glx_context.c",
			"%{prj.name}/src/egl_context.c",
			"%{prj.name}/src/osmesa_context.c",
			"%{prj.name}/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11"
		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files
		{
			"%{prj.name}/src/win32_init.c",
			"%{prj.name}/src/win32_joystick.c",
			"%{prj.name}/src/win32_monitor.c",
			"%{prj.name}/src/win32_time.c",
			"%{prj.name}/src/win32_thread.c",
			"%{prj.name}/src/win32_window.c",
			"%{prj.name}/src/wgl_context.c",
			"%{prj.name}/src/egl_context.c",
			"%{prj.name}/src/osmesa_context.c"
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"