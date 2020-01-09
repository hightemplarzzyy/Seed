#pragma once

#ifdef SEED_DEBUG
	#define SEED_ENABLE_ASSERTS
#endif

#ifdef SEED_ENABLE_ASSERTS
	#define SEED_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { SEED_ERROR("Assertion Failed!"); __debugbreak(); } }
	#define SEED_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { SEED_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

	#define SEED_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro
	#define SEED_GET_ASSERT_MACRO(...) SEED_EXPAND_VARGS(SEED_ASSERT_RESOLVE(__VA_ARGS__, SEED_ASSERT_MESSAGE, SEED_ASSERT_NO_MESSAGE))

	#define SEED_ASSERT(...) SEED_EXPAND_VARGS(SEED_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__))
	#define SEED_CORE_ASSERT(...) SEED_EXPAND_VARGS(SEED_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__))
#else
	#define SEED_ASSERT(...)
	#define SEED_CORE_ASSERT(...)
#endif