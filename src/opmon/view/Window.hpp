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


namespace OpMon {
    namespace View {
        class Window {
          private:
            sf::RenderWindow window;
            sf::RenderTexture frame;
            bool fullScreen = false;

          public:
            sf::RenderTexture &getFrame() { return frame; }
            sf::RenderWindow &getWindow() { return window; }
            void close();
            void open();
            void refresh();
        };
    } // namespace View
} // namespace OpMon

#endif
