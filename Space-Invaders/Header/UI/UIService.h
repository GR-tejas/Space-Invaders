#pragma once
#include "../../Header/UI/MainMenu/MainMenuUIContoller.h"
#include"../../Header/UI/Interface/IUIController.h"

namespace UI
{
	using namespace UI::MainMenu;
	using namespace Interface;
	class UIService
	{
	private:
		MainMenuUIController* main_menu_controller;


		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
		/*void show();*/
		IUIController* getCurrentUIController();
	};
}
