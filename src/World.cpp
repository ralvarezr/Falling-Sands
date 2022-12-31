#include "../inc/World.hpp"

#include <iostream>

World::World(sf::RenderWindow *window, const int width, const int height) : m_window{window}, m_height{height}, m_width{width}
{

    std::cout << "Mundo construido" << std::endl;

    m_grid.reserve(m_width * m_height);

    ClearGrid();
}

World::~World()
{
    std::cout << "Mundo destruido" << std::endl;
}

void World::AddParticle(Particle& p)
{
    sf::Vector2i position = p.GetPosition();
    if (InBounds(position.x, position.y))
    {
        m_particles.push_back(std::move(p));
        std::cout << "Se agrega particula nro: " << m_particles.size() << std::endl;
    }
    else
    {
        std::cout << "Particula fuera de rango, no se agrega" << std::endl;
    }
}

void World::Draw()
{
    for (auto& particle: m_particles)
    {
        particle.Draw(m_window);
    }
}

bool World::InBounds(const int x, const int y) const
{
    return x >= 0 && y >= 0 && x < m_width && y < m_height;
}

void World::ClearGrid()
{
    for (auto it = m_grid.begin(); it != m_grid.end(); ++it)
    {
        *it = PARTICLE_TYPE::AIR;
    }
}