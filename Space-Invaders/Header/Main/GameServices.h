#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

class ServiceLocator;
namespace Main
{
	enum class GameState 
	{
		BOOT,
		SPLASH_SCREEN,
		INSTRUCTIONS,
		MAIN_MENU,
		GAMEPLAY,
		CREDITS,
	};
	class GameService
	{
	private:
		static GameState current_state;

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void showSplashScreen();
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