workspace "PyroEngine"
	architecture "x86_64"
	startproject "PyroEditor"

	configurations
	{
		"Debug",
		"Release"
	}

	group "Dependencies"
		project "GLFW"
		project "Glad"
	group ""

project "PyroEngine"
	location "PyroEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++latest"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

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
		"Dependencies/GLFW/include",
		"Dependencies/Glad/include"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	links
	{
		"GLFW",
		"Glad"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PYRO_PLATFORM_WINDOWS"
		}

		links
		{
			"opengl32.lib"
		}

	filter "system:linux"
		pic "On"
		systemversion "latest"

		defines
		{
			"PYRO_PLATFORM_LINUX"
		}

		links
		{
			"GL"
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
	language "C++"
	cppdialect "C++latest"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

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

	postbuildcommands
	{
		"{MKDIR} %[Bin/%{cfg.buildcfg}-%{cfg.system}/FinalBuild]",
		"{COPYFILE} %[Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}/%{cfg.buildtarget.name}] %[Bin/%{cfg.buildcfg}-%{cfg.system}/FinalBuild/PyroEngine%{cfg.buildtarget.extension}]"
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

		links
		{
			"GLFW",
			"Glad",
			"GL",
			"X11",
			"Xrandr",
			"Xi",
			"Xinerama",
			"Xcursor"
		}

	filter "configurations:Debug"
		kind "ConsoleApp"
		defines "PYRO_CONFIG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		kind "WindowedApp"
		defines "PYRO_CONFIG_RELEASE"
		runtime "Release"
		optimize "On"

project "GLFW"
	location "Dependencies/GLFW"
	kind "StaticLib"
	language "C"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

	files
	{
		"Dependencies/%{prj.name}/include/GLFW/glfw3.h",
		"Dependencies/%{prj.name}/include/GLFW/glfw3native.h",
		"Dependencies/%{prj.name}/src/glfw_config.h",
		"Dependencies/%{prj.name}/src/context.c",
		"Dependencies/%{prj.name}/src/init.c",
		"Dependencies/%{prj.name}/src/input.c",
		"Dependencies/%{prj.name}/src/monitor.c",
		"Dependencies/%{prj.name}/src/vulkan.c",
		"Dependencies/%{prj.name}/src/window.c"
	}

	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"

		files
		{
			"Dependencies/%{prj.name}/src/x11_init.c",
			"Dependencies/%{prj.name}/src/x11_monitor.c",
			"Dependencies/%{prj.name}/src/x11_window.c",
			"Dependencies/%{prj.name}/src/xkb_unicode.c",
			"Dependencies/%{prj.name}/src/posix_time.c",
			"Dependencies/%{prj.name}/src/posix_thread.c",
			"Dependencies/%{prj.name}/src/glx_context.c",
			"Dependencies/%{prj.name}/src/egl_context.c",
			"Dependencies/%{prj.name}/src/osmesa_context.c",
			"Dependencies/%{prj.name}/src/linux_joystick.c"
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
			"Dependencies/%{prj.name}/src/win32_init.c",
			"Dependencies/%{prj.name}/src/win32_joystick.c",
			"Dependencies/%{prj.name}/src/win32_monitor.c",
			"Dependencies/%{prj.name}/src/win32_time.c",
			"Dependencies/%{prj.name}/src/win32_thread.c",
			"Dependencies/%{prj.name}/src/win32_window.c",
			"Dependencies/%{prj.name}/src/wgl_context.c",
			"Dependencies/%{prj.name}/src/egl_context.c",
			"Dependencies/%{prj.name}/src/osmesa_context.c"
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

project "Glad"
	location "Dependencies/Glad"
	kind "StaticLib"
	language "C"
	staticruntime "On"

	targetdir ("Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
	objdir ("Bin-Int/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

	files
	{
		"Dependencies/%{prj.name}/include/glad/glad.h",
		"Dependencies/%{prj.name}/include/KHR/khrplatform.h",
		"Dependencies/%{prj.name}/src/glad.c"
	}

	includedirs
	{
		"Dependencies/%{prj.name}/include"
	}

	filter "system:windows"
		systemversion "latest"

	filter "system:linux"
		pic "On"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"