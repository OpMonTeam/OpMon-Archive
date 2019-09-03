#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <cmath>

namespace Utils::Origin {
    /**
     * Template function for centering graphical objects' origins.
     *
     * It has to be a template function, because we need setOrigin() from Transformable and getLocalBounds() from
     * the Drawable implementations.
     * @tparam T The type of the graphical object in argument
     * @param transformable The graphical object that will have its origin centered
     */
    template <class T>
    void centerOrigin(T& transformable) {
        sf::FloatRect bounds = transformable.getLocalBounds();
        transformable.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
    }
}
