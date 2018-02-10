/*
    Evolution.hpp
    Author : Jlppc
    File under the GPL-3.0 license
    http://opmon-game.ga
    Contains the Evolution class definition
*/
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include "../OpMon.hpp"
#include <iostream>

namespace OpMon {
    namespace Model {

        class Species;
        /**
       Permet de définir un type d'évolution
    */
        //->PureVirtual
        class Evolution {
          public:
            virtual ~Evolution() {}
            Evolution() {
                evo = -1;
            }
            Evolution(int evo);
            /**Permet de vérifier si le pokémon évolue. Renvoie true si il peut evoluer*/
            virtual bool checkEvolve(OpMon const &toCheck) const = 0;
            Species *getEvolution() const;
            /**Check evo permet de récuperer l'species d'évolution. Ne pas confondre avec checkEvolve*/
            void checkEvo();
            virtual int getEvolID() const {
                return evolID;
            }
            //->JustUse->E_Item
            virtual bool itemEvolve(Item *tem) const {
                return false;
            }

          protected:
            static const int evolID = 0;
            Species *toEvolve;
            int evo;
        };

    } // namespace Model
} // namespace OpMon
#endif /* EVOLUTION_HPP */
