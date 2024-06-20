#include <SFML/Graphics.hpp>

int main()
{
    // Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    // Create a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, "Player 1");

    sf::CircleShape circle1(50);
    circle1.setFillColor(sf::Color::Green);
    circle1.setPosition(100, 200);

    sf::RectangleShape Square(sf::Vector2f(60, 60));
    Square.setFillColor(sf::Color::Red);
    Square.setPosition(600, 100);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(400, 100)); // Top point
    triangle.setPoint(1, sf::Vector2f(500, 500)); // Bottom-right point
    triangle.setPoint(2, sf::Vector2f(300, 500)); // Bottom-left point
    triangle.setFillColor(sf::Color::Blue);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Clear the window
        window.clear(sf::Color::Black);
         
        window.draw(circle1);
         
        window.draw(Square);

        window.draw(triangle);

        window.display();
    }
    return 0;
}