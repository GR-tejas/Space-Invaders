#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    //enum class Enemy;
    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
    private:
        /*EnemyView* player_view;
        EnemyModel* player_model;

        void moveLeft();
        void moveRight();*/

        EnemyView* enemy_view;
        EnemyModel* enemy_model;    

    public:
        EnemyController();
        ~EnemyController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
    };
}