/*
evolutions.hpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#ifndef EVOLUTIONS_HPP_INCLUDED
#define EVOLUTIONS_HPP_INCLUDED

#include "../item/Item.hpp"
#include "Evolution.hpp"
#include <iostream>
#pragma GCC diagnostic ignored "-Wunused-parameter"
namespace OpMon {
    namespace Model {

        /**
       Namespace containing evolution definitions
		*/
        namespace Evolutions {

            const int EItem = 7, ELand = 6, ELevel = 5, ELove = 4, ENope = 3, ETrade = 2, ETradeItem = 1;

            class E_Item : public Evolution {
              public:
                E_Item(int evo, Item *forEvolve);
                bool checkEvolve(OpMon const &toCheck) const;
                bool itemEvolve(Item *forEvolve) const;
                const int evolID = 7;

              protected:
                Item *forEvolve;
            };

            class E_Land : public Evolution {
              public:
                E_Land(int evo, std::string lieu);

                bool checkEvolve(OpMon const &toCheck) const {
                    return false; //TODO : Check if the map where the player is is the good map.
                }

                const int evolID = 6;

              private:
                //Map* place;
            };

            class E_Level : public Evolution {
              public:
                E_Level(int evo, int level);
                bool checkEvolve(OpMon const &toCheck) const;
                const int evolID = 5;

              private:
                int level;
            };

            class E_Love : public Evolution {
              public:
                E_Love(int evo)
                  : Evolution(evo) {}
                bool checkEvolve(OpMon const &toCheck) const {
                    return (toCheck.getStatLove() > 100);
                }
                const int evolID = 4;

              private:
            };

            class E_Nope : public Evolution {
              public:
                E_Nope(){};
                bool checkEvolve(OpMon const &toCheck) const {
                    return false;
                };
                const int evolID = 3;
            };

            class E_Trade : public Evolution {
              public:
                E_Trade(int evo)
                  : Evolution(evo){};
                bool checkEvolve(OpMon const &toCheck) const {
                    return true;
                }
                const int evolID = 2;
            };

            class E_TradeItem : public E_Item {
              public:
                E_TradeItem(int evo, Item *forEvolve, int ID)
                  : E_Item(evo, forEvolve){};
                bool checkEvolve(OpMon const &toCheck);
                const int evolID = 1;
            };
        } // namespace Evolutions

        using namespace Evolutions;
    } // namespace Model
} // namespace OpMon
#pragma GCC diagnostic pop
#endif // EVOLUTIONS_HPP_INCLUDED
