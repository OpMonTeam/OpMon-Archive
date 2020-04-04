/*!
 * \file AnimationEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"

namespace OpMon::Elements {

	/*!
	 * \brief An event that animates itself when triggered.
	 */
	class AnimationEvent : public AbstractEvent {
	private:
		/*!
		 *  \brief The number of ticks elapsed between two frames.
		 *
		 *  0 means one frame per tick.
		 */
		unsigned int framerate;

		/*!
		 * \brief If `true`, the animation will loop. A new action will stop the animation.
		 */
		bool loop;

		/*!
		 * \brief If the animation is currently playing.
		 */
		bool playing = false;

		/*!
		 * \brief Counter to know how many ticks has been elapsed since the last update.
		 */
		unsigned int framecount = 0;
	public:
		AnimationEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, unsigned int framerate, bool loop, bool passable, int sides = SIDE_ALL);
		void action(Player &player, Overworld &overworld);
		void update(Player &player, Overworld &overworld);
		bool isOver() const {return !playing;}
	};
}
