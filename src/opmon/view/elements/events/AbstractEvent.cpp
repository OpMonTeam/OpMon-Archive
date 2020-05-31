#include "AbstractEvent.hpp"

#include "src/opmon/screens/overworld/Overworld.hpp"
#include "src/utils/log.hpp"
#include "src/utils/misc.hpp"

namespace OpMon {
    namespace Elements {
        AbstractEvent::AbstractEvent(sf::Texture &texture,
                                     std::vector<sf::IntRect> rectangles,
                                     EventTrigger eventTrigger,
                                     sf::Vector2f const &position, int sides,
                                     bool passable)
            : texture(texture),
              rectangles(rectangles),
              eventTrigger(eventTrigger),
              position(32.0f * position),
              mapPos(position),
              passable(passable),
              sides(sides),
              sprite(new sf::Sprite(texture)),
              currentFrame(rectangles.begin()) {}

        AbstractEvent::AbstractEvent(OverworldData &data,
                                     nlohmann::json jsonData)
            : texture(data.getEventsTexture(jsonData.at("textures"))),
              rectangles({sf::IntRect()}),
              eventTrigger(jsonData.value("trigger", EventTrigger::PRESS)),
              position(
                  32.0f *
                  sf::Vector2f(
                      jsonData.value("position", std::vector<int> {0, 0})[0],
                      jsonData.value("position", std::vector<int> {0, 0})[1])),
              mapPos((1.0f / 32.0f) * position),
              passable(jsonData.value("passable", true)),
              sides(jsonData.value("side", SIDE_ALL)),
              sprite(new sf::Sprite(texture)),
              currentFrame(rectangles.begin()) {}

        void AbstractEvent::updateFrame() {
            this->sprite->setPosition(position);
            this->sprite->setTextureRect(*currentFrame);
        }

        void AbstractEvent::setPosition(sf::Vector2i pos) {
            position = 32.0f * sf::Vector2f(pos.x, pos.y);
            mapPos.setPosition(pos.x, pos.y);
            sprite->setPosition(position);
        }
    } // namespace Elements
} // namespace OpMon
