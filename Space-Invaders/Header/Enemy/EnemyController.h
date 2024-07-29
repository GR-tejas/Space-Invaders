#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;
    enum class EnemyType;
    enum class EnemyState;

    class EnemyController
    {
    protected:
        
        float vertical_movement_speed = 30.f;
        float horizontal_movement_speed = 200.0f;

        float rate_of_fire = 3.f;
        float elapsed_fire_duration = 0.f;

        void updateFireTimer();
        void processBulletFire();
        virtual void fireBullet() = 0;

        sf::Vector2f getRandomInitialPosition();
        void handleOutOfBounds();

        void virtual move() = 0;
        
    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        void virtual initialize();
        void update();
        void render();

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        sf::Vector2f getEnemyPosition();
        EnemyType getEnemyType();
        EnemyState getEnemyState();
    };
}