#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
    private:
        EnemyView* enemy_view;
        EnemyModel* enemy_model;   

        void virtual move();
        void moveLeft();
        void moveRight();
        void moveDown();

    public:
        EnemyController();
        virtual ~EnemyController();

        void virtual initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
    };
}