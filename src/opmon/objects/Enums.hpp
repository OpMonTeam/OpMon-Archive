/*!
 * \file Enums.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \authors Samurai413x
 * \copyright GNU GPL v3.0
*/
#ifndef ENUMS_HPP
#define ENUMS_HPP

/*Macros created to make the effectivenesses table more easy to read*/

#define NOT 0    /*!<\brief Not effective at all*/
#define VLO 0.25 /*!< \brief Very low effectiveness*/
#define LO_ 0.5  /*!< \brief Low effectiveness*/
#define AVG 1    /*!< \brief Average effectiveness*/
#define HI_ 2    /*!< \brief High effectiveness*/
#define VHI 4    /*!< \brief Very High effectiveness*/

namespace OpMon {
    namespace Model {

        /*!
         * \brief Enumerates the OpMon statuses.
         */
        enum class Status {
            BURNING,
            PARALYSED,
            SLEEPING,
            FROZEN,
            POISONED,
            NOTHING
        };
        /*!
         * \brief Enumerates the OpMon stats.
         */
        enum class Stats : int {
            ATK = 6,/*!< Attack*/
            DEF = 1,/*!< Defense*/
            ATKSPE = 2,/*!< Special Attack*/
            DEFSPE = 3,/*!< Special Defense*/
            SPE = 4,/*!< Speed*/
            HP = 5,/*!< Health Points*/
            ACC = 7,/*!< Accuracy*/
            EVA = 8,/*!< Evasion*/
            NOTHING = 0
        };
        /*!
         * \brief Enumerates the bag categories
         */
        enum class BagCat {
            HEAL,
            OBJECTS,
            RARES,
            HMS
        };
        /**
         * \brief Enumerates the OpMon types
         */
        enum class Type : int {
            LIQUID = 3,
            BURNING = 6,
            VEGETAL = 10,
            ELECTRON = 4,
            MENTAL = 12,
            BAD = 16,
            DRAGON = 2,
            FIGHT = 1,
            MINERAL = 13,
            GROUND = 14,
            NEUTRAL = 9,
            MAGIC = 5,
            GHOST = 15,
            TOXIC = 11,
            METAL = 0,
            BUG = 8,
            SKY = 17,
            COLD = 7,
            NOTHING = -1
        };
        /*!
         * \brief Enumerates the different types of contacts between events and the player.
         */
        enum class ActionType {
            ENTER,/*!< Event activated by pressing the action key.*/
            TOUCH,/*!< Event activated by the player being in an adjacent square from the event.*/
            IN_,/*!< Event activated by the player being on the same square as the event.*/
            VIEW/*!< Event activated as soon as it is on the screen.*/
        };
        /*!
         * \brief Enumerates sprite directions.
         */
        enum class Side : int {
            TO_DOWN = 0,
            TO_RIGHT = 1,
            TO_LEFT = 2,
            TO_UP = 3,
            NO_MOVE = -1,
            STAY = -2
        };

        /*!
         * \brief Enumerates different encodings
         */
        enum class Encoding {
            LATIN,
            UNICODE,
            UTF8
        };

        bool operator==(Side side, int integer);
        bool operator!=(Side side, int integer);
        bool operator>=(Side, int);
        bool operator>(Side, int);
        bool operator<=(Side, int);
        bool operator<(Side, int);
        int operator+(Side, int);
        int operator-(Side, int);
        Side getSide(int);

        /*!
         * \brief Contains the type effectiveness-related functions / objects
         */
        namespace ArrayTypes {
            /*!
             * \brief Calculates the effectiveness of an attack and returns it.
             * \return The effectiveness.
             * \param atk The type of the attack.
             * \param def1 The first type of the OpMon.
             * \param def2 The second type of the OpMon.
             */
            float calcEffectiveness(Type atk, Type def1, Type def2);

        } // namespace ArrayTypes
    }     // namespace Model
} // namespace OpMon

#endif /* ENUMS_HPP */
