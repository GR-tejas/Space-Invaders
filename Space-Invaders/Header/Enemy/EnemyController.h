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
        
        sf::Vector2f getRandomInitialPosition();
        void handleOutOfBounds();

        void virtual move() = 0;
        /*void moveLeft();
        void moveRight();
        void moveDown();*/

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
        EnemyState getEnemyState();
    };
}