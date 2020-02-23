/*!
 * \file Item.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 * \warn Work in progress. The documentation may not be complete or up to date.
 */
#pragma once

#include <memory>

#include "../core/Core.hpp"
#include "OpMon.hpp"
#include "../../utils/OpString.hpp"

namespace OpMon {
class OpMon;
}  // namespace OpMon

#pragma GCC diagnostic ignored "-Wunused-parameter"

namespace OpMon {

    struct Turn;

    typedef struct Turn Turn;

    class Player;

    /*!
     * \brief Defines the effect of an item.
     * \warn Work in progress.
     */
    class ItemEffect {
    public:
        ItemEffect() {}

        /** Different effects. The boolean returned is true if the item must be consumed */

        /*!
         * \brief Effect when the item is used on an OpMon.
         * \return `true` if the item has to be consumed.
         * \param opmon A pointer to the OpMon on which the item has been used.
         */
        virtual bool use(OpMon *opmon) { return false; }
        /*!
         * \brief Effect when the item used in the overworld.
         * \return `true` if the item has to be consumed.
         * \param player A pointer to the Player.
         */
        virtual bool use(Player *player) { return false; }
        /*!
         *\brief Returns the dialog shown when the object is used on an OpMon or on the field.
         *
         * Can be used only one time because it moves the unique_ptr.
         */
        std::unique_ptr<std::vector<sf::String>> getDialog() { return std::move(dialog); }

    protected:
        /*!
         * \brief The dialog shown when the object is used.
         */
        std::unique_ptr<std::vector<sf::String>> dialog = std::make_unique<std::vector<sf::String>>();
    };

    class Item {
    public:
        Item(Utils::OpString name, bool usable, bool onOpMon, std::unique_ptr<ItemEffect> opmonEffect = nullptr, std::unique_ptr<ItemEffect> playerEffect = nullptr, std::unique_ptr<ItemEffect> heldEffect = nullptr);

        ~Item() = default;

        std::unique_ptr<std::vector<sf::String>> use(OpMon *opmon, int &itemCount);
        std::unique_ptr<std::vector<sf::String>> use(Player *player, int &itemCount);
//            void updateHeld(Turn &owner, Turn &opponent, int &itemCount);

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

            bool use(OpMon *opmon) override;

        protected:
            const int hpHealed;
        };

    } // namespace Items

} // namespace OpMon

#pragma GCC diagnostic pop
