/*
MapLayer.hpp
Author : Jlppc
File under the license GPL-3.0
http://opmon-game.ga
Contains MainMenu class definition
*/
#ifndef MAPLAYER_HPP
#define MAPLAYER_HPP

class MapLayer : public sf::Drawable, public sf::Transformable {
private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates stats) const;

  sf::VertexArray tiles;
public:
  MapLayer(sf::Vector2i size, const int tilesCode[]);
};

#endif
