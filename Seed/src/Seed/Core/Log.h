#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Seed
{
	class SEED_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define SEED_CORE_TRACE(...)	Seed::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SEED_CORE_INFO(...)		Seed::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SEED_CORE_WARN(...)		Seed::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SEED_CORE_ERROR(...)	Seed::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SEED_CORE_FATAL(...)	Seed::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros
#define SEED_TRACE(...)		Seed::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SEED_INFO(...)		Seed::Log::GetClientLogger()->info(__VA_ARGS__)
#define SEED_WARN(...)		Seed::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SEED_ERROR(...)		Seed::Log::GetClientLogger()->error(__VA_ARGS__)
#define SEED_FATAL(...)		Seed::Log::GetClientLogger()->critical(__VA_ARGS__)