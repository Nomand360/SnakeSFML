#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "window.h"
#include "snake.h"
#include "apple.h"

const int block = 16;
const int N = 30;
const int M = 20;

class Game
{
public:
    Game(); 
    void handleInput();
    void eatApple();
    void update();
    void render();
    void runGame();
    ~Game();
private:
    Game(const Game &g) = delete;
    Game operator=(const Game &g) = delete;
    Window window;
    Snake snake;
    Apple apple;
    float timeStep;

};

#endif // GAME_H
