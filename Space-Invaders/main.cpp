#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class player
{
    int health = 3, playerScore = 0;

    Vector2f position = Vector2f(400.0f, 500.0f); 
    
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

    void takeDamage() 
    {
        cout << "player takes damage\n";
    }
    void move()
    {
        cout << "player moves\n";
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


    cout << speed << "\n";

    cout << "position:" << pos.x << "," << pos.y << "\n";

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear(sf::Color::Blue);

        window.display();
    }
    return 0;
}