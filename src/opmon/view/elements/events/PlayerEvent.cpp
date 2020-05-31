#include "PlayerEvent.hpp"

#include "src/opmon/screens/overworld/OverworldData.hpp"

namespace OpMon {
    namespace Elements {

        PlayerEvent::PlayerEvent(OverworldData &data)
            : CharacterEvent(data.getTexturePP(), data.getPPRect(),
                             sf::Vector2f(0, 0), Side::TO_DOWN,
                             MoveStyle::NO_MOVE, EventTrigger::PRESS),
              player(data.getPlayerPtr()) {
            Elements::Position::setPlayerPos(&mapPos);
        }

        bool PlayerEvent::move(Side dir, Map *map, bool debugCol) {
            if(!mapPos.isLocked()) {
                startFrames = frames;
                return mapPos.move(dir, map, debugCol);
            } else
                return false;
        }

    } /* namespace Elements */
} /* namespace OpMon */
