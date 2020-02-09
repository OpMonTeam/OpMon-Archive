/*
Dialog.cpp
Author : BAKFR
Contributor : Cyrielle
File under GNU GPL v3.0 license
*/
#include "Dialog.hpp"
#include "../../../utils/StringKeys.hpp"
#include "../../../utils/defines.hpp"
#include "../../core/Core.hpp"
#include "Window.hpp"

namespace OpMon {
    namespace View {

        Dialog::Dialog(sf::String text, Model::UiData *uidata)
          : uidata(uidata) {
            this->text = Utils::StringKeys::autoNewLine(text);

            while(this->text.size() % 3 != 0) {
                this->text.push(sf::String(" "));
            }

            init();
        }

        Dialog::Dialog(std::queue<sf::String> text, Model::UiData *uidata)
          : text(text)
          , uidata(uidata) {
            if(this->text.size() % 3 != 0) {
                while(this->text.size() % 3 != 0) {
                    this->text.push(sf::String(" "));
                }
                if(this->text.size() % 3 != 0) {
                    handleError("Error : string missing in Dialog, even after trying to fix it.", true);
                }
            }

            init();
        }

        Dialog::Dialog(std::vector<sf::String> text, Model::UiData *uidata)
          : uidata(uidata) {

            for(sf::String str : text) {
                this->text.push(str);
            }

            if(this->text.size() % 3 != 0) {
                while(this->text.size() % 3 != 0) {
                    this->text.push(sf::String(" "));
                }
                if(this->text.size() % 3 != 0) {
                    handleError("Error : string missing in Dialog, even after trying to fix it.", true);
                }
            }

            init();
        }

        void Dialog::init() {
            background.setTexture(uidata->getDialogBackground());
            arrDial.setTexture(uidata->getDialogArrow());

            background.setPosition(0, 512 - 150);
            arrDial.setPosition(512 - 40, 512 - 40);
            arrDial.setScale(2, 2);

            int minusPos = 32;
            for(size_t i = 0; i < 3; ++i) {
                dialogText[i].setFont(uidata->getFont());
                dialogText[i].setCharacterSize(FONT_SIZE_DEFAULT);
                dialogText[i].setSfmlColor(sf::Color::Black);

                dialogText[i].setPosition(25, background.getPosition().y + minusPos);
                minusPos += 32;
            }
        }

        void Dialog::pass() {
            /* If the dialog is not completely displayed, display the dialog when pressing space */
            if(changeDialog == false) {
                for(unsigned int p = line; p < 3; p++) {
                    currentTxt[p] = text.front();
                    text.pop();
                }
                changeDialog = true;
                /* If the dialog is completely displayed, pass to the next dialog when pressing space, if there is one */
            } else if(text.size() > 0) {
                uidata->getJukebox().playSound("dialog pass");
                line = 0;
                i = 0;
                currentTxt[0] = sf::String(" ");
                currentTxt[1] = sf::String(" ");
                currentTxt[2] = sf::String(" ");
                changeDialog = false;
            } else { //If there is no more dialogs
                is_dialog_over = true;
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
                dialogText[itor].setString(currentTxt[itor].toUtf32());
            }
            sf::Vector2f posArrow(512 - 40, 512 - 40);
            arrDial.move(0, 0.33f);
            if(arrDial.getPosition().y - posArrow.y > 5) {
                arrDial.move(0, -6);
            }
        }

        void Dialog::draw(sf::RenderTarget &target, sf::RenderStates states) const {
            if(backgroundVisible) {
                target.draw(background);
                {
                    for(size_t itor = 0; itor < 3; itor++) {
                        target.draw(dialogText[itor]);
                    }

                    if(text.size() > 0 && changeDialog)
                        target.draw(arrDial);
                }
            }
        }

        bool Dialog::isDialogOver() {
            return is_dialog_over;
        }

        void Dialog::setBackgroundVisible(bool visible) {
            backgroundVisible = visible;
        }

    } // namespace View
} // namespace OpMon
