/*
Dialog.cpp
Author : BAKFR
Contributor : Cyrion
File under GNU GPL v3.0 license
*/
#include "Dialog.hpp"
#include "../../utils/defines.hpp"
#include "Window.hpp"
#include "../start/Core.hpp"

namespace OpMon {
    namespace View {

        Dialog::Dialog(const std::vector<sf::String> &text, Model::UiData *uidata)
          : text(text)
          , uidata(uidata) {

	    if(text.size() % 3 != 0){
		handleError("Error : string missing in Dialog. Aborting to avoid more issues.", true);
	    }
	    
            background.setTexture(uidata->getDialogBackground());
            arrDial.setTexture(uidata->getDialogArrow());

            background.setPosition(0, 512 - 150);
            arrDial.setPosition(512 - 75, 512 - 30);

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
            if(changeDialog == false) {
                currentTxt[0] = text[dialogNb];
                if(dialogNb + 2 < text.size()) {
                    currentTxt[1] = text[dialogNb + 1];
                    currentTxt[2] = text[dialogNb + 2];
                } else if(dialogNb + 1 < text.size()) {
                    currentTxt[1] = text[dialogNb + 1];
                    currentTxt[2] = sf::String(" ");
                } else {
                    currentTxt[1] = sf::String(" ");
                    currentTxt[2] = sf::String(" ");
                }

                changeDialog = true;
            } else if(dialogNb + 3 < text.size()) {
                uidata->getJukebox().playSound("dialog pass");
                line = 0;
                dialogNb += 3;
                i = 0;
                currentTxt[0] = sf::String(" ");
                currentTxt[1] = sf::String(" ");
                currentTxt[2] = sf::String(" ");
                changeDialog = false;
            } else {
                is_dialog_over = true;
            }
        }

        void Dialog::updateTextAnimation() {
            if(!changeDialog) {
                if(i < text[line + dialogNb].toUtf32().size()) {

                    if(currentTxt[line] == sf::String(" ")) {
                        currentTxt[line] = text[line + dialogNb].toUtf32()[i];
                    } else if(text[line + dialogNb].toUtf32()[i] > 10) {
                        currentTxt[line] += text[line + dialogNb].toUtf32()[i];
                    }
                    i++;
                } else {
                    if(line == 2) {
                        changeDialog = true;
                    } else {
                        line++;
                        i = 0;
                    }
                }
            }
        }

        void Dialog::draw(sf::RenderTarget &frame) {
            frame.draw(background);

            for(size_t itor = 0; itor < 3; itor++) {
                dialogText[itor].setString(currentTxt[itor].toUtf32());
                frame.draw(dialogText[itor]);
            }

            sf::Vector2f posArrow(512 - 75, 512 - 30);
            arrDial.move(0, 1);
            if(arrDial.getPosition().y - posArrow.y > 5) {
                arrDial.move(0, -6);
            }
            frame.draw(arrDial);
        }

        bool Dialog::isDialogOver() {
            return is_dialog_over;
        }

    } // namespace View
} // namespace OpMon
