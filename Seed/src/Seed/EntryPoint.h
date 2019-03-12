#pragma once

#ifdef SEED_PLATFORM_WINDOWS

extern Seed::Application* Seed::CreateApplication();

int main(int argc, char** argv)
{
	Seed::Log::Init();
	SEED_CORE_WARN("Initialized Log!");
	int a = 5;
	SEED_INFO("Game Log Test! Var={0}", a);
	auto app = Seed::CreateApplication();
	app->Run();
	delete app;
}

#endif