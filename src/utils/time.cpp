/*
time.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#include "time.hpp"
#include <SFML/System.hpp>

/**
 * Clock created at the very beginning, used as the time reference.
 */
static sf::Clock ticks;

namespace Utils::Time {

    void initClock() {
        ticks.restart();
    }

    int getElapsedMilliseconds() {
        return ticks.getElapsedTime().asMilliseconds();
    }

    float getElapsedSeconds() {
        return ticks.getElapsedTime().asSeconds();
    }

    void wait(int duration) {
        sf::sleep(sf::milliseconds(duration));
    }

} // namespace Utils::Time
