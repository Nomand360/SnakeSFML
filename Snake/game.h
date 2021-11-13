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
    void handleInput();
    void update();
    void render();
    void runGame();
    ~Game();
private:
    Game(const Game &g) = delete;
    Game operator=(const Game &g) = delete;
    Window window;
    Snake snake;
    float timeStep;

};

#endif // GAME_H
