#pragma once
#include "../Header/GraphicsServices.h"
#include"../Header/EventService.h"

class ServiceLocator
{
private:
    GraphicsService* graphics_service;
    EventService* event_service;

    ServiceLocator();

    ~ServiceLocator();

    void createServices();
    void clearAllServices();

public:
    static ServiceLocator* getInstance();

    void initialize();
    void update(); 
    void render();

    GraphicsService* getGraphicsService();
    EventService* getEventService();
};