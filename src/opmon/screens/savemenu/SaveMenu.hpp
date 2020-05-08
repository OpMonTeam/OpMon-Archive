#pragma once

#include "SaveMenuData.hpp"

#include "src/opmon/core/GameStatus.hpp"
#include "src/opmon/view/ui/TextBox.hpp"
#include "src/utils/i18n/ATranslatable.hpp"

namespace OpMon {

    /*!
     * \brief State of the save menu, i.e. whether the player is currently
     * selecting a file or confirming the selected file.
     */
    enum class SaveMenuState { FILE_SELECTION,
                               FILE_CONFIRMATION };

    /*!
     * \brief Confirmation options when the player has selected a file.
     */
    enum class SaveMenuConfirmationOption { YES,
                                            NO };

    class SaveMenu : public Utils::I18n::ATranslatable, public sf::Drawable {
      public:
        SaveMenu(SaveMenuData &data);

        ~SaveMenu() = default;

        void onLangChanged() override;

        void draw(sf::RenderTarget &frame, sf::RenderStates states) const;

        GameStatus update();

        GameStatus fileConfirmationLoop();

        GameStatus fileSelectionloop();

        SaveMenuState getCurrentState();

        void setCurrentState(SaveMenuState state);

        void moveCursorDown();

        void moveCursorUp();

        void switchCursorConfirmationOption();

      private:
        SaveMenuData &data;

        /*!
         * \brief Text box displayed at the top of the save menu to indicate if the context is
         * saving or loading.
         */
        TextBox hintTextBox;

        /*!
         * \brief Text boxes representing save files displayed in the save menu.
         *
         */
        std::vector<TextBox> saveFilesTextBoxes;

        /*!
         * \brief Text box displayed at the bottom of the save menu to ask the user to confirm the
         * selected file.
         *
         */
        TextBox confirmationTextBox;

        /*!
         * \brief Text box displaying the "yes" answer for confirmation of the selected file.
         *
         */
        TextBox yesTextBox;

        /*!
         * \brief Text box displaying the "no" answer for confirmation of the selected file.
         *
         */
        TextBox noTextBox;

        int currentCursorPosition = 0;

        SaveMenuConfirmationOption currentCursorConfirmationOption = SaveMenuConfirmationOption::NO;

        SaveMenuState currentState = SaveMenuState::FILE_SELECTION;
    };

} // namespace OpMon
