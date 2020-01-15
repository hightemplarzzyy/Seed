#pragma once

#include "Seed/Renderer/RendererAPI.h"

namespace Seed {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void Shutdown() override;

		virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		virtual void Clear(float r, float g, float b, float a) override;
		virtual void SetClearColor(float r, float g, float b, float a) override;

		virtual void DrawIndexed(uint32_t count, bool depthTest = true) override;

		virtual void LoadRequiredAssets() override;
	};
}