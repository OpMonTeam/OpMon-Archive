/*
Player.cpp
Author : Cyrielle
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#include "Player.hpp"

#include "../../utils/StringKeys.hpp"

#include "Core.hpp"
#include "../objects/Attack.hpp"

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

        void Player::addItem(std::string const &itemID) {
            bag[itemID]++;
        }

        int Player::checkItem(std::string const &itemID) {
            return bag[itemID];
        }

        bool Player::deleteItem(std::string const &itemID) {
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

        void Player::tp(std::string mapToTp, sf::Vector2i newPos) {
            mapID = mapToTp;
            position.tp(newPos);
        }

    } // namespace Model
} // namespace OpMon
