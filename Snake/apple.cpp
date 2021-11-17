#include "apple.h"

Apple::Apple()
{
    position.x = rand() % 30;
    position.y = rand() % 20;
    apple.setRadius(8.f);
    apple.setFillColor(sf::Color::Red);
    apple.setPosition(position.x * 16, position.y * 16);

}

sf::Vector2f Apple::getPosApple()
{
    return position;
}

void Apple::resetPosition(int N, int M)
{
    position.x = rand() % N;
    position.y = rand() % M;
    apple.setPosition(position.x * 16, position.y * 16);
}

void Apple::renderApple(sf::RenderWindow &window)
{
    window.draw(apple);
}
