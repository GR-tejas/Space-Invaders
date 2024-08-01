#pragma once
#include "../../Header/Global/ServiceLocator.h"

class ServiceLocator;
namespace Main
{
	enum class GameState 
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};
	class GameService
	{
	private:
		void showMainMenu();
		static GameState current_state;

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

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

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}