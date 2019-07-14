/*
Elements.hpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#define F_NOTHING 0
#define F_SINUS 1
#define F_COSINUS 2
#define F_ABS 3
#define F_POW 4

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

      /* Polynomial Formula exemple : {2, 8, 1, 6, 9} will be used as 2 + 8t + t² + 6t^3 + 9t^4 */
        /* Multiformula Formula exemple : {1, 2, 3, -5, 3, -3, 4, 2} will be used as 2sin(3t - 5) - 3abs(4t + 2)
           See the explainations in Elements.cpp, from line 123.
           The format can be repeated to add each part to the total (See first exemple)
           The cosinus and sinus functions are the ones with parameters in radians.
     */
	enum class FormulaMode : unsigned int {
	    POLYNOMIAL = 0,
	    MULTIFUNCTIONS = 1
	};
	
	class Transformation {
	protected:
		/* When the movement ends, from 0 to this. Set to 0 for no limit */
		const unsigned int time;

		unsigned int t = 0;
		/* Sprite to move */
		sf::Sprite* sprite;

		Transformation(sf::Sprite* sprite, unsigned int const& time);

		double calcFormula(std::vector<double> formula, FormulaMode mode, int t);

	public:
		/* Attack a sprite to the object. Set replace to true to replace the current sprite if there is one.
					       Returns a pointer to the old sprite, nullptr if it was empty or if replace = false and one was already present */
		virtual sf::Sprite* attach(sf::Sprite* sprite, bool replace = false);

		/* Detach the current sprite. Returns a pointer to the old sprite, nullptr if there were none */
		virtual sf::Sprite* detach();

		/* Returns true if no sprite is attached, false otherwise */
		bool empty();

		/* Apply the movement to the attached sprite, incrementing t and calculating the new coordinates. Returns false if :
					       - t reached time
					       - no sprite is attached
					       Returns true otherwise
		 */
		virtual bool apply() = 0;

		virtual ~Transformation();
	};

	class Movement : public Transformation{
	private:
	    /* Formulas giving the x and y coordinates as a function of t */
	    FormulaMode modeX = FormulaMode::POLYNOMIAL;
	    FormulaMode modeY = FormulaMode::POLYNOMIAL;
	    
	    /* Polynomial Formula exemple : {2, 8, 1, 6, 9} will be used as 2 + 8t + t² + 6t^3 + 9t^4 */
	    /* Multifunctions Formula exemple : {0, 2, 3, -5, 1, 1, -3, 4, 2, -4} will be used as + 2sin(3t - 5) + 1 - 3cos(4t + 2) - 4
	       Explication : The array must have this form : 
	       {function ID (see the macros higher on the file), a, b, c, d} will give a*f(b*t + c) + d.
	       The format can be repeated to add each part to the total (See first exemple)
	       The cosinus and sinus function are the ones with parameters in radians.
	    */
	    std::vector<double> xformula;
	    std::vector<double> yformula;
	    /* If true, the movement will be relative to the object position */
	    const bool relative;

	    sf::Vector2f basePos;


	public:
	    
	    Movement(FormulaMode modeX, FormulaMode modeY, std::vector<double> xformula, std::vector<double> yformula, int const& time, bool const& relative = true, sf::Sprite* sprite = nullptr);

	    ~Movement();
	    
	    sf::Sprite* attach(sf::Sprite* sprite, bool replace = false) override;
	    sf::Sprite* detach() override;

	    bool apply() override;

	    /* Changes the formulas signs. Used in the battles to set the movement to the defender.*/
	    static Movement* mirror(Movement const& movement);
		
	};

	class Rotation : public Transformation{
	private:

		/* Formula giving the angle (in degrees) as a function of t */
		std::vector<double> formula;

		FormulaMode formulaMode;

		sf::Vector2f origin;
		sf::Vector2f baseOrigin;

	public:
		Rotation(FormulaMode formulaMode, std::vector<double> formula, sf::Vector2f origin, int const& time, sf::Sprite *sprite = nullptr);
		~Rotation();

		bool apply() override;

		/* Return the coordinates of a sprite center (x/2; y/2)*/
		static sf::Vector2f spriteCenter(sf::Sprite const& spr);
	};

	class Deformation : public Transformation {
	private:

	  FormulaMode modeX = FormulaMode::POLYNOMIAL;
	  FormulaMode modeY = FormulaMode::POLYNOMIAL;
	  /* Formulas giving the x and y coordinates as a function of t */
	  std::vector<double> xformula;
	  std::vector<double> yformula;

	public:
	      Deformation(FormulaMode modeX, FormulaMode modeY, std::vector<double> xformula, std::vector<double> yformula, int const& time, sf::Sprite* sprite = nullptr);


	};


    } // namespace View
} // namespace OpMon

#endif // ELEMENTS_HPP
