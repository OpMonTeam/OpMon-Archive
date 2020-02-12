#pragma once

#include <SFML/Graphics.hpp>

/// A class used to draw a UI box that can contain text or other elements.
class TextBox : public sf::Drawable {
  private:
    sf::VertexArray vertexArray = sf::VertexArray(sf::Quads, 36);

    // The texture used to draw the box
    sf::Texture texture;

    // The position of the box
    sf::Vector2f position;

    // The width of the box
    int width;

    // The height of the box
    int height;

    // An eventual text to be displayed in the left side of the box
    std::vector<sf::Text> leftText;

    // An eventual text to be displayed in the right side of the box
    std::vector<sf::Text> rightText;

    // The font to display the text with
    sf::Font font;

    bool active;

    sf::Color activeColor = sf::Color(255, 255, 255, 255);

    sf::Color inactiveColor = sf::Color(50, 50, 50, 200);

    // Draw the box on the given render texture
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  public:
    /**!
     * \brief Create a text box that can be later drawn on screen.
     * \param texture The texture used for the background of the box.
     * \param position The position fo the box.
     * \param width The width of the box.
     * \param height The height of the box.
     */
    TextBox(sf::Texture texture, sf::Vector2f position, int width, int height, uint32_t linesCount = 1);

    ~TextBox() = default;

    /**!
     * \brief Set the font used for the content of the text box.
     * \param font The font to use for the content of the text box.
     */
    void setFont(const sf::Font& font);

    /**!
     * \brief Set the string used for the content of the text in the left of the box.
     * \param content A string to use for the content.
     */
    void setLeftContent(const sf::String& content, uint32_t line = 0);

    /**!
     * \brief Set the string used for the content of the text in the right of the box.
     * \param content A string to use for the content.
     */
    void setRightContent(const sf::String& content);

    /**!
     * \brief Set the box as inactive or active (i.e. greyed out or not).
     * \param active Wheter the box should be set active (for true) or inactive (for false).
     */
    void setActive(bool active);
};
