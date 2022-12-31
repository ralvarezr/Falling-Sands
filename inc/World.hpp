#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include <vector>

class World
{
public:
    // Constructor
    World(sf::RenderWindow* window, const int width, const int height);
    // Destructor
    ~World();
    // Add Particle to the World.
    void AddParticle(Particle& p);
    // Draw World
    void Draw();

private:
    sf::RenderWindow* m_window;
    int m_height;
    int m_width;
    std::vector<PARTICLE_TYPE> m_grid;
    std::vector<Particle> m_particles;
};


#endif //WORLD_HPP