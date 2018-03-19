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
      //The OpMons' sprites (The textures IDs will be in the OpMon object)
      sf::Sprite atk;
      sf::Sprite def;

      //The cursor's position for the choices
      int cursorPos;
      //The list of cursor's positions in pixel, depending of the situation
      std::map<std::string, std::vector<sf::Vector2f> > cursorsList;
      //True if the turn have been calculated
      bool turnLaunched = false;
    public:
      //Used to print the turn
      GameStatus operator()(Model::Turn const& atk, Model::Turn const& def);//Sets turnLaunched to true
      //Used to print the choices
      GameStatus operator()(Model::Turn* atkTurn);
      //Moves the cursor
      void moveCur(Model::Side where);
      
    };

  }
}
