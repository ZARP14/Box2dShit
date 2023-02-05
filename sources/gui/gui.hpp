#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <set>
#include <vector>

class Gui
{
public:
    static Gui global;
    void visualStarted();
    void vectorInput(sf::Sprite& a);

    void bebraMustDie();
    std::vector<sf::Sprite*> SpriteVector;

private:
    Gui();
    void drawAnything();
    sf::RenderWindow mWindow;
};
#endif // !GUI_HPP
