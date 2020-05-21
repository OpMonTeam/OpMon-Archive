/*!
 * \file TextBox.hpp
 * \author Olivier Grech
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/String.hpp>
#include <SFML/System/Vector2.hpp>

namespace sf {
    class RenderTarget;
}  // namespace sf

namespace OpMon{

    /// \brief A class used to draw a UI box that can contain text or other elements.
    class TextBox : public sf::Drawable {
    private:
        sf::VertexArray vertexArray = sf::VertexArray(sf::Quads, 36);

        /// \brief The texture used to draw the box
        sf::Texture texture;

        /// \brief The position of the box
        sf::Vector2f position;

        /// \brief The width of the box
        uint32_t width;

        /// \brief The height of the box
        uint32_t height;

        /// \brief An eventual text to be displayed in the left side of the box
        std::vector<sf::Text> leftText;

        /// \brief An eventual text to be displayed in the right side of the box
        std::vector<sf::Text> rightText;

        /// \brief The font to display the text with
        sf::Font font;

        /// \brief Whether or not the box is active (i.e. if it's greyed out or not)
        bool active;

        sf::Color activeColor = sf::Color(255, 255, 255, 255);

        sf::Color inactiveColor = sf::Color(50, 50, 50, 200);

        /// \brief Draw the box on the given render texture
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        /**!
         * \brief Create a text box that can be later drawn on screen.
         * \param texture The texture used for the background of the box.
         * \param position The position fo the box.
         * \param width The width of the box.
         * \param height The height of the box.
         * \param linesCount The number of lines of text to display in the box.
         */
        TextBox(sf::Texture texture, sf::Vector2f position, uint32_t width, uint32_t height, uint32_t linesCount = 1);

        TextBox() = default;

        ~TextBox() = default;

        /**!
         * \brief Set the font used for the content of the text box.
         * \param font The font to use for the content of the text box.
         */
        void setFont(const sf::Font& font);

        /**!
         * \brief Set the string used for the content of the text in the left of the box.
         * \param content A string to use for the content.
         * \param line The index of the line for which the content will be set (start at 0).
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


}
