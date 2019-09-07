/*
Evolution.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include "../OpMon.hpp"
#include <iostream>

//TODO : Enhance the evolution system

namespace OpMon::Model {

    class Species;
    /**
		Defines an evolution type
		*/
    class Evolution {
      public:
        virtual ~Evolution() = default;
        Evolution() {
            evo = -1;
        }
        explicit Evolution(int evo);
        /**Checks if the OpMon evolves.*/
        [[nodiscard]] virtual bool checkEvolve(OpMon const &toCheck) const = 0;
        [[nodiscard]] Species *getEvolution() const;
        /**Gets the Species pointer to the evolution. Can't be done in the constructor, since the evolution might not be defined yet.*/
        void checkEvo(); // TODO

      protected:
        Species *toEvolve;
        int evo;
    };

} // namespace OpMon::Model
#endif /* EVOLUTION_HPP */
