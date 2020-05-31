#include "DialogEvent.hpp"

#include "src/opmon/screens/overworld/Overworld.hpp"

namespace OpMon {
    namespace Elements {

        DialogEvent::DialogEvent(sf::Texture &texture,
                                 std::vector<sf::IntRect> rectangles,
                                 sf::Vector2f const &position,
                                 Utils::OpString const &dialogKey, int sides,
                                 EventTrigger eventTrigger, bool passable)
            : AbstractEvent(texture, rectangles, eventTrigger, position, sides,
                            passable),
              Utils::I18n::ATranslatable(),
              dialogKey(dialogKey) {
            this->onLangChanged();
        }

        DialogEvent::DialogEvent(OverworldData &data, nlohmann::json jsonData)
            : AbstractEvent(data, jsonData), Utils::I18n::ATranslatable() {
            Utils::OpString dialog;
            std::vector<std::string> dialogKeys =
                jsonData.value("dialog", std::vector<std::string>());
            std::string key = dialogKeys[0];
            std::vector<sf::String *> toAdd;
            for(unsigned int j = 1; j < dialogKeys.size(); j++) {
                toAdd.push_back(data.getCompletion(dialogKeys[j]));
            }
            this->dialogKey = Utils::OpString(
                data.getGameDataPtr()->getStringKeys(), key, toAdd);
            this->onLangChanged();

            this->rectangles = std::vector<sf::IntRect> {
                sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y)};
            this->currentFrame = rectangles.begin();
        }

        void DialogEvent::onLangChanged() {
            dialog.clear();
            dialog = dialogKey.getString(stringkeys);
        }

        void DialogEvent::action(Overworld &overworld) {
            overworld.startDialog(this->dialog);
            over = overworld.isDialogOver();
        }

        void DialogEvent::update(Overworld &overworld) {
            over = overworld.isDialogOver();
        }

        void DialogEvent::changeDialog(Utils::OpString newDialog) {
            dialogKey = newDialog;
            this->onLangChanged();
        }

    } /* namespace Elements */
} /* namespace OpMon */
