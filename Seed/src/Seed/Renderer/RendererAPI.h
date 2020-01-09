#pragma once

#include "Seed/Core/Core.h"

namespace Seed {

	using RendererID = uint32_t;

	enum class RendererAPIType
	{
		None,
		OpenGL
	};

	struct RendererAPICapabilities
	{
		std::string Vendor;
		std::string Renderer;
		std::string Version;
		
		int MaxSamples;
		float MaxAnisotropy;
	};

	class RendererAPI
	{
	private:

	public:
		static void Init();
		static void Shutdown();

		static void Clear(float r, float g, float b, float a);
		static void SetClearColor(float r, float g, float b, float a);

		static void DrawIndexed(unsigned int count, bool depthTest = true);

		static RendererAPICapabilities& GetCapabilities() { static RendererAPICapabilities Capabiilities; return Capabiilities; };

		static RendererAPIType Current() { return s_CurrentRendererAPI; }

	private:
		static void LoadRequiredAssets();
	private:
		static RendererAPIType s_CurrentRendererAPI;
	};
}