#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>

class Window
{
private:
    sf::RenderWindow *window;
    sf::Vector2u size;
    std::string title;
    void createWindow();
    void destroyWindow();
public:
    Window();
    Window(sf::Vector2u sz, std::string title);
    ~Window();
    void beginDraw();
    void endDeaw();
    void update();
    sf::Vector2u getWindowSize() const;
    sf::RenderWindow *getRenderWindow();
    void draw(sf::Drawable &drawable);
};

#endif // WINDOW_H
