#include "StartScene.hpp"
#include "Animations.hpp"
#include "Dialog.hpp"
#include "../model/storage/Data.hpp"
#include "../../utils/OpString.hpp"
#include "../../utils/StringKeys.hpp"
#include "../../utils/defines.hpp"
#include "../model/storage/Data.hpp"
#include "../model/sysObjects/Player.hpp"
#include "./Window.hpp"


#define SIZE_P0 18
#define SIZE_P1 15

UNS

namespace OpMon{
  namespace View{

    void StartScene::initStrings() {
      auto kget = Utils::StringKeys::get;

      unsigned int it = 0;
      for(it = 0; it < 18; it++) {
        string actual;
        actual << string("prof.dialog.start.") << it+1;
        txtP0[it] = kget(actual);
      }
      int ite = 1;
      it++;
      strName = Utils::OpString("prof.dialog.start.19", Model::Data::player.getNameP());
      txtP1[0] = strName.getString();
      for(it = it; it < 27; it++) {
        string actual;
        actual << string("prof.dialog.start.") << it+1;
        txtP1[ite] = kget(actual);
        ite++;
      }

      textDescs[0].setString(kget("nameEntry.med"));
      textDescs[1].setString(kget("nameEntry.top"));
      textDescs[2].setString(kget("nameEntry.indic.1"));
      textDescs[3].setString(kget("nameEntry.indic.2"));
    }

    StartScene::StartScene() : dialog(nullptr) {
      initStrings();
      Dialog::dialog.setPosition(0, 362);
      textDescs[1].setPosition(85, 25);
      textDescs[0].setPosition(155, 200);
      textDescs[2].setPosition(95, 375);
      textDescs[3].setPosition(95, 405);


      txtEnCours[0] = sf::String(" ");
      txtEnCours[1] = sf::String(" ");
      txtEnCours[2] = sf::String(" ");

      textures[0].loadFromFile(RESSOURCES_PATH + "backgrounds/start/startscene.png");
      textures[1].loadFromFile(RESSOURCES_PATH + "sprites/chara/jlppc/profkiwai.png");
      textures[2].loadFromFile(RESSOURCES_PATH + "backgrounds/dialog/dialog.png");
      textures[3].loadFromFile(RESSOURCES_PATH + "sprites/misc/arrDial.png");
      textures[4].loadFromFile(RESSOURCES_PATH + "backgrounds/start/nameEntry.png");
      bg.setTexture(textures[0]);
      prof.setTexture(textures[1]);
      Dialog::dialog.setTexture(textures[2]);
      Dialog::arrDial.setTexture(textures[3]);
      bgName.setTexture(textures[4]);
      bgName.setPosition(0, 0);

      bg.setPosition(0, 0);
      prof.setPosition(205, 120);
      prof.setScale(1.5, 1.5);

      for(sf::Text &cellTxt : textDescs) {
        cellTxt.setCharacterSize(FONT_SIZE_DEFAULT);
        cellTxt.setFillColor(sf::Color::Black);
        cellTxt.setFont(Model::Data::Ui::font);
      }

      nameField.setFont(Model::Data::Ui::font);
      nameField.setPosition(120, 300);

      Dialog::arrDial.setPosition(437, 482);

      jukebox.play("Start");
      
      // Init loop 0
      unsigned int sizeOfTxt = 18;
      dialog = new Dialog(txtP0, sizeOfTxt);
    }

    void StartScene::onLangChanged(){
      initStrings();
    }

    GameStatus StartScene::operator()(){
      switch(part){
        case 0:
          if(!dialog->isDialogOver()) {
            dialog->updateTextAnimation();
          } else {
            // Init loop 1
            delete(dialog);
            dialog = nullptr;
            window.setKeyRepeatEnabled(true);
            part++;
	    return GameStatus::NEXT;
          }
          break;

        case 1:
          return GameStatus::CONTINUE; // Everything is handled by Ctrl

        case 2:
          if(!dialog->isDialogOver()) {
            dialog->updateTextAnimation();
          } else{
            part++;
            return GameStatus::NEXT;
          }
          break;

        default:
          ; // TODO: LOG
      }
      return GameStatus::CONTINUE;
    }

    void StartScene::delLoop1(){
      window.setKeyRepeatEnabled(false);
      Model::Data::player.setName(pName);
      txtP1[0] = strName.getString();
      part++;

      // Init loop 2
      unsigned int sizeOfTxt = 27 - 18;
      dialog = new Dialog(txtP1, sizeOfTxt);
    }

    void StartScene::draw(sf::RenderTarget &frame){
      switch(part){
        case 0:
        case 2:
          if(!dialog->isDialogOver()){
            frame.clear(sf::Color::White);
            frame.draw(bg);
            frame.draw(prof);

            dialog->draw(frame);
          }
          break;

        case 1:
          frame.clear(sf::Color::White);
          frame.draw(bgName);
          for(sf::Text desc : textDescs){
            desc.setFillColor(sf::Color::White);
            desc.setFont(Model::Data::Ui::font);
            frame.draw(desc);
          }
          nameField.setString(pName);
          frame.draw(nameField);
          break;

        default:
          ;// TODO: log something !
      }
    }

    void StartScene::play(){
      jukebox.play("Start");
    }

    void StartScene::pause(){
      jukebox.pause("Start");
    }

    StartScene::~StartScene(){
      jukebox.stop("Start");
      delete(dialog);
    }
  }
}
