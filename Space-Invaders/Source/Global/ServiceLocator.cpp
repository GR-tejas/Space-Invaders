#include"../../Header/Global/ServiceLocator.h"
#include"../../Header/Graphic/GraphicsServices.h"

namespace Global
{
	ServiceLocator::ServiceLocator()
	{
		graphics_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
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
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphics_service);
		delete(event_service);
		delete(player_service);
		delete(time_service);
		delete(ui_service);
		graphics_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
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
	}

	void ServiceLocator::update()
	{
		graphics_service->update();
		event_service->update();
		player_service->update();
		time_service->update();
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphics_service->render();
		player_service->render();
		ui_service->render();
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
}