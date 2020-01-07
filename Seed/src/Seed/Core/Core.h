#pragma once

#include <memory>

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
	#define SEED_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { SEED_ERROR("Assertion Failed!"); __debugbreak(); } }
	#define SEED_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { SEED_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define SEED_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro

	#define SEED_ASSERT(...) SEED_ASSERT_RESOLVE(__VA_ARGS__, SEED_ASSERT_MESSAGE, SEED_ASSERT_NO_MESSAGE)(__VA_ARGS__)
	#define SEED_CORE_ASSERT(...) SEED_ASSERT_RESOLVE(__VA_ARGS__, SEED_ASSERT_MESSAGE, SEED_ASSERT_NO_MESSAGE)(__VA_ARGS__)
#else
	#define SEED_ASSERT(...)
	#define SEED_CORE_ASSERT(...)
#endif

#define BIT(x) 1<<x

#define SEED_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Seed {

	void InitializeCore();
	void ShutdownCore();

	// Pointer Wrappers
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	using byte = unsigned char;

}