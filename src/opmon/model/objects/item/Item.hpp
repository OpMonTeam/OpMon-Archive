/*
  Item.hpp
  Author : Jlppc
  File under the licence GPL-3.0
  http://opmon-game.ga
  Contains the definition of ItemType enumeration and Item class
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

#include "../Enums.hpp"
#include <iostream>
#define ITEM_NUMBER 151

namespace OpMon {
    namespace Model {

        /**
       Namespace énumérant les types de classes d'item
    */
        enum class ItemType : int {
            Unknown = 0,
            IHeal = 1,
            IOpBox = 2,
            ICT = 3
        };
        /**
       Enumarions containing the items ids
    */
        enum class Items : unsigned int {

        };
        /**
       Classe définissant un item du jeu
    */
        class Item {
          public:
            /**La liste des items du jeu*/
            static Item *itemsLst[ITEM_NUMBER];
            Item(std::string name, bool usable, bool usableInFight, bool givable, BagCat categorie, int id);
            static Item *getItem(std::string const &name);
            static Item *getItem(int id);
            /**Recherche un item et renvoie son ID dans itemsList*/
            static int searchItem(Item *toSearch);
            bool operator==(Item const &b) const;
            std::string getName() const {
                return name;
            }
            bool isUsable() const {
                return usable;
            }
            bool isGivable() const {
                return givable;
            }
            BagCat getCategorie() const {
                return categorie;
            }
            bool isUsableInFight() const {
                return usableInFight;
            }
            int getID() const {
                return id;
            }
            static int getItemNumber() {
                return ITEM_NUMBER;
            }
            virtual ItemType getItemTypeID() const {
                return itemTypeID;
            }

          private:
            ItemType itemTypeID = ItemType::Unknown;
            std::string name;
            bool usable;
            bool givable;
            BagCat categorie;
            bool usableInFight;
            int id;
        };

        void initItems();

    } // namespace Model
} // namespace OpMon

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_ */
