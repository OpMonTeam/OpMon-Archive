/*
  KeyData.hpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <unordered_map>

namespace OpMon {
    namespace Model {

        struct KeyData {
            static const std::string &findNameKeyCode(sf::Keyboard::Key searchKeyCode);

            //Loading controls compile time
            static const std::unordered_map<std::string, sf::Keyboard::Key> keysMap;
        };
    } // namespace Model
} // namespace OpMon
