/*
Item.hpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_ITEM_HPP_

#include "../Enums.hpp"
#include <iostream>
#define ITEM_NUMBER 151

//TODO : Redo the item system

namespace OpMon {
    namespace Model {

        enum class ItemType : int {
            Unknown = 0,
            IHeal = 1,
            IOpBox = 2,
            ICT = 3
        };
        /**
       Enumarions containing the items ids
		*/
        /*enum class Items : unsigned int {

        };*/

        class Item {
          public:
            /**Items list*/
            static Item *itemsLst[ITEM_NUMBER];
            Item(std::string name, bool usable, bool usableInFight, bool givable, BagCat categorie, int id);
            static Item *getItem(std::string const &name);
            static Item *getItem(int id);
            /**Searches an item and returns it's ID*/
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
