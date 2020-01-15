#pragma once

#include "Seed/Core/Core.h"

namespace Seed {

	using RendererID = uint32_t;

	enum class RendererAPIType
	{
		None,
		OpenGL,
		DX11
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
		static RendererAPI* Create();
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		virtual void Clear(float r, float g, float b, float a) = 0;
		virtual void SetClearColor(float r, float g, float b, float a) = 0;

		virtual void DrawIndexed(uint32_t count, bool depthTest = true) = 0;

		virtual void LoadRequiredAssets() = 0;

		static RendererAPICapabilities& GetCapabilities() { static RendererAPICapabilities Capabiilities; return Capabiilities; };
		static RendererAPIType& Current()
		{
			static RendererAPIType s_API;
			return s_API;
		}

	};
}