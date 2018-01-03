#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP
#define FPS_TICKS 33

#include <stack>

#include "Core.hpp"
#include "../model/sysObjects/Player.hpp"
#include "../view/Interface.hpp"

namespace OpMon{
  namespace View{
    class Interface;
  }
  class GameLoop{
  public:
    GameLoop();
    GameStatus operator()();
    GameStatus checkQuit();

    Model::Player& getPlayer(){
      return player;
    }

    

  private:
    sf::Event events;
    bool endGame = false;
    std::stack<View::Interface*> interfaces;
    Model::Player player;
    
    
    int frames = 0;
    int oldticks = 0;
  };
}

#endif
