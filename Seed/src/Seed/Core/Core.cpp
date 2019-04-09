#include "Seedpch.h"
#include "Core.h"

#define SEED_BUILD_VERSION "v0.1"

namespace Seed {

	void InitializeCore()
	{
		Seed::Log::Init();

		SEED_CORE_TRACE("Seed Engine {}", SEED_BUILD_VERSION);
		SEED_CORE_TRACE("Initializing Core...");
	}

	void ShutdownCore()
	{
		SEED_CORE_TRACE("Shutting down...");
	}

}