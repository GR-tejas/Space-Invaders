#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class PlayerService
{
private:
    int health = 3, playerScore = 0;

    Vector2f position = Vector2f(350.0f, 500.0f);

    float moveSpeed = 5;

    const sf::String player_texture_path = "assets/textures/player_ship.png";

    Texture playerTexture;

    Sprite playerSprite;

    RenderWindow* game_window;

    void initializePlayerSprite();

    void processPlayerInput();

public:
    PlayerService();
    ~PlayerService();

    void initialize();
    void update();
    void render();

    void move(float offsetX);
    int getMoveSpeed();
    Vector2f getPosition();
};
