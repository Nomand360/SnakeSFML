#ifndef APPLE_H
#define APPLE_H
#include <SFML/Graphics.hpp>

class Apple
{
public:
    Apple();
    sf::Vector2f getPosApple();
    void resetPosition(int N, int M);
    void renderApple(sf::RenderWindow &window);
private:
    Apple(const Apple &a) = delete;
    Apple operator=(const Apple &a) = delete;
    sf::Vector2f position;
    sf::CircleShape apple;
};

#endif // APPLE_H
