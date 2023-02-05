#ifndef TIME_HPP
#define TIME_HPP

#include <SFML/Graphics.hpp>

class Time
{
public:
    static Time me;
    sf::Clock mainTime;
    void reTime();
    double getTime();
};
#endif // !TIME_HPP