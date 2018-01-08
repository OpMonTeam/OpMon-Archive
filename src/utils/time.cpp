
#include <SFML/System/Clock.hpp>
#include "time.hpp"


/**
 * Clock created at the very beginning, used as the time reference.
 */
static sf::Clock ticks;


namespace Utils {

  void initClock(){
    ticks.restart();
  }

  int getElapsedMilliseconds(){
    return ticks.getElapsedTime().asMilliseconds();
  }

}
