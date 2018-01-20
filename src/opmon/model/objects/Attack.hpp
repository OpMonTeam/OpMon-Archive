/*
Attack.hpp
Author : Jlppc
File under GPL-3.0 license
http://opmon-game.ga
Contains Attack class definition
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include <iostream>
#include "src/utils/misc.hpp"
#include "Enums.hpp"

namespace OpMon{
  namespace Model{

    class OpMon;
    /**
       Represent an OpMon attack
    */
    //->PureVirtual
    class Attack {
    public:
      virtual ~Attack() {}
      Attack(std::string nom, int puissance, Type type, int accuracy, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite, std::string className);
      //->PureVirtual
      virtual int effetAvant(OpMon &/*atk*/, OpMon &/*def*/) { return 0; }
      //->PureVirtual
      virtual int effetApres(OpMon &/*atk*/, OpMon &/*def*/) { return 0; }
      void healPP() {
        pp = ppMax;
      }
      Type getType() {
        return type;
      }
      /**atk attack the def OpMon*/
      //->Final
      virtual int attack(OpMon &atk, OpMon &def);
      virtual void siEchoue(OpMon&, OpMon&) {}
      virtual std::string getClassName() {
        return className;
      }
      virtual std::string save();
      void setPP(int PP) {
        this->pp = PP;
      }
      void setPPMax(int PPMax) {
        this->ppMax = PPMax;
      }
    protected:
      std::string className;
      std::string nom;
      int puissance;
      int priorite;
      int accuracy;
      Type type;
      bool special;
      bool status;
      int part = 0;
      int pp;
      int ppMax;
      /**La chance de coups critiques, en 1/nombre (Par défaut, 16)*/
      int chanceDeCoups;
      bool rateJamais;
      /**Variable utilisée dans effetAvant et effetAprès*/
      int hpPerdus = 0;
    };

  }
}
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
