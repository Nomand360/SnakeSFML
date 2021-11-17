#include "snake.h"

Snake::Snake(float size)
{
    this->blockSize = 16;
    this->body.setSize(sf::Vector2f(size, size));
    this->body.setOutlineThickness(1.f);
    this->body.setOutlineColor(sf::Color::Black);
    this->setup();
}

Snake::~Snake()
{

}

void Snake::setup()
{
    snake.push_back(Segment(5,5));
    snake.push_back(Segment(4,5));
    snake.push_back(Segment(3,5));

    setDirection(Direction::Right);
}

void Snake::setDirection(Direction dr)
{
    this->dir = dr;
}

Direction Snake::getDir()
{
    return this->dir;
}

sf::Vector2f Snake::getPos() const
{
    return this->snake.front().position;
}

void Snake::setPos(float x1, float y1)
{
    this->snake.front().position.x = x1;
    this->snake.front().position.y = y1;
}

void Snake::moveSnake()
{
    for(size_t i = snake.size() - 1; i > 0; --i){
        snake[i].position.x = snake[i - 1].position.x;
        snake[i].position.y = snake[i - 1].position.y;
    }
    if(dir == Direction::Up){
        --snake[0].position.y;
    }else if(dir == Direction::Down){
        ++snake[0].position.y;
    }else if(dir == Direction::Right){
        ++snake[0].position.x;
    }else if(dir == Direction::Left){
        --snake[0].position.x;
    }
}

void Snake::renderSnake(sf::RenderWindow &window)
{
    for(size_t i = 0; i < snake.size(); ++i){
        body.setPosition(snake[i].position.x * blockSize, snake[i].position.y * blockSize);
        window.draw(body);
    }
}

void Snake::checkCollision(const sf::Vector2u &size)
{

    if(getPos().x >= size.x / blockSize || getPos().y>= size.y / blockSize || getPos().x < 0 || getPos().y < 0){
        snake.clear();
        this->setup();
    }
    for(size_t i = 1; i < snake.size(); ++i){
        if(snake.front().position.x == snake[i].position.x && snake.front().position.y == snake[i].position.y){
            snake.clear();
            this->setup();
        }
    }

}

void Snake::growSnake()
{
    snake.push_back(Segment(snake.back().position.x, snake.back().position.y));
}
