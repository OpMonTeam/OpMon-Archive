#include "PlayerEvent.hpp"
#include "src/opmon/screens/overworld/OverworldData.hpp"

namespace OpMon {
	namespace Elements {

		PlayerEvent::PlayerEvent(OverworldData& data)
		: CharacterEvent(data.getTexturePP(), data.getPPRect(), sf::Vector2f(0,0), Side::TO_DOWN, MoveStyle::NO_MOVE, EventTrigger::PRESS)
		, player(data.getPlayerPtr()){

		}

	} /* namespace Elements */
} /* namespace OpMon */
