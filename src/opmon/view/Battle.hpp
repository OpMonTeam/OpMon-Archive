#pragma once


#include "../model/objects/Turn.hpp"
#include "../start/Core.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
#include <map>

namespace OpMon{
  
  namespace View{
       
    class Battle {
    private:
      sf::Sprite atk;
      sf::Sprite def;

      int cursorPos;
      std::map<std::string, std::vector<sf::Vector2f> > cursorsList;
      
      bool turnLaunched = false;
    public:
      GameStatus operator()(Model::Turn atk, Model::Turn def);//Sets turnLaunched to true
      GameStatus operator()(Model::Turn* atkTurn);

      void moveCur(Model::Side where);
      
    };

  }
}
