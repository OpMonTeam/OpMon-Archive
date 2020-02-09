/*!
 * \file Nature.hpp
 * \authors Cyrielle
 * \authors Navet56
 * \copyright GNU GPL v3.0
 * \todo Improve the system of natures.
 */
#ifndef SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_
#define SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_

#include "Enums.hpp"

namespace OpMon {

    /*!
     * \brief Defines a nature.
     *
     * A natures brings a malus and a bonus on some stats. Each OpMon have a randomy-generated nature.
     */
    class NatureClass {
    public:
        /*!
         * \brief The bonus brought by the nature.
         */
        Stats bonus;
        /*!
         * \brief The malus brought by the nature.
         */
        Stats malus;
        /*!
         * \brief The id of the nature.
         */
        int id;
        /*!
         * \brief Creates an object.
         * \param bonus \copydoc NatureClass::bonus
         * \param malus \copydoc NatureClass::malus
         * \param id \copydoc NatureClass::id
         */
        NatureClass(Stats bonus, Stats malus, int id)
            : bonus(bonus)
            , malus(malus)
            , id(id){};
    };

    /*!
     * \brief Array containing every nature.
     */
    extern const NatureClass natures[25];

    /*!
     * \brief Compares two natures.
     */
    bool operator==(NatureClass const &one, NatureClass const &two);

    /**
     * \brief Enumerates the natures
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
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
