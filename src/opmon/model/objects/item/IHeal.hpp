/*
IHeal.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contains the I_Heal class definition
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
            /**Construit un item de heal (prevaue) polyvalent*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, int hpHeal, Status heal, bool healAllStatus, int ID);
            /**Construit un item de heal de PP*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, int ppHeal, bool allAttacksHeal, int ID);
            /**Construit un item de heal de pv*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, int hpHeal, int ID);
            /**Construit un item de heal de status*/
            I_Heal(std::string &name, bool usable, bool usableInFight, bool givable, BagCat categorie, Status heal, bool healAllStatus, int ID, bool status); //De toutes facons meme si status est false ce sera quand meme du status
            /**Construit un stat+*/
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
            /**Le status soigné*/
            //->ExpectEnum->Status
            Status healed;
            /**Si l'item soigne tous les status*/
            bool healAll;
            Stats statAdd;
            /**Si l'item soigne des PP*/
            bool PPheal;
            /**Les PP soignés*/
            int ppHeal;

            bool allAttacksHeal;
        };
    } // namespace Model
} // namespace OpMon
#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ITEM_IHEAL_HPP_ */
