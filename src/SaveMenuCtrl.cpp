#include "SaveMenuCtrl.hpp"

namespace OpMon {

    SaveMenuCtrl::SaveMenuCtrl(GameData *data)
      : data(data)
      , view(this->data) {
    }

    GameStatus SaveMenuCtrl::checkEvent(sf::Event const &event) {
        auto &menu = view;
        switch(event.type) {
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Down) {
                if(menu.getCurrentState() == SaveMenuState::FILE_SELECTION) {
                    menu.moveCursorDown();
                } else if(menu.getCurrentState() == SaveMenuState::FILE_CONFIRMATION) {
                    menu.switchCursorConfirmationOption();
                }
            } else if(event.key.code == sf::Keyboard::Up) {
                if(menu.getCurrentState() == SaveMenuState::FILE_SELECTION) {
                    menu.moveCursorUp();
                } else if(menu.getCurrentState() == SaveMenuState::FILE_CONFIRMATION) {
                    menu.switchCursorConfirmationOption();
                }
            } else if(event.key.code == sf::Keyboard::Return) {
                if(menu.getCurrentState() == SaveMenuState::FILE_SELECTION) {
                    menu.setCurrentState(SaveMenuState::FILE_CONFIRMATION);
                } else if(menu.getCurrentState() == SaveMenuState::FILE_CONFIRMATION) {
                    menu.setCurrentState(SaveMenuState::FILE_SELECTION);
                }
            } else if(event.key.code == sf::Keyboard::BackSpace) {
                    return GameStatus::PREVIOUS;
            }
        }
        return GameStatus::CONTINUE;
    }

    GameStatus SaveMenuCtrl::update(sf::RenderTexture &frame) {
        GameStatus status = view.update();
        frame.draw(view);
        return status;
    }

} // namespace OpMon
