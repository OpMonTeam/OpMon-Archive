/*!
 * \file Elements.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 * \todo Separate this file in two: MapLayer and Transformation
 */
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

/*!
 * \brief ·1 function : {F_NOTHING, a} -> a
 */
#define F_NOTHING 0
/*!
 * \brief Sine function : {1, a, b, c} -> a·sin(b·t + c)
 * \warning The sine function is in radians.
 */
#define F_SINE 1
/*!
 * \brief Cosine function : {2, a, b, c} -> a·cos(b·t + c)
 * \warning The cosine function is in radians.
 */
#define F_COSINE 2
/*!
 * \brief Absolute value function : {3, a, b, c} -> a·|b·t + c|
 */
#define F_ABS 3
/*!
 * \brief Power function : {4, a, b, c} -> a·(t + b)^c
 */
#define F_POW 4

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

#include "../../core/Player.hpp"

namespace sf {
    class RenderTarget;
    class Sprite;
    class Texture;
    class Transform;
} // namespace sf

namespace OpMon {
    /*!
     * \brief Namespace containing the view part.
     */
    namespace Ui {

        /*!
         * \brief A map layer.
         */
        class MapLayer : public sf::Drawable, public sf::Transformable {
          private:
            /*!
             * \brief Method called by RenderTexture::draw.
             */
            virtual void draw(sf::RenderTarget &target,
                              sf::RenderStates stats) const;
            /*!
             * \brief The tiles.
             */
            sf::VertexArray tiles;

            /*!
             * \brief The tileset used in the map.
             */
            sf::Texture &tileset;

          public:
            /*!
             * \brief Builds a map layer.
             * \param size The dimentions of the map.
             * \param tilesCode An array containing the tiles codes to build the map.
             */
            MapLayer(sf::Vector2i size, const int tilesCode[],
                     sf::Texture &tileset);
        };

        /*!
         * \brief The different types of formulas used in MovementData.
         */
        enum class FormulaMode : unsigned int {
            /*!
             * A polynomial formula. Each element of the array will be
             * interpreted as the coefficient of the variable put to the power
             * of the index of the element in the array. Exemple : {2, 8, 1, 6,
             * 9} will be interpreted as 2 + 8t + t^2 + 6t^3 + 9t^4.
             */
            POLYNOMIAL = 0,
            /*!
             * A formula using different base fonctions. The interpretation will
             * change according to the chosen function. Exemple : {#F_SINE, 2,
             * 3, -5, #F_ABS, -3, 4, -2} will be interpreted as 2sin(3t - 5) -
             * 3·|4t - 2| List of currently available functions : #F_NOTHING
             * #F_SINE
             * #F_COSINE
             * #F_ABS
             * #F_POW
             * See the documentation of each one to see how to use it.
             */
            MULTIFUNCTIONS = 1
        };

        /*!
         * \brief A structure containing information about a translation.
         * \todo Unify MovementData, RotationData and ScaleData in one formula.
         */
        struct MovementData {
            /*!
             * \brief The type of the formula giving the x coordinate as a function of t.
             */
            FormulaMode modeX;
            /*!
             * \brief The type of the formula giving the y coordinate as a function of t.
             */
            FormulaMode modeY;

            /*!
             * \brief The array containing the formula giving the x coordinate as a function of t.
             * \details The format is detailed in the documentation of FormulaMode.
             */
            std::vector<double> xformula;
            /*!
             * \brief The array containing the formula giving the y coordinate as a function of t.
             * \details The format is detailed in the documentation of FormulaMode.
             */
            std::vector<double> yformula;
            /*!
             * \brief If `true`, the movement will be relative to the object current position.
             */
            bool relative = true;

            /*!
             * \brief If `false`, the object is not ready to be used.
             */
            bool init = false;
        };

        /*!
         * \brief A structure containing information about a rotation.
         * \todo Unify MovementData, RotationData and ScaleData in one formula.
         */
        struct RotationData {
            /*!
             * \brief Formula giving the angle of rotation (in degrees) as a function of t.
             */
            std::vector<double> formula;

            /*!
             * \brief The type of the formula giving the angle of rotation.
             */
            FormulaMode formulaMode;

            /*!
             * \brief Origin of the rotation.
             */
            sf::Vector2f origin;
            /*!
             * \brief If `false`, the object is not ready to be used.
             */
            bool init = false;
        };

        /*!
         * \brief A structure containing information about a scaling.
         * \todo Unify MovementData, RotationData and ScaleData in one formula.
         */
        struct ScaleData {
            /*!
             * \brief The type of the formula giving the horizontal scaling as a function of t.
             */
            FormulaMode modeX = FormulaMode::POLYNOMIAL;
            /*!
             * \brief The type of the formula giving the vertical scaling as a function of t.
             */
            FormulaMode modeY = FormulaMode::POLYNOMIAL;
            /*!
             * \brief The formula giving the horizontal stretching as a function of t.
             */
            std::vector<double> xformula;
            /*!
             * \brief The formula giving the vertical stretching as a function of t.
             */
            std::vector<double> yformula;

            /*!
             * \brief Origin of the rotation.
             */
            sf::Vector2f origin;
            /*!
             * \brief If `false`, the object is not ready to be used.
             */
            bool init = false;
        };

        typedef struct MovementData MovementData;
        typedef struct RotationData RotationData;
        typedef struct ScaleData ScaleData;

        /**
         * \brief Transformation class uses sf::Transform to create animations following parametric formulas.
         * \warning The sf::Transform objects are names "sprite" because a sprite has been used before realising it wouldn't work.
         * \todo Change the name of the sf::Transform object.
         */
        class Transformation {
          protected:
            /*!
             * \brief When the movement ends, from 0 to this.
             * \details Set to 0 for no limit.
             */
            const unsigned int time;

            /*!
             * \brief The variable used, corresponding to the number of frames elapsed.
             */
            unsigned int t = 0;
            /*!
             * \brief The data for the a translation.
             */
            const MovementData md;
            /*!
             * \brief The data for a rotation.
             */
            const RotationData rd;
            /*!
             * \brief The data for a scaling.
             */
            const ScaleData sd;
            /*!
             * \brief The transform object which will be applied to the sprite to animate.
             */
            sf::Transform *sprite;

            /*!
             * \brief The last translation applied.
             */
            sf::Vector2f lastTranslation = sf::Vector2f(0., 0.);
            /*!
             * \brief The angle of the last rotation applied.
             */
            float lastRotation = 0.;
            /*!
             * \brief The last scaling applied.
             */
            sf::Vector2f lastScaling = sf::Vector2f(1.0, 1.0);

            /*!
             * \brief Calculates the value of the formula for a given value of t.
             * \param formula The formula to calculate.
             * \param mode The type of formula.
             * \param t The value of t.
             * \returns The value of the formula with the given value of t.
             */
            float calcFormula(std::vector<double> formula, FormulaMode mode,
                              int t);
            /*!
             * \brief Rotates a vector.
             * \param vect The vector to rotate.
             * \param angle The angle to apply, in degrees.
             * \returns The rotated vector.
             */
            sf::Vector2f rotateVector(sf::Vector2f const &vect, double angle);

            /*!
             * \brief Reverses the sign of some coefficients to mirror the formula.
             * \returns The mirrored formula.
             */
            std::vector<double> inverseFormula(std::vector<double> formula,
                                               FormulaMode mode);

          public:
            /*!
             * \brief Constructs an animation.
             * \param time The duration of the animation, in frames.
             * \param md The data of the translation.
             * \param rd The data of the rotation.
             * \param sd The data of the scaling.
             * \param sprite The sf::Transform in which apply the transformation.
             */
            Transformation(unsigned int const &time,
                           MovementData const md = MovementData(),
                           RotationData const rd = RotationData(),
                           ScaleData const sd = ScaleData(),
                           sf::Transform *sprite = nullptr);

            /*!
             * \brief Attachs a Transform to the object.
             * \details Set replace to true to replace the current sprite if there is one.
             * \param sprite The Transform to attach to the object.
             * \param replace If `false`, prevents the method from replacing the current Transform is one is already attached.
             * \returns A pointer to the old sprite, `nullptr` if it was empty or if replace = `false` and one was already present.
             */
            sf::Transform *attach(sf::Transform *sprite, bool replace = false);

            /*!
             * \brief Detach the current sprite.
             * \returns A pointer to the old sprite, `nullptr` if there were none.
             */
            sf::Transform *detach();

            /*!
             * \brief Checks if no sprite is attached to the object.
             * \returns `true` if no sprite is attached, `false` otherwise.
             */
            bool empty();

            /*!
             * \brief Apply the movement to the attached sprite, incrementing t and calculating the new coordinates.
             * \returns `false` if t reached the time limit or if no sprite is attached, `true` otherwise.
             */
            bool apply();

            /*!
             * \brief Shortcut for apply().
             */
            bool operator()() { return apply(); }

            virtual ~Transformation();

            /*!
             * \brief Returns a inversed version of the animation (for the other OpMon in the battle).
             * \details See Transformation::inverseFormula
             */
            Transformation inverse();
            /*!
             * Calculates the coordinates of a the center of a sprite (width/2;
             * height/2).
             */
            static sf::Vector2f spriteCenter(sf::Sprite const &spr);

            /*!
             * \brief Creates a new MovementData.
             */
            static const MovementData newMovementData(
                FormulaMode modeX, FormulaMode modeY,
                std::vector<double> xformula, std::vector<double> yformula,
                bool relative = true);
            /*!
             * \brief Creates a new RotationData.
             */
            static const RotationData newRotationData(
                FormulaMode formulaMode, std::vector<double> formula,
                sf::Vector2f origin);
            /*!
             * \brief Creates a new ScaleData.
             */
            static const ScaleData newScaleData(FormulaMode modeX,
                                                FormulaMode modeY,
                                                std::vector<double> xformula,
                                                std::vector<double> yformula,
                                                sf::Vector2f origin);
        };

    } // namespace Ui
} // namespace OpMon

#endif // ELEMENTS_HPP
