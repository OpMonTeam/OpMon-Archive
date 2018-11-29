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
#include <SFML/System/String.hpp>
#include <cmath>
#include <iostream>

namespace OpMon {
    namespace Model {

        class Species;

        class Attack;

      class Item;
      
        /**
            Class defining a particular OpMon. To see the class that defines a species, see Species.hpp
        */
        class OpMon {

          protected:
          private:
            sf::String nickname;
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

            //General stat
            int statATK;
            int statDEF;
            int statATKSPE;
            int statDEFSPE;
            int statSPE;
            //Other stats
            int statEVA;
            float statACC;
            int statHP;
            int statLove;
            //Variables indicating stats variation level (See changeSTAT methods (Ex : changeATK) )
            int atkChange = 0;
            int defChange = 0;
            int defSpeChange = 0;
            int atkSpeChange = 0;
            int evaChange = 0;
            int accChange = 0;
            int speChange = 0;
            const Species *species;
            int level;

            std::vector<Attack *> attacks;

            Nature nature;

            /**Warning: This variable contains the current PV of the OPMon, the statPV class contains the max PV*/
            int HP;
            //->ExpectEnum->Status
            Status status = Status::NOTHING;
            //->ExpectEnum->Type
            Type type1;
            //->ExpectEnum->Type
            Type type2;

            int exp;
            /**The exp to get to reach the next level*/
            int toNextLevel;
            /**In some cases, like a exchange, the OpMon can get an exp boost*/
            float expBoost = 1;

            /**The item held*/
            Item *held;

            int captureRate;

            unsigned int confusedCD = 0;
            unsigned int sleepingCD = 0;

          public:
            /**Lets you know if a OPMon is an OPMon that is initialized with a default initializer*/
            //Not very useful anymore I think...
            bool initialized = true;

            bool confused = false;
            bool afraid = false;
            bool inLove = false;
            bool vampigraine = false;
            bool malediction = false;

            virtual ~OpMon();

            OpMon(const std::string &nickname, const Species *species, int level, const std::vector<Attack *> &attacks,
                  Nature nature);

            OpMon() {
                initialized = true;
            }

            int getConfusedCD() {
                return confusedCD;
            }

            int getSleepingCD() {
                return sleepingCD;
            }

            void passCD(bool sleep);

            void goToSleep() {
                sleepingCD = Utils::Misc::randU(3);
                setStatus(Status::SLEEPING);
            }

            void drinkTooMuch() {
                confused = true;
                confusedCD = Utils::Misc::randU(4);
            }

            /**Returns true if the OPMon is well captured*/
            bool captured(Item const &OpBox);

            /** Set the stat given*/
            void setStat(Stats stat, int newStat);

            /**Method called when leveling up*/
            void levelUp();

            bool isHoldingItem() const {
                return (held == nullptr);
            }

            /**Method called when the Opmon wins*/
            int win(OpMon const &vaincu);

            /**Recalculates the stats*/
            void calcStats();

            /**Method called when an item is used. Returns true if the item must be deleted from the player's inventory*/
            bool itemUsed(Item *used);

            Item *hold(Item *item);
            /**Method called during an exchange*/
            void traded();

            /**Method called when the OpMon is about to evolve*/
            void evolve();

            /**Allows to completely change the OPMon*/
            void setStats(int stats[], Attack *attacks[], const Species &species, Type types[]);

            /**Attack the OpMon (he looses HP)*/
            void attacked(int hpPerdus);

            /**Changes the STAT depending of the power given. It doesn't edit directly the variable, it lowers or increases (Depending of the power's sign) by multiplicating it.*/
            int changeATK(int power);

            int changeACC(int power);

            int changeEVA(int power);

            int changeDEF(int power);

            int changeATKSPE(int power);

            int changeDEFSPE(int power);

            int changeSPE(int power);

            Status getStatus() {
                return status;
            }

            /**Changes OpMon's status*/
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

            sf::String &getNickname() {
                return nickname;
            }

            /**Heals the OPMon (Opposite of attack() )*/
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

            //Warning! The == and != operators do not compare two OPMons! They compare whether OPMons are "initialized" or not (see initialized))
            //Yup, I should change this in the future (TODO)
            bool operator==(OpMon const &a) {
                return (initialized == a.initialized);
            }

            bool operator!=(OpMon const &a) {
                return !(initialized == a.initialized);
            }

            Item *itemHeld() const {
                return held; //It's a getted, even if there is no "get" before.
            }

            std::string save();
        };

    } // namespace Model
} // namespace OpMon

#endif // OpMon_HPP
