/*
OverworldCtrl.hpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../model/sysObjects/Player.hpp"
#include "../start/Core.hpp"
#include "../view/Overworld.hpp"
#include "AGameScreen.hpp"
#include "EventsCtrl.hpp"

namespace OpMon::Controller {

    class OverworldCtrl : public AGameScreen {
      private:
        Model::OverworldData data;

        View::Overworld view;
        Model::Player &player;

        int loadNext = 0;

        sf::Texture screenTexture;

      public:
        OverworldCtrl(Model::Player &player, Model::UiData *uidata);

        GameStatus checkEvent(sf::Event const &event) override;
        GameStatus checkEventsDialog(sf::Event const &events, View::Overworld &overworld);
        GameStatus checkEventsNoDialog(sf::Event const &events, Model::Player &player);
        GameStatus update(sf::RenderTexture &frame) override;

        void loadNextScreen() override;
        void suspend() override;
        void resume() override;
    };

} // namespace OpMon::Controller

#endif
