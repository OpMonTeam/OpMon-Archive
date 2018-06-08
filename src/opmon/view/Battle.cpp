#include "Battle.hpp"
#include "../model/sysObjects/OpTeam.hpp"
#include "../model/storage/Data.hpp"
#include "../../utils/StringKeys.hpp"
#include "Window.hpp"
#include <iostream>
#include <sstream>
#include <SFML/Graphics/Rect.hpp>

namespace OpMon{
  namespace View{
    GameStatus Battle::operator()(Model::Turn const& atkTurn, Model::Turn const& defTurn, bool *turnActivated, bool atkFirst){
      if(atkHp == -1){
	atkHp = atkTurn.opmon->getHP();
      }
      if(defHp == -1){
	defHp = defTurn.opmon->getHP();
      }
      frame.draw(background);
      /*frame.draw(shadowPlayer);
	frame.draw(shadowTrainer);*/
      frame.draw(playerSpr);
      frame.draw(trainerSpr);
      atk.setTexture(Model::Data::OpMons::opSprites[atkTurn.opmon->getSpecies().getOpdexNumber()][0]);
      this->def.setTexture(Model::Data::OpMons::opSprites[defTurn.opmon->getSpecies().getOpdexNumber()][1]);
      frame.draw(atk);
      frame.draw(this->def);
      frame.draw(infoboxPlayer);
      frame.draw(infoboxTrainer);
      

      healthbar2[0].setTextureRect(sf::IntRect(0, 0, (defHp * Model::Data::Battle::healthbar2.getSize().x) / defTurn.opmon->getStatHP(), Model::Data::Battle::healthbar2.getSize().y));
      healthbar2[1].setTextureRect(sf::IntRect(0, 0, (atkHp * Model::Data::Battle::healthbar2.getSize().x) / atkTurn.opmon->getStatHP(), Model::Data::Battle::healthbar2.getSize().y));

      
      for(unsigned int i = 0; i < 2; i++){
	frame.draw(healthbar1[i]);
	frame.draw(healthbar2[i]);
      }

      std::ostringstream oss;
      oss << "Lv. " << atkTurn.opmon->getLevel();
      opLevel[0].setString(oss.str());
      std::ostringstream oss2;
      oss2 << "Lv. " << defTurn.opmon->getLevel();
      opLevel[1].setString(oss2.str());

      opName[0].setString(atkTurn.opmon->getNickname());
      opName[1].setString(defTurn.opmon->getNickname());

      frame.draw(opName[0]);
      frame.draw(opName[1]);
      frame.draw(opLevel[0]);
      frame.draw(opLevel[1]);
      if(!turnLaunched && *turnActivated){
	phase = 1;
	dialogSpr.setTexture(Model::Data::Ui::dialogBackground);
	turnLaunched = true;
      }else if(turnLaunched && !(*turnActivated)){
	phase = 0;
	dialogSpr.setTexture(Model::Data::Battle::dialog);
	turnLaunched = false;
      }
      frame.draw(dialogSpr);
      //TODO the little arrow
      
      if(*turnActivated && turnNber <= 1){
	const Model::Turn* turns[2];
	if(atkFirst){
	  turns[0] = &atkTurn;
	  turns[1] = &defTurn;
	}else{
	  turns[0] = &defTurn;
	  turns[1] = &atkTurn;
	}
	Utils::OpString str = Utils::OpString("battle.dialog.attack", new std::string("Poké1"), new std::string("atk1"));
	switch(phase){
	case 1:
	  turnTxt[0].setString(Utils::OpString::quickString("battle.dialog.attack", {turns[turnNber]->opmon->getNickname(), turns[turnNber]->attackUsed->getName()}));
	  break;
	case 2:
	  turnTxt[0].setString("");
	  if(turns[turnNber]->toPrintBefore.size() == 0){
	    phase++;
	  }else{
	    for(unsigned int i = 0; i < turns[turnNber]->toPrintBefore.size() && i < 3; i++){
	      turnTxt[i].setString(turns[turnNber]->toPrintBefore.at(i).getString());
	    }
	    break;
	  }
	  
	case 3:
	  if(atkFirst && turnNber == 0 || !atkFirst && turnNber == 2){
	    defHp = defTurn.opmon->getHP();
	  }else{
	    atkHp = atkTurn.opmon->getHP();
	  }
	  phase++;
	case 4:
	  if(turns[turnNber]->toPrintAfter.size() == 0){
	    phase++;
	  }else{
	    for(unsigned int i = 0; i < turns[turnNber]->toPrintAfter.size() && i < 3; i++){
	      turnTxt[i].setString(turns[turnNber]->toPrintAfter.at(i).getString());
	    }
	    break;
	  }

	case 5:
	  phase = 1;
	  turnNber++;
	  if(turnNber > 1){
	    turnNber = 0;
	    phase = 0;
	    *turnActivated = false;
	  }
	  break;
	}

	frame.draw(turnTxt[0]);
	frame.draw(turnTxt[1]);
	frame.draw(turnTxt[2]);
	
      }else if(!attackChoice){
	
	for(sf::Text &txt : choicesTxt){
	  frame.draw(txt);
	}

	waitText.setString(Utils::StringKeys::get("battle.wait"));
	frame.draw(waitText);

	cursor.setPosition(posChoices[curPos] + sf::Vector2f((choicesTxt[curPos].getGlobalBounds().width / 2) - 10, 25));

      }else{
	
	for(unsigned int i = 0; i < 4; i++){
	  if(atkTurn.opmon->getAttacks()[i] != nullptr){
	    attacks[i].setString(atkTurn.opmon->getAttacks()[i]->getName());
	  }else{
	    attacks[i].setString("----");
	  }
	  frame.draw(attacks[i]);
	}

	if(atkTurn.opmon->getAttacks()[curPos] != nullptr){
	  
	  std::ostringstream oss3;
	  oss3 << atkTurn.opmon->getAttacks()[curPos]->getPP() << " / " << atkTurn.opmon->getAttacks()[curPos]->getPPMax();
	  if(atkTurn.opmon->getAttacks()[curPos]->getPP() <= (atkTurn.opmon->getAttacks()[curPos]->getPPMax() / 5) && atkTurn.opmon->getAttacks()[curPos]->getPP() > 0){
	    ppTxt.setColor(sf::Color::Yellow);
	  }else if(atkTurn.opmon->getAttacks()[curPos]->getPP() == 0){
	    ppTxt.setColor(sf::Color::Red);
	  }else{
	    ppTxt.setColor(sf::Color::Black);
	  }
	  ppTxt.setString(oss3.str());
	  type.setTexture(Model::Data::OpMons::typesTextures[atkTurn.opmon->getAttacks()[curPos]->getType()]);
	  frame.draw(type);
	}else{
	  ppTxt.setColor(sf::Color::Red);
	  ppTxt.setString("0 / 0");
	 
	}

	
	frame.draw(ppTxt);
	frame.draw(ppStrTxt);
	
	
	cursor.setPosition(posChoices[curPos] + sf::Vector2f((attacks[curPos].getGlobalBounds().width / 2) - 10, 30));

	
      }

      if(!turnLaunched){
	frame.draw(cursor);
      }
      return GameStatus::CONTINUE;
    }

    bool Battle::nextTxt(){
      if(phase >= 4){
	phase = 1;
	turnNber++;
	if(turnNber > 1){
	  turnNber = 0;
	  return false;
	}
      }else{
	phase++;
      }
      return true;
    }

    void Battle::toggleAttackChoice(){
      attackChoice = !attackChoice;
      if(attackChoice){
	dialogSpr.setTexture(Model::Data::Battle::attackDialog);
	posChoices[0].x = 40;
	posChoices[0].y = 370;
	posChoices[1].x = 140;
	posChoices[1].y = 370;
	posChoices[2].x = 40;
	posChoices[2].y = 425;
	posChoices[3].x = 140;
	posChoices[3].y = 425;
	for(unsigned int i = 0; i < 4; i++){
	  attacks[i].setPosition(posChoices[i]);
	  attacks[i].setFont(Model::Data::Ui::font);
	  attacks[i].setCharacterSize(26);
	  attacks[i].setColor(sf::Color::Black);
	}

      }else{
	posChoices[0].x = 326;
	posChoices[0].y = 380;
	posChoices[1].x = 430;
	posChoices[1].y = 380;
	posChoices[2].x = 330;
	posChoices[2].y = 445;
	posChoices[3].x = 430;
	posChoices[3].y = 445;
	dialogSpr.setTexture(Model::Data::Battle::dialog);
      }
      
    }
    
    Battle::Battle(const Model::OpTeam* atkTeam, const Model::OpTeam* defTeam, std::string trainerClass, std::string background)
      : atkTeam(atkTeam), defTeam(defTeam){
      this->background.setTexture(Model::Data::Battle::backgrounds[background]);
      playerSpr.setTexture(Model::Data::Battle::charaBattleTextures["player"][0]);
      playerSpr.setPosition(20, 206);
      playerSpr.setScale(2, 2);
      trainerSpr.setTexture(Model::Data::Battle::charaBattleTextures[trainerClass][0]);
      trainerSpr.setPosition(400, 20);

      dialogArrow.setTexture(Model::Data::Ui::dialogArrow);
      
      choicesTxt[0].setString(Utils::StringKeys::get("battle.attack"));
      choicesTxt[1].setString(Utils::StringKeys::get("battle.bag"));
      choicesTxt[2].setString(Utils::StringKeys::get("battle.opmon"));
      choicesTxt[3].setString(Utils::StringKeys::get("battle.run"));
      posChoices[0].x = 326;
      posChoices[0].y = 380;
      posChoices[1].x = 430;
      posChoices[1].y = 380;
      posChoices[2].x = 330;
      posChoices[2].y = 445;
      posChoices[3].x = 430;
      posChoices[3].y = 445;
      for(unsigned int i = 0; i < 4; i++){
	choicesTxt[i].setFont(Model::Data::Ui::font);
	choicesTxt[i].setCharacterSize(20);
	choicesTxt[i].setPosition(posChoices[i]);
	choicesTxt[i].setColor(sf::Color::White);
      }

      //ppText.setPosition(326, 380);
      
      dialogSpr.setTexture(Model::Data::Battle::dialog);
      dialogSpr.setPosition(0, 350);
      cursor.setTexture(Model::Data::Battle::cursor);
      cursor.setPosition(posChoices[0] + sf::Vector2f((choicesTxt[0].getGlobalBounds().width / 2) - 10, 25));
      curPos = 0;
      cursor.setScale(2, 2);
      frame.setView(frame.getDefaultView());
      atk.setPosition(110, 160);
      def.setPosition(305, 120);
      atk.setScale(2, 2);

      infoboxPlayer.setTexture(Model::Data::Battle::infoboxPlayer);
      infoboxPlayer.setPosition(321, 250);
      infoboxTrainer.setTexture(Model::Data::Battle::infoboxTrainer);
      infoboxTrainer.setPosition(17, 148);
      shadowPlayer.setTexture(Model::Data::Battle::shadowPlayer);
      shadowPlayer.setPosition(130, 281);
      shadowTrainer.setTexture(Model::Data::Battle::shadowTrainer);
      shadowTrainer.setPosition(320, 175);
      for(unsigned int i = 0; i < 2; i++){

	healthbar1[i].setTexture(Model::Data::Battle::healthbar1);
	healthbar2[i].setTexture(Model::Data::Battle::healthbar2);
      }

      infoboxTrainer.setPosition(17, 148);
      healthbar1[0].setPosition(30, 130);
      healthbar2[0].setPosition(30, 130);

      infoboxPlayer.setPosition(321, 250);
      healthbar1[1].setPosition(335, 230);
      healthbar2[1].setPosition(335, 230);

      opName[0].setPosition(332, 289);
      opLevel[0].setPosition(332, 314);
      opName[1].setPosition(22, 160);
      opLevel[1].setPosition(22, 185);

      for(unsigned int i = 0; i < 2; i++){
	opName[i].setFont(Model::Data::Ui::font);
	opLevel[i].setFont(Model::Data::Ui::font);
	opName[i].setCharacterSize(22);
	opLevel[i].setCharacterSize(22);
	opName[i].setColor(sf::Color::Black);
	opLevel[i].setColor(sf::Color::Black);
      }

      waitText.setFont(Model::Data::Ui::font);
      waitText.setCharacterSize(22);
      waitText.setColor(sf::Color::Black);
      waitText.setPosition(25, 410);

      ppStrTxt.setPosition(326, 380);
      ppStrTxt.setString("PP :");
      ppTxt.setPosition(326, 400);
      ppStrTxt.setFont(Model::Data::Ui::font);
      ppTxt.setFont(Model::Data::Ui::font);
      ppStrTxt.setCharacterSize(26);
      ppTxt.setCharacterSize(26);
      ppStrTxt.setColor(sf::Color::Black);
      ppTxt.setColor(sf::Color::Black);

      for(unsigned int i = 0; i < 3; i++){
	turnTxt[i].setFont(Model::Data::Ui::font);
	turnTxt[i].setCharacterSize(22);
	turnTxt[i].setColor(sf::Color::Black);
	turnTxt[i].setPosition(25, 410 + i * 20);
      }
      
      type.setPosition(326, 440);
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
