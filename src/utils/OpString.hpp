/*
OpString.hpp
Author : Cyrielle
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
   * Class defining an OpString, which is basically a string with an empty space to complete, used with StringKeys so it's independant from the language.
   */
    class OpString {
      private:
        /**
	 * The StringKey key to get the string.
	 */
        std::string key;
        /**
	 * The vecteur of objects to insert in the string. It's a pointer because it allows the value to change later.
	 */
        std::vector<sf::String *> objects;

      public:
        explicit OpString(std::string const &key, std::vector<sf::String *> obj = {});
        OpString();

        /**
	 * Return the object at the given index.
	 * @param index
	 */
        [[nodiscard]] const sf::String &getObject(int index) const {
            return *(objects[index]);
        }
        /**
	 * Return the key giving the string in StringKeys
	 */
        [[nodiscard]] const std::string &getKey() const {
            return key;
        }
        /**
	 * Return the completed key.
	 */
        [[nodiscard]] sf::String getString() const;
        /* A empty OpString */

        /**
	 * An empty OpString
	 */
        static OpString voidStr;

        /** Create an OpString and returns the result of getString. Quick version to have a string because it uses std::string instead of sf::String pointers. 
	 * @param key
	 * @param vstr The competions*/
        static sf::String quickString(std::string const &key, const std::vector<std::string> &vstr = {});
    };

} // namespace Utils

#endif
