/*!
 * \file Dialog.hpp
 * \authors BAKFR
 * \authors Cyrielle
 * \copyright GNU GPL 3.0
*/
#ifndef OPMON_DIALOG_CPP_HPP
#define OPMON_DIALOG_CPP_HPP

#include "../../core/UiData.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <queue>
#include <string>

namespace OpMon {
    namespace Ui {

        class Dialog : public sf::Drawable {
          private:
            /*!
             * \brief Array of all lines composing the dialog.
             */
            std::queue<sf::String> text;

            /*!
             * \brief The 3 lines currently displayed.
             */
            sf::String currentTxt[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};

            /*!
             * \brief Checks if the dialog box is full.
             * \details If `true`, the dialog is fully displayed by the text animation, and the
             * next step (on user action) would be to display the next lines.
            */
            bool changeDialog = false;

            /*!
             * \brief Number of completely displayed lines.
             */
            unsigned int line = 0;
            /*!
             * \brief Index of the next character to display by the text animation.
             */
            unsigned int i = 0;

            /*!
             * \brief Set to `true` when the entire dialog has been displayed.
             */
            bool is_dialog_over = false;

            /*!
             * \brief The sound played when a dialog is passed.
             */
            sf::Sound dialogPass;

            UiData *uidata;

            bool backgroundVisible = true;

            void init();

            sf::Sprite arrDial;
            sf::Text dialogText[3];
            sf::Sprite background;

          public:
            /*!
             * \brief Initialises a dialog with an array of texts to print.
             * \param text An array of texts. One element = one line.
             * \deprecated Use std::queue instead of std::vector, or send one sf::String directly.
             */
            OP_DEPRECATED Dialog(std::vector<sf::String> text, UiData *uidata);
            /*!
             * \brief Initises a dialog with a queue of texts to print.
             * \param text A queue of texts. One element = one line.
             */
            Dialog(std::queue<sf::String> text, UiData *uidata);
            /*!
             * \brief Initialises a dialog.
             * \param text The text of the dialog.
             */
            Dialog(sf::String text, UiData *uidata);

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

            /*!
             * \brief Set the background visible or invisible, used in screens using other dialog boxes.
             */
            void setBackgroundVisible(bool visible);
        };
    } // namespace Ui
} // namespace OpMon
#endif //OPMON_DIALOG_CPP_HPP
