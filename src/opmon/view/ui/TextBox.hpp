#pragma once

#include <SFML/Graphics.hpp>

/// A class used to draw a UI box that can contain text or other elements.
class TextBox : public sf::Drawable {
  private:
    sf::VertexArray vertexArray = sf::VertexArray(sf::Quads, 36);

    // The texture used to draw the box
    sf::Texture texture;

    // The width of the box
    int width;

    // The height of the box
    int height;

    // An eventual text to be displayed in the box
    sf::Text text;

    // The font to display the text with
    sf::Font font;

    // The position of the box
    sf::Vector2f position;

    // Draw the box on the given render texture
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  public:
    // Create a box with the given texture, position, widht and height that can be later drawn on screen
    TextBox(sf::Texture texture, const sf::Font &font, sf::Vector2f position, int width, int height);

    ~TextBox() = default;

    void setContent(std::string);
};
