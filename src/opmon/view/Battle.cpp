#include "Battle.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "../model/storage/Data.hpp"
#include "../../utils/StringKeys.hpp"
#include "Window.hpp"
#include <iostream>

namespace OpMon{
  namespace View{
    GameStatus Battle::operator()(Model::Turn* atkTurn){
      std::cout << "Screen update" << std::endl;
      frame.draw(background);
      frame.draw(playerSpr);
      frame.draw(trainerSpr);
      frame.draw(dialogSpr);
      for(sf::Text &txt : choicesTxt){
	frame.draw(txt);
      }
      frame.draw(cursor);
      return GameStatus::CONTINUE;
    }

    GameStatus Battle::operator()(Model::Turn const& atk, Model::Turn const& def){
      return GameStatus::CONTINUE;
    }

    Battle::Battle(const Model::OpTeam* atkTeam, const Model::OpTeam* defTeam, std::string trainerClass, std::string background)
      : atkTeam(atkTeam), defTeam(defTeam){
      this->background.setTexture(Model::Data::Battle::backgrounds[background]);
      playerSpr.setTexture(Model::Data::Battle::charaBattleTextures["player"][0]);
      playerSpr.setPosition(0, 193);
      playerSpr.setScale(1, 1);
      trainerSpr.setTexture(Model::Data::Battle::charaBattleTextures[trainerClass][0]);
      trainerSpr.setPosition(400, 20);
      choicesTxt[0].setString(Utils::StringKeys::get("battle.attack"));
      choicesTxt[1].setString(Utils::StringKeys::get("battle.bag"));
      choicesTxt[2].setString(Utils::StringKeys::get("battle.opmon"));
      choicesTxt[3].setString(Utils::StringKeys::get("battle.run"));
      posChoices[0].x = 280;
      posChoices[0].y = 385;
      posChoices[1].x = 420;
      posChoices[1].y = 385;
      posChoices[2].x = 280;
      posChoices[2].y = 435;
      posChoices[3].x = 420;
      posChoices[3].y = 435;
      for(unsigned int i = 0; i < 4; i++){
	choicesTxt[i].setFont(Model::Data::Ui::font);
	choicesTxt[i].setCharacterSize(21);
	choicesTxt[i].setPosition(posChoices[i]);
	choicesTxt[i].setColor(sf::Color::Black);
      }
      dialogSpr.setTexture(Model::Data::Battle::dialog);
      dialogSpr.setPosition(0, 350);
      cursor.setTexture(Model::Data::Battle::cursor);
      cursor.setPosition(posChoices[0] - sf::Vector2f(20, -15));
      frame.setView(frame.getDefaultView());
    }
  }
}
