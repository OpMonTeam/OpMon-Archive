/**
  Translator.hpp
  Author : BAKfr
  File under licence GNU GPL-3.0
  http://opmon-game.ga
*/
#pragma once

#include <map>
#include <string>
#include <unordered_set>

namespace OpMon {
    namespace I18n {

        class ATranslatable;

        /**
     * Class in charge of the lang setting. It load (and reload) language file.
     *
     * When the lang changes, it informs all `Translatable` instances registered with `subscribe()`.
     *
     * Note: This class is a singleton. It can only be acceded by using `getInstance()`.
     */
        class Translator {
          public:
            //Ensure Singleton can't be copied.
            Translator(Translator const &) = delete;
            void operator=(Translator const &) = delete;

            static Translator &getInstance();

            /**
       * Set the language. It MUST be called at start to set the first language.
       *
       * @param lang_code should be "en", "es" or "fr".
       */
            void setLang(const std::string &lang_code);

            const std::string &getLang();

            const std::map<const std::string, const std::string> getAvailableLanguages();

            void subscribe(ATranslatable *listener);
            void unsubscribe(ATranslatable *listener);

          private:
            Translator() = default;

            std::string _currentLang;
            std::unordered_set<ATranslatable *> _listeners;
        };

    } // namespace I18n
} // namespace OpMon
