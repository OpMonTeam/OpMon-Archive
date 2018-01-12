
#pragma once

namespace OpMon {
  namespace I18n {

    /**
     * Base class for any element requiring to reload when the lang changes.
     */
    class ATranslatable{
    protected:
      ATranslatable();
      virtual ~ATranslatable();

    public:
      /**
       * Method called after the lang has been changed.
       */
      virtual void onLangChanged() = 0;
    };

  }
}
