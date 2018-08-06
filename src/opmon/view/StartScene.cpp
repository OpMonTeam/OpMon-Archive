#include "StartScene.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/ResourceLoader.hpp"
#include "../model/sysObjects/Player.hpp"
#include "./Window.hpp"
#include "Dialog.hpp"

namespace OpMon {
    namespace View {

        void StartScene::initStrings() {
            auto kget = Utils::StringKeys::get;

            unsigned int it = 0;
            for(it = 0; it < 18; it++) {
                std::string actual;
                actual << std::string("prof.dialog.start.") << it + 1;
                txtP0.push_back(kget(actual));
            }
            it++;
            strName = Utils::OpString("prof.dialog.start.19", data.getPlayer().getNameP());
            txtP1.emplace_back(); // empty space replaced later by OpString 'strName'
            for(it = it; it < 27; it++) {
                std::string actual;
                actual << std::string("prof.dialog.start.") << it + 1;
                txtP1.push_back(kget(actual));
            }

            textDescs[0].setString(kget("nameEntry.med"));
            textDescs[1].setString(kget("nameEntry.top"));
            textDescs[2].setString(kget("nameEntry.indic.1"));
            textDescs[3].setString(kget("nameEntry.indic.2"));
        }

        StartScene::StartScene(Model::StartSceneData &data)
          : dialog(nullptr)
          , data(data) {
            initStrings();
            textDescs[1].setPosition(85, 25);
            textDescs[0].setPosition(155, 200);
            textDescs[2].setPosition(95, 375);
            textDescs[3].setPosition(95, 405);

            bg.setTexture(data.getBackground());
            prof.setTexture(data.getProf());
            bgName.setTexture(data.getNameBg());
            bgName.setPosition(0, 0);

            bg.setPosition(0, 0);
            prof.setPosition(205, 120);
            prof.setScale(1.5, 1.5);

            for(sf::Text &cellTxt : textDescs) {
                cellTxt.setCharacterSize(FONT_SIZE_DEFAULT);
                cellTxt.setFillColor(sf::Color::White);
                cellTxt.setFont(data.getUiDataPtr()->getFont());
            }

            nameField.setFont(data.getUiDataPtr()->getFont());
            nameField.setPosition(120, 300);

            data.getUiDataPtr()->getJukebox().play("Start");

            // Init loop 0
            dialog = new Dialog(txtP0, data.getUiDataPtr());
        }

        void StartScene::onLangChanged() {
            initStrings();
        }

        GameStatus StartScene::operator()() {
            switch(part) {
            case 0:
                if(!dialog->isDialogOver()) {
                    dialog->updateTextAnimation();
                } else {
                    // Init loop 1
                    delete(dialog);
                    dialog = nullptr;
                    part++;
                    return GameStatus::NEXT;
                }
                break;

            case 1:
                return GameStatus::CONTINUE; // Everything is handled by Ctrl

            case 2:
                if(!dialog->isDialogOver()) {
                    dialog->updateTextAnimation();
                } else {
                    part++;
                    return GameStatus::NEXT;
                }
                break;

            default:; // TODO: LOG
            }
            return GameStatus::CONTINUE;
        }

        void StartScene::delLoop1() {

            txtP1[0] = strName.getString();
            part++;

            // Init loop 2
            dialog = new Dialog(txtP1, data.getUiDataPtr());
        }

        void StartScene::draw(sf::RenderTarget &frame) {
            frame.clear(sf::Color::White);
            switch(part) {
            case 0:
            case 2:
                frame.draw(bg);
                frame.draw(prof);
                dialog->draw(frame);
                break;
            case 1:
                frame.draw(bgName);
                for(const sf::Text &desc : textDescs) {
                    frame.draw(desc);
                }
                nameField.setString(pName);
                frame.draw(nameField);
                break;

            default:; // TODO: log something !
            }
        }

        void StartScene::play() {
            data.getUiDataPtr()->getJukebox().play("Start");
        }

        void StartScene::pause() {
        }

        StartScene::~StartScene() {
            delete(dialog);
        }
    } // namespace View
} // namespace OpMon
