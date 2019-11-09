/*
Translator.cpp
Author : BAKFR
Contributors : Cyrielle, jubalh 
File under GNU GPL v3.0
*/
#include "Translator.hpp"
#include "../../../utils/StringKeys.hpp"
#include "../../../utils/log.hpp"
#include "../../../utils/path.hpp"
#include "ATranslatable.hpp"

namespace OpMon {
    namespace I18n {

        Translator &Translator::getInstance() {
            static Translator instance;

            return instance;
        }

        void Translator::setLang(const std::string &langCode) {

            std::map<const std::string, const std::string> langMap{
              {"en", "keys/english.rkeys"},
              {"es", "keys/espanol.rkeys"},
              {"fr", "keys/francais.rkeys"},
              {"de", "keys/deutsch.rkeys"}};

            /*            if(langCode == _currentLang)
	      return; // Nothing to do
	      Desactivated : if we need to reload the keys
*/

            Utils::StringKeys::initialize(Utils::Path::getResourcePath() + langMap[langCode]);

            _currentLang = langCode;
            for(auto &listener : _listeners) {
                listener->onLangChanged();
            }
        }

        const std::string &Translator::getLang() {
            return _currentLang;
        }

        const std::map<const std::string, const std::string> Translator::getAvailableLanguages() {
            std::map<const std::string, const std::string> languages = {
              {"en", "English"},
              {"es", "Espa\u00F1ol"},
              {"fr", "Fran\u00E7ais"},
              {"de", "Deutsch"}};

            return languages;
        }

        void Translator::subscribe(ATranslatable *listener) {
            auto result = _listeners.insert(listener);
            if(!result.second) {
                Utils::Log::warn("Translator: a listener is trying to subscribe twice.");
            }
        }

        void Translator::unsubscribe(ATranslatable *listener) {
            if(!_listeners.erase(listener)) {
                Utils::Log::warn("Translator: a listener not registered is trying to unsubscribe.");
            }
        }

    } // namespace I18n
} // namespace OpMon
