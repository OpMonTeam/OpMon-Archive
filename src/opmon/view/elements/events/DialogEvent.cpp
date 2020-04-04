#include "DialogEvent.hpp"

namespace OpMon {
	namespace Elements {

		DialogEvent::DialogEvent(std::vector<sf::Texture> &otherTextures, sf::Vector2f const &position, Utils::OpString const &dialogKey, int sides, EventTrigger eventTrigger, bool passable)
		: AbstractEvent(otherTextures, eventTrigger, position, sides, passable)
		, Utils::I18n::ATranslatable()
		, dialogKey(dialogKey) {
			this->onLangChanged();
		}

		void DialogEvent::onLangChanged() {
			dialog.clear();
			dialog = dialogKey.getString(stringkeys);
		}

		void DialogEvent::action(Player &player, Overworld &overworld) {
			overworld.startDialog(this->dialog);
			over = overworld.isDialogOver();
		}

		void DialogEvent::update(Player &player, Overworld &overworld) {
			over = overworld.isDialogOver();
		}

		void DialogEvent::changeDialog(Utils::OpString newDialog) {
			dialogKey = newDialog;
			this->onLangChanged();
		}

	} /* namespace Elements */
} /* namespace OpMon */
