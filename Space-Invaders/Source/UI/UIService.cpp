#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameServices.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;

	UIService::UIService()
	{
		main_menu_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->update();
		/*switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->update();;
			break;
		}*/
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->render();
		/*switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->render();
			break;
		}*/
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) ui_controller->show();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller;

		default:
			return nullptr;
		}
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	void UIService::destroy()
	{
		delete(main_menu_controller);
	}
}