/*!
 * \file CharacterEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"

namespace OpMon::Elements {

	/*!
	 * \brief Defines different ways of moving of the npcs.
	 * \ingroup Events
	 */
	enum class MoveStyle : int {
		NO_MOVE = 0,/*!< The npc has to stay still.*/
		PREDEFINED = 1,/*!< The npc follows a predefined path.*/
		RANDOM = 2,/*!< The npc moves randomly.*/
		FOLLOWING = 3/*!< The npc follows the player (unimplemented yet).*/
	};

	/*!
	 * \brief A NPC that just walks through the map.
	 * \ingroup Events
	 *
	 * When the NPC is triggered, it turns itself to face the player.
	 */
	class CharacterEvent : public AbstractEvent {
	private:
		/*!
		 * \brief The way the npc moves.
		 */
		MoveStyle moveStyle;

		/*!
		 * \brief A counter used for the predefined movements.
		 */
		unsigned int predefinedCounter = 0;
		/*!
		 * \brief A counter for the movement animation.
		 */
		int animsCounter = 0;

		/*!
		 * \brief The predefined movements.
		 */
		std::vector<Side> movements;

		/*!
		 * \brief The frame number when the movement animation started.
		 */
		int startFrames = 0;
		/*!
		 * \brief If the npc is currently animated.
		 */
		bool anims = false;
		/*!
		 * \brief Counts the frames.
		 */
		int frames = 0;
		/*!
		 * \brief If set to true, the character has to turn towards the player.
		 */
		bool wantmove = false;

	public:
		CharacterEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, Side posDir = Side::TO_UP, MoveStyle moveStyle = MoveStyle::NO_MOVE, EventTrigger eventTrigger = EventTrigger::PRESS, std::vector<Side> predefinedPath = std::vector<Side>(), bool passable = false, int sides = SIDE_ALL);
		CharacterEvent(OverworldData &data, nlohmann::json jsonData);
		virtual void update(Player &player, Overworld &overworld);
		virtual void action(Player &, Overworld &){wantmove = true;}
		/*!
		 * \brief Sets the predefined movement.
		 */
		void setPredefinedMove(std::vector<Side> movement);
		/*!
		 * \brief Moves the npc
		 * \deprecated Use directly move(Side direction, Map *map). This method searches in overworld for the map, which is completely useless.
		 */
		OP_DEPRECATED void move(Side direction, Player &player, Overworld &overworld);
		/*!
		 * \brief Moves the npc
		 */
		bool move(Side direction, Map *map);

		bool isOver() const {return !wantmove;}

		/*!
		 * \brief Changes the position of the event.
		 *
		 * This method moves the event by changing \ref position, but also \ref mapPos and the position of the \ref sprite.
		 * The new position has to be in squares.
		 */
		virtual void setPosition(int x, int y) {setPosition(sf::Vector2i(x,y));}

		/*!
		 * \brief Changes the position of the event.
		 *
		 * This method moves the event by changing \ref position, but also \ref mapPos and the position of the \ref sprite.
		 * \param xy The new position, in squares.
		 */
		virtual void setPosition(sf::Vector2i pos);
	};
}
