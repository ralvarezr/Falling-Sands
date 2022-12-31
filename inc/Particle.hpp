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
    // Constructor.
    Particle(const sf::Vector2i position, const PARTICLE_TYPE type);
    // Destructor.
    ~Particle();
    // Copy constructor.
    Particle(const Particle& rhs);
    // Copy assignment operator.
    Particle& operator=(const Particle& rhs);
    // Move constructor.
    Particle(Particle&& source);
    // Move assigment operator.
    Particle& operator=(Particle&& source);
    // Draw Particle.
    void Draw(sf::RenderWindow *window);
    // Get particle type.
    PARTICLE_TYPE GetType() const;
    // Get particle position.
    sf::Vector2i GetPosition() const;

private:
    PARTICLE_TYPE m_type;
    sf::Vector2i m_position;
};


#endif  //PARTICLE_HPP