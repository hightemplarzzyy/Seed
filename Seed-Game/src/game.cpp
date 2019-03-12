#include <Seed.h>

class ExampleLayer :public Seed::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}
};

class Game : public Seed::Application 
{
public:
	Game()
	{
		PushLayer(new ExampleLayer());
	}

	~Game()
	{

	}
};

Seed::Application* Seed::CreateApplication()
{
	return new Game;
}