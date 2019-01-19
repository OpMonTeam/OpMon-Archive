/*
IHeal.hpp
Author : Cyrion
File under GNU GPL v3.0 license
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_

#include "Item.hpp"
#include <iostream>

namespace OpMon {
    namespace Model {
        /**
       Define care item
    */
        class I_Heal : public Item {
          public:
            /**Build a heal item nearly polyvalent*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, int hpHeal, Status heal, bool healAllStatus, int ID);
            /**Build a PP heal item*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, int ppHeal, bool allAttacksHeal, int ID);
            /**Build a PV heal item*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, int hpHeal, int ID);
            /**Build a status heal item*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, Status heal, bool healAllStatus, int ID, bool status); //De toutes facons meme si status est false ce sera quand meme du status
            /**Build a stat+*/
            I_Heal(std::string &name, Stats statAdd, int ID);
            bool isHealAll() const {
                return healAll;
            }
            bool getHpHeal() const {
                return hpHeal;
            }
            Status getStatusHeald() const {
                return healed;
            }
            ItemType itemTypeID = ItemType::IHeal;

          private:
            int hpHeal;
            /**The healed status*/
            Status healed;
            /**If the item heals every status*/
            bool healAll;
            Stats statAdd;
            /**If the item heals pp*/
            bool PPheal;
            /**The PP healed*/
            int ppHeal;

            bool allAttacksHeal;
        };
    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_ */
