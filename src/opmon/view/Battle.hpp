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
      sf::Text waitText;

      sf::Text opName[2];
      sf::Text opLevel[2];

      sf::Sprite healthbar1[2];
      sf::Sprite healthbar2[2];
      sf::Sprite infoboxPlayer;
      sf::Sprite infoboxTrainer;
      sf::Sprite shadowTrainer;
      sf::Sprite shadowPlayer;
            
      int curPos;

      /* If true, the attack selection dialog is printed. If false, the action selection dialog is printed. */
      bool attackChoice = false;
      
      sf::Text attacks[4];
      //Prints the pp count
      sf::Text ppTxt;
      //Just prints the text "PP:"
      sf::Text ppStrTxt;
      sf::Sprite type;
      
    public:
      
      Battle(const Model::OpTeam* atkTeam, const Model::OpTeam* defTeam, std::string trainerClass, std::string background);
      
      GameStatus operator()(Model::Turn const& atk, Model::Turn const& def, bool *turnActivated);
      //Moves the cursor
      void moveCur(Model::Side where);
      //Returns the cursor's position
      int getCurPos() {return curPos;}
      //Tooggle the interface printed, the action or attack selection
      void toggleAttackChoice();

      bool isAttackChoice() {return attackChoice;}

    };

  }
}
