/*
Nature.hpp
Author : Jlppc
File under  GPL-3.0 licence
http://opmon-game.ga
Define nature enumerations
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
            BOLD,
            BASHFUL,
            BRAVE,
            CALM,
            QUIET,
            DOCILE,
            MILD,
            RASH,
            GENTLE,
            HARDY,
            JOLLY,
            LAX,
            IMPISH,
            SASSY,
            NAUGHTY,
            MODEST,
            NAIVE,
            HASTY,
            CAREFUL,
            QUIRKY,
            RELAXED,
            ADAMANT,
            SERIOUS,
            LONELY,
            TIMID
        };
    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
