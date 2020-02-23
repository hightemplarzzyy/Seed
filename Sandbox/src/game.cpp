#include <Seed.h>

#include "Seed/EntryPoint.h"
#include "EditorLayer.h"

class SeedApplication : public Seed::Application
{
public:
	SeedApplication(const Seed::ApplicationProps props)
		:Application(props)
	{
	}

	virtual void OnInit() override
	{
		PushLayer(new Seed::EditorLayer());
	}
};

Seed::Application* Seed::CreateApplication()
{
	return new SeedApplication({ "Seed Editor", 1600, 900, "OpenGL"});
}