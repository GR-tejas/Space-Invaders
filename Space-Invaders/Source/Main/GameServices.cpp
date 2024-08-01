#include "../../header/Main/GameServices.h"
#include "../../header/Graphic/GraphicsServices.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"

namespace Main
{
	using namespace Global;
	using namespace Graphics;
	using namespace Event;
	using namespace UI;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		service_locator = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::start()
	{
		service_locator = Global::ServiceLocator::getInstance();
		initialize();
	}

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showSplashScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicsService()->getGameWindow();
	}

	void GameService::destroy()
	{
		service_locator->deleteServiceLocator();
	}

	void GameService::showSplashScreen()
	{
		setGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::getInstance()->getUIService()->showScreen();
	}

	void GameService::update()
	{
		service_locator->getEventService()->processEvents();

		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear(); 
		service_locator->render();
		game_window->display();
	}
	bool GameService::isRunning()
	{
		return service_locator->getGraphicsService()->isGameWindowOpen();
	}
	void GameService::setGameState(GameState new_state) 
	{
		current_state = new_state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}
}