/*!
 * \file PlayerEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "CharacterEvent.hpp"
#include "src/opmon/model/Player.hpp"
#include "src/opmon/model/Enums.hpp"
#include "src/opmon/screens/overworld/Position.hpp"
#include "src/opmon/screens/overworld/events/AbstractEvent.hpp"

namespace OpMon {
    class PlayerEvent : public CharacterEvent {
      private:
        Player *player;

      public:
        PlayerEvent(OverworldData &data);

        Player *getPlayer() { return player; }

        bool move(Side dir, Map *map, bool debugCol);
    };
} // namespace OpMon
