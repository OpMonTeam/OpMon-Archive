#include "BattleEvent.hpp"

#include <SFML/Graphics/Rect.hpp>

#include "src/opmon/screens/overworld/Overworld.hpp"
#include "src/opmon/screens/overworld/OverworldData.hpp"
#include "src/opmon/screens/overworld/events/AbstractEvent.hpp"

namespace OpMon {

    BattleEvent::BattleEvent(sf::Texture &texture,
                             std::vector<sf::IntRect> rectangles,
                             sf::Vector2f const &position, OpTeam *team,
                             EventTrigger eventTrigger, bool passable, int side)
        : AbstractEvent(texture, rectangles, eventTrigger, position, side,
                        passable),
          team(team) {}

    BattleEvent::BattleEvent(OverworldData &data, nlohmann::json jsonData)
        : AbstractEvent(data, jsonData),
          team(data.getTrainer(jsonData.at("trainer"))) {
        this->rectangles = std::vector<sf::IntRect> {
            sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y)};
        this->currentFrame = rectangles.begin();
    }

    void BattleEvent::action(Overworld &overworld) {
        if(over) {
            overworld.declareBattle(this);
            over = false;
        }
    }

    void BattleEvent::update(Overworld &overworld) {}

    BattleEvent::~BattleEvent() { delete(team); }

} // namespace OpMon
