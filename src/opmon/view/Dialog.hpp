/*!
 * \file Dialog.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \copyright GNU GPL 3.0
*/

#pragma once

#include "../model/storage/UiData.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ui/TextBox.hpp"
#include <queue>
#include <string>

namespace OpMon {
    namespace View {

        class Dialog : public sf::Drawable {
          private:
            TextBox *dialogBox;

            /*!
             * \brief Height of a dialog box.
             */
            uint32_t dialogBoxHeight;

            /*!
             * \brief Width of a dialog box.
             */
            uint32_t dialogBoxWidth;

            /*!
             * \brief Array of all lines composing the dialog.
             */
            std::queue<sf::String> text;

            /*!
             * \brief The 3 lines currently displayed.
             */
            sf::String currentTxt[2] = {sf::String(" "), sf::String(" ")};

            /*!
             * \brief Checks if the dialog box is full.
             * \details If `true`, the dialog is fully displayed by the text animation, and the
             * next step (on user action) would be to display the next lines.
            */
            bool changeDialog = false;

            /*!
             * \brief Number of completely displayed lines.
             */
            uint32_t line = 0;

            /*!
             * \brief Index of the next character to display by the text animation.
             */
            uint32_t i = 0;

            /*!
             * \brief Set to `true` when the entire dialog has been displayed.
             */
            bool dialogOver = false;

            /*!
             * \brief The sound played when a dialog is passed.
             */
            sf::Sound dialogPass;

            Model::UiData *uidata;

            sf::Sprite arrDial;

            void init();

          public:
            /*!
             * \brief Initises a dialog with a queue of texts to print.
             * \param text A queue of texts. One element = one line.
             */
            Dialog(std::queue<sf::String> text, Model::UiData *uidata);
            /*!
             * \brief Initialises a dialog.
             * \param text The text of the dialog.
             */
            Dialog(sf::String text, Model::UiData *uidata);

            /*!
             * \brief Move forward in a dialog, in response to an event like a space key pressed.
             *
             * If the current dialog lines aren't fully displayed (text animation
             * ongoing), terminate the animation, wait 50ms, then ask for a dialog change.
             * If the animation is over, and there still remaining lines to display,
             * play a sound (dialogPass) then pass to the next lines.
             * If there is no more line to display, the dialog is over.
             */
            void pass();

            /*!
             * \brief Display the dialog character by character until the 3 lines are fully displayed.
             */
            void updateTextAnimation();

            /*!
             * \brief Draw the dialog on the main frame.
             */
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

            /*!
             * \return `true` is the entire dialog has been displayed; `false` otherwise.
             */
            bool isDialogOver();
        };
    } // namespace View
} // namespace OpMon
