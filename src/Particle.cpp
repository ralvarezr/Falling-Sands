#include "../inc/Particle.hpp"

#include <iostream>

Particle::Particle(const sf::Vector2i position, const PARTICLE_TYPE type) : m_type{type}, m_position{position}
{
    std::cout << position.x << "," << position.y << std::endl;
    std::cout << "Particula construida" << std::endl;
}

Particle::~Particle()
{
    std::cout << "Particula Destruida" << std::endl;
}

Particle::Particle(const Particle &rhs)
{
    std::cout << "Constructor por Copia de Particula" << std::endl;

    m_type = rhs.m_type;
    m_position = rhs.m_position;
}

Particle& Particle::operator=(const Particle &rhs)
{
    std::cout << "Copia por Asignacion de Particula" << std::endl;

    if (&rhs != this)
    {
        m_type = rhs.m_type;
        m_position = rhs.m_position;
    }

    return *this;
}

Particle::Particle(Particle &&source)
{
    std::cout << "Constructor por Move de Particula" << std::endl;
    
    m_type = source.m_type;
    source.m_type = PARTICLE_TYPE::AIR;

    m_position = source.m_position;
    source.m_position.x = 0;
    source.m_position.y = 0;
}

Particle& Particle::operator=(Particle &&source)
{
    std::cout << "Move por asignacion de Particula" << std::endl;

    if (&source != this)
    {
        m_type = source.m_type;
        source.m_type = PARTICLE_TYPE::AIR;
       
        m_position = source.m_position;
        source.m_position.x = 0;
        source.m_position.y = 0;
    }

    return *this;
}

void Particle::Draw(sf::RenderWindow *window)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(1.0f, 1.0f));
    rectangle.setPosition(m_position.x, m_position.y);

    switch (m_type)
    {
    case PARTICLE_TYPE::AIR:
        rectangle.setFillColor(sf::Color::Transparent);
        break;

    case PARTICLE_TYPE::SAND:
        rectangle.setFillColor(sf::Color::Yellow);
        break;

    case PARTICLE_TYPE::WATER:
        rectangle.setFillColor(sf::Color::Blue);
        break;

    case PARTICLE_TYPE::STONE:
        rectangle.setFillColor(sf::Color::White);
        break;

    default:
        rectangle.setFillColor(sf::Color::Transparent);
        break;
    }

    window->draw(rectangle);
}

PARTICLE_TYPE Particle::GetType() const
{
    return m_type;
}

sf::Vector2i Particle::GetPosition() const
{
    return m_position;
}