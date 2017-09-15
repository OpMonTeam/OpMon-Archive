
#ifndef OPMON_DIALOG_CPP_HPP
#define OPMON_DIALOG_CPP_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "MainFrame.hpp"


/**
 * Move forward in a dialog, in response to an event like a space key pressed.
 *
 * If the text animation is ongoing, display the 3 lines from the `dialog` index,
 * wait 50ms, then mark the text animation has over.
 * If there is no text animation, and there still remains lines to display, play a sound
 * (dialogPass) then reset the animation variables.
 * If there is no more line to display, the dialog is over, we go to the next
 * phase.
 *
 * @param varname (sf::String[] or std::vector<sf::String>): the full dialog
 * @param changeDialog  `true` if there is no ongoing text animation.
 * @param txtEnCours    the 3 lines currently displayed
 * @param dialog        index of the first line to be displayed on screen
 * @param sizeOfTxt     number of dialog lines in `varname`
 * @param line          current line of the text animation
 * @param i             next character to be displayed by the text animation.
 * @param phase         reference incremented by 1 when the dialog is over.
 */
void dialogPass(const sf::String varname[], bool &changeDialog,
                 sf::String txtEnCours[3], unsigned int &dialog, int sizeOfTxt,
                 unsigned int &line, unsigned int &i, int &phase);

#endif //OPMON_DIALOG_CPP_HPP
