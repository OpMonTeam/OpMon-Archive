/*
  StartScene.cpp
  Author : Cyrielle
  Contributors : BAKFR, JonnyPtn, torq, Navet56
  File under GNU GPL v3.0 license
*/
#include "StartScene.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../../utils/log.hpp"
#include "../core/system/ResourceLoader.hpp"
#include "ui/Window.hpp"
#include "ui/Dialog.hpp"

namespace OpMon {

    void StartScene::initStrings() {

        txtP1 = Utils::OpString("prof.dialog.start.2", {data.getPlayer().getNameP()});

        textDescs[0].setString(Utils::StringKeys::get("nameEntry.med"));
        textDescs[1].setString(Utils::StringKeys::get("nameEntry.top"));
        textDescs[2].setString(Utils::StringKeys::get("nameEntry.indic.1"));
        textDescs[3].setString(Utils::StringKeys::get("nameEntry.indic.2"));
    }

    StartScene::StartScene(StartSceneData &data)
        : data(data) {
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
            cellTxt.setSfmlColor(sf::Color::White);
            cellTxt.setFont(data.getUiDataPtr()->getFont());
        }

        nameField.setFont(data.getUiDataPtr()->getFont());
        nameField.setPosition(120, 300);

        data.getUiDataPtr()->getJukebox().play("Start");

        // Init loop 0
        dialog = std::make_unique<Ui::Dialog>(Utils::StringKeys::get("prof.dialog.start.1"), data.getUiDataPtr());
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
                dialog = nullptr;
                part++;
                return GameStatus::NEXT_NLS;
            }
            break;

        case 1:
            return GameStatus::CONTINUE; // Everything is handled by StartSceneCtrl

        case 2:
            if(!dialog->isDialogOver()) {
                dialog->updateTextAnimation();
            } else {
                part++;
                return GameStatus::NEXT;
            }
            break;

        default:
            handleError("Unknown part in StartScene::operator()", true);
        }
        return GameStatus::CONTINUE;
    }

    void StartScene::delLoop1() {
        part++;
        // Init loop 2
        dialog = std::make_unique<Ui::Dialog>(txtP1.getString(), data.getUiDataPtr());
    }

    void StartScene::draw(sf::RenderTarget &frame) {
        frame.clear(sf::Color::White);
        switch(part) {
        case 0:
        case 2:
            frame.draw(bg);
            frame.draw(prof);
            frame.draw(*dialog);
            break;
        case 1:
            frame.draw(bgName);
            for(const sf::Text &desc : textDescs) {
                frame.draw(desc);
            }
            nameField.setString(pName);
            frame.draw(nameField);
            break;

        default:
            handleError("Unknown part in StartScene::draw()", true);
        }
    }

    void StartScene::play() {
        data.getUiDataPtr()->getJukebox().play("Start");
    }

    void StartScene::pause() {
    }
} // namespace OpMon
