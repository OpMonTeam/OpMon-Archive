#ifndef PLAYERCTRL_HPP
#define PLAYERCTRL_HPP

namespace OpMon{
  namespace Controller{
    namespace PlayerCtrl{
      void checkMove(Player& player, sf::Event const& events);
      void move(Side direction, Player& player);
    }
  }
}

#endif
