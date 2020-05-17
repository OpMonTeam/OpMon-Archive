#include "Keyboard.hpp"

namespace Utils {
    std::ostream &operator<<(std::ostream &os, sf::Keyboard::Key k) {
        os << key_to_string(k);
        return os;
    }
} // namespace Utils
