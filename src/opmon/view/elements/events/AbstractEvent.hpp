/*!
 * \file AbstractEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "src/opmon/core/Player.hpp"
#include "src/nlohmann/json.hpp"


//Macros defining constants to know the side from where the events can be triggered.
#define SIDE_UP 0x0001
#define SIDE_DOWN 0x0002
#define SIDE_LEFT 0x0010
#define SIDE_RIGHT 0x0020
#define SIDE_ALL (SIDE_UP | SIDE_DOWN | SIDE_RIGHT | SIDE_LEFT)

namespace OpMon{
	class Overworld;
	class OverworldData;
	class TalkingCharaEvent;

	namespace Elements {

		/*!
		 * \brief Used to know when the event must be triggered, relatively from the player.
		 */
		enum class EventTrigger {
			PRESS = 0,/*!< The event is triggered when the player presses the action key.*/
					GO_IN = 1,/*!< The event is triggered when the player is moving to the tile.*/
					ZONE = 2,/*!< The event is triggered as soon as the player sees it.*/
					BE_IN = 3/*!< The event is triggered as long as the player is on its position.*/
		};

		class AbstractEvent {
			friend class TalkingCharaEvent; //Needed to update currentTexture without creating a public setter.
		protected:
			/*!
			 * \brief How the event is triggered by the player.
			 */
			EventTrigger eventTrigger;
			/*!
			 * \brief If the player can go through the even or not.
			 */
			bool passable = false;
			/*!
			 * \brief From which sides the player is able to interact with the event.
			 */
			int sides = SIDE_ALL;

			/*!
			 * \brief The position of the event on the screen, in pixels.
			 */
			sf::Vector2f position;

			/*!
			 * \brief The sprite of the event.
			 */
			sf::Sprite* sprite;
			/*!
			 * \brief The position of the even of the map.
			 */
			Position mapPos;
			/*!
			 * \brief Other textures used by the event.
			 */
			std::vector<sf::Texture> &otherTextures;
			/*!
			 * \brief An iterator to the current texture in Event::otherTextures.
			 */
			std::vector<sf::Texture>::iterator currentTexture;

		public:
			/*!
			 * \warn The parameter position represents the position in squares, unlike the field position which stores the position in pixels.
			 */
			AbstractEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, int sides, bool passable);
			AbstractEvent(OverworldData &data, nlohmann::json jsonData);
			virtual ~AbstractEvent() = default;
			/*!
			 * \brief Method called at each frame.
			 */
			virtual void update(Player &player, Overworld &overworld) = 0;
			/**
			 * \brief Method called when the player interacts with the event.
			 */
			virtual void action(Player &player, Overworld &overworld) = 0;
			/*!
			 * \brief Updates Event::sprite with Event::currentTexture and Event::position.
			 */
			virtual void updateTexture();

			int getSide() const {
				return sides;
			}
			virtual const sf::Texture &getTexture() {
				return *currentTexture;
			}
			EventTrigger getEventTrigger() const {
				return eventTrigger;
			}

			sf::Vector2f getPosition() const {
				return position;
			}

			Position getPositionMap() const {
				return mapPos;
			}

			bool isPassable() const {
				return passable;
			}

			virtual const sf::Sprite *getSprite() const {
				return sprite;
			}

			void setCurrentTexture(std::vector<sf::Texture>::iterator itor) {
				currentTexture = itor;
			}

			/*!
			 * \brief If the activation of the event is over, returns true. If the event is still doing something, returns false.
			 */
			 virtual bool isOver() const = 0;

			std::vector<sf::Texture>& getTextures() {return otherTextures;}
		};
	}
}
