#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>
#include "Particle.hpp"
#include <vector>

class World
{
public:
    // Constructor.
    World(sf::RenderWindow* window, const int width, const int height);
    // Destructor.
    ~World();
    // Add Particle to the World.
    void AddParticle(Particle& p);
    // Draw World.
    void Draw();
    // Update World.
    void Update();

private:
    sf::RenderWindow* m_window;
    int m_height;
    int m_width;
    std::vector<PARTICLE_TYPE> m_grid;
    std::vector<Particle> m_particles;

    // Return if the coordinates are witin the world's bounds.
    bool InBounds(const int x, const int y) const;
    // Clear the world's grid.
    void ClearGrid();
    // Update the grid with the Particles.
    void UpdateGrid();
    // Return if the coordinates corresponds to an empty cell.
    bool IsEmpty(const int x, const int y) const;
    // Move the Particles around the grid.
    void MoveParticles();
    // Set a Cell in the Grid with the type specified.
    void SetCell(const int x, const int y, const PARTICLE_TYPE type);
};


#endif //WORLD_HPP