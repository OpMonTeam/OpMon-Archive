/*
Elements.hpp
Author : Cyrielle
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


          struct MovementData {
            /* Formulas giving the x and y coordinates as a function of t */
            FormulaMode modeX;
            FormulaMode modeY;

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
            bool relative = true;

            bool init = false;//If false, the object is not ready to be used
          };



          struct RotationData {
                  /* Formula giving the angle (in degrees) as a function of t */
                  std::vector<double> formula;

                  FormulaMode formulaMode;

                  sf::Vector2f origin;//The origin point where the rotation is calculated from.
                  bool init = false;//If false, the object is not ready to be used

          };

          struct ScaleData {
            FormulaMode modeX = FormulaMode::POLYNOMIAL;
            FormulaMode modeY = FormulaMode::POLYNOMIAL;
            /* Formulas giving the x and y coordinates as a function of t */
            std::vector<double> xformula;
            std::vector<double> yformula;
            bool init = false;//If false, the object is not ready to be used
            sf::Vector2f origin;//The origin point where the scaling is calculated from.

          };

          typedef struct MovementData MovementData;
          typedef struct RotationData RotationData;
          typedef struct ScaleData ScaleData;

          /**
           * Transformation class uses sf::Transform to create animations following parametric formulas.
           * Warning : The sf::Transform objects are names "sprite" in Transformation, Movement and Rotation, because a sprite has been used before realising it wouldn't work. TODO : Change the names.
           */
          class Transformation {
          protected:
                  /* When the movement ends, from 0 to this. Set to 0 for no limit */
                  const unsigned int time;

                  unsigned int t = 0;
                  /* Transform object to transform.*/
                  sf::Transform* sprite;

                  const MovementData md;
                  const RotationData rd;
                  const ScaleData sd;


                  sf::Vector2f lastTranslation = sf::Vector2f(0., 0.);
                  float lastRotation = 0.;
                  sf::Vector2f lastScaling = sf::Vector2f(1.0, 1.0);

                  float calcFormula(std::vector<double> formula, FormulaMode mode, int t);
                  //Rotates a vector. The angle is in degrees.
                  sf::Vector2f rotateVector(sf::Vector2f const& vect, double angle);

          public:
                  Transformation(unsigned int const& time, MovementData const md = MovementData(), RotationData const rd = RotationData(), ScaleData const sd = ScaleData(), sf::Transform* sprite = nullptr);

                  /* Attack a sprite to the object. Set replace to true to replace the current sprite if there is one.
                                                 Returns a pointer to the old sprite, nullptr if it was empty or if replace = false and one was already present */
                  sf::Transform* attach(sf::Transform* sprite, bool replace = false);

                  /* Detach the current sprite. Returns a pointer to the old sprite, nullptr if there were none */
                  sf::Transform* detach();

                  /* Returns true if no sprite is attached, false otherwise */
                  bool empty();

                  /* Apply the movement to the attached sprite, incrementing t and calculating the new coordinates. Returns false if :
                                                 - t reached time
                                                 - no sprite is attached
                                                 Returns true otherwise
                   */
                  bool apply();

                  /* Shortcut for apply() */
                  bool operator()() {return apply();}

                  virtual ~Transformation();

                  static MovementData mirror(MovementData const& movement);
                  /* Return the coordinates of a sprite center (width/2; height/2)*/
                  static sf::Vector2f spriteCenter(sf::Sprite const& spr);

                  static const MovementData newMovementData(FormulaMode modeX, FormulaMode modeY, std::vector<double> xformula, std::vector<double> yformula, bool relative = true);
                  static const RotationData newRotationData(FormulaMode formulaMode, std::vector<double> formula, sf::Vector2f origin);
                  static const ScaleData newScaleData(FormulaMode modeX, FormulaMode modeY, std::vector<double> xformula, std::vector<double> yformula, sf::Vector2f origin);
          };


    } // namespace View
} // namespace OpMon

#endif // ELEMENTS_HPP
