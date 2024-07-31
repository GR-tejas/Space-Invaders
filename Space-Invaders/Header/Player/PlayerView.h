#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Player/PlayerController.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Player
{
    class PlayerView
    {
    private:

        const sf::String player_texture_path = "assets/textures/player_ship.png";
        const float player_sprite_width = 100.f;
        const float player_sprite_height = 100.f;

        sf::RenderWindow* game_window;

        sf::Texture player_texture;
        sf::Sprite player_sprite;

        UI::UIElement::ImageView* player_image;

        void initializePlayerSprite();
        void scalePlayerSprite();

        PlayerController* player_controller;

    public:
        PlayerView();
        ~PlayerView();
                
        void initialize(PlayerController* controller);
        void update();
        void render();

        const sf::Sprite& getPlayerSprite();

        void createUIElements();
        void initializeImage();

        void destroy();
    };
}