#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>

enum PARTICLE_TYPE
{
    AIR,
    SAND,
    WATER,
    STONE
};

class Particle
{
public:
    Particle(/* args */);
    ~Particle();

private:
    PARTICLE_TYPE m_type;
    sf::Vector2i m_position;
};


#endif  //PARTICLE_HPP