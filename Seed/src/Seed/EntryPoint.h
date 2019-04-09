#pragma once

#ifdef SEED_PLATFORM_WINDOWS

extern Seed::Application* Seed::CreateApplication();

int main(int argc, char** argv)
{
	Seed::InitializeCore();
	auto app = Seed::CreateApplication();
	app->Run();
	delete app;
	Seed::ShutdownCore();
}

#endif