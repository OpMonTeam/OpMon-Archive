#include "Dialog.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/Data.hpp"
#include "Window.hpp"

namespace OpMon {
    namespace View {

      Dialog::Dialog(const std::vector<sf::String> &text, UiData* uidata)
	: text(text), uidata(uidata) {

	background.setTexture(uidata->getDialogBackground());
	arrDial.setTexture(uidata->getDialogArrow());

            background.setPosition(0, 512 - 150);
            arrDial.setPosition(512 - 75, 512 - 30);

            int minusPos = 32;
            for(size_t i = 0; i < 3; ++i) {
	      dialogText[i].setFont(uidata->getFont());
                dialogText[i].setCharacterSize(FONT_SIZE_DEFAULT);
                dialogText[i].setColor(sf::Color::Black);

                dialogText[i].setPosition(25, background.getPosition().y + minusPos);
                minusPos += 32;
            }
        }

        void Dialog::pass() {
            if(changeDialog == false) {
                txtEnCours[0] = text[dialogNb];
                txtEnCours[1] = text[dialogNb + 1];
                txtEnCours[2] = text[dialogNb + 2];

                changeDialog = true;
            } else if(dialogNb + 3 < text.size()) {
	      uidata->getJukebox().playSound("dialog pass");
                line = 0;
                dialogNb += 3;
                i = 0;
                txtEnCours[0] = sf::String(" ");
                txtEnCours[1] = sf::String(" ");
                txtEnCours[2] = sf::String(" ");
                changeDialog = false;
            } else {
                is_dialog_over = true;
            }
        }

        void Dialog::updateTextAnimation() {
            if(!changeDialog) {
                if(i < text[line + dialogNb].toUtf32().size()) {

                    if(txtEnCours[line] == sf::String(" ")) {
                        txtEnCours[line] = text[line + dialogNb].toUtf32()[i];
                    } else if(text[line + dialogNb].toUtf32()[i] > 10) {
                        txtEnCours[line] += text[line + dialogNb].toUtf32()[i];
                    }
                    /*cout << (char) text[line + dialog].toUtf32()[i] << "|" << text[line + dialog].toUtf32()[i] << endl;
	    cout << "Caractère : " << i << " - Ligne : " << line << endl;
	    cout << "Taille : " << text[line + dialog].toUtf32().size() << endl;*/
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
                dialogText[itor].setString(txtEnCours[itor].toUtf32());
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
