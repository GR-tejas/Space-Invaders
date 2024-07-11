#include "../Header/GameServices.h"
#include"../Header/GraphicsServices.h"

GameService::GameService()
{
	service_locator = nullptr;
	game_window = nullptr;
}

GameService::~GameService()
{
	destroy();
}

void GameService::start()
{
	service_locator = ServiceLocator::getInstance();
	initialize();
}

void GameService::initialize()
{
	service_locator->initialize();
	initializeVariables();
}

void GameService::initializeVariables()
{
	game_window = service_locator->getGraphicsService()->getGameWindow();
}

void GameService::destroy()
{
	
}

void GameService::update()
{
	service_locator->getEventService()->processEvents();

	service_locator->update();
}

void GameService::render()
{
	game_window->clear(service_locator->getGraphicsService()->getWindowColor());
	service_locator->render();
	game_window->display();
}
bool GameService::isRunning()
{
	return service_locator->getGraphicsService()->isGameWindowOpen();
}