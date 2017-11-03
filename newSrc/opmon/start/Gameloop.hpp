#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

namespace OpMon{
  class GameLoop{
  public:
    GameLoop();
    GameStatus operator()();
    GameStatus checkQuit();
    
  private:
    sf::Event events;
    View::Overworld overworld;
    View::StartScene startscene;
    View::MainMenu mainmenu;
    View::OptionsMenu optionsmenu;
    GamePart gamepart = GamePart::START;
    bool endGame = false;

    int frames = 0;
  }
}

#endif
