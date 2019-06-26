/*
  Dialog.hpp
  Author : BAKFR
  Contributor : Cyriel
  File under GNU GPL 3.0 licence
*/
#ifndef OPMON_DIALOG_CPP_HPP
#define OPMON_DIALOG_CPP_HPP

#include "../model/storage/UiData.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <queue>

namespace OpMon {
    namespace View {

        class Dialog {
          private:
            /** array of all lines composing the dialog. */
            std::queue<sf::String> text;

            /** The 3 lines currently displayed. */
            sf::String currentTxt[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};

            /**
             * If true, the dialog is fully displayed by the text animation, and the
             * next step (on user action) would be to display the next lines.
            */
            bool changeDialog = false;

            /** Number of completely displayed lines. */
            unsigned int line = 0;
            /** index of the next character to display by the text animation. */
            unsigned int i = 0;

            /** Set to `true` when the entire dialog has been displayed. */
            bool is_dialog_over = false;

            sf::Sound dialogPass;

            Model::UiData *uidata;

            bool backgroundVisible = true;

          public:
            OP_DEPRECATED Dialog(std::vector<sf::String> text, Model::UiData *uidata);
            Dialog(std::queue<sf::String> text, Model::UiData *uidata);
            Dialog(sf::String text, Model::UiData *uidata);

            /**
       * Move forward in a dialog, in response to an event like a space key pressed.
       *
       * If the current dialog lines aren't fully displayed (text animation
       * ongoing), terminate the animation, wait 50ms, then ask for a dialog change.
       * If the animation is over, and there still remaining lines to display,
       * play a sound (dialogPass) then pass to the next lines.
       * If there is no more line to display, the dialog is over.
       */
            void pass();

            /**
       * Display the dialog character by character until the 3 lines are fully displayed.
       */
            void updateTextAnimation();

            /**
       * Draw the dialog on the main frame.
       */
            void draw(sf::RenderTarget &frame);

            /**
       * @return `true` is the entire dialog has been displayed; `false` otherwise.
       */
            bool isDialogOver();

            /**
				Set the background visible or invisible, used in screens using other dialog boxes.
			*/
            void setBackgroundVisible(bool visible);

            sf::Sprite arrDial;
            sf::Text dialogText[3];
            sf::Sprite background;
        };
    } // namespace View
} // namespace OpMon
#endif //OPMON_DIALOG_CPP_HPP
