#include "game.h"

Game::Game() : window(sf::Vector2u(30 * block, 20 * block), "Snake SFML"), snake(15)
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

}

void Game::render()
{

}

void Game::runGame()
{

}
