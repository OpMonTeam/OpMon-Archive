#include "Battle.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "../model/storage/Data.hpp"
#include "../../utils/StringKeys.hpp"
#include "Window.hpp"
#include <iostream>
#include <sstream>

namespace OpMon{
  namespace View{
    GameStatus Battle::operator()(Model::Turn* atkTurn, Model::Turn *def){
      frame.draw(background);
      frame.draw(playerSpr);
      frame.draw(trainerSpr);
      atk.setTexture(Model::Data::OpMons::opSprites[atkTurn->opmon->getSpecies().getOpdexNumber()][0]);
      this->def.setTexture(Model::Data::OpMons::opSprites[def->opmon->getSpecies().getOpdexNumber()][1]);
      frame.draw(atk);
      frame.draw(this->def);

      for(unsigned int i = 0; i < 2; i++){
	frame.draw(infobox[i]);
	frame.draw(healthbar1[i]);
	frame.draw(healthbar2[i]);
      }

      std::ostringstream oss;
      oss << "Lv. " << atkTurn->opmon->getLevel();
      opLevel[0].setString(oss.str());
      std::ostringstream oss2;
      oss2 << "Lv. " << def->opmon->getLevel();
      opLevel[1].setString(oss2.str());

      opName[0].setString(atkTurn->opmon->getNickname());
      opName[1].setString(def->opmon->getNickname());

      frame.draw(opName[0]);
      frame.draw(opName[1]);
      frame.draw(opLevel[0]);
      frame.draw(opLevel[1]);
      
      frame.draw(dialogSpr);
      for(sf::Text &txt : choicesTxt){
	frame.draw(txt);
      }
      cursor.setPosition(posChoices[curPos] - sf::Vector2f(30, -8));
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
      playerSpr.setPosition(20, 206);
      playerSpr.setScale(2, 2);
      trainerSpr.setTexture(Model::Data::Battle::charaBattleTextures[trainerClass][0]);
      trainerSpr.setPosition(400, 20);
      choicesTxt[0].setString(Utils::StringKeys::get("battle.attack"));
      choicesTxt[1].setString(Utils::StringKeys::get("battle.bag"));
      choicesTxt[2].setString(Utils::StringKeys::get("battle.opmon"));
      choicesTxt[3].setString(Utils::StringKeys::get("battle.run"));
      posChoices[0].x = 60;
      posChoices[0].y = 385;
      posChoices[1].x = 220;
      posChoices[1].y = 385;
      posChoices[2].x = 60;
      posChoices[2].y = 435;
      posChoices[3].x = 220;
      posChoices[3].y = 435;
      for(unsigned int i = 0; i < 4; i++){
	choicesTxt[i].setFont(Model::Data::Ui::font);
	choicesTxt[i].setCharacterSize(26);
	choicesTxt[i].setPosition(posChoices[i]);
	choicesTxt[i].setColor(sf::Color::Black);
      }
      dialogSpr.setTexture(Model::Data::Battle::dialog);
      dialogSpr.setPosition(0, 350);
      cursor.setTexture(Model::Data::Battle::cursor);
      cursor.setPosition(posChoices[0] - sf::Vector2f(30, -8));
      curPos = 0;
      cursor.setScale(2, 2);
      frame.setView(frame.getDefaultView());
      atk.setPosition(110, 160);
      def.setPosition(305, 120);
      atk.setScale(2, 2);


      for(unsigned int i = 0; i < 2; i++){
	infobox[i].setTexture(Model::Data::Battle::infoBox);
	healthbar1[i].setTexture(Model::Data::Battle::healthbar1);
	healthbar2[i].setTexture(Model::Data::Battle::healthbar2);
      }

      infobox[0].setPosition(17, 148);
      healthbar1[0].setPosition(30, 130);
      healthbar2[0].setPosition(30, 130);

      infobox[1].setPosition(321, 277);
      healthbar1[1].setPosition(335, 257);
      healthbar2[1].setPosition(335, 257);

      opName[0].setPosition(22, 160);
      opLevel[0].setPosition(22, 185);
      opName[1].setPosition(332, 289);
      opLevel[1].setPosition(332, 314);

      for(unsigned int i = 0; i < 2; i++){
	opName[i].setFont(Model::Data::Ui::font);
	opLevel[i].setFont(Model::Data::Ui::font);
	opName[i].setCharacterSize(22);
	opLevel[i].setCharacterSize(22);
	opName[i].setColor(sf::Color::Black);
	opLevel[i].setColor(sf::Color::Black);
      }
      
    }

    void Battle::moveCur(Model::Side where){
      int cur = curPos;
      switch(where){
      case Model::Side::TO_LEFT:
	cur -= 1;
	break;
      case Model::Side::TO_RIGHT:
	cur += 1;
	break;
      case Model::Side::TO_UP:
	cur -= 2;
	break;
      case Model::Side::TO_DOWN:
	cur += 2;
	break;
      }
      
      if(cur >= 0 && cur < 4){
	curPos = cur;
      }
    }
  }
}
