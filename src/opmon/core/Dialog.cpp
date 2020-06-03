/*
Dialog.cpp
Author : BAKFR
Contributor : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Dialog.hpp"

#include "TextBox.hpp"
#include "Window.hpp"
#include "src/utils/StringKeys.hpp"
#include "src/utils/defines.hpp"

namespace OpMon {
    namespace Ui {

        void Dialog::init() {
            unsigned int DIALOG_BOX_WIDTH = 504;
            unsigned int DIALOG_BOX_HEIGHT = 100;

            float dialogBoxX =
                (gamedata->getWindowWidth() - DIALOG_BOX_WIDTH) / 2;
            float dialogBoxY =
                gamedata->getWindowHeight() - DIALOG_BOX_HEIGHT - 4;

            sf::Vector2f dialogBoxPosition(dialogBoxX, dialogBoxY);
            dialogBox = new TextBox(gamedata->getMenuFrame(), dialogBoxPosition,
                                    DIALOG_BOX_WIDTH, DIALOG_BOX_HEIGHT, 3);
            dialogBox->setFont(gamedata->getFont());

            // Create the arrow that appears to prompt the player to press the
            // action key
            arrDial.setTexture(gamedata->getDialogArrow());
            arrDialX = dialogBoxX + DIALOG_BOX_WIDTH - 32;
            arrDialY = dialogBoxY + DIALOG_BOX_HEIGHT - 32;
            arrDial.setPosition(arrDialX, arrDialY);
            arrDial.setScale(2, 2);
        }

        Dialog::Dialog(std::queue<sf::String> text, GameData *gamedata)
            : text(text), gamedata(gamedata) {
            if(this->text.size() % 2 != 0) {
                while(this->text.size() % 2 != 0) {
                    this->text.push(sf::String(" "));
                }
                if(this->text.size() % 2 != 0) {
                    throw std::runtime_error("String missing in Dialog, even "
                                             "after trying to fix it.");
                }
            }

            init();
        }

        Dialog::Dialog(sf::String text, GameData *gamedata)
            : gamedata(gamedata) {
            this->text = Utils::StringKeys::autoNewLine(
                text, gamedata->getFont(), 16, 456);

            while(this->text.size() % 2 != 0) {
                this->text.push(sf::String(" "));
            }

            init();
        }

        void Dialog::pass() {
            if(changeDialog == false) {
                // If the current lines are not completely displayed, display
                // them in full when pressing space
                for(uint32_t p = line; p < 2; p++) {
                    currentTxt[p] = text.front();
                    text.pop();
                }
                changeDialog = true;
            } else if(text.size() > 0) {
                // If the current lines are completely displayed, pass to the
                // next set of lines when pressing space (if there is one)
                gamedata->getJukebox().playSound("dialog pass");
                line = 0;
                i = 0;
                currentTxt[0] = sf::String(" ");
                currentTxt[1] = sf::String(" ");
                changeDialog = false;
            } else {
                // If there are no more lines to display
                dialogOver = true;
            }
        }

        void Dialog::updateTextAnimation() {
            if(!changeDialog) {
                if(i < text.front().toUtf32().size()) {
                    if(currentTxt[line] == sf::String(" ")) {
                        currentTxt[line] = text.front().toUtf32()[i];
                    } else if(text.front().toUtf32()[i] > 10) {
                        currentTxt[line] += text.front().toUtf32()[i];
                    }
                    i++;
                } else {
                    text.pop();
                    line++;
                    if(line == 2) {
                        changeDialog = true;
                    } else {
                        i = 0;
                    }
                }
            }
            for(size_t itor = 0; itor < 2; itor++) {
                dialogBox->setLeftContent(currentTxt[itor].toUtf32(), itor);
            }
            sf::Vector2f posArrow(arrDialX, arrDialY);
            arrDial.move(0, 0.33f);
            if(arrDial.getPosition().y - posArrow.y > 5) {
                arrDial.move(0, -6);
            }
        }

        void Dialog::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
            target.draw(*dialogBox);
            {
                if(text.size() > 0 && changeDialog)
                    target.draw(arrDial);
            }
        }

        bool Dialog::isDialogOver() { return dialogOver; }

    } // namespace Ui
} // namespace OpMon
