#include "Keyboard.hpp"

#include <ostream>

namespace OpMon {
    std::ostream &operator<<(std::ostream &os, sf::Keyboard::Key k) {
        os << keyToString(k);
        return os;
    }
} // namespace OpMon
