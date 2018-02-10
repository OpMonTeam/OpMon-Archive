/*
  OpMon.hpp
  Author : Jlppc
  File under the GPL 3.0 license.
  http://opmon-game.ga
  Contains CalCourbs namespace defintions and OpMon class
*/
#ifndef OPMON_HPP
#define OPMON_HPP

#include "../../../utils/misc.hpp"
#include "Nature.hpp"
#include "Species.hpp"
#include "item/IOpBox.hpp"
#include "item/Item.hpp"
#include <cmath>
#include <iostream>

namespace OpMon {
    namespace Model {

        class Species;

        /**
           Namespace permettant de faire des calculs sur les courbes d'experience. D'ou son nom, j'ai envie de dire...
        */
        namespace CalcCourbs {
            float p(int x);

            int erratic(int n);

            int fluctuating(int n);

            int slow(int n);

            int normal(int n);

            int parabolic(int n);

            int quick(int n);
        } // namespace CalcCourbs

        class Attack;

        /**
            Class defining a particular OpMon. To see the class that defines a species, see Species.hpp
        */
        class OpMon {

          protected:
          private:
            std::string nickname;
            int atkIV = Utils::Misc::randU(32);
            int defIV = Utils::Misc::randU(32);
            int atkSpeIV = Utils::Misc::randU(32);
            int defSpeIV = Utils::Misc::randU(32);
            int speIV = Utils::Misc::randU(32);
            int hpIV = Utils::Misc::randU(32);
            int atkEV = 0;
            int defEV = 0;
            int atkSpeEV = 0;
            int defSpeEV = 0;
            int speEV = 0;
            int hpEV = 0;

            //Les statistiques en general
            int statATK;
            int statDEF;
            int statATKSPE;
            int statDEFSPE;
            int statSPE;
            //Les autrees stats.
            int statEVA;
            float statACC;
            int statHP;
            int statLove;
            //Les variables indiquant le niveau de changement.
            int atkChange = 0;
            int defChange = 0;
            int defSpeChange = 0;
            int atkSpeChange = 0;
            int evaChange = 0;
            int accChange = 0;
            int speChange = 0;

            int level;

            Nature nature;

            std::vector<Attack *> attacks;

            const Species *species;
            /**Warning: This variable contains the current PV of the OPMon, the statPV class contains the max PV*/
            int HP;
            //->ExpectEnum->Status
            Status status = Status::NOTHING;
            //->ExpectEnum->Type
            Type type1;
            //->ExpectEnum->Type
            Type type2;

            int exp;
            /**L'experience a avoir pour le prochain niveau*/
            int toNextLevel;
            float expBoost = 1;

            /**L'item tenu*/
            Item *held;

            int tauxCapture;

          public:
            /**Lets you know if a OPMon is an OPMon that is initialized with a default initializer*/
            bool falsif = true;

            bool confus = false;
            bool peur = false;
            bool amour = false;
            bool vampigraine = false;
            bool malediction = false;

            virtual ~OpMon();

            OpMon(const std::string &nickname, const Species &species, int level, const std::vector<Attack *> &attacks,
                  Nature nature);

            /**
         Merci d'utiliser ce constructeur dans le cadre du chargement et UNIQUEMENT dans ce cas, sinon cela pourrait
         conduire a des bugs. Explication : Ce constructeur est concu pour marcher dans un shema bien particulier.
         Si le shema est incorrect, cela génèrera des erreurs de segmentation ou des données corrompues.
            */
            OpMon(std::ifstream &in);

            /**Returns true if the OPMon is well captured*/
            bool captured(I_OpBox const &OpBox);

            /**Permet de changer une stat, les possibilités d'entrées dans le paramètre stat sont "ATK" "DEF" "ATKSPE" "DEFSPE" "SPE" "PV"*/
            void setStat(Stats stat, int newStat);

            /**Methode appellée lors d'une montée de niveau*/
            void levelUp();

            bool isHoldingItem() const {
                return (held == nullptr);
            }

            /**Methode appelée lors d'une victoire*/
            int win(OpMon const &vaincu);

            /**Recalcule les stats*/
            void calcStats();

            /**Methode appelée lors de l'utilisation d'un item. Renvoie true si l'item est a supprimer*/
            bool itemUsed(Item *used);

            Item *hold(Item *item); //Cette est un setteur, en gros.
            /**Methode appelée lors d'un échange*/
            void traded();

            /**SPOILERSµµµ*/
            void toolEvTrade(); //SPOILERS!
            /**Methode appelée lors de l'évolution*/
            void evolve();

            /**Allows to completely change the OPMon*/
            void setStats(int stats[], Attack *attacks[], const Species &species, Type types[]);

            /**Fait perdre des pv*/
            void attacked(int hpPerdus);

            /**Les methode suivantes modifient les stats en fonction des niveaux. Cela ne modifie pas directement la stat*/
            bool changeATK(int power);

            bool changeACC(int power);

            bool changeEVA(int power);

            bool changeDEF(int power);

            bool changeATKSPE(int power);

            bool changeDEFSPE(int power);

            bool changeSPE(int power);

            Status getStatus() {
                return status;
            }

            /**Change le status*/
            bool setStatus(Status status);

            int getStatHP() const {
                return statHP;
            }

            int getStatLove() const {
                return statLove;
            }

            int getHP() const {
                return HP;
            }

            std::string getNickname() {
                return nickname;
            }

            /**Heal the OPMon*/
            void heal(int HP);

            int getLevel() const {
                return level;
            }

            std::vector<Attack *> getAttacks() {
                return attacks;
            }

            int getStatEVA() const {
                return statEVA;
            }

            int getStatACC() const {
                return statACC;
            }

            void getEvs(OpMon const &vaincu);

            Type getType1() const {
                return type1;
            }

            Type getType2() const {
                return type2;
            }

            void setType1(Type type);

            void setType2(Type type);

            int getStatATK() const {
                return statATK;
            }

            int getStatATKSPE() const {
                return statATKSPE;
            }

            int getStatDEF() const {
                return statDEF;
            }

            int getStatDEFSPE() const {
                return statDEFSPE;
            }

            int getStatSPE() const {
                return statSPE;
            }

            const Species &getSpecies() const {
                return *species;
            }

            //Warning! The == and! = operators did not compare two OPMons! They compare whether OPMons are "falsif" or not (see falsif))
            bool operator==(OpMon const &a) {
                return (falsif == a.falsif);
            }

            bool operator!=(OpMon const &a) {
                return !(falsif == a.falsif);
            }

            Item *itemHeld() const {
                return held; //C'est un getteur. Y'a pas get mais je m'en fous. C'est un getteur.
            }

            std::string save();
        };

    } // namespace Model
} // namespace OpMon

#endif // OpMon_HPP
