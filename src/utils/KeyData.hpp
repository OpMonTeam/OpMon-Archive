/*!
 * \file KeyData.hpp
 * \author Cyrielle
 * \copyright GNU GPL v3.0
 */
#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <unordered_map>

namespace Utils {

    /*!
     * \brief Used to link the keyboard keys to std::strings.
     */
    struct KeyData {
        /*!
         * \brief Gets the code associated with a keyboard key.
         * \param searchKeyCode The key whose associated code is wanted.
         * \returns The code associated with the key.
         */
        static const std::string &findNameKeyCode(
            sf::Keyboard::Key searchKeyCode);

        /*!
         * \brief A map associating a code to some keys.
         */
        static const std::unordered_map<std::string, sf::Keyboard::Key> keysMap;
    };
} // namespace Utils
