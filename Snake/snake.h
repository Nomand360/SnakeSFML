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
    Snake(const Snake &s) = delete;
    Snake operator=(const Snake &s) = delete;
    ~Snake();
    void setup();
    void setDirection(Direction dr);
    Direction getDir();
    sf::Vector2f getPos() const;
    void setPos(float x1, float y1);
    void moveSnake();
    void renderSnake(sf::RenderWindow &window);
private:
    float blockSize;
    std::vector<Segment> snake;
    Direction dir;
    sf::RectangleShape body;
};

#endif // SNAKE_H
