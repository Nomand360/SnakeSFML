#include <iostream>
#include <SFML/Graphics.hpp>

const int block = 16;
const int N = 30 , M = 20;
const int weightScreen = N * block;
const int heightScreen  = M *block;
bool right = true, left = true, up = false, down = true;
int dir = 2, num = 4;

struct snake{
    int x, y;
}s[100];

struct apple{
    int x, y;
}f;

void tick(){

    for(int i = num; i > 0; --i){
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }
    if(dir == 0){
        s[0].y += 1;
    }
    if(dir == 1){
        s[0].x -= 1;
    }
    if(dir == 2){
        s[0].x += 1;
    }
    if(dir == 3){
        s[0].y -= 1;
    }

    if(s[0].x == f.x && s[0].y == f.y){
        num++;
        f.x = rand() % N;
        f.y = rand() % M;
    }

    if(s[0].x > N) s[0].x = 0;
    if(s[0].y > M) s[0].y = 0;

    if(s[0].x < 0) s[0].x = N;
    if(s[0].y < 0) s[0].y = M;

    for(int i = 1; i < num; i++){
        if(s[0].x == s[i].x && s[0].y == s[i].y){
                num = i;
            }
    }
}

int main()

{
    sf::Clock clock;
    float timer = 0, delay = 0.1f;
    sf::RenderWindow window(sf::VideoMode(weightScreen, heightScreen), "SFML Snake");
    window.setFramerateLimit(60);
    sf::RectangleShape rect(sf::Vector2f(15.f, 15.f));
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(1.f);
    rect.setOutlineColor(sf::Color::Black);
    sf::CircleShape app(8.f);
    app.setFillColor(sf::Color::Red);

    while(window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && left == true){
            dir = 1;
            right = false;
            up = true;
            down = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && right == true){
            dir = 2;
            left = false;
            up = true;
            down = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& up == true){
            dir = 3;
            down = false;
            left = true;
            right = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& down == true){
            dir = 0;
            up = false;
            left = true;
            right = true;
        }

        if(timer > delay){
            timer = 0;
            tick();
        }
        window.clear();
        for(int i = 0; i < num; i++){
            rect.setPosition(s[i].x * block, s[i].y * block );
            window.draw(rect);
        }
        app.setPosition(f.x * block, f.y * block);
        window.draw(app);
        window.display();
    }
    return 0;
}
