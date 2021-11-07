#include "window.h"

void Window::createWindow()
{
    this->window = new sf::RenderWindow();
    this->window->create({this->size.x, this->size.y}, this->title);
    window->setFramerateLimit(60);
}

void Window::destroyWindow()
{
    this->window->close();
    delete window;
}

Window::Window()
{
    this->size = {600, 400};
    this->title = "New Game";
    this->createWindow();
}

Window::Window(sf::Vector2u sz, std::string title)
{
    this->size = sz;
    this->title = title;
    this->createWindow();
}

Window::~Window()
{
    this->destroyWindow();
}

void Window::beginDraw()
{
    window->clear();
}

void Window::endDeaw()
{
    window->display();
}

void Window::update()
{
    sf::Event event;
    while(this->window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->destroyWindow();
        }
    }
}

sf::Vector2u Window::getWindowSize() const
{
    return this->window->getSize();
}

sf::RenderWindow *Window::getRenderWindow()
{
    return this->window;
}

void Window::draw(sf::Drawable &drawable)
{
    this->window->draw(drawable);
}
