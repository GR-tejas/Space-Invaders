#pragma once
#include "../Header/GraphicsServices.h"
#include"../Header/EventService.h"
#include"../Header/PlayerService.h"
#include"../Header/TimeService.h"

class ServiceLocator
{
private:
    GraphicsService* graphics_service;
    EventService* event_service;
    PlayerService* player_service;
    TimeService* time_service;

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
    PlayerService* getPlayerService();
    TimeService* getTimeService();
};