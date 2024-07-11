#pragma once
#include "../Header/GraphicsServices.h"
class ServiceLocator
{
private:
    GraphicsService *graphics_service;

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
};