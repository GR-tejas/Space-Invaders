#include"../Header/ServiceLocator.h"
#include"../Header/GraphicsServices.h"

ServiceLocator::ServiceLocator()
{
	graphics_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

void ServiceLocator::createServices()
{
	graphics_service = new GraphicsService();
	event_service = new EventService();
	player_service = new PlayerService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphics_service);
	delete(event_service);
	delete(player_service);
	graphics_service = nullptr;
	event_service = nullptr;
	player_service = nullptr;
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{
	graphics_service -> initialize();
	event_service->initialize();
	player_service->initialize();

}

void ServiceLocator::update()
{
	graphics_service->update();
	event_service->update();
	player_service->update();
}

void ServiceLocator::render()
{
	graphics_service->render();
	player_service->render();
}

GraphicsService* ServiceLocator::getGraphicsService()
{
	return graphics_service;
}

EventService* ServiceLocator::getEventService()
{
	return event_service;
}

PlayerService* ServiceLocator::getPlayerService()
{
	return player_service;
}