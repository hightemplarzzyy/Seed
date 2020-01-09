#pragma once

#include <memory>

#ifndef SEED_PLATFORM_WINDOWS
	#error Seed Only Support Windows Now!
#endif

// __VA_ARGS__ expansion to get past MSVC "bug"
#define SEED_EXPAND_VARGS(x) x

#define BIT(x) (1 << x)

#define SEED_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)

#include "Assert.h"

namespace Seed {

	void InitializeCore();
	void ShutdownCore();

	// Pointer Wrappers
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	using byte = unsigned char;

}