#ifndef MAPLAYER_HPP
#define MAPLAYER_HPP

class MapLayer : public sf::Drawable, public sf::Transformable{
private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates stats) const;
  sf::VertexArray tiles;
public:
  MapLayer(sf::Vector2i size, const int tilesCode[]);
};

#endif
