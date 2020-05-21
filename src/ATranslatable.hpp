/*!
 * \file ATranslatable.hpp
 * \author BAKfr
 * \copyright GNU GPL v3.0
 * \date 12/01/18
*/
#pragma once

#include "Translator.hpp"

namespace Utils {
    /*!
     * \namespace Utils::I18n
     * \brief Contains internationalisation tools.
     */
    namespace I18n {

        /*!
         * \brief Base class for any element requiring to reload when the lang changes.
         */
        class ATranslatable {
          protected:
            ATranslatable();
            virtual ~ATranslatable();

            StringKeys& stringkeys = Translator::getInstance().getStringKeys();

          public:
            /*!
             * \brief Method called after the language has been changed.
             */
            virtual void onLangChanged() = 0;
        };

    } // namespace I18n
} // namespace OpMon
