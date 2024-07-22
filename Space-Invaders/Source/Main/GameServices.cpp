#include"../../Header/Main/GameServices.h"
#include"../../Header/Graphic/GraphicsServices.h"
#include"../../Header/Global/ServiceLocator.h"

namespace Main
{
	using namespace Global;
	class ServiceLocator;
	GameState GameService::current_state = GameState::BOOT;

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
		showMainMenu();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicsService()->getGameWindow();
	}

	void GameService::destroy()
	{

	}

	void GameService::showMainMenu()
	{
		setGameState(GameState::MAIN_MENU);
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
	void GameService::setGameState(GameState new_state) 
	{
		current_state = new_state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}
}