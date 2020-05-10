/*!
 * \file IntroScene.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 */
#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "IntroSceneData.hpp"
#include "src/utils/i18n/ATranslatable.hpp"
#include "src/opmon/view/ui/Dialog.hpp"
#include "src/opmon/core/GameStatus.hpp"

namespace sf {
class RenderTarget;
}  // namespace sf

namespace OpMon {
class IntroSceneData;

    /*!
     * \brief View managing the introduction scene.
     * \todo Change name to IntroScene.
     */
    class IntroScene : public Utils::I18n::ATranslatable, public sf::Drawable {
    public:
        IntroScene(IntroSceneData &data);
        ~IntroScene() override = default;

        /*!
         * \brief Updates the screen.
         */
        GameStatus update();
        /*!
         * \brief Draws the screen.
         */
        void draw(sf::RenderTarget &frame, sf::RenderStates states) const;

        void play();
        void pause();

        /*!
         * \brief Retreives the strings from the language files.
         */
        void initStrings();
        void onLangChanged() override;

        Ui::Dialog *getDialog() {
            return dialog.get();
        }

        /*!
         * \brief Returns IntroScene::part
         */
        int getPart() {
            return part;
        }

        /*!
         * \brief Returns the entered player name.
         */
        sf::String &getpName() {
            return pName;
        }

        /*!
         * \brief Deletes the data used for the name input screen.
         */
        void delLoop1();

    private:
        sf::Sprite bg;
        sf::Sprite prof;

        /*!
         * \brief Indicates the part the introduction scene is currently playing.
         *
         * - The first part (part 0) is a dialog introducing the professor.
         * - The second part (part 1) is the name input screen.
         * - The third part (part 2) is an another dialog with the professor.
         * Any other value than 0,1 or 2 for this variable is invalid.
         */
        int part = 0;

        /*!
         * \brief Contains the dialog with the professor in the third part.
         * \todo Change the name to txtP2
         */
        Utils::OpString txtP1;

        std::unique_ptr<Ui::Dialog> dialog;

        /*!
         * \brief The texts shown during the name input screen.
         */
        sf::Text textDesc;
        sf::Sprite bgName;
        sf::Text nameField;

        /*!
         * \brief The player's entered name.
         */
        sf::String pName;
        IntroSceneData &data;
    };

} // namespace OpMon

#endif // STARTSCENE_H
