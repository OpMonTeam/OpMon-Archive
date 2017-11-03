#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#define FPS_TICKS 33

namespace OpMon{
  class GameLoop{
  public:
    GameLoop();
    GameStatus operator()();
    GameStatus checkQuit();

    void setActualDialog(std::vector<sf::String> newDialog){
      actualDialog = newDialog;
    }

    bool isWait(){
      return wait;
    }

    void setWait(bool wait){
      this->wait = wait;
    }
    
  private:
    sf::Event events;
    View::Overworld overworld;
    View::StartScene startscene;
    View::MainMenu mainmenu;
    View::OptionsMenu optionsmenu;
    GamePart gamepart = GamePart::START;
    bool endGame = false;
    bool wait = true;

    std::vector<sf::String> actualDialog;
    
    int frames = 0;
    int oldticks = 0;
  }
}

#endif
