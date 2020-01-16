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

    // Some default values for the text
    sf::Vector2f textPosition(position.x + 24, position.y + 24);
    text.setPosition(textPosition);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(16);

    // Size of one of the nine parts of the text box (assuming its a square)
    int partSize = 16;

    for(unsigned int i = 0; i < 3; ++i) {
        for(unsigned int j = 0; j < 3; ++j) {
            sf::Vertex *quad = &this->vertexArray[(i * 3 + j) * 4];

            int currentQuadX = 0;
            int currentQuadY = 0;
            int currentQuadWidth = 0;
            int currentQuadHeight = 0;

            if(i == 0 && j == 0) {
                // Top-left part
                currentQuadX = position.x;
                currentQuadY = position.y;
                currentQuadWidth = partSize;
                currentQuadHeight = partSize;
            } else if(i == 1 && j == 0) {
                // Top part
                currentQuadX = position.x + partSize;
                currentQuadY = position.y;
                currentQuadWidth = width - (partSize * 2);
                currentQuadHeight = partSize;
            } else if(i == 2 && j == 0) {
                // Top-right part
                currentQuadX = position.x + width - partSize;
                currentQuadY = position.y;
                currentQuadWidth = partSize;
                currentQuadHeight = partSize;
            } else if(i == 0 && j == 1) {
                // Left part
                currentQuadX = position.x;
                currentQuadY = position.y + partSize;
                currentQuadWidth = partSize;
                currentQuadHeight = height - (partSize * 2);
            } else if(i == 1 && j == 1) {
                // Center part
                currentQuadX = position.x + partSize;
                currentQuadY = position.y + partSize;
                currentQuadWidth = width - (partSize * 2);
                currentQuadHeight = height - (partSize * 2);
            } else if(i == 2 && j == 1) {
                // Right part
                currentQuadX = position.x + width - partSize;
                currentQuadY = position.y + partSize;
                currentQuadWidth = partSize;
                currentQuadHeight = height - (partSize * 2);
            } else if(i == 0 && j == 2) {
                // Bottom-left part
                currentQuadX = position.x;
                currentQuadY = position.y + height - partSize;
                currentQuadWidth = partSize;
                currentQuadHeight = partSize;
            } else if(i == 1 && j == 2) {
                // Bottom part
                currentQuadX = position.x + partSize;
                currentQuadY = position.y + height - partSize;
                currentQuadWidth = width - (partSize * 2);
                currentQuadHeight = partSize;
            } else if(i == 2 && j == 2) {
                // Bottom-right part
                currentQuadX = position.x + width - partSize;
                currentQuadY = position.y + height - partSize;
                currentQuadWidth = partSize;
                currentQuadHeight = partSize;
            }

            quad[0].position = sf::Vector2f(currentQuadX, currentQuadY);
            quad[1].position = sf::Vector2f(currentQuadX + currentQuadWidth, currentQuadY);
            quad[2].position = sf::Vector2f(currentQuadX + currentQuadWidth, currentQuadY + currentQuadHeight);
            quad[3].position = sf::Vector2f(currentQuadX, currentQuadY + currentQuadHeight);

            quad[0].texCoords = sf::Vector2f(i * partSize, j * partSize);
            quad[1].texCoords = sf::Vector2f((i + 1) * partSize, j * partSize);
            quad[2].texCoords = sf::Vector2f((i + 1) * partSize, (j + 1) * partSize);
            quad[3].texCoords = sf::Vector2f(i * partSize, (j + 1) * partSize);
        }
    }
}

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.texture = &this->texture;
    target.draw(this->vertexArray, states);
    target.draw(this->text, states);
}

void TextBox::setFont(const sf::Font &font) {
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setCharacterSize(16);
}

void TextBox::setContent(const std::string &content) {
    text.setString(content);
}

void TextBox::setActive(bool active) {

    for(unsigned int i = 0; i < 3; ++i) {
        for(unsigned int j = 0; j < 3; ++j) {
            sf::Vertex *quad = &this->vertexArray[(i * 3 + j) * 4];

            if(active) {
                quad[0].color = activeColor;
                quad[1].color = activeColor;
                quad[2].color = activeColor;
                quad[3].color = activeColor;
            } else {
                quad[0].color = inactiveColor;
                quad[1].color = inactiveColor;
                quad[2].color = inactiveColor;
                quad[3].color = inactiveColor;
            }
        }
    }
}
