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
		class DialogEvent : public AbstractEvent, public Utils::I18n::ATranslatable {
		private:
			/*!
			 * \brief The OpString containing the dialog to show.
			 */
			Utils::OpString dialogKey;

		protected:
			/*!
			 * \brief The dialog to show.
			 */
			sf::String dialog;

		public:
			DialogEvent(std::vector<sf::Texture> &otherTextures, sf::Vector2f const &position, Utils::OpString const &dialogKey, int sides = SIDE_ALL, EventTrigger eventTrigger = EventTrigger::PRESS, bool passable = false);
			void onLangChanged() override;
			virtual void update(Player &player, Overworld &overworld);
			virtual void action(Player &player, Overworld &overworld);
			/*!
			 * \brief Changes the dialog shown by the event.
			 * \param newDialog An OpString containing the new dialog.
			 */
			virtual void changeDialog(Utils::OpString newDialog);
		};
	}
}
