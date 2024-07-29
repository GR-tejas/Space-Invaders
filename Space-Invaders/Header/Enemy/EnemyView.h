#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    class EnemyController;
    enum class EnemyType;
    class EnemyView
    {
    private:

        const sf::String subzero_texture_path = "assets/textures/subzero.png";
        const sf::String zapper_texture_path = "assets/textures/zapper.png";
        const sf::String ufo_texture_path = "assets/textures/ufo.png";

        const float Enemy_sprite_width = 60.f;
        const float Enemy_sprite_height = 60.f;

        EnemyController* enemy_controller;

        sf::RenderWindow* game_window;

        sf::Texture Enemy_texture;
        sf::Sprite Enemy_sprite;

        void initializeEnemySprite(EnemyType type);
        void scaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController* controller);

        void initialize();
        void update();
        void render();
    };
}