#ifndef OVERWORLDCTRL_HPP
#define OVERWORLDCTRL_HPP

#include <SFML/Window/Event.hpp>

#include "../start/Core.hpp"
#include "../view/Overworld.hpp"
#include "../model/sysObjects/Player.hpp"
#include "AGameScreen.hpp"

namespace OpMon{
  namespace Controller{

    class OverworldCtrl : public AGameScreen{
    private:
      View::Overworld &view;
      Model::Player &player;
    public:
      OverworldCtrl(Model::Player &player);
      virtual GameStatus checkEvent(sf::Event const &event);
      GameStatus checkEventsDialog(sf::Event const& events, View::Overworld& overworld);
      GameStatus checkEventsNoDialog(sf::Event const& events, Model::Player& player);
      virtual GameStatus update();
    };

  }
}

#endif
