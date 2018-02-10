/*
Player.hpp
Author : Jlppc
File under the GPL-3.0 license
http://opmon-game.ga
Contains the Player class.
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_

#include "../objects/item/Item.hpp"
#include "OpTeam.hpp"
#include "Position.hpp"
#include <SFML/System.hpp>

namespace OpMon {
    namespace Model {

        class OpMon;

        class Player {
          public:
            Player(sf::String const &name);

            Player();

            OpTeam *getOpTeam();

            void addItem(int itemID);

            /**Returns the number of items of the item type given in paramter*/
            int checkItem(int itemID);

            /**Delete an item from the player inventory. Returns false if the item was not present.*/
            bool deleteItem(int itemID);

            sf::String getName() const {
                return name;
            }

            const sf::String *getNameP() const {
                return &name;
            }

            void setName(sf::String const &name) {
                this->name = name;
            }

            int getTrainerID() const {
                return trainerID;
            }

            void addOpMonToPC(OpMon *toAdd) {
                pc.push_back(toAdd);
            }

            OpMon *getOp(int ID) const {
                return opteam[ID];
            }

            OpMon *getPcOp(int ID) const {
                return pc[ID];
            }

            /**Heals all the player's OpMons*/
            void healOp();

            /**Tries to add an OpMon to the team. Returns false if the team is already full*/
            bool addOpToOpTeam(OpMon *toAdd);

            void save();

            Player(std::ifstream &in, std::string &name);

            bool isKo() {
                return opteam.isKo();
            }

            int getPosX() {
                return position.getPosition().x;
            }

            int getPosY() {
                return position.getPosition().y;
            }

            Position &getPosition() {
                return position;
            }

            const std::string &getMapId() {
                return mapID;
            }

            void setMapID(std::string mapID) {
                this->mapID = mapID;
            }

            /**
           * Teleport the player.
           *
           * NOTE: it will NOT move the Camera. You should call Overworld.tp() instead.
           */
            void tp(std::string mapToTp, sf::Vector2i position);

          private:
            sf::String name;
            const unsigned int trainerID; //Max : 8 digits in hexadecimal
            int bag[ITEM_NUMBER];
            std::vector<OpMon *> pc = std::vector<OpMon *>();
            OpTeam opteam;
            std::string mapID = "Player's room"; //Player's room is the start room for the player

            Position position;
        };
    } // namespace Model
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
