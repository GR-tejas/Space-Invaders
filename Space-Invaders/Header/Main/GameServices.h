#pragma once
#include "../../Header/Global/ServiceLocator.h"
using namespace sf;

namespace Main
{
	using namespace Global;
	class GameService
	{
	private:
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
	};
}