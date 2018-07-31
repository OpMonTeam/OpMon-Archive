/*
Species.hpp
Author : Jlppc
File under the GPL-3.0 license
http://opmon-game.ga
Define the CourbeExp enumération and the Species class
*/
#ifndef ESPECE_HPP
#define ESPECE_HPP

#include "item/CT.hpp"
#include "CurveExp.hpp"
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
            int niveauEvolution;
            Evolution *evolType;
            Type type1;
            Type type2;
            //NumberedArray atksByLevels[];
            std::string opdexEntry;
            float height;
            float weight;
            //CT ctCompatibles[];
            unsigned int baseAtk;
            unsigned int baseDef;
            unsigned int baseAtkSpe;
            unsigned int baseDefSpe;
            unsigned int baseSpe;
            unsigned int baseHP;
            /**La courbe d'experience*/
            CurveExp *curve;
            /**L'exp au niveau 100*/
            int expMax;
            /**C'est le tableau des EV donnés*/
            std::vector<Stats> EVgiven;
            //Variables de sprites a inserer ICI
            unsigned int expGiven;
            int captureRate;
            /**La height du tableau d'ev*/
            int evSize;

          public:
            Species(Species &&other) noexcept;

            virtual ~Species();
            Species(unsigned int atk, unsigned int def, unsigned int atkSpe, unsigned int defSpe, unsigned int spe, unsigned int hp, std::string name, Type type1, Type type2, int maniereEvolution, int niveauEvolution, Evolution *evolType, std::vector<Stats> EVGiven, float height, float weight, std::string opdexEntry, unsigned int expGiven, int expMax, int captureRate, int opdexNumber);
            /**Methode permettant de récuperer l'espèce d'évolution, car le mode d'initialisation des espèces ne permet pas de le faire dans le constructeur*/
            void checkEvol();
            /**Methode ayant la même fonction que checkEvol mais pour les attaques par niveau*/
            void checkAtkLvls();
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
            int getEvSize() const {
                return evSize;
            }
            int getOpdexNumber() const {
                return this->opdexNumber;
            }
        };
    } // namespace Model
} // namespace OpMon
#endif // ESPECE_HPP
