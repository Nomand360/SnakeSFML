#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>


struct Segment{
    Segment(float x, float y) : position(x,y){}
    sf::Vector2f position;
};

enum class Direction{None, Up, Down, Right, Left};

class Snake
{
public:
    Snake(float size);
    ~Snake();
    Direction getDir();
    sf::Vector2f getPos() const;
    sf::Vector2f setPos(float x1, float y1);
private:
    float blockSize;
    std::vector<Segment> snake;
    Direction dir;
    sf::RectangleShape body;
};

#endif // SNAKE_H
