#include "Player.hpp"
#include "../start/main.hpp"
#include "../save/Save.hpp"

namespace OpMon{
  namespace Model{

    Player::Player(sf::String const& name):
      name(name), trainerID(Utils::randUI(0xFFFFFFFF)), opteam(name) {
      for(unsigned int i = 0; i < ITEM_NUMBER; i++) {
        bag[i] = 0;
      }

    }

    Player::Player():
      trainerID(Utils::randUI(0xFFFFFFFF)), opteam(name) {
      for(unsigned int i = 0; i < ITEM_NUMBER; i++) {
        bag[i] = 0;
      }
    }

    OpTeam *Player::getOpTeam() {
      return &opteam;
    }

    void Player::addItem(int itemID) {
      bag[itemID]++;
    }

    int Player::checkItem(int itemID) {
      unsigned int itemID2 = itemID;
      if (itemID2 > ITEM_NUMBER || itemID2 < 0) {
        handleError("Player : itemID invalide", true);
      }
      return bag[itemID];
    }

    bool Player::deleteItem(int itemID) {

      if (bag[itemID] != 0 || itemID < 0) {
        handleError("Player : itemID invalide", true);
      }
      if (bag[itemID] != 0) {
        bag[itemID]--;
        return true;
      } else {
        return false;
      }
    }

    void Player::healOp() {
      opteam.heal();
      for (int i = 0; i < opteam.getSize(); i++) {
        OpMon *pkmn = opteam[i];

        pkmn->amour = false;
        pkmn->malediction = false;
        pkmn->vampigraine = false;
        for (int j = 0; j < 4; j++) {
	  Attack *atk = (pkmn->getAttacks())[j];
	  atk->healPP();

        }


      }
    }

    bool Player::addOpToOpTeam(OpMon *toAdd) {
      if (opteam.addOpMon(toAdd)) {
        return true;
      } else {
        addOpMonToPC(toAdd);
        return false;
      }
    }

#include "../start/StringKeys.hpp"

    void Player::save() {
      UNS
	SOUT << StringKeys::sfStringtoStdString(this->name) << endl;
      SOUT << Save::intToChar(trainerID) << endl;
      SOUT << Save::intToChar(ITEM_NUMBER) << endl;
      for(unsigned int it = 0; it < ITEM_NUMBER; it++) {
        SOUT << Save::intToChar(bag[it]) << endl;
      }
      SOUT << Save::intToChar(pc.size()) << endl;
      for(unsigned int it = 0; it < pc.size(); it++) {
        SOUT << pc[it]->save();
      }
      for(unsigned int it = 0; it < 6; it++) {
        SOUT << opteam[it]->save();
      }

    }
#include "../objects/OpMon.hpp"
    Player::Player(std::ifstream &in, std::string &name):
      name(name), trainerID(in.get()), opteam(name) {
      UNS
	in.get();
      int iNber = in.get();
      in.get();
      if(iNber > ITEM_NUMBER) {
        iNber = ITEM_NUMBER;
      }
      for(int i = 0; i < iNber; i++) {
        this->bag[i] = in.get();
        in.get();
      }
      if(iNber < ITEM_NUMBER) {
        for(unsigned int i = iNber - 1; i < ITEM_NUMBER; i++) {
	  bag[i] = 0;
        }
      }
      int pcNbre = in.get();
      in.get();
      for(int i = 0; i < pcNbre; i++) {
        OpMon *op = new OpMon(in);
        this->pc.push_back(op);
      }
      for(unsigned int i = 0; i < 6; i++) {
        OpMon *op = new OpMon(in);
        opteam.addOpMon(op);
      }

    }
  }
}
