/*
Window.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contains Window namespace
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Jukebox.hpp"

namespace OpMon {
    namespace View {
      class Window{
      private:
        sf::RenderWindow window;
        sf::RenderTexture frame;
        bool init;
        bool fullScreen;
      public:
	sf::RenderTexture& getFrame() {return frame; }
	sf::RenderWindow& getWindow() {return window;}
        void close();
        void open();
        void winRefresh();
      };
    } // namespace View
} // namespace OpMon

#endif
