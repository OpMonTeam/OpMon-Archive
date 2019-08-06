/*
OpTeam.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include "../objects/OpMon.hpp"
#include <iostream>
#include <vector>

namespace OpMon {
    namespace Model {

        class OpMon;

        /**
	   Class defining a OpMon team, used by the player and the trainers.
	*/
        class OpTeam {
          public:
            ~OpTeam();
            OpTeam(std::string const &name);
            std::string getName() const {
                return name;
            }
            std::vector<OpMon *> getOpTeam() {
                return opteam;
            }
            /**Heals all the team*/
            void heal();
            /**
	       Adds an OpMon to the team. Returns false if the team is full and the OpMon is not added.
	    */
            bool addOpMon(OpMon *toAdd);
            /**Delete the OpMon with the index specified*/
            OpMon *removeOp(int number);
            /**
	       Returns the OpMon in the index specified.
	    */
            OpMon *operator[](int id) const;
            OpMon *getOp(int id) const {
                return (*this)[id];
            }
            /**Returns true if the team is K.O*/
            bool isKo() const;
            int getSize() const;
            void operator+=(OpMon *pkmn) {
                addOpMon(pkmn);
            }
            void operator-=(int id) {
                removeOp(id);
            }
            void save();

          private:
            std::vector<OpMon *> opteam;
            std::string name;
            OpTeam(OpTeam const &) = delete;
        };

    } // namespace Model
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
