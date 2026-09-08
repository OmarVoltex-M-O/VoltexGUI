workspace "VoltexGUI_Framework"
	architecture "x64"
	configurations { "Debug", "Release", "DllDebug", "DllRelease" }

outDir = "/%{cfg.system}_%{cfg.buildcfg}_%{cfg.architecture}"

project "VoltexGUI"
	location "VoltexGUI"
	language "C++"
	cppdialect "C++23"

	targetdir("bin" .. outDir)
	objdir("bin-int" .. outDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Inc/VoltexGUI/**.h",
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/Src/",
		"%{prj.name}/Src/Common",
		"%{prj.name}/Src/Common/Inc",
		"%{prj.name}/Src/Common/HelperMacroes",
		"%{prj.name}/Src/Common/Colors",
		"%{prj.name}/Src/Common/Types",
		"%{prj.name}/Src/Common/Math",
		"%{prj.name}/Src/Common/NativeHandles",
		"%{prj.name}/Src/Core/",
		"%{prj.name}/Src/Core/Dll",
		"%{prj.name}/Src/Core/Dll/Inc",
		"%{prj.name}/Src/Core/Window",
		"%{prj.name}/Src/Core/Application",
		"%{prj.name}/Src/Core/Renderer",
		"%{prj.name}/Src/Core/RenderEngine",
		"%{prj.name}/Src/Core/Compositor",
		"%{prj.name}/Src/Core/Event",
		"%{prj.name}/Src/Core/Logger",
		"%{prj.name}/Src/Core/Visual",
		"%{prj.name}/Src/PAL/WindowSystem",
		"%{prj.name}/Src/PAL/ApplicationSystem",
		"%{prj.name}/Src/PAL/RenderingSystem",
	}

	filter"configurations:Debug"
		defines { "VX_DEBUG" }
		symbols "On"
		optimize "Debug"
		kind "StaticLib"
	
	filter"configurations:Release"
		defines { "VX_NDEBUG" }
		symbols "Off"
		optimize "Speed"
		kind "StaticLib"
	
	filter"configurations:DllDebug"
		defines { "VX_DEBUG", "VX_BUILD_DLL", "VX_EXPORT_DLL" }
		symbols "On"
		optimize "Debug"
		kind "SharedLib"
	
	filter"configurations:DllRelease"
		defines { "VX_NDEBUG", "VX_BUILD_DLL", "VX_EXPORT_DLL" }
		symbols "Off"
		optimize "Speed"
		kind "SharedLib"

	filter "system:Windows"
		defines { "VX_OS_WINDOWS" }
		systemversion "latest"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++23"

	files
	{
		"%{prj.name}/Src/**.h",
		"%{prj.name}/Src/**.cpp",
	}

	includedirs
	{
		"VoltexGUI/Inc/VoltexGUI",
		"VoltexGUI/Src",
		"VoltexGUI/Src/Common",
		"VoltexGUI/Src/Common/Inc",
		"VoltexGUI/Src/Common/HelperMacroes",
		"VoltexGUI/Src/Common/Colors",
		"VoltexGUI/Src/Common/Types",
		"VoltexGUI/Src/Common/Math",
		"VoltexGUI/Src/Common/NativeHandles",
		"VoltexGUI/Src/Core",
		"VoltexGUI/Src/Core/Dll",
		"VoltexGUI/Src/Core/Dll/Inc",
		"VoltexGUI/Src/Core/Window",
		"VoltexGUI/Src/Core/Application",
		"VoltexGUI/Src/Core/Renderer",
		"VoltexGUI/Src/Core/RenderEngine",
		"VoltexGUI/Src/Core/Compositor",
		"VoltexGUI/Src/Core/Event",
		"VoltexGUI/Src/Core/Logger",
		"VoltexGUI/Src/Core/Visual",
		"VoltexGUI/Src/PAL/WindowSystem",
		"VoltexGUI/Src/PAL/ApplicationSystem",
		"VoltexGUI/Src/PAL/RenderingSystem",
	}

	filter"configurations:Debug"
		defines { "VX_DEBUG" }
		symbols "On"
		optimize "Debug"
		links { "VoltexGUI" }
	
	filter"configurations:Release"
		defines { "VX_NDEBUG" }
		symbols "Off"
		optimize "Speed"
		links { "VoltexGUI" }
	
	filter"configurations:DllDebug"
		defines { "VX_DEBUG", "VX_BUILD_DLL" }
		symbols "On"
		optimize "Debug"
		links { "VoltexGUI" }
	
	filter"configurations:DllRelease"
		defines { "VX_NDEBUG", "VX_BUILD_DLL" }
		symbols "Off"
		optimize "Speed"
		links { "VoltexGUI" }

	filter "system:Windows"
		defines { "VX_OS_WINDOWS" }
		systemversion "latest"