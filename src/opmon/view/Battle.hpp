#pragma once


#include "../model/objects/Turn.hpp"
#include "../start/Core.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>

namespace OpMon{

  namespace Model{
    class OpTeam;
  }
  
  namespace View{
       
    class Battle {
    private:
      //The OpMons' sprites (The textures IDs will be in the OpMon object)
      sf::Sprite atk;
      sf::Sprite def;

      const Model::OpTeam* atkTeam;
      const Model::OpTeam* defTeam;
      
      //The cursor's position for the choices
      int cursorPos;
      //True if the turn have been calculated
      bool turnLaunched = false;

      sf::Sprite background;
      sf::Sprite playerSpr;
      sf::Sprite trainerSpr;
      sf::Sprite dialogSpr;
      sf::Text choicesTxt[4];
      sf::Vector2f posChoices[4];
      sf::Sprite cursor;

      sf::Text opName[2];
      sf::Text opLevel[2];

      sf::Sprite healthbar1[2];
      sf::Sprite healthbar2[2];
      sf::Sprite infoboxPlayer;
      sf::Sprite infoboxTrainer;
      sf::Sprite shadowTrainer;
      sf::Sprite shadowPlayer;
      
      int curPos;
    public:

      Battle(const Model::OpTeam* atkTeam, const Model::OpTeam* defTeam, std::string trainerClass, std::string background);
      //Used to print the turn
      GameStatus operator()(Model::Turn const& atk, Model::Turn const& def);//Sets turnLaunched to true
      //Used to print the choices
      GameStatus operator()(Model::Turn* atkTurn, Model::Turn *def);
      //Moves the cursor
      void moveCur(Model::Side where);

      Battle(){}//TEMP
      
    };

  }
}
