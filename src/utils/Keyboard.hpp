#pragma once

#include <SFML/Window/Keyboard.hpp>

#include <array>
#include <iosfwd>
#include <string_view>
#include <utility>

namespace Utils {
    using key_string_pair = std::pair<sf::Keyboard::Key, std::string_view>;
    using keymap_type = std::array<key_string_pair, sf::Keyboard::KeyCount + 2>;

    constexpr keymap_type keymap {
            std::pair<sf::Keyboard::Key, std::string_view>
            { sf::Keyboard::Unknown, "Unknown" },
            { sf::Keyboard::A, "A" },
            { sf::Keyboard::B, "B" },
            { sf::Keyboard::C, "C" },
            { sf::Keyboard::D, "D" },
            { sf::Keyboard::E, "E" },
            { sf::Keyboard::F, "F" },
            { sf::Keyboard::G, "G" },
            { sf::Keyboard::H, "H" },
            { sf::Keyboard::I, "I" },
            { sf::Keyboard::J, "J" },
            { sf::Keyboard::K, "K" },
            { sf::Keyboard::L, "L" },
            { sf::Keyboard::M, "M" },
            { sf::Keyboard::N, "N" },
            { sf::Keyboard::O, "O" },
            { sf::Keyboard::P, "P" },
            { sf::Keyboard::Q, "Q" },
            { sf::Keyboard::R, "R" },
            { sf::Keyboard::S, "S" },
            { sf::Keyboard::T, "T" },
            { sf::Keyboard::U, "U" },
            { sf::Keyboard::V, "V" },
            { sf::Keyboard::W, "W" },
            { sf::Keyboard::X, "X" },
            { sf::Keyboard::Y, "Y" },
            { sf::Keyboard::Z, "Z" },
            { sf::Keyboard::Num0, "Num0" },
            { sf::Keyboard::Num1, "Num1" },
            { sf::Keyboard::Num2, "Num2" },
            { sf::Keyboard::Num3, "Num3" },
            { sf::Keyboard::Num4, "Num4" },
            { sf::Keyboard::Num5, "Num5" },
            { sf::Keyboard::Num6, "Num6" },
            { sf::Keyboard::Num7, "Num7" },
            { sf::Keyboard::Num8, "Num8" },
            { sf::Keyboard::Num9, "Num9" },
            { sf::Keyboard::Escape, "Escape" },
            { sf::Keyboard::LControl, "LControl" },
            { sf::Keyboard::LShift, "LShift" },
            { sf::Keyboard::LAlt, "LAlt" },
            { sf::Keyboard::LSystem, "LSystem" },
            { sf::Keyboard::RControl, "RControl" },
            { sf::Keyboard::RShift, "RShift" },
            { sf::Keyboard::RAlt, "RAlt" },
            { sf::Keyboard::RSystem, "RSystem" },
            { sf::Keyboard::Menu, "Menu" },
            { sf::Keyboard::LBracket, "LBracket" },
            { sf::Keyboard::RBracket, "RBracket" },
            { sf::Keyboard::Semicolon, "Semicolon" },
            { sf::Keyboard::Comma, "Comma" },
            { sf::Keyboard::Period, "Period" },
            { sf::Keyboard::Quote, "Quote" },
            { sf::Keyboard::Slash, "Slash" },
            { sf::Keyboard::Backslash, "Backslash" },
            { sf::Keyboard::Tilde, "Tilde" },
            { sf::Keyboard::Equal, "Equal" },
            { sf::Keyboard::Hyphen, "Hyphen" },
            { sf::Keyboard::Space, "Space" },
            { sf::Keyboard::Enter, "Enter" },
            { sf::Keyboard::Backspace, "Backspace" },
            { sf::Keyboard::Tab, "Tab" },
            { sf::Keyboard::PageUp, "PageUp" },
            { sf::Keyboard::PageDown, "PageDown" },
            { sf::Keyboard::End, "End" },
            { sf::Keyboard::Home, "Home" },
            { sf::Keyboard::Insert, "Insert" },
            { sf::Keyboard::Delete, "Delete" },
            { sf::Keyboard::Add, "Add" },
            { sf::Keyboard::Subtract, "Subtract" },
            { sf::Keyboard::Multiply, "Multiply" },
            { sf::Keyboard::Divide, "Divide" },
            { sf::Keyboard::Left, "Left" },
            { sf::Keyboard::Right, "Right" },
            { sf::Keyboard::Up, "Up" },
            { sf::Keyboard::Down, "Down" },
            { sf::Keyboard::Numpad0, "Numpad0" },
            { sf::Keyboard::Numpad1, "Numpad1" },
            { sf::Keyboard::Numpad2, "Numpad2" },
            { sf::Keyboard::Numpad3, "Numpad3" },
            { sf::Keyboard::Numpad4, "Numpad4" },
            { sf::Keyboard::Numpad5, "Numpad5" },
            { sf::Keyboard::Numpad6, "Numpad6" },
            { sf::Keyboard::Numpad7, "Numpad7" },
            { sf::Keyboard::Numpad8, "Numpad8" },
            { sf::Keyboard::Numpad9, "Numpad9" },
            { sf::Keyboard::F1, "F1" },
            { sf::Keyboard::F2, "F2" },
            { sf::Keyboard::F3, "F3" },
            { sf::Keyboard::F4, "F4" },
            { sf::Keyboard::F5, "F5" },
            { sf::Keyboard::F6, "F6" },
            { sf::Keyboard::F7, "F7" },
            { sf::Keyboard::F8, "F8" },
            { sf::Keyboard::F9, "F9" },
            { sf::Keyboard::F10, "F10" },
            { sf::Keyboard::F11, "F11" },
            { sf::Keyboard::F12, "F12" },
            { sf::Keyboard::F13, "F13" },
            { sf::Keyboard::F14, "F14" },
            { sf::Keyboard::F15, "F15" },
            { sf::Keyboard::Pause, "Pause" },
            { sf::Keyboard::KeyCount, "KeyCount" }
    };

    inline constexpr auto key_to_string(sf::Keyboard::Key k) noexcept {
        return keymap[k + 1].second;
    }

    inline constexpr auto string_to_key(std::string_view str) noexcept {
        for(const auto &i : keymap)
            if(i.second == str)
                return i.first;
        return sf::Keyboard::Unknown;
    }

    std::ostream &operator<<(std::ostream &os, sf::Keyboard::Key k);
} // namespace Utils
