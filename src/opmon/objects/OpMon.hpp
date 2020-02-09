/*!
  \file OpMon.hpp
  \author Cyrielle
  \copyright GNU GPL 3.0
*/
#ifndef OPMON_HPP
#define OPMON_HPP

#include "../../utils/misc.hpp"
#include "Nature.hpp"
#include "Species.hpp"
#include <SFML/System/String.hpp>
#include <cmath>
#include <iostream>

namespace OpMon {

    class Species;

    class Attack;

    class Item;

    /*!
      \brief Class defining an OpMon. To see the class defining a species, see Species
      \todo Re-check the class a bit, rewrite what's necessary. There is a lot of old code here. Also check for french and translate it.
      \todo Change the IV, EV and stat variables into arrays working with the enumeration Stats.
      \todo Delete the stat variables and make the methods returing the stats calculating them.
      \todo Finish to document the file when the changes are done.
    */
    class OpMon {
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

        int HP;
        Status status = Status::NOTHING;
        Type type1;
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
        bool confused = false;
        bool afraid = false;
        bool inLove = false;

        virtual ~OpMon();

        /*!
         * \param nickname The OpMon's nickname. Replaced by the species name if empty.
         * \param species The OpMon's species.
         * \param level The OpMon's level.
         * \param attacks The OpMon's attacks.
         */
        OpMon(const std::string &nickname, const Species *species, int level, const std::vector<Attack *> &attacks,
              Nature nature);

        int getConfusedCD() const {
            return confusedCD;
        }

        int getSleepingCD() const {
            return sleepingCD;
        }

        /*!
         * \brief Updates the sleep or confused countdown.
         * \param sleep If `true`, updates the sleep countdown, if `false`, updates the confused countdown.
         */
        void passCD(bool sleep);

        /*!
         * \brief Makes the OpMon asleep.
         */
        void goToSleep() {
            sleepingCD = Utils::Misc::randU(3);
            setStatus(Status::SLEEPING);
        }

        /*!
         * \brief Makes the OpMon confused.
         * \todo Change the name, maybe ?
         */
        void drinkTooMuch() {
            confused = true;
            confusedCD = Utils::Misc::randU(4);
        }

        /**Returns true if the OPMon is well captured*/
        /*!
         * \brief Calculates the capture of an OpMon.
         * \param OpBox The OpBox used to capture the OpMon.
         * \returns `true` if the OpMon is captured, `false` otherwise.
         */
        bool captured(Item const &OpBox);

        /*!
         * \brief Sets a stat.
         * \param stat The stat to set.
         * \param newStat The new value of the stat.
         */
        void setStat(Stats stat, int newStat);

        /*!
         * \brief Makes the OpMon level up.
         */
        void levelUp();

        /*!
         * \brief Returns if the OpMon is holding an item or not.
         * \returns `true` if the held item is not `nullptr`, `false` otherwise.
         */
        bool isHoldingItem() const {
            return (held != nullptr);
        }

        /*!
         * \brief Method called when the OpMon wins against another one.
         * \param defeated The defeated OpMon.
         * \returns The number of exp gained by this OpMon.
         */
        int win(OpMon const &defeated);

        /*!
         * \brief Calculates the stats
         */
        void calcStats();

        /*!
         * \warn Work in progress.
         * \brief Method called when an item is used.
         * \return `true` if the item has to be deleted from the player's inventory.
         */
        bool itemUsed(Item *used);

        /*!
         * \brief Makes the OpMon hold an item.
         * \return The previous held item.
         * \param item The item the hold.
         */
        Item *hold(Item *item);

        /*!
         * \brief Method called when the OpMon evolves.
         */
        void evolve();

        /*!
         * \brief Changes different stats of the OpMon.
         * \param stats An array containing the stats in the order of the enumeration Stats.
         * \param attacks An array containing up to 4 attacks.
         * \param species The new species of the OpMon.
         * \param types The two new types of the OpMon.
         */
        void setStats(int stats[], Attack *attacks[], const Species &species, Type types[]);

        /*!
         * \brief Makes the OpMon loose HP.
         * \details The method makes sure the HP can't go below 0.
         * \param hpLost The HP lost by the OpMon.
         */
        void attacked(int hpLost);

        /*!
         * \brief Changes the STAT depending of the power given.
         * \details It doesn't edit directly the variable, it lowers or increases (Depending of the sign of the paramter) by multiplicating it.
         * \param power The power of the change (negative if the stat descreases, positif if it increases).
         */
        int changeATK(int power);
        /*!
         * \copydoc OpMon::changeATK
         */
        int changeACC(int power);
        /*!
         * \copydoc OpMon::changeATK
         */
        int changeEVA(int power);
        /*!
         * \copydoc OpMon::changeATK
         */
        int changeDEF(int power);
        /*!
         * \copydoc OpMon::changeATK
         */
        int changeATKSPE(int power);
        /*!
         * \copydoc OpMon::changeATK
         */
        int changeDEFSPE(int power);
        /*!
         * \copydoc OpMon::changeATK
         */
        int changeSPE(int power);

        Status getStatus() {
            return status;
        }

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

        /*!
         * \brief Returns the OpMon's nickname.
         */
        sf::String getNickname() const {
            return nickname;
        }

        /*!
         * \brief Returns a reference to the OpMon's nickname.
         */
        sf::String &getNicknameRef() {
            return nickname;
        }

        /*!
         * \brief Returns a pointer to the OpMon's nickname.
         */
        sf::String *getNicknamePtr() {
            return &nickname;
        }

        /*!
         * \brief Heals the OPMon (Opposite of attack()). Makes sure the HP doesn't go higher than the maximum HP.
         */
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

        /*!
         * \brief Gives the OpMon the evs gained by defeating an OpMon.
         * \param defeated The defeated OpMon.
         */
        void getEvs(OpMon const &defeated);

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

        Item *itemHeld() const {
            return held;
        }

    };

} // namespace OpMon

#endif // OpMon_HPP
