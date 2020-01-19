/*!
 * \file OpString.hpp
 * \brief A fillable string utility.
 * \authors Cyrielle
 * \authors JonnyPtn
 * \authors BAKFR
 * \date 31/10/17
 * \copyright GNU GPL v3.0 license
*/
#ifndef OPSTRING_PROTECTED
#define OPSTRING_PROTECTED
#include <SFML/System/String.hpp>
#include <iostream>
#include <vector>

/*! \namespace Utils
 *  \brief Contains different utilities.
 */
namespace Utils {

    /*!
     * \class OpString OpString.hpp "utils/OpString.hpp"
     * \brief A string with an empty space to complete using StringKeys.
     * \details Every `~` in the character string will be completed by the given array of objects, one by one. If there isn't enough objects, the `~` will be deleted from the string, and if there is too much objects, they will only be ignored.
     */
    class OpString {
      private:
        /*!
         * \brief The StringKey key to get the string.
         */
        std::string key;
        /*!
         * \brief The vector of objects to insert in the string.
         * \details It's a pointer because it allows the value to change after the initialisation of the object.
         */
        std::vector<sf::String *> objects;

      public:
        /*!
         * \brief Constructs an OpString with a StringKeys key and objects.
         * \param key The key allowing to get the character string from StringKeys.
         * \param obj A array of pointers to objects completing the string.
         */
        OpString(std::string const &key, std::vector<sf::String *> obj = {});
        /*!
         * \brief Contructs an empty OpString with no key nor object.
         * \details It is not possible to set the key and the objects after. However, it is still possible to call getString(), which will return an empty string.
         */
        OpString();

        /*!
         * \returns The object at the given index.
         * \param index The index at which is the object wanted.
         */
        const sf::String &getObject(int index) const {
            return *(objects[index]);
        }
        /*!
         * \returns The key giving the string in StringKeys.
         */
        const std::string &getKey() const {
            return key;
        }
        /*!
         * \brief Generates the completed string and returns it.
         * \returns The completed string.
         */
        sf::String getString() const;

        /*!
         * \brief An empty OpString.
         */
        static OpString voidStr;

        /*!
         * \brief Creates an OpString and directly returns the result of getString().
         * \details It's a quicker version to have a string because it uses std::string instead of sf::String pointers.
         * \param key The key allowing to get the character string from StringKeys.
         * \param vstr The array of objects completing the string.
         */
        static sf::String quickString(std::string const &key, std::vector<std::string> vstr = {});
    };

} // namespace Utils

#endif
