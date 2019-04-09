#pragma once

#ifdef SEED_PLATFORM_WINDOWS
#ifdef SEED_DYNAMIC_LINK
	#ifdef SEED_BUILD_DLL
		#define SEED_API __declspec(dllexport)
	#else
		#define SEED_API __declspec(dllimport)
	#endif
#else
	#define SEED_API 
#endif
#else
	#error Seed Only Support Windows Now!
#endif

#ifdef SEED_DEBUG
	#define SEED_ENABLE_ASSERTS
#endif

#ifdef SEED_ENABLE_ASSERTS
	#define SEED_ASSERT(x, ...) { if(!(x)) { SEED_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SEED_CORE_ASSERT(x, ...) { if(!(x)) { SEED_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SEED_ASSERT(x, ...)
	#define SEED_CORE_ASSERT(x, ...)
#endif

#define BIT(x) 1<<x

#define SEED_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Seed {

	void InitializeCore();
	void ShutdownCore();

}