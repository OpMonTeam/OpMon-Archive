/*
Translator.cpp
Author : BAKFR
Contributors : Cyrielle, jubalh 
File under GNU GPL v3.0
*/
#include "Translator.hpp"

#include <utility>

#include "../StringKeys.hpp"
#include "../log.hpp"
#include "../ResourceLoader.hpp"
#include "ATranslatable.hpp"

namespace Utils {
    namespace I18n {

        Translator &Translator::getInstance() {
            static Translator instance;

            return instance;
        }

        void Translator::setLang(const std::string &langCode) {

            /*            if(langCode == _currentLang)
                          return; // Nothing to do
                          Desactivated : if we need to reload the keys
            */

            stringkeys = StringKeys(Utils::ResourceLoader::getResourcePath() + langMap[langCode]);

            _currentLang = langCode;
            for(auto &listener : _listeners) {
                listener->onLangChanged();
            }
        }

        const std::string &Translator::getLang() {
            return _currentLang;
        }

        const std::map<const std::string, const std::string> Translator::getAvailableLanguages() {
            return langMap;
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

        void Translator::setAvailableLanguages(std::map<const std::string, const std::string> langMap) {
            this->langMap = langMap;
        }
    } // namespace I18n
} // namespace Utils
