#pragma once
#include "../../Header/Global/ServiceLocator.h"
using namespace sf;

namespace Main
{
	enum class GameState 
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};
	using namespace Global;
	class GameService
	{
	private:
		void showMainMenu();
		static GameState current_state;

		Global::ServiceLocator* service_locator;
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

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};
}