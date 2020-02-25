/*!
  \file Species.hpp
  \authors Cyrielle
  \authors Stelyus
  \authors BAKFR
  \authors Navet56
  \authors JonnyPtn
  \copyright GNU GPL v3.0
*/
#ifndef ESPECE_HPP
#define ESPECE_HPP

#include <iostream>
#include <vector>
#include <string>

#include "CurveExp.hpp"
#include "Enums.hpp"

namespace OpMon {
    class Evolution;
class CurveExp;

    /*!
     * \brief Defines a species of OpMon.
     * \todo Put the stats in one array.
     * \todo Add a json constructor.
     */
    class Species {
    private:
        std::string name;
        int opdexNumber; /*!< \brief The number of the Species in the OpDex.*/
        Species *evolution; /*!< \biref The species in which the current species evolves.*/
        Evolution *evolType; /*!< \brief The way the species evolves*/
        Type type1;
        Type type2;
        std::string opdexEntry;/*!< \brief The descrption of the species in the OpDex.*/
        float height;
        float weight;
        unsigned int baseAtk;
        unsigned int baseDef;
        unsigned int baseAtkSpe;
        unsigned int baseDefSpe;
        unsigned int baseSpe;
        unsigned int baseHP;
        CurveExp *curve; /*!< \brief The EXP curve used by the species.*/
        /*! \brief The total EXP the OpMon can have (EXP at level max) */
        int expMax;
        /*! \brief Array representing the EV given by the OpMon when defeated. */
        std::vector<Stats> EVgiven; /*!< \brief The EVs given when one OpMon of this species is defeated.*/

        unsigned int expGiven; /*!< \brief The base EXP given when one OpMon of this species if defeated.*/ 
        int captureRate; /*!< \brief The capture rate of the species*/

    public:
        Species(Species &&other) noexcept;

        virtual ~Species();
        /*!
         * \param atk
         * \param def
         * \param atkSpe
         * \param defSpe
         * \param spe
         * \param hp
         * \param name
         * \param type1
         * \param type2
         * \param evolType The way the species evolves.
         * \param evGiven The EVs given when one OpMon of this species is defeated.
         * \param height
         * \param weight
         * \param opdexEntry The descrption of the species in the OpDex.
         * \param expGiven The base EXP given when one OpMon of this species if defeated.
         * \param captureRate The capture rate of the species.
         * \param opdexNumber The number of the Species in the OpDex.
         */
        Species(unsigned int atk, unsigned int def, unsigned int atkSpe, unsigned int defSpe, unsigned int spe, unsigned int hp, std::string name, Type type1, Type type2, Evolution *evolType, std::vector<Stats> evGiven, float height, float weight, std::string opdexEntry, unsigned int expGiven, int expMax, int captureRate, int opdexNumber);
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
} // namespace OpMon
#endif // ESPECE_HPP
