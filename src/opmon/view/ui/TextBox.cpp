#include "TextBox.hpp"

#include <SFML/Graphics.hpp>

#include "../../../utils/log.hpp"
#include <ostream>
#include <sstream>

TextBox::TextBox(sf::Texture texture, sf::Vector2f position, int width, int height)
  : texture(texture)
  , position(position)
  , width(width)
  , height(height) {

    for(unsigned int i = 0; i < 3; ++i) {
        for(unsigned int j = 0; j < 3; ++j) {
            sf::Vertex *quad = &this->vertexArray[(i * 3 + j) * 4];

            int currentQuadX = 0;
            int currentQuadY = 0;
            int currentQuadWidth = 0;
            int currentQuadHeight = 0;

            if (i==0 && j ==0) {
                // Top-left part
                currentQuadX = position.x;
                currentQuadY = position.y;
                currentQuadWidth = 8;
                currentQuadHeight = 8;
            } else if (i==1 && j ==0) {
                // Top part
                currentQuadX = position.x + 8;
                currentQuadY = position.y;
                currentQuadWidth = width - 16;
                currentQuadHeight = 8;
            } else if (i==2 && j ==0) {
                // Top-right part
                currentQuadX = position.x + width - 8;
                currentQuadY = position.y;
                currentQuadWidth = 8;
                currentQuadHeight = 8;
            } else if (i==0 && j ==1) {
                // Left part
                currentQuadX = position.x;
                currentQuadY = position.y + 8;
                currentQuadWidth = 8;
                currentQuadHeight = height - 16;
            } else if (i==1 && j ==1) {
                // Center part
                currentQuadX = position.x + 8;
                currentQuadY = position.y + 8;
                currentQuadWidth = width - 16;
                currentQuadHeight = height - 16;
            } else if (i==2 && j==1) {
                // Right part
                currentQuadX = position.x + width - 8;
                currentQuadY = position.y + 8;
                currentQuadWidth = 8;
                currentQuadHeight = height - 16;
            } else if (i==0 && j==2) {
                // Bottom-left part
                currentQuadX = position.x;
                currentQuadY = position.y + height - 8;
                currentQuadWidth = 8;
                currentQuadHeight = 8;
            } else if (i==1 && j==2) {
                // Bottom part
                currentQuadX = position.x + 8;
                currentQuadY = position.y + height - 8;
                currentQuadWidth = width - 16;
                currentQuadHeight = 8;
            } else if (i==2 && j==2) {
                // Bottom-right part
                currentQuadX = position.x + width - 8;
                currentQuadY = position.y + height - 8;
                currentQuadWidth = 8;
                currentQuadHeight = 8;
            }

            quad[0].position = sf::Vector2f(currentQuadX, currentQuadY);
            quad[1].position = sf::Vector2f(currentQuadX+currentQuadWidth, currentQuadY);
            quad[2].position = sf::Vector2f(currentQuadX+currentQuadWidth, currentQuadY+currentQuadHeight);
            quad[3].position = sf::Vector2f(currentQuadX, currentQuadY+currentQuadHeight);

            quad[0].texCoords = sf::Vector2f(i * 8, j * 8);
            quad[1].texCoords = sf::Vector2f((i + 1) * 8, j * 8);
            quad[2].texCoords = sf::Vector2f((i + 1) * 8, (j + 1) * 8);
            quad[3].texCoords = sf::Vector2f(i * 8, (j + 1) * 8);
        }
    }
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.texture = &this->texture;
    target.draw(this->vertexArray, states);
}
