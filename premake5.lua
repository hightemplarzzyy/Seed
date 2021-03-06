workspace "Seed"
	architecture "x86_64"
	targetdir "build"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Seed/vendor/GLFW/include"
IncludeDir["Glad"] = "Seed/vendor/Glad/include"
IncludeDir["ImGui"] = "Seed/vendor/imgui"
IncludeDir["glm"] = "Seed/vendor/glm"

include "Seed/vendor/GLFW"
include "Seed/vendor/Glad"
include "Seed/vendor/imgui"

project "Seed"
	location "Seed"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Seedpch.h"
	pchsource "Seed/src/Seedpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{prj.name}/vendor/assimp/include",
		"%{prj.name}/vendor/stb/include"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SEED_PLATFORM_WINDOWS",
			"SEED_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
	
	filter "configurations:Debug"
		defines "SEED_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SEED_RELEASE"
		runtime "Debug"
		optimize "on"

	filter "configurations:Dist"
		defines "SEED_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	links
	{
		"Seed"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"Seed/src",
		"Seed/vendor",
		"Seed/vendor/spdlog/include",
		"%{IncludeDir.glm}"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SEED_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "SEED_DEBUG"
		runtime "Debug"
		symbols "on"

		links
		{
			"Seed/vendor/assimp/bin/Debug/assimp-vc141-mtd.lib"
		}

		postbuildcommands
		{
			'{COPY} "../Seed/vendor/assimp/bin/Debug/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
		}

	filter "configurations:Release"
		defines "SEED_RELEASE"
		runtime "Debug"
		optimize "on"

		links
		{
			"Seed/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
		}
		
		postbuildcommands
		{
			'{COPY} "../Seed/vendor/assimp/bin/Release/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
		}

	filter "configurations:Dist"
		defines "SEED_DIST"
		runtime "Release"
		optimize "on"

		links
		{
			"Seed/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
		}

		postbuildcommands
		{
			'{COPY} "../Seed/vendor/assimp/bin/Release/assimp-vc141-mtd.dll" "%{cfg.targetdir}"'
		}
