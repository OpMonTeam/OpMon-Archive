/*
Window.hpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
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
            //sf::RenderTexture* frame = new sf::RenderTexture();
            bool fullScreen = false;

          public:
            sf::RenderWindow &getFrame() { return window; }
            sf::RenderWindow &getWindow() { return window; }
            void close();
            void open();
            void refresh();
	          void reboot();
            void handleEvent(sf::Event* event);
        };
    } // namespace View
} // namespace OpMon

#endif
