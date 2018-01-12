
#pragma once

#include <map>
#include <string>
#include <unordered_set>


namespace Opmon{
  namespace Start{
    namespace I18n {

      class ATranslatable;

      /**
       * Class in charge of the lang setting.
       * It load (and reload) language file.
       *
       * On lang changes, it informs all `Translatable` instances.
       *
       * Note: This class should not be instanced, except the `translation` instance below.
       */
      class Translator{
      public:

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
        std::string _currentLang;
        std::unordered_set<ATranslatable *> _listeners;
      };


      /**
       * Only instance of Translator.
       */
      extern Translator translator;

    }
  }
}
