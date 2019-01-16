/*
Nature.hpp
Author : Cyrion
Contributor : Navet56
File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_
#define SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_

#include "Enums.hpp"

namespace OpMon {
    namespace Model {

        /**
       Defines a nature. A natures brings a malus and a bonus on a stat. Each OpMon have a nature chosen randomly.
	*/
        class NatureClass {
          public:
            /**The bonus brought by the nature*/
            Stats bonus;
            /**The malus brought by the nature*/
            Stats malus;

            int id;
            NatureClass(Stats bonus, Stats malus, int id)
              : bonus(bonus)
              , malus(malus)
              , id(id){};
        };

        extern const NatureClass natures[25];

        bool operator==(NatureClass const &one, NatureClass const &two);

        /**
       Enumerate the natures
    */
        enum class Nature : unsigned int {
            BOLD = 0,
            BASHFUL = 1,
            BRAVE = 2,
            CALM = 3,
            QUIET = 4,
            DOCILE = 5,
            MILD = 6,
            RASH = 7,
            GENTLE = 8,
            HARDY = 9,
            JOLLY = 10,
            LAX = 11,
            IMPISH = 12,
            SASSY = 13,
            NAUGHTY = 14,
            MODEST = 15,
            NAIVE = 16,
            HASTY = 17,
            CAREFUL = 18,
            QUIRKY = 19,
            RELAXED = 20,
            ADAMANT = 21,
            SERIOUS = 22,
            LONELY = 23,
            TIMID = 24
        };
    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
