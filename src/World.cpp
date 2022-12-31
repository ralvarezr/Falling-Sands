#include "../inc/World.hpp"

#include <iostream>

World::World(sf::RenderWindow *window, const int width, const int height) : m_window{window}, m_height{height}, m_width{width}
{

    std::cout << "Mundo construido" << std::endl;

    m_grid.reserve(m_width * m_height);

    for (auto it = m_grid.begin(); it != m_grid.end(); ++it)
    {
        *it = PARTICLE_TYPE::AIR;
    }

}

World::~World()
{
    std::cout << "Mundo destruido" << std::endl;
}

void World::AddParticle(Particle& p)
{
    m_particles.push_back(std::move(p));
    std::cout << "Se agrega particula nro: " << m_particles.size() << std::endl;
}

void World::Draw()
{
    for (auto& particle: m_particles)
    {
        particle.Draw(m_window);
    }
}