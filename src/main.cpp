#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "Starting Bouncing Balls Simulation" << std::endl;

    unsigned int windowWidth = 800;
    unsigned int windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode({800,600}), "Bouncing Balls Simulation");

    while (window.isOpen())
    {
        while(const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>())        {
                window.close();
            }    
            
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                std::cout << "You pressed a key! Code: " << static_cast<int>(keyPressed->code) << std::endl;
            }

            // Check if the mouse was moved
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                std::cout << "Mouse at: " << mouseMoved->position.x << ", " << mouseMoved->position.y << "\r";
            }

        }    
    }
    return 0;
}    
