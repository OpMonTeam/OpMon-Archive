/*
Elements.cpp
Author : Cyrion
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Elements.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/ResourceLoader.hpp"

namespace OpMon {
    namespace View {

        sf::Texture MapLayer::tileset;

        MapLayer::MapLayer(sf::Vector2i size, const int tilesCodes[]) {
            if(tileset.getSize() == sf::Vector2u(0, 0)) {
                Model::ResourceLoader::load(tileset, "tileset/tileset.png");
            }
            tiles.setPrimitiveType(sf::Quads);
            tiles.resize(size.x * size.y * 4);

            for(int i = 0; i < size.y; i++) {
                for(int j = 0; j < size.x; j++) {

                    //The software we use (Tiled map editor) starts the first tile at 1, and leaves 0 for void. This line substracts one to every square.

                    int tileNumber = tilesCodes[(i * size.x) + j] - 1;

                    //Now that every void (0) became -1, this replaces every -1 by the "official" void tile.
                    if(tileNumber == -1) {
                        tileNumber = 257; //official void tile
                    }

                    int tx = tileNumber % (tileset.getSize().x / 32);
                    int ty = tileNumber / (tileset.getSize().x / 32);

                    sf::Vertex *quad = &tiles[((i * size.x) + j) * 4];

                    quad[0].position = sf::Vector2f(j * 32, i * 32);
                    quad[1].position = sf::Vector2f((j + 1) * 32, i * 32);
                    quad[2].position = sf::Vector2f((j + 1) * 32, (i + 1) * 32);
                    quad[3].position = sf::Vector2f(j * 32, (i + 1) * 32);

                    quad[0].texCoords = sf::Vector2f(tx * 32, ty * 32);
                    quad[1].texCoords = sf::Vector2f((tx + 1) * 32, ty * 32);
                    quad[2].texCoords = sf::Vector2f((tx + 1) * 32, (ty + 1) * 32);
                    quad[3].texCoords = sf::Vector2f(tx * 32, (ty + 1) * 32);
                }
            }
        }

        void MapLayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            states.transform *= getTransform();

            states.texture = &tileset;

            target.draw(tiles, states);
        }

    } // namespace View
} // namespace OpMon
