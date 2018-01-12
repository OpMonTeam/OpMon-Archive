
#include "./ATranslatable.hpp"
#include "./Translator.hpp"


namespace Opmon{
  namespace Start{
    namespace I18n {

      ATranslatable::ATranslatable(){
        translator.subscribe(this);
      }

      ATranslatable::~ATranslatable(){
        translator.unsubscribe(this);
      }

    }
  }
}
