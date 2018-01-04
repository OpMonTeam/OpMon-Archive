/*
Evolution.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la définition da la classe Evolution
*/
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include "../OpMon.hpp"

namespace OpMon{
  namespace Model{
    

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

  }
}
#endif /* EVOLUTION_HPP */
