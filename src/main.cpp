#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Global variables
const float Gravity = 980.0f;
const float Restitution = 0.8f; // 1 = perfectly elastic 0 = perfectly ineleastic

struct Ball{
    sf::Vector2f position;
    float radius;
    sf::Color colour;
    sf::Vector2f velocity;

public:
    Ball(sf::Vector2f Position, float Radius = 1.0f, sf::Color Colour = sf::Color::White) {
        radius = Radius;
        colour = Colour;
        position = Position;
        velocity = { 0.0f,0.0f };
    }
};


void DrawBall(Ball b, sf::RenderWindow& window) {
    sf::CircleShape circle;
    circle.setRadius(b.radius);
    circle.setPosition({b.position.x - b.radius, b.position.y - b.radius}); // Centre the pos 
    circle.setFillColor(b.colour); 
    window.draw(circle); 
}

void UpdateBall(Ball& b) {
    b.velocity.y += Gravity;
    b.position += b.velocity;
}

int main()
{
    std::cout << "=== BounceLab Starting ===" << std::endl;

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "BounceLab");
    window.setFramerateLimit(60);
    std::cout << "FPS";

    std::vector<Ball> balls;

    Ball ball1 = Ball({ 400.0f,300.0f }, 25.0f, sf::Color::Red);
    Ball ball2 = Ball({ 250.0f,300.0f }, 45.0f, sf::Color::Magenta);
    balls.push_back(ball1);
    balls.push_back(ball2);

    // Loop
    while (window.isOpen())
    {
        // Events here

        window.clear(sf::Color::Black);

        // Draw balls
        for (int i = 0; i < balls.size(); i++) {}

        for (Ball b : balls) {           
            UpdateBall(b);
            DrawBall(b, window);
        }

        window.display();
    }

    return 0;
}