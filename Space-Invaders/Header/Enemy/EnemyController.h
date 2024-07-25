#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;
    enum class EnemyType;

    class EnemyController
    {
    private:
        
        void virtual move();
        void moveLeft();
        void moveRight();
        void moveDown();

    public:
        EnemyController();
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        void virtual initialize();
        void update();
        void render();

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        sf::Vector2f getEnemyPosition();
        EnemyType getEnemyType();
    };
}