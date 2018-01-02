#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP
#define FPS_TICKS 33

#include <stack>

#include "Core.hpp"
#include "../model/sysObject/Player.hpp"

namespace OpMon{
  class GameLoop{
  public:
    GameLoop();
    GameStatus operator()();
    GameStatus checkQuit();

    Player& getPlayer(){
      return player;
    }

    

  private:
    sf::Event events;
    bool endGame = false;
    std::Stack<View::Interface*> interfaces;
    Player player;
    
    
    int frames = 0;
    int oldticks = 0;
  };
}

#endif
