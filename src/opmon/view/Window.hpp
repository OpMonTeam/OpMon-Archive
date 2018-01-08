#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace OpMon{
  namespace View{
    extern sf::RenderWindow window;
    extern sf::RenderTexture frame;
    void open();
    void winRefresh();
  }
}

#endif
