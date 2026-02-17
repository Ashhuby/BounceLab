#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::cout << "Starting Bouncing Balls Simulation" << std::endl;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Bouncing Balls");
    
    // We'll add our ball struct here
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();
        // We'll draw here
        window.display();
    }
    
    return 0;
}