/*
StartScene.hpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "../../utils/OpString.hpp"
#include "../model/storage/StartSceneData.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "../start/Core.hpp"
#include "../start/i18n/ATranslatable.hpp"
#include "./Dialog.hpp"

namespace OpMon::View {

    class StartScene : public I18n::ATranslatable {
      public:
        explicit StartScene(Model::StartSceneData &data);
        ~StartScene() override = default;

        GameStatus operator()();
        void draw(sf::RenderTarget &frame);

        void play();
        static void pause();

        void initStrings();
        void onLangChanged() override;

        Dialog *getDialog() {
            return dialog.get();
        }

        int getPart() {
            return part;
        }

        sf::String &getpName() {
            return pName;
        }

        void delLoop1();

      private:
        sf::Sprite bg;
        sf::Sprite prof;

        int part = 0;

        Utils::OpString txtP1;

        std::unique_ptr<Dialog> dialog;

        sf::Text textDescs[4];
        sf::Sprite bgName;
        sf::Text nameField;

        sf::String pName;
        Model::StartSceneData &data;
    };

} // namespace OpMon::View

#endif // STARTSCENE_H
