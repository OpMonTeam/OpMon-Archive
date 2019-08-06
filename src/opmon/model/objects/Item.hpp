/**
Item.hpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#pragma once

#include "../../../utils/OpString.hpp"
#include "../../start/Core.hpp"
#include "OpMon.hpp"
#include <memory>
#include <vector>

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace OpMon {
    namespace Model {

        struct Turn;

        typedef struct Turn Turn;

        class Player;

        class ItemEffect {
          public:
            ItemEffect() {}

            /** Different effects. The boolean returned is true if the item must be consumed */

            /** Effect when used on an OpMon */
            bool operator()(OpMon *opmon) { return false; }
            /** Effect when used on the field */
            bool operator()(Player *player) { return false; }
            /** Effect when held during a turn */
            bool operator()(Turn &owner, Turn &opponent) { return false; }
            /** Dialog used when the object is used on an OpMon or on the field. Can be used only one time because it moves the unique_ptr. */
            std::unique_ptr<std::vector<sf::String>> getDialog() { return std::move(dialog); }

          protected:
            std::unique_ptr<std::vector<sf::String>> dialog = std::make_unique<std::vector<sf::String>>();
        };

        class Item {
          public:
            Item(Utils::OpString name, bool usable, bool onOpMon, std::unique_ptr<ItemEffect> opmonEffect = nullptr, std::unique_ptr<ItemEffect> playerEffect = nullptr, std::unique_ptr<ItemEffect> heldEffect = nullptr);

            ~Item() = default;

            std::unique_ptr<std::vector<sf::String>> use(OpMon *opmon, int &itemCount);
            std::unique_ptr<std::vector<sf::String>> use(Player *player, int &itemCount);
            void updateHeld(Turn &owner, Turn &opponent, int &itemCount);

          protected:
            Utils::OpString name;
            bool usable;
            bool onOpMon;
            std::unique_ptr<ItemEffect> opmonEffect;
            std::unique_ptr<ItemEffect> playerEffect;
            std::unique_ptr<ItemEffect> heldEffect;
        };

        namespace Items {

            class HpHealEffect : public ItemEffect {
              public:
                HpHealEffect(int hpHealed);

                bool operator()(OpMon *opmon);

              protected:
                const int hpHealed;
            };

        } // namespace Items

    } // namespace Model
} // namespace OpMon

#pragma GCC diagnostic pop
