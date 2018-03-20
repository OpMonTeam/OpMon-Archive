/*
  Dialog.hpp
  Author : BAKFR
  File under GNU GPL 3.0 licence
  http://opmon-game.ga
*/
#ifndef OPMON_DIALOG_CPP_HPP
#define OPMON_DIALOG_CPP_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

namespace OpMon {
    namespace View {

        class Dialog {
          private:
            /** array of all lines composing the dialog. */
            const sf::String *text;

            /** number of lines in `text`. */
            size_t sizeOfTxt;

            /** The 3 lines currently displayed. */
            sf::String txtEnCours[3] = {sf::String(" "), sf::String(" "), sf::String(" ")};

            /** index of the first line currently displayed on screen */
            unsigned int dialogNb = 0;

            /**
       * If true, the dialog is fully displayed by the text animation, and the
       * next step (on user action) would be to display the next lines.
       */
            bool changeDialog = false;

            /** index of line being displayed by the text animation. */
            unsigned int line = 0;
            /** index of the next character to display by the text animation. */
            unsigned int i = 0;

            /** Set to `true` when the entire dialog has been displayed. */
            bool is_dialog_over = false;

            void printText(sf::RenderTarget &frame, sf::String text[]);

            sf::Sound dialogPass;

          public:
            Dialog(const sf::String *text, size_t size);

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

            static sf::Sprite arrDial;
            static sf::Text dialogText[3];
            static sf::Sprite dialog;
        };
    } // namespace View
} // namespace OpMon
#endif //OPMON_DIALOG_CPP_HPP
