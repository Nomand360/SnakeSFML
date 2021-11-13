#include "game.h"

Game::Game() : window(sf::Vector2u(30 * block, 20 * block), "Snake SFML"), snake(block), timeStep(0.1f)
{
    srand(time(nullptr));
    this->runGame();
}

void Game::handleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getDir() != Direction::Down){
        snake.setDirection(Direction::Up);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDir() != Direction::Up){
        snake.setDirection(Direction::Down);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getDir() != Direction::Left){
        snake.setDirection(Direction::Right);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDir() != Direction::Right){
        snake.setDirection(Direction::Left);
    }
}

void Game::update()
{
    this->snake.moveSnake();
}

void Game::render()
{
    this->window.beginDraw();
    this->snake.renderSnake(*this->window.getRenderWindow());
    this->window.endDeaw();
}

void Game::runGame()
{
    sf::Clock clock;
    float elapseTime = 0;
    while (this->window.getRenderWindow()->isOpen()){
        this->window.update();
        this->handleInput();
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        elapseTime += time;
        if(elapseTime > timeStep){
            elapseTime = 0;
            this->update();
        }
        this->render();

    }
}

Game::~Game()
{

}
