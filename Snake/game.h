#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "window.h"
#include "snake.h"
#include "apple.h"

const int block = 16;

class Game
{
public:
    Game();
    Game(const Game &g) = delete;
    Game operator=(const Game &g) = delete;
    void handleInput();
    void update();
    void render();
    void runGame();
    ~Game();
private:
    Window window;
    Snake snake;
    sf::Time timeStep;

};

#endif // GAME_H
