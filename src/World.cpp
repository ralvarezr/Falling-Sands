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

void World::Update()
{
    // Clear the grid.
    ClearGrid();

    // Update the grid.
    for (auto& particle: m_particles)
    {
        sf::Vector2i position = particle.GetPosition();
        m_grid[position.y * m_width + position.x] = particle.GetType();
    }
    
    // Move the particles.
    for (auto& particle: m_particles)
    {
        sf::Vector2i particle_position = particle.GetPosition();

        PARTICLE_TYPE particle_type = particle.GetType();

        switch (particle_type)
        {
        case PARTICLE_TYPE::SAND:

            if (PARTICLE_TYPE::AIR == GetBottomCellType(particle_position.x, particle_position.y))
            {
                // Set the current Cell to Air.
                SetCell(particle_position.x, particle_position.y, PARTICLE_TYPE::AIR);
                // Move down the Cell.
                SetCell(particle_position.x, (particle_position.y + 1), particle_type);
                // Set the new position to the particle.
                particle.SetPosition(particle_position.x, (particle_position.y + 1));
            }

            break;
        
        default:
            break;
        }

 


    }

}

bool World::InBounds(const int x, const int y) const
{
    return x >= 0 && y >= 0 && x < m_width && y < m_height;
}

void World::ClearGrid()
{
    for (auto& cell : m_grid)
    {
        cell = PARTICLE_TYPE::AIR;
    }
}

PARTICLE_TYPE World::GetBottomCellType(int x, int y)
{
    // If the y coordinate is the maximum possible.
    if (y >= m_height - 1)
    {
        // Substract 2 from the height to get the current cell.
        y = m_height - 2;
    }

    return m_grid[(y + 1) * m_width + x];
}

PARTICLE_TYPE World::GetBottomRightCellType(const int x, const int y)
{
    return PARTICLE_TYPE::AIR;
}

PARTICLE_TYPE World::GetBottomLeftCellType(const int x, const int y)
{
    return PARTICLE_TYPE::AIR;
}

void World::SetCell(const int x, const int y, const PARTICLE_TYPE type)
{
    m_grid[y * m_width + x] = type;
}
