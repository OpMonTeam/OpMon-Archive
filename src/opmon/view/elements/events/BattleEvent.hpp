/*!
 * \file TrainerEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"

namespace OpMon::Elements {
	class BattleEvent : public AbstractEvent {
	private:
		/*!
		 * \brief The trainer's team.
		 */
		OpTeam *team;

		/*!
		 * \brief If the battle is over or has not begun.
		 */
		bool over = true;
	public:
		BattleEvent(std::vector<sf::Texture> &textures, sf::Vector2f const &position, OpTeam *team, EventTrigger eventTrigger = EventTrigger::PRESS, bool passable = false, int side = SIDE_ALL);
		BattleEvent(OverworldData &data, nlohmann::json jsonData);

		virtual void update(Player &player, Overworld &overworld);
		virtual void action(Player &player, Overworld &overworld);

		OpTeam *getOpTeam() {
			return team;
		}

		bool isOver() const {return over;}

		/*!
		 * \brief Sets over to true.
		 */
		void setOver() {over = true;}

		virtual ~BattleEvent();
	};
}
