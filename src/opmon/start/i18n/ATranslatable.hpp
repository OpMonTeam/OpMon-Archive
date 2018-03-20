/**
  ATranslatable.hpp
  Author : BAKfr
  File under licence GNU GPL-3.0
  http://opmon-game.ga

*/
#pragma once

namespace OpMon {
    namespace I18n {

        /**
     * Base class for any element requiring to reload when the lang changes.
     */
        class ATranslatable {
          protected:
            ATranslatable();
            virtual ~ATranslatable();

          public:
            /**
       * Method called after the lang has been changed.
       */
            virtual void onLangChanged() = 0;
        };

    } // namespace I18n
} // namespace OpMon
