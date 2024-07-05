#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class player
{
    int health = 3, playerScore = 0;

    Vector2f position = Vector2f(350.0f, 500.0f); 
    
    float moveSpeed = 5;

public:

    Texture playerTexture;

    Sprite playerSprite;

    void setScore(int newScore)
    {
        playerScore += newScore;
    }

    int getHealth()
    {
        return health;
    }

    int getMoveSpeed()
    {
        return moveSpeed;
    }

    int getPlayerScore()
    {
        return playerScore;
    }

    Vector2f getPlayerPosition()
    {
        return position;
    }

    /*void setPlayerPostion(Vector2f newPos)
    {
        position = newPos;
    }*/

    void takeDamage() 
    {
        cout << "player takes damage\n";
    }
    void move(float offsetX)
    {
        position.x += offsetX;
        cout << "player moved";
    }
    void shootBullets()
    {
        cout << "player shoots bullets\n";
    }
};

int main()
{

    VideoMode videoMode = sf::VideoMode(800, 600);

    RenderWindow window(videoMode, "Player 1");
            
    player player;

    int speed = player.getMoveSpeed();

    Vector2f pos = player.getPlayerPosition();

    player.playerTexture.loadFromFile("assets/textures/player_ship.png");

    player.playerSprite.setTexture(player.playerTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                player.move(-1.0f * player.getMoveSpeed());
                cout << " left\n";
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                player.move(1.0f * player.getMoveSpeed());
                cout << " Right\n";
            }
        }


        window.clear(sf::Color::Blue);

        player.playerSprite.setPosition(player.getPlayerPosition());

        window.draw(player.playerSprite);

        window.display();
    }
    return 0;
}