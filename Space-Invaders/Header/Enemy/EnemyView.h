#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    class EnemyView
    {
    private:

        const sf::String Enemy_texture_path = "assets/textures/enemy_ship.png";
        const float Enemy_sprite_width = 60.f;
        const float Enemy_sprite_height = 60.f;

        sf::RenderWindow* game_window;

        sf::Texture Enemy_texture;
        sf::Sprite Enemy_sprite;

        void initializeEnemySprite();
        void scaleEnemySprite();

        EnemyController* enemy_controller;

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController* controller);

        void initialize();
        void update();
        void render();
    };
}