/*
Window.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contains Window namespace
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

namespace OpMon {
  namespace View {
    extern sf::RenderWindow window;
    extern sf::RenderTexture frame;

    void open();

    void winRefresh();
  }
}

#endif
