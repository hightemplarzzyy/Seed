workspace "Seed"
	architecture "x64"
	startproject "Seed-Game"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

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
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Seedpch.h"
	pchsource "Seed/src/Seedpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SEED_PLATFORM_WINDOWS",
			"SEED_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Seed-Game")
		}
	
	filter "configurations:Debug"
		defines "SEED_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SEED_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SEED_DIST"
		runtime "Release"
		optimize "On"

project "Seed-Game"
	location "Seed-Game"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Seed/vendor/spdlog/include",
		"Seed/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Seed"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SEED_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "SEED_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SEED_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SEED_DIST"
		runtime "Release"
		optimize "On"