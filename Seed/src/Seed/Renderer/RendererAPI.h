#pragma once

#include "Seed/Core/Core.h"

namespace Seed {

	using RendererID = unsigned int;

	enum class SEED_API RendererAPIType
	{
		None,
		OpenGL
	};

	class SEED_API RendererAPI
	{
	private:

	public:
		static void Init();
		static void Shutdown();

		static void Clear(float r, float g, float b, float a);
		static void SetClearColor(float r, float g, float b, float a);

		static void DrawIndexed(unsigned int count);

		static RendererAPIType Current() { return s_CurrentRendererAPI; }
	private:
		static RendererAPIType s_CurrentRendererAPI;
	};
}