#include "Keyboard.hpp"

namespace OpMon {
    std::ostream &operator<<(std::ostream &os, sf::Keyboard::Key k) {
        os << keyToString(k);
        return os;
    }
} // namespace OpMon
