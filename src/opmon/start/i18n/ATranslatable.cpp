
#include "./ATranslatable.hpp"
#include "./Translator.hpp"

namespace OpMon {
    namespace I18n {

        ATranslatable::ATranslatable() {
            Translator::getInstance().subscribe(this);
        }

        ATranslatable::~ATranslatable() {
            Translator::getInstance().unsubscribe(this);
        }

    } // namespace I18n
} // namespace OpMon
