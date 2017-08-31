/*
StartScene.hpp
Author : Jlppc
File under the GPL-3.0 license
http://opmon-game.ga
*/
#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "../start/bigDefines.hxx"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace MainFrame {
    namespace StartScene {
        int startScene();
        void initVars();
        void initStrings();

        extern sf::Sprite bg;
        extern sf::Sprite prof;
        extern sf::Music bgMus;
    }
}


#endif // STARTSCENE_H
