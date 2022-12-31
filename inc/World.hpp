#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include <vector>

class World
{
public:

    World(sf::RenderWindow* window, const int width, const int height);
    ~World();

private:

    sf::RenderWindow* m_window;
    int m_height;
    int m_width;
    std::vector<PARTICLE_TYPE> m_grid;
    std::vector<Particle> particles;
};


#endif //WORLD_HPP