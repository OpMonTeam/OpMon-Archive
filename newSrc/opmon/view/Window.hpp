#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace OpMon{
  namespace View{
    extern sf::RenderWindow window;
    extern sf::RenderTexture frame;
    GameStatus open();
    void winRefresh();
  }
}

#endif
