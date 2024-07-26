#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Graphic/GraphicsServices.h"
#include"../../Header/Main/GameServices.h"

namespace Global
{
	ServiceLocator::ServiceLocator()
	{
		graphics_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphics_service = new Graphic::GraphicsService();
		event_service = new EventSpace::EventService();
		player_service = new Player::PlayerService();
		time_service = new TimeSpace::TimeService();
		ui_service = new UI::UIService();
		enemy_service = new Enemy::EnemyService();
		gameplay_service = new Gameplay::GameplayService();
		element_service = new Element::ElementService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphics_service);
		delete(event_service);
		delete(player_service);
		delete(time_service);
		delete(ui_service);
		delete(enemy_service);
		delete(gameplay_service);
		delete(element_service);
		graphics_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphics_service->initialize();
		event_service->initialize();
		player_service->initialize();
		time_service->initialize();
		ui_service->initialize();
		enemy_service->initialize();
		gameplay_service->initialize();
		element_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphics_service->update();
		event_service->update();
		time_service->update();
		ui_service->update();
		
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
		{
			player_service->update();
			enemy_service->update();
			gameplay_service->update();
			element_service->update();
		}
	}

	void ServiceLocator::render()
	{
		graphics_service->render();
		ui_service->render();

		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			element_service->render();
		}
	}

	Graphic::GraphicsService* ServiceLocator::getGraphicsService()
	{
		return graphics_service;
	}

	EventSpace::EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	Player::PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	TimeSpace::TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}
	UI::UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}
	Enemy::EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}
	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	Element::ElementService* ServiceLocator::getElementService()
	{
		return element_service;
	}
}