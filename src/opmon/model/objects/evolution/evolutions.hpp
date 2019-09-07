/*
evolutions.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#ifndef EVOLUTIONS_HPP_INCLUDED
#define EVOLUTIONS_HPP_INCLUDED

#include "../Item.hpp"
#include "Evolution.hpp"
#include <iostream>

namespace OpMon::Model {

    /**
	   Namespace containing evolution definitions
	*/
    namespace Evolutions {

        class E_Item : public Evolution {
          public:
            E_Item(int evo, std::string itemID);
            [[nodiscard]] bool checkEvolve(OpMon const &toCheck) const override;

          protected:
            const std::string itemID;
        };

        class E_Level : public Evolution {
          public:
            E_Level(int evo, int level);
            [[nodiscard]] bool checkEvolve(OpMon const &toCheck) const override;

          private:
            int level;
        };
    } // namespace Evolutions

    using namespace Evolutions;
} // namespace OpMon::Model

#endif // EVOLUTIONS_HPP_INCLUDED
