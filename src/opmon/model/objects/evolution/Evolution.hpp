/*
Evolution.hpp
Author : Cyriel
File under GNU GPL v3.0 license
*/
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include "../OpMon.hpp"
#include <iostream>

//TODO : Enhance the evolution system

namespace OpMon {
    namespace Model {

        class Species;
        /**
		Defines an evolution type
		*/
        class Evolution {
          public:
            virtual ~Evolution() {}
            Evolution() {
                evo = -1;
            }
            Evolution(int evo);
            /**Checks if the OpMon evolves.*/
            virtual bool checkEvolve(OpMon const &toCheck) const = 0;
            Species *getEvolution() const;
            /**Gets the Species pointer to the evolution. Can't be done in the constructor, since the evolution might not be defined yet.*/
            void checkEvo();
	  
          protected:
            Species *toEvolve;
            int evo;
        };

    } // namespace Model
} // namespace OpMon
#endif /* EVOLUTION_HPP */
