/*
Species.hpp
Author : Cyrielle
Contributors : Stelyus, BAKFR, Navet56, JonnyPtn
File under GNU GPL v3.0 license
*/
#ifndef ESPECE_HPP
#define ESPECE_HPP

#include "CurveExp.hpp"
#include "Enums.hpp"
#include <iostream>
#include <vector>

namespace OpMon {
    namespace Model {

        class Evolution;

        /**
           Class to define a species of OPMon.
        */
        //->Final
        class Species {

          protected:
          private:
            std::string name;
            int opdexNumber;
            Species *evolution;
            Evolution *evolType;
            Type type1;
            Type type2;
            std::string opdexEntry;
            float height;
            float weight;
            unsigned int baseAtk;
            unsigned int baseDef;
            unsigned int baseAtkSpe;
            unsigned int baseDefSpe;
            unsigned int baseSpe;
            unsigned int baseHP;
            /**The EXP curve*/
            CurveExp *curve;
            /**The total EXP the OpMon can have (EXP at level 100)*/
            int expMax;
            /**Array representing the EV given by the OpMon when defeated*/
            std::vector<Stats> EVgiven;

            unsigned int expGiven;
            int captureRate;

          public:
            Species(Species &&other) noexcept;

            virtual ~Species();
            Species(unsigned int atk, unsigned int def, unsigned int atkSpe, unsigned int defSpe, unsigned int spe, unsigned int hp, std::string name, Type type1, Type type2, Evolution *evolType, std::vector<Stats> EVGiven, float height, float weight, std::string opdexEntry, unsigned int expGiven, int expMax, int captureRate, int opdexNumber);
            unsigned int getBaseAtk() const {
                return baseAtk;
            }
            unsigned int getBaseDef() const {
                return baseDef;
            }
            unsigned int getBaseAtkSpe() const {
                return baseAtkSpe;
            }
            unsigned int getBaseDefSpe() const {
                return baseDefSpe;
            }
            unsigned int getBaseSpe() const {
                return baseSpe;
            }
            unsigned int getBaseHP() const {
                return baseHP;
            }
            std::string getName() const {
                return name;
            }
            int getCaptureRate() const {
                return captureRate;
            }
            Type getType1() const {
                return type1;
            }
            Type getType2() const {
                return type2;
            }
            unsigned int getExp() const {
                return expGiven;
            }
            int getExpMax() const {
                return expMax;
            }
            Evolution *getEvolType() const {
                return evolType;
            }
            CurveExp *getCurve() const {
                return curve;
            }
            Species *getEvolution() const {
                return evolution;
            }
            float getWeight() const {
                return weight;
            }
            float getHeight() const {
                return height;
            }
            std::vector<Stats> getEv() const {
                return EVgiven;
            }
            int getOpdexNumber() const {
                return this->opdexNumber;
            }
        };
    } // namespace Model
} // namespace OpMon
#endif // ESPECE_HPP
