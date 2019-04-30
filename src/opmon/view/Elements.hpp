/*
Elements.hpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "../model/sysObjects/Player.hpp"

namespace OpMon {
    namespace View {

        class MapLayer : public sf::Drawable, public sf::Transformable {
          private:
            static sf::Texture tileset;
            virtual void draw(sf::RenderTarget &target, sf::RenderStates stats) const;
            sf::VertexArray tiles;

          public:
            MapLayer(sf::Vector2i size, const int tilesCode[]);
        };

	enum class MovementMode : unsigned int {
	    POLYNOMIAL,
	    SINUSOIDAL
	};
	
	class Movement {
	private:
	    /* When the movement ends, from 0 to this. Set to 0 for no limit */
	    const unsigned int time;

	    MovementMode modeX = MovementMode::POLYNOMIAL;
	    MovementMode modeY = MovementMode::POLYNOMIAL;
	    
	    /* Polynomial Formula exemple : {2, 8, 1, 6, 9} will be used as 2 + 8t + t² + 6t^3 + 9t^4 */
	    /* Sinusoidal Formula exemple : {0, 2, 3, -5, 1, 1, -3, 4, 2, -4} will be used as + 2sin(3t - 5) + 1 - 3cos(4t + 2) - 4
	       Explication : The array must have this form : 
	       {sinus (0) or cosinus (1), a, b, c, d} will give a*sin/cos(b*t + c) + d.
	       The format can be repeated to add each part to the total (See first exemple)
	       The cosinus and sinus function are the radian ones.
	    */
	    const std::vector<int> xformula;
	    const std::vector<int> yformula;
	    /* If true, the movement will be relative to the object's position */
	    const bool relative;
	    /* Sprite to move */
	    sf::Sprite* sprite;
	    unsigned int t = 0;
	public :
	    
	    Movement(std::vector<int> const& xformula, std::vector<int> const& yformula, int const& time, bool const& relative = true, sf::Sprite* sprite = nullptr);

	    /* Attack a sprite to the object. Set replace to true to replace the current sprite if there is one.
	       Returns a pointer to the old sprite, nullptr if it was empty or if replace = false and one was already present */
	    sf::Sprite* attach(sf::Sprite* sprite, bool replace = false);

	    /* Detach the current sprite. Returns a pointer to the old sprite, nullptr if there were none */
	    sf::Sprite* detach();

	    /* Returns true if no sprite is attached, false otherwise */
	    bool empty();

	    /* Apply the movement to the attached sprite, incrementing t and calculating the new coordinates. Returns false if :
	       - t reached time
	       - no sprite is attached
	       Returns true otherwise
	    */
	    bool apply();
		
	};


    } // namespace View
} // namespace OpMon

#endif // ELEMENTS_HPP
