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
        extern sf::RenderWindow window;
        extern sf::RenderTexture frame;
        extern Jukebox jukebox;
        extern bool init;
        extern bool fullScreen;
        void close();
        void open();
        void winRefresh();
    } // namespace View
} // namespace OpMon

#endif
