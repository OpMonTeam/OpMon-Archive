/*!
 * \file Evolution.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 * \warning This file is to be completely redone later. It way not have a lot of documentation.
 */
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include "OpMon.hpp"
#include <iostream>

namespace OpMon {

    class Species;
    /**
     * \brief Defines an evolution type
     */
    class Evolution {
    public:
        virtual ~Evolution() {}
        Evolution() {
            evo = -1;
        }
        Evolution(int evo);
        /**\brief Checks if the OpMon evolves.*/
        virtual bool checkEvolve(OpMon const &toCheck) const = 0;
        Species *getEvolution() const;
        /**\brief Gets the Species pointer to the evolution.
           \details Can't be done in the constructor, since the evolution might not be defined yet.*/
        void checkEvo();

    protected:
        Species *toEvolve;
        int evo;
    };

} // namespace OpMon
#endif /* EVOLUTION_HPP */
