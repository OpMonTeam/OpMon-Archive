/*
Enums.hpp
Author : Jlppc
File under GPL-3.0 license
http://opmon-game.ga
Define lot of enumerations
*/
#ifndef ENUMS_HPP
#define ENUMS_HPP

/**Defines permettant de rendre plus pratique l'écriture des tables des types*/
#define NOT 0    //Not effective at all
#define VLO 0.25 //Very low effectiveness
#define LO_ 0.5  //Low effectiveness
#define AVG 1    //Average effectiveness
#define HI_ 2    //High effectiveness
#define VHI 4    //Very High effectiveness

namespace OpMon {
    namespace Model {

        /**
       Enumerate the OPMons statues
    */
        //->Enum
        enum class Status {
            BURNING,
            PARALYSED,
            SLEEPING,
            FROZEN,
            POISONED,
            NOTHING
        };
        /**
       Enumerate the OPMons stats
    */
        //->Enum
        enum class Stats : int {
            ATK = 6,
            DEF = 1,
            ATKSPE = 2,
            DEFSPE = 3,
            SPE = 4,
            HP = 5,
            ACC = 7,
            EVA = 8,
            NOTHING = 0
        };
        /**
       Enumerate the bag categories
    */
        //->Enum
        enum class BagCat {
            HEAL,
            OBJECTS,
            RARES,
            HMS
        };
        /**
       Enumerate the OPMons types
    */
        //->Enum
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
        /**
       Enumère les types de contacts entre un evènement et le joueur.
    */
        //->Enum
        enum class ActionType {
            ENTER,
            TOUCH,
            IN_,
            VIEW
        };
        /**
       Enumère les directions des sprites.
    */
        //->Enum
        enum class Side : int {
            TO_DOWN = 0,
            TO_RIGHT = 1,
            TO_LEFT = 2,
            TO_UP = 3,
            NO_MOVE = -1,
            STAY = -2
        };

        /**
       Enumère les differents encodages
    */
        //->Enum
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

        namespace ArrayTypes {

            float calcEffectiveness(Type atk, Type def1, Type def2);

        } // namespace ArrayTypes
    }     // namespace Model
} // namespace OpMon

#endif /* ENUMS_HPP */
