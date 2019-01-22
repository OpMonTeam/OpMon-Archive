/*
Enums.hpp
Author : Cyriel
Contributor : BAKFR, Samurai413x
File under GNU GPL v3.0 license
*/
#ifndef ENUMS_HPP
#define ENUMS_HPP

/**Macros created to make the effectivenesses table more easy to read*/
#define NOT 0    //Not effective at all
#define VLO 0.25 //Very low effectiveness
#define LO_ 0.5  //Low effectiveness
#define AVG 1    //Average effectiveness
#define HI_ 2    //High effectiveness
#define VHI 4    //Very High effectiveness

namespace OpMon {
    namespace Model {

        /**
	 Enumerate the OPMons status
      */
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
        enum class BagCat {
            HEAL,
            OBJECTS,
            RARES,
            HMS
        };
        /**
	   Enumerate the OPMons types
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
        /**
       Enumerates kinds of contacts between events and the player.
    */
        enum class ActionType {
            ENTER,
            TOUCH,
            IN_,
            VIEW
        };
        /**
	   Enumerates sprites directions.
	*/
        enum class Side : int {
            TO_DOWN = 0,
            TO_RIGHT = 1,
            TO_LEFT = 2,
            TO_UP = 3,
            NO_MOVE = -1,
            STAY = -2
        };

        /**
	   Enumerates differents encodings
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

        namespace ArrayTypes {

            float calcEffectiveness(Type atk, Type def1, Type def2);

        } // namespace ArrayTypes
    }     // namespace Model
} // namespace OpMon

#endif /* ENUMS_HPP */
