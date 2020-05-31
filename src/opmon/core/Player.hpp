/*!
 * \file Player.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors JonnyPtn
 * \authors Stelyus
 * \authors Navet56
 * \copyright GNU GPL v3.0
 */
#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <SFML/System.hpp>
#include <map>
#include <algorithm>

#include "../model/Item.hpp"
#include "../model/OpTeam.hpp"
#include "../view/elements/Position.hpp"

namespace OpMon {

    class OpMon;

    /*!
     * \brief Contains information about the player.
     */
    class Player {
    public:
        Player(sf::String const &name);

        Player();

        /*!
         * \brief Returns a pointer to the player's team.
         */
        OpTeam *getOpTeam();

        /*!
         * \warning Work in progress.
         */
        void addItem(std::string const &itemID);

        /*!
         * \warning Work in progress.
         */
        int checkItem(std::string const &itemID);

        /*!
         * \warning Work in progress.
         */
        bool deleteItem(std::string const &itemID);

        sf::String getName() const {
            return name;
        }

        /*!
         * \brief Returns a const pointer to the player's name.
         */
        const sf::String *getNameP() const {
            return &name;
        }

        /*!
         * \brief Returns a pointer to the player's name.
         */
        sf::String *getNameP() {
            return &name;
        }

        void setName(sf::String const &name) {
            this->name = name;
        }

        int getTrainerID() const {
            return trainerID;
        }

        /*!
         * \brief Adds an OpMon to the computer.
         */
        void addOpMonToPC(OpMon *toAdd) {
            pc.push_back(toAdd);
        }

        /*!
         * \brief Returns an OpMon from the player's team.
         */
        OpMon *getOp(int ID) const {
            return opteam[ID];
        }

        /*!
         * \brief Returns an OpMon from the computer.
         */
        OpMon *getPcOp(int ID) const {
            return pc[ID];
        }

        /*!
         * \brief  Heals all the player's OpMon
         */
        void healOp();

        /*!
         * \brief Tries to add an OpMon to the team.
         * \returns `false` if the team is already full.
         */
        bool addOpToOpTeam(OpMon *toAdd);

        bool isKo() {
            return opteam.isKo();
        }

    private:
        sf::String name;
        const unsigned int trainerID; //Max : 8 digits in hexadecimal (Unimplemented yet)
        std::map<std::string, int> bag;
        std::vector<OpMon *> pc = std::vector<OpMon *>();
        OpTeam opteam;
    };
} // namespace OpMon

#endif /* _PLAYER_HPP_ */
