#include "../inc/World.hpp"

#include <iostream>
#include <random>

World::World(sf::RenderWindow *window, const int width, const int height) : m_window{window}, m_height{height}, m_width{width}
{
    m_grid.reserve(m_width * m_height);
}

World::~World()
{
}

void World::AddParticle(Particle& p)
{
    sf::Vector2i position = p.GetPosition();
    if (InBounds(position.x, position.y))
    {
        m_particles.push_back(std::move(p));
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
    ClearGrid();

    UpdateGrid();
    
    MoveParticles();
}

bool World::InBounds(const int x, const int y) const
{
    return ((x >= 0) && (y >= 0) && (x < m_width) && (y < m_height));
}

void World::ClearGrid()
{
    for (auto& cell : m_grid)
    {
        cell = PARTICLE_TYPE::AIR;
    }
}

void World::SetCell(const int x, const int y, const PARTICLE_TYPE type)
{
    m_grid[y * m_width + x] = type;
}


void World::UpdateGrid()
{
    for (auto &particle : m_particles)
    {
        sf::Vector2i position = particle.GetPosition();
        m_grid[position.y * m_width + position.x] = particle.GetType();
    }

}

void World::MoveParticles()
{
    for (auto &particle : m_particles)
    {
        sf::Vector2i pos = particle.GetPosition();

        PARTICLE_TYPE type = particle.GetType();

        switch (type)
        {
        case PARTICLE_TYPE::SAND:
            {
                bool down = IsEmpty(pos.x, (pos.y + 1));
                bool downleft = IsEmpty((pos.x - 1), (pos.y + 1));
                bool downright = IsEmpty((pos.x + 1), (pos.y + 1));

                if (down)
                {
                    SetCell(pos.x, (pos.y + 1), type);
                    particle.SetPosition(pos.x, (pos.y + 1));
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);
                }
                // If downleft and downright are empty, pick one randomly.
                else if (downleft && downright)
                {
                    // Get a random number betweem 0 and 1.
                    std::random_device rd;  // Will be used to obtain a seed for the random number engine
                    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
                    std::uniform_int_distribution<> distrib(0, 1);
                    bool rand = distrib(gen);

                    downleft = rand ? true : false;
                    downright = rand ? false : true;
                }
                else if (downright)
                {
                    SetCell((pos.x + 1), (pos.y + 1), type);
                    particle.SetPosition((pos.x + 1), (pos.y + 1));
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);
                }
                else if (downleft)
                {
                    SetCell((pos.x - 1), (pos.y + 1), type);
                    particle.SetPosition((pos.x - 1), (pos.y + 1));
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);
                }

                /*if (down || downleft || downright)
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);*/
            }
            break;

        case PARTICLE_TYPE::WATER:
            {
                bool down = IsEmpty(pos.x, pos.y + 1);
                bool left = IsEmpty(pos.x - 1, pos.y);
                bool right = IsEmpty(pos.x + 1, pos.y);

                if (down)
                {
                    SetCell(pos.x, (pos.y + 1), type);
                    particle.SetPosition(pos.x, (pos.y + 1));
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);
                }
                // If left and right are empty, pick one randomly.
                else if (left && right)
                {
                    // Get a random number betweem 0 and 1.
                    std::random_device rd;  // Will be used to obtain a seed for the random number engine
                    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
                    std::uniform_int_distribution<> distrib(0, 1);
                    bool rand = distrib(gen);

                    left = rand ? true : false;
                    right = rand ? false : true;
                }
                else if (right)
                {
                    SetCell((pos.x + 1), pos.y, type);
                    particle.SetPosition((pos.x + 1), pos.y);
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);
                }
                else if (left)
                {
                    SetCell((pos.x - 1), pos.y, type);
                    particle.SetPosition((pos.x - 1), pos.y);
                    SetCell(pos.x, pos.y, PARTICLE_TYPE::AIR);
                }
            }
            break;

        case PARTICLE_TYPE::STONE:
            SetCell(pos.x, pos.y, type);
            break;

        case PARTICLE_TYPE::AIR:
            SetCell(pos.x, pos.y, type);
            break;

        default:
            break;
        }
    }
}

bool World::IsEmpty(const int x, const int y) const
{
    return (InBounds(x, y) && m_grid[y * m_width + x] == PARTICLE_TYPE::AIR);
}