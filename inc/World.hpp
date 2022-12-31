#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>


class World
{

public:

    World(sf::RenderWindow* p_window, const int width, const int height);

    ~World();

private:

    //int* m_grid;
};


#endif