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
      /* Waits sf::String pointers to update the string with the pointed variable's value at each getString() call.*/
      OpString(std::string key, .../*Waiting sf::String pointer*/);
      OpString(std::string const& key, std::vector<sf::String*> obj);
      OpString();
      ~OpString();

        sf::String getObject(int const &index) {
            return *(objects[index]);
        }
        std::string getKey() {
            return key;
        }
        sf::String getString() const;
      /* A empty OpString */
        static OpString voidStr;

      /** Create an OpString and returns the result of getString. Quick version to have a string because it uses std::string instead of sf::String pointers. */
      static sf::String quickString(std::string const& key, .../* Waiting std::string pointers*/);
      static sf::String quickString(std::string const& key, std::vector<std::string> vstr);
    };

} // namespace Utils

#endif
