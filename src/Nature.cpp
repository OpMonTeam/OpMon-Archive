/*
  Nature.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "Nature.hpp"

#include "Enums.hpp"

namespace OpMon {

    const NatureClass BOLD = NatureClass(Stats::DEF, Stats::ATK, 0),
        BASHFUL = NatureClass(Stats::NOTHING, Stats::NOTHING, 1),
        BRAVE = NatureClass(Stats::ATK, Stats::SPE, 2),
        CALM = NatureClass(Stats::DEFSPE, Stats::ATK, 3),
        QUIET = NatureClass(Stats::ATKSPE, Stats::SPE, 4),
        DOCILE = NatureClass(Stats::NOTHING, Stats::NOTHING, 5),
        MILD = NatureClass(Stats::ATKSPE, Stats::DEF, 6),
        RASH = NatureClass(Stats::ATKSPE, Stats::DEFSPE, 7),
        GENTLE = NatureClass(Stats::DEFSPE, Stats::DEF, 8),
        HARDY = NatureClass(Stats::NOTHING, Stats::NOTHING, 9),
        JOLLY = NatureClass(Stats::SPE, Stats::ATKSPE, 10),
        LAX = NatureClass(Stats::DEF, Stats::DEFSPE, 11),
        IMPISH = NatureClass(Stats::DEF, Stats::ATKSPE, 12),
        SASSY = NatureClass(Stats::DEFSPE, Stats::SPE, 13),
        NAUGHTY = NatureClass(Stats::ATK, Stats::DEFSPE, 14),
        MODEST = NatureClass(Stats::ATKSPE, Stats::ATK, 15),
        NAIVE = NatureClass(Stats::SPE, Stats::DEFSPE, 16),
        HASTY = NatureClass(Stats::SPE, Stats::DEF, 17),
        CAREFUL = NatureClass(Stats::DEFSPE, Stats::ATKSPE, 18),
        QUIRKY = NatureClass(Stats::NOTHING, Stats::NOTHING, 19),
        RELAXED = NatureClass(Stats::DEF, Stats::SPE, 20),
        ADAMANT = NatureClass(Stats::ATK, Stats::ATKSPE, 21),
        SERIOUS = NatureClass(Stats::NOTHING, Stats::NOTHING, 22),
        LONELY = NatureClass(Stats::ATK, Stats::DEF, 23),
        TIMID = NatureClass(Stats::SPE, Stats::ATK, 24);

    const NatureClass natures[25] = {BOLD, BASHFUL, BRAVE, CALM, QUIET, DOCILE, MILD, RASH, GENTLE, HARDY, JOLLY, LAX, IMPISH, SASSY, NAUGHTY, MODEST, NAIVE, HASTY, CAREFUL, QUIRKY, RELAXED, ADAMANT, SERIOUS, LONELY, TIMID};

    bool operator==(NatureClass const &one, NatureClass const &two) {
        if((one.malus == two.malus) && (one.bonus == two.bonus)) {
            return true;
        }
        return false;
    }

} // namespace OpMon
