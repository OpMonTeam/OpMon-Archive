#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#define FPS_TICKS 33

namespace OpMon{
  class GameLoop{
  public:
    GameLoop();
    GameStatus operator()();
    GameStatus checkQuit();

    bool isWait(){
      return wait;
    }

    void setWait(bool wait){
      this->wait = wait;
    }

    GamePart getGamePart(){
      return gamepart;
    }

    void setGamePart(GamePart toSet){
      gamepart = toSet;
    }

    Player& getPlayer(){
      return player;
    }

  private:
    sf::Event events;
    GamePart gamepart = GamePart::START;
    bool endGame = false;
    bool wait = true;
    std::Stack<View::Interface*> interfaces;
    Player player;
    
    
    int frames = 0;
    int oldticks = 0;
  }
}

#endif
