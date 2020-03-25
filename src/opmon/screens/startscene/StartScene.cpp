/*
  StartScene.cpp
  Author : Cyrielle
  Contributors : BAKFR, JonnyPtn, torq, Navet56
  File under GNU GPL v3.0 license
*/
#include "StartScene.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "src/utils/OpString.hpp"
#include "src/utils/StringKeys.hpp"
#include "src/utils/defines.hpp"
#include "src/opmon/view/ui/Dialog.hpp"
#include "src/opmon/core/Player.hpp"
#include "src/opmon/core/UiData.hpp"
#include "StartSceneData.hpp"
#include "src/opmon/view/ui/Jukebox.hpp"

namespace OpMon {

    void StartScene::initStrings() {

        txtP1 = Utils::OpString(stringkeys, "prof.dialog.start.2", {data.getPlayer().getNameP()});

        textDesc.setString(data.getUiDataPtr()->getString("nameEntry.desc"));
    }

    StartScene::StartScene(StartSceneData &data)
        : data(data) {
        initStrings();
        textDesc.setPosition(310, 450);
        bg.setTexture(data.getBackground());
        prof.setTexture(data.getProf());
        bgName.setTexture(data.getNameBg());
        bgName.setPosition(0, 0);

        bg.setPosition(0, 0);
        sf::FloatRect backgroundGlobalBounds = bg.getGlobalBounds();
        float backgroundWidth = backgroundGlobalBounds.width;
        float backgroundHeight = backgroundGlobalBounds.height;
        float backgroundScaleX = (float)Ui::Window::getBaseWindowWidth()/backgroundWidth;
        float backgroundScaleY = (float)Ui::Window::getBaseWindowHeight()/backgroundHeight;
        bg.setScale(sf::Vector2f(backgroundScaleX, backgroundScaleY));

        // Calculate professor sprite position
        sf::FloatRect professorGlobalBounds = prof.getGlobalBounds();
        float professorWidth = professorGlobalBounds.width;
        float professorHeight = professorGlobalBounds.height;
        float professorX = (Ui::Window::getBaseWindowWidth() - professorWidth)/2 - 20;
        float professorY = (Ui::Window::getBaseWindowHeight() - professorHeight)/2 - 26;
        prof.setPosition(professorX, professorY);
        prof.setScale(1.5, 1.5);

        textDesc.setCharacterSize(FONT_SIZE_DEFAULT);
        textDesc.setSfmlColor(sf::Color::White);
        textDesc.setFont(data.getUiDataPtr()->getFont());

        nameField.setSfmlColor(sf::Color::Black);
        nameField.setFont(data.getUiDataPtr()->getFont());
        nameField.setPosition(310, 255);

        data.getUiDataPtr()->getJukebox().play("Start");

        // Init loop 0
        dialog = std::make_unique<Ui::Dialog>(data.getUiDataPtr()->getString("prof.dialog.start.1"), data.getUiDataPtr());
    }

    void StartScene::onLangChanged() {
        initStrings();
    }

    GameStatus StartScene::update() {
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
            nameField.setString(pName);
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
            throw Utils::UnexpectedValueException(std::to_string(part), "an integer in [0,2] in StartScene::update()");
        }
        return GameStatus::CONTINUE;
    }

    void StartScene::delLoop1() {
        part++;
        // Init loop 2
        dialog = std::make_unique<Ui::Dialog>(txtP1.getString(data.getUiDataPtr()->getStringKeys()), data.getUiDataPtr());
    }

    void StartScene::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
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
            frame.draw(textDesc);
            frame.draw(nameField);
            break;

        default:
            throw Utils::UnexpectedValueException(std::to_string(part), "an integer in [0,2] in StartScene::draw()");
        }
    }

    void StartScene::play() {
        data.getUiDataPtr()->getJukebox().play("Start");
    }

    void StartScene::pause() {
    }
} // namespace OpMon
