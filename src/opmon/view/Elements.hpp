/*
Elements.hpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../model/sysObjects/Player.hpp"

namespace OpMon {
    namespace View {

        class MapLayer : public sf::Drawable, public sf::Transformable {
          private:
            static sf::Texture tileset;
            virtual void draw(sf::RenderTarget &target, sf::RenderStates stats) const;
            sf::VertexArray tiles;

          public:
            MapLayer(sf::Vector2i size, const int tilesCode[]);
        };

    } // namespace View
} // namespace OpMon

#endif // ELEMENTS_HPP
