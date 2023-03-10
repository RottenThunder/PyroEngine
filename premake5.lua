workspace "PyroEngine"
	architecture "x86_64"
	startproject "Sandbox"

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
		"Dependencies/GLFW/include"
	}

	links
	{
		"Dependencies/GLFW/lib/glfw3_mt.lib",
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

project "Sandbox"
	location "Sandbox"
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
		"PyroEngine/src",
		"Dependencies/GLFW/include"
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
