#include "../inc/World.hpp"


World::World(sf::RenderWindow *window, const int width, const int height) : m_window{window}, m_height{height}, m_width{width}
{
    m_grid.reserve(m_width * m_height);

    for (auto it = m_grid.begin(); it != m_grid.end(); ++it)
    {
        *it = PARTICLE_TYPE::AIR;
    }

}

World::~World()
{

}