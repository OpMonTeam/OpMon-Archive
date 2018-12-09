/*
Player.cpp
Author : Cyrion
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Player.hpp"
#include "../../../utils/StringKeys.hpp"
#include "../../start/Core.hpp"
#include "../objects/Attack.hpp"
#include "../save/Save.hpp"
#include <sstream>



namespace OpMon {
    namespace Model {

        Player::Player(sf::String const &name)
          : Player() {
            this->name = name;
            this->opteam = OpTeam(name);
        }

        Player::Player()
          : trainerID(Utils::Misc::randUI(0xFFFFFFFF))
          , opteam(name) {
            Position::setPlayerPos(&position);
        }

        OpTeam *Player::getOpTeam() {
            return &opteam;
         }
      
        void Player::addItem(std::string const& itemID) {
            bag[itemID]++;
        }
      
      int Player::checkItem(std::string const& itemID) {
	return bag[itemID];
      }

      bool Player::deleteItem(std::string const& itemID) {
            if(bag[itemID] != 0) {
                bag[itemID]--;
                return true;
            } else {
                return false;
            }
        }

        void Player::healOp() {
            opteam.heal();
            for(int i = 0; i < opteam.getSize(); i++) {
                OpMon *pkmn = opteam[i];
                if(pkmn != nullptr) {
                    //TODO : Reset status problems
                    for(int j = 0; j < 4; j++) {
                        Attack *atk = (pkmn->getAttacks())[j];
                        if(atk != nullptr) {
                            atk->healPP();
                        }
                    }
                }
            }
        }

        bool Player::addOpToOpTeam(OpMon *toAdd) {
            if(opteam.addOpMon(toAdd)) {
                return true;
            } else {
                addOpMonToPC(toAdd);
                return false;
            }
        }

        //TODO : Update the save system
        void Player::save() {
	  /*SOUT
              << Utils::StringKeys::sfStringtoStdString(this->name) << std::endl;
            SOUT << Save::intToChar(trainerID) << std::endl;
            SOUT << Save::intToChar(ITEM_NUMBER) << std::endl;
            for(unsigned int it = 0; it < ITEM_NUMBER; it++) {
                SOUT << Save::intToChar(bag[it]) << std::endl;
            }
            SOUT << Save::intToChar(pc.size()) << std::endl;
            for(unsigned int it = 0; it < pc.size(); it++) {
                SOUT << pc[it]->save();
            }
            for(unsigned int it = 0; it < 6; it++) {
                SOUT << opteam[it]->save();
		}*/
        }

#include "../objects/OpMon.hpp" //This will be deleted soon
                                //TODO : Update the save system

        Player::Player(std::ifstream &in, std::string &name)
          : name(name)
          , trainerID(in.get())
          , opteam(name) { /*
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
		}*/
        }

        void Player::tp(std::string mapToTp, sf::Vector2i newPos) {
            mapID = mapToTp;
            position.tp(newPos);
        }

    } // namespace Model
} // namespace OpMon
