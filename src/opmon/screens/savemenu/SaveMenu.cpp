#include "SaveMenu.hpp"

#include "src/utils/log.hpp"
#include "src/opmon/core/GameData.hpp"
#include "src/opmon/view/ui/TextBox.hpp"

namespace OpMon {

    int SAVE_MENU_ITEM_WIDTH = 504;
    int SAVE_MENU_ITEM_PADDING = 4;

    SaveMenu::SaveMenu(SaveMenuData &data)
      : data(data) {
        float saveMenuItemX = (data.getGameDataPtr()->getWindowWidth() - SAVE_MENU_ITEM_WIDTH) / 2;

        sf::Vector2f hintTextBoxPosition(saveMenuItemX, SAVE_MENU_ITEM_PADDING);
        hintTextBox = TextBox(data.getGameDataPtr()->getMenuFrame(), hintTextBoxPosition, SAVE_MENU_ITEM_WIDTH, 64);
        hintTextBox.setFont(data.getGameDataPtr()->getFont());
        hintTextBox.setLeftContent("Select a file to save to:");

        for(int i = 0; i < 3; i++) {
            sf::Vector2f position(saveMenuItemX, 64 + (2 * SAVE_MENU_ITEM_PADDING) + i * (96 + SAVE_MENU_ITEM_PADDING));
            TextBox saveFileTextBox(data.getGameDataPtr()->getMenuFrame(), position, SAVE_MENU_ITEM_WIDTH, 96);
            saveFileTextBox.setFont(data.getGameDataPtr()->getFont());
            saveFileTextBox.setLeftContent("File " + std::to_string(i + 1));
            saveFilesTextBoxes.push_back(saveFileTextBox);
        }

        sf::Vector2f confirmationTextBoxPosition(saveMenuItemX, 64 + (2 * SAVE_MENU_ITEM_PADDING) + 3 * (96 + SAVE_MENU_ITEM_PADDING));
        float confirmationTextBoxHeight = 132;
        float confirmationTextBoxWidth = SAVE_MENU_ITEM_WIDTH - 128 - SAVE_MENU_ITEM_PADDING;
        confirmationTextBox = TextBox(data.getGameDataPtr()->getMenuFrame(), confirmationTextBoxPosition, confirmationTextBoxWidth, confirmationTextBoxHeight);
        confirmationTextBox.setFont(data.getGameDataPtr()->getFont());
        confirmationTextBox.setLeftContent("Are you sure?");

        float yesTextBoxX = saveMenuItemX + confirmationTextBoxWidth + SAVE_MENU_ITEM_PADDING;
        float yesTextBoxY = 64 + (2 * SAVE_MENU_ITEM_PADDING) + 3 * (96 + SAVE_MENU_ITEM_PADDING);
        sf::Vector2f yesTextBoxPosition(yesTextBoxX, yesTextBoxY);
        yesTextBox = TextBox(data.getGameDataPtr()->getMenuFrame(), yesTextBoxPosition, 128, 64);
        yesTextBox.setFont(data.getGameDataPtr()->getFont());
        yesTextBox.setLeftContent("Yes");

        float noTextBoxX = saveMenuItemX + confirmationTextBoxWidth + SAVE_MENU_ITEM_PADDING;
        float noTextBoxY = 64 + (3 * SAVE_MENU_ITEM_PADDING) + 3 * (96 + SAVE_MENU_ITEM_PADDING) + 64;
        sf::Vector2f noTextBoxPosition(noTextBoxX, noTextBoxY);
        noTextBox = TextBox(data.getGameDataPtr()->getMenuFrame(), noTextBoxPosition, 128, 64);
        noTextBox.setFont(data.getGameDataPtr()->getFont());
        noTextBox.setLeftContent("No");
    }

    void SaveMenu::onLangChanged() {
        // TODO: initialize strings for localization
    }

    void SaveMenu::draw(sf::RenderTarget &frame, sf::RenderStates states) const {
        frame.clear(sf::Color(74, 81, 148));
        frame.draw(hintTextBox);
        for(auto &saveFileTextBox : saveFilesTextBoxes) {
            frame.draw(saveFileTextBox);
        }

        if(currentState == SaveMenuState::FILE_CONFIRMATION) {
            frame.draw(confirmationTextBox);
            frame.draw(yesTextBox);
            frame.draw(noTextBox);
        }
    }

    GameStatus SaveMenu::update() {
        if(currentState == SaveMenuState::FILE_SELECTION) {
            return fileSelectionloop();
        } else {
            return fileConfirmationLoop();
        }
    }

    GameStatus SaveMenu::fileConfirmationLoop() {
        noTextBox.setActive(currentCursorConfirmationOption == SaveMenuConfirmationOption::NO);
        yesTextBox.setActive(currentCursorConfirmationOption == SaveMenuConfirmationOption::YES);

        return GameStatus::CONTINUE;
    }

    GameStatus SaveMenu::fileSelectionloop() {
        for(auto &saveFileTextBox : saveFilesTextBoxes) {
            saveFileTextBox.setActive(false);
        }
        saveFilesTextBoxes[currentCursorPosition].setActive(true);
        return GameStatus::CONTINUE;
    }

    SaveMenuState SaveMenu::getCurrentState() {
        return currentState;
    }

    void SaveMenu::setCurrentState(SaveMenuState state) {
        currentState = state;
    }

    void SaveMenu::moveCursorDown() {
        if(currentCursorPosition == 2) {
            currentCursorPosition = 0;
        } else {
            currentCursorPosition++;
        }
    }

    void SaveMenu::moveCursorUp() {
        if(currentCursorPosition == 0) {
            currentCursorPosition = 2;
        } else {
            currentCursorPosition--;
        }
    }

    void SaveMenu::switchCursorConfirmationOption() {
        if(currentCursorConfirmationOption == SaveMenuConfirmationOption::NO) {
            currentCursorConfirmationOption = SaveMenuConfirmationOption::YES;
        } else {
            currentCursorConfirmationOption = SaveMenuConfirmationOption::NO;
        }
    }

} // namespace OpMon
