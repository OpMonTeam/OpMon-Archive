/*
OpString.hpp
Author : Cyrion
Contributors : JonnyPtn, BAKFR
File under GNU GPL v3.0 license
*/
#ifndef OPSTRING_PROTECTED
#define OPSTRING_PROTECTED
#include <SFML/System/String.hpp>
#include <iostream>
#include <vector>

namespace Utils {

    /**
   * Class defining an OpString. See the OpMon documentation (http://opmon.ga/pages/doc) for more details
   */
    class OpString {
      private:
        std::string key;
        std::vector<sf::String *> objects;

      public:
        /* Waits sf::String pointers to update the string with the pointed variable's value at each getString() call.*/
        OpString(std::string const &key, std::vector<sf::String *> obj = {});
        OpString();

        const sf::String &getObject(int index) const {
            return *(objects[index]);
        }
        const std::string &getKey() const {
            return key;
        }
        sf::String getString() const;
        /* A empty OpString */
        static OpString voidStr;

        /** Create an OpString and returns the result of getString. Quick version to have a string because it uses std::string instead of sf::String pointers. */
      static sf::String quickString(std::string const &key, std::vector<std::string> vstr = {});
    };

} // namespace Utils

#endif
