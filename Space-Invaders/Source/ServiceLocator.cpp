#include"../Header/ServiceLocator.h"
#include"../Header/GraphicsServices.h"

ServiceLocator::ServiceLocator()
{
	graphics_service = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

void ServiceLocator::createServices()
{
	graphics_service = new GraphicsService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphics_service);
	graphics_service = nullptr;
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::initialize()
{
	graphics_service -> initialize();
}

void ServiceLocator::update()
{
	graphics_service->update();
}

void ServiceLocator::render()
{
	graphics_service->render();
}

GraphicsService* ServiceLocator::getGraphicsService()
{
	return graphics_service;
}