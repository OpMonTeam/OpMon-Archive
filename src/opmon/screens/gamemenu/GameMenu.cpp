/*
  GameMenu.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/

#include "GameMenu.hpp"

#include <cstddef>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>

#include "src/utils/StringKeys.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/opmon/screens/gamemenu/GameMenuData.hpp"
#include "src/utils/defines.hpp"

namespace OpMon {

    GameMenu::GameMenu(GameMenuData &data)
        : data(data) {
        background.setTexture(data.getBackground());
        menuBg.setTexture(data.getMenuTexture());
        for(size_t i = 0; i < 6; i++) {
            selections[i].setTexture(data.getSelectionTexture(i));
            selections[i].setPosition(data.getSelectionPos(i));
            selectxt[i].setFont(data.getUiDataPtr()->getFont());
            selectxt[i].setCharacterSize(20);
            selectxt[i].setSfmlColor(sf::Color::White);
        }
        selectxt[0].setString(data.getUiDataPtr()->getString("gamemenu.save"));
        selectxt[1].setString(data.getUiDataPtr()->getString("gamemenu.id"));
        selectxt[2].setString(data.getUiDataPtr()->getString("gamemenu.bag"));
        selectxt[3].setString(data.getUiDataPtr()->getString("gamemenu.opmons"));
        selectxt[4].setString(data.getUiDataPtr()->getString("gamemenu.opdex"));
        selectxt[5].setString(data.getUiDataPtr()->getString("gamemenu.settings"));

        selectxt[0].setPosition(146, 143);
        selectxt[1].setPosition(260, 143);
        selectxt[2].setPosition(113, 225);
        selectxt[3].setPosition(314, 225);
        selectxt[4].setPosition(153, 310);
        selectxt[5].setPosition(262, 310);
    }

    void GameMenu::setCurPos(int newCurPos) {
        if(newCurPos < 6 && newCurPos >= 0) {
            curPos = newCurPos;
        }
    }

    void GameMenu::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
        frame.draw(background);
        frame.draw(menuBg);
        frame.draw(selections[curPos]);
        for(size_t i = 0; i < 6; i++) {
            frame.draw(selectxt[i]);
        }
    }

} // namespace OpMon
