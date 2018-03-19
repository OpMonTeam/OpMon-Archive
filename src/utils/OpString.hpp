/*
OpString.hpp
Author : Jlppc
File under license GNU GPL-3.0
http://opmon-game.ga
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
      bool created = false;
      public:
      OpString(std::string const& key, std::vector<sf::String*> const& objects = std::vector<sf::String*>());
      OpString(std::string const& key, std::vector<std::string*> const& objects = std::vector<std::string*>());
      OpString(std::string const& key, std::string const& object);
        OpString();
      ~OpString();

        sf::String getObject(int const &index) {
            return *(objects[index]);
        }
        std::string getKey() {
            return key;
        }
        sf::String getString();
        static OpString voidStr;
    };

} // namespace Utils

#endif
