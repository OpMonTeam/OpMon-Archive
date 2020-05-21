/*!
 * \file Window.hpp
 * \author Cyrielle
 * \author BAKFR
 * \copyright GNU GPL v3.0
 */
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "OptionsSave.hpp"


namespace OpMon {
    namespace Ui {
        /*!
         * \brief Manages and stores the objects related to the game window.
         */
        class Window {
          private:
            /*!
             * \brief The game window.
             */
            sf::RenderWindow window;
            /*!
             * \brief The frame where everything will be printed.
             * \details A sf::RenderTexture is used to allow the game to do final modifications on the entire screen before showing it.
             */
            sf::RenderTexture frame;
            /*!
             * \brief The sprite shown on Window::window containing the texture of Window::frame
             */
            sf::Sprite sprite;
            bool fullScreen = false;

          public:
            sf::RenderTexture &getFrame() { return frame; }
            sf::RenderWindow &getWindow() { return window; }
            /*!
             * \brief Closes the window.
             */
            void close();
            /*!
             * \brief Opens the window.
             */
            void open(Utils::OptionsSave &options);
            /*!
             * \brief Updates the Window::window with RenderTexture::frame
             */
            void refresh();
            /*!
             * \brief Shortcut calling close() and open().
             */
            void reboot(Utils::OptionsSave &options);
            /*!
             * \brief Resizes Window::frame to fit with the size of Window::window.
             */
            void updateView();
            static int getBaseWindowWidth();
            static int getBaseWindowHeight();
        };
    } // namespace Ui
} // namespace OpMon

#endif
