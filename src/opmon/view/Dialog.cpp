/*
Dialog.cpp
Author : BAKFR
Contributor : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Dialog.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../start/Core.hpp"
#include "Window.hpp"
#include "ui/TextBox.hpp"

namespace OpMon {
    namespace View {

        void Dialog::init() {
            // Create the text box in which the dialogue will be displayed
            dialogBoxHeight = 112;
            dialogBoxWidth = uidata->getWindowWidth() - 8;
            sf::Vector2f position(4, uidata->getWindowHeight() - dialogBoxHeight - 4);
            dialogBox = new TextBox(uidata->getMenuFrame(), position, dialogBoxWidth, dialogBoxHeight, 3);
            dialogBox->setFont(uidata->getFont());

            // Create the arrow that appears to prompt the player to press the action key
            arrDial.setTexture(uidata->getDialogArrow());
            arrDial.setPosition(512 - 40, 512 - 40);
            arrDial.setScale(2, 2);
        }

        Dialog::Dialog(std::queue<sf::String> text, Model::UiData *uidata)
          : text(text)
          , uidata(uidata) {
            if(this->text.size() % 3 != 0) {
                while(this->text.size() % 3 != 0) {
                    this->text.push(sf::String(" "));
                }
                if(this->text.size() % 3 != 0) {
                    handleError("Error: string missing in Dialog, even after trying to fix it.", true);
                }
            }

            init();
        }

        Dialog::Dialog(sf::String text, Model::UiData *uidata)
          : uidata(uidata) {
            this->text = Utils::StringKeys::autoNewLine(text);

            while(this->text.size() % 3 != 0) {
                this->text.push(sf::String(" "));
            }

            init();
        }

        void Dialog::pass() {
            if(changeDialog == false) {
                // If the current lines are not completely displayed, display them in full when
                // pressing space
                for(uint32_t p = line; p < 3; p++) {
                    currentTxt[p] = text.front();
                    text.pop();
                }
                changeDialog = true;
            } else if(text.size() > 0) {
                // If the current lines are completely displayed, pass to the next set of lines when
                // pressing space (if there is one)
                uidata->getJukebox().playSound("dialog pass");
                line = 0;
                i = 0;
                currentTxt[0] = sf::String(" ");
                currentTxt[1] = sf::String(" ");
                currentTxt[2] = sf::String(" ");
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
                    if(line == 3) {
                        changeDialog = true;
                    } else {
                        i = 0;
                    }
                }
            }
            for(size_t itor = 0; itor < 3; itor++) {
                dialogBox->setLeftContent(currentTxt[itor].toUtf32(), itor);
            }
            sf::Vector2f posArrow(512 - 40, 512 - 40);
            arrDial.move(0, 0.33f);
            if(arrDial.getPosition().y - posArrow.y > 5) {
                arrDial.move(0, -6);
            }
        }

        void Dialog::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            target.draw(*dialogBox);
            {
                if(text.size() > 0 && changeDialog)
                    target.draw(arrDial);
            }
        }

        bool Dialog::isDialogOver() {
            return dialogOver;
        }

    } // namespace View
} // namespace OpMon
