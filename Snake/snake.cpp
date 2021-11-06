#include "snake.h"

Snake::Snake(float size)
{
    this->blockSize = size;
    this->body.setSize(sf::Vector2f(size, size));
    this->body.setOutlineThickness(1.f);
    this->body.setOutlineColor(sf::Color::Black);
}

Snake::~Snake()
{

}

Direction Snake::getDir()
{

}

sf::Vector2f Snake::getPos() const
{

}

sf::Vector2f Snake::setPos(float x1, float y1)
{

}
