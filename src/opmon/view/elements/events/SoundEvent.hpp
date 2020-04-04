/*!
 * \file SoundEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"

namespace OpMon::Elements {
	/*!
	 * \brief An event that plays a sound or a music when triggered.
	 */
	class SoundEvent : public AbstractEvent {
	private:
		/*!
		 * \brief The ID of the sound/music to play.
		 */
		std::string playID;

		/*!
		 * \brief If the thing to play is a music.
		 */
		bool music;

		/*!
		 * \brief If an action toggles the music/sound or just starts it.
		 */
		bool toggle;

		/*!
		 * \brief If the music is playing or not.
		 */
		bool playing = false;
	public:
		SoundEvent(std::vector<sf::Texture> &otherTextures, EventTrigger eventTrigger, sf::Vector2f const &position, std::string const& playID, bool music, bool toggle, int sides = SIDE_ALL, bool passable = true);
		virtual void update(Player &player, Overworld &overworld) {}
		virtual void action(Player &player, Overworld &overworld);
		bool isOver() const {return !playing;}
	};
}
