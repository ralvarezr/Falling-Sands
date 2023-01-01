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

    // Returns if the coordinates are witin the world's bounds.
    bool InBounds(const int x, const int y) const;
    // Clears the world's grid.
    void ClearGrid();
    // Get the Bottom Cell Type.
    PARTICLE_TYPE GetBottomCellType(int x, int y);
    // Get the Right Cell Type.
    PARTICLE_TYPE GetBottomRightCellType(int x, int y);
    // Get the Left Cell Type.
    PARTICLE_TYPE GetBottomLeftCellType(int x, int y);
    // Set a Cell in the Grid with the type specified.
    void SetCell(const int x, const int y, const PARTICLE_TYPE type);
};


#endif //WORLD_HPP