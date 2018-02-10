
#include "time.hpp"
#include <SFML/System.hpp>

/**
 * Clock created at the very beginning, used as the time reference.
 */
static sf::Clock ticks;

namespace Utils {
    namespace Time {

        void initClock() {
            ticks.restart();
        }

        int getElapsedMilliseconds() {
            return ticks.getElapsedTime().asMilliseconds();
        }

        void wait(int duration) {
            sf::sleep(sf::milliseconds(duration));
        }

    } // namespace Time
} // namespace Utils
