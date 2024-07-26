#pragma once
#include"../../Header/Graphic/GraphicsServices.h"
#include"../../Header/Event/EventService.h"
#include"../../Header/Player/PlayerService.h"
#include"../../Header/Time/TimeService.h"
#include"../../Header/UI/UIService.h"
#include"../../Header/Enemy/EnemyService.h"
#include"../../header/Gameplay/GameplayService.h"
#include"../../Header/Element/ElementService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Graphic::GraphicsService* graphics_service;
        EventSpace::EventService* event_service;
        Player::PlayerService* player_service;
        TimeSpace::TimeService* time_service;
        UI::UIService* ui_service;
        Enemy::EnemyService* enemy_service;
        Gameplay::GameplayService* gameplay_service;
        Element::ElementService* element_service;

        ServiceLocator();

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphic::GraphicsService* getGraphicsService();
        EventSpace::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        TimeSpace::TimeService* getTimeService();
        UI::UIService* getUIService();
        Enemy::EnemyService* getEnemyService();
        Gameplay::GameplayService* getGameplayService();
        Element::ElementService* getElementService();
    };
}