#pragma once
#include"../../Header/Graphic/GraphicsServices.h"
#include"../../Header/Event/EventService.h"
#include"../../Header/Player/PlayerService.h"
#include"../../Header/Time/TimeService.h"
#include"../../Header/UI/UIService.h"
#include"../../Header/Enemy/EnemyService.h"
#include"../../header/Gameplay/GameplayService.h"
#include"../../Header/Element/ElementService.h"
#include"../../Header/Sound/SoundService.h"
#include"../../Header/Bullet/BulletService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        GraphicsService* graphics_service;
        EventService* event_service;
        PlayerService* player_service;
        TimeService* time_service;
        UIService* ui_service;
        EnemyService* enemy_service;
        GameplayService* gameplay_service;
        ElementService* element_service;
        SoundService* sound_service;
        BulletService* bullet_service;
        

        ServiceLocator();

        ~ServiceLocator();

        void deleteServiceLocator();
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
        UIService* getUIService();
        EnemyService* getEnemyService();
        GameplayService* getGameplayService();
        ElementService* getElementService();
        SoundService* getSoundService();
        BulletService* getBulletService();

    };
}