#pragma once
#include "../Header/ServiceLocator.h"
using namespace sf;

class GameService
{
private:
	ServiceLocator* service_locator;
	RenderWindow* game_window;

	void initialize();
	void initializeVariables();
	void destroy();

public:
	GameService();
	~GameService();

	void start();
	void update();
	void render();
	bool isRunning();
};