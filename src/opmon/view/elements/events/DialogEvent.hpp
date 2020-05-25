/*!
 * \file DialogEvent.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */

#pragma once

#include "AbstractEvent.hpp"
#include "src/utils/i18n/ATranslatable.hpp"

namespace OpMon{
	namespace Elements {
		/*!
		 * \brief An event that shows a dialog.
		 * \ingroup Events
		 */
		class DialogEvent : public AbstractEvent, public Utils::I18n::ATranslatable {
		private:
			/*!
			 * \brief The OpString containing the dialog to show.
			 */
			Utils::OpString dialogKey;
			/*!
			 * \brief The dialog to show.
			 */
			sf::String dialog;

			/*!
			 * \brief If the dialog is over.
			 */
			bool over = true;

		public:
			DialogEvent(sf::Texture &texture, std::vector<sf::IntRect> rectangles, sf::Vector2f const &position, Utils::OpString const &dialogKey, int sides = SIDE_ALL, EventTrigger eventTrigger = EventTrigger::PRESS, bool passable = false);
			DialogEvent(OverworldData &data, nlohmann::json jsonData);
			void onLangChanged() override;
			virtual void update(Player &player, Overworld &overworld);
			virtual void action(Player &player, Overworld &overworld);
			/*!
			 * \brief Changes the dialog shown by the event.
			 * \param newDialog An OpString containing the new dialog.
			 */
			virtual void changeDialog(Utils::OpString newDialog);

			bool isOver() const {return over;}
		};
	}
}
