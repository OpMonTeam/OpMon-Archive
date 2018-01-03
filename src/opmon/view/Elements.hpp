/*
Elements.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Fichier contenant des Ã©lÃ©ments utiles
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../model/sysObjects/Player.hpp"

namespace OpMon{
  namespace View{

    class Event;

    class MapLayer : public sf::Drawable, public sf::Transformable{
    private:
      virtual void draw(sf::RenderTarget &target, sf::RenderStates stats) const;
      sf::VertexArray tiles;
    public:
      MapLayer(sf::Vector2i size, const int tilesCode[]);
    };

  }
}


#endif // ELEMENTS_HPP
