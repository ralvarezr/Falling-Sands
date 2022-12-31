#include <iostream>
#include <SFML/Graphics.hpp>

#include "../inc/World.hpp"
#include "../inc/Particle.hpp"

const int g_worldWidth = 400;
const int g_worldHeight = 400;

int main()
{
    // Create the window.
    sf::RenderWindow window(sf::VideoMode(g_worldWidth, g_worldHeight), "Falling Sands");

    // Create our world for the simulation.
    World world(&window, g_worldWidth, g_worldHeight);

    // Create a variable to hold the Particle Type to be created.
    PARTICLE_TYPE particle_type = PARTICLE_TYPE::SAND;

    // Run the program as long as the window is open.
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            particle_type = PARTICLE_TYPE::SAND;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            particle_type = PARTICLE_TYPE::WATER;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            particle_type = PARTICLE_TYPE::STONE;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i position = sf::Mouse::getPosition(window);

            Particle p(position, particle_type);
            world.AddParticle(p);
        }

        // Clear the window.
        window.clear(sf::Color::Transparent);
  
        // Updates the world.
        //world.Update();

        // Draw all the particles.
        world.Draw();

        window.display();
    }

    return 0;
}
