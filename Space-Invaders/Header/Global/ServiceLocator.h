#pragma once
#include "../../Header/Graphic/GraphicsServices.h"
#include"../../Header/Event/EventService.h"
#include"../../Header/Player/PlayerService.h"
#include"../../Header/Time/TimeService.h"

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