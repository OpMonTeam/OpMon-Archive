/*!
 * \file defines.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0 license
 * \date 31/10/17
*/
#ifndef DEFINES_HPP
#define DEFINES_HPP

#include "config.hpp"

#ifdef __GNUC__
#define OP_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define OP_DEPRECATED __declspec(deprecated)
#else
/*!
 * \brief Indicates the deprecation of an object.
 */
#define OP_DEPRECATED
#endif

#ifdef SFML_COMPATIBILITY
#define setSfmlColor setColor
#else
/*!
 * \brief Compatibility macro to avoir deprecation warning with earlier SFMl versions.
 * \details Redirects to setFillColor() if SFML_COMPATIBILITY is declared, or setColor() otherwise.
 */
#define setSfmlColor setFillColor
#endif

#include <string>

/*!
 * \brief Returns the location of the save path folder.
 * \deprecated Use Utils::Path::getSavePath().
 */
#define SAVE_PATH Utils::Path::getSavePath()

/*!
 * \brief Contains the default size font.
 */
#define FONT_SIZE_DEFAULT 25

/*!
 * \brief Contains the number PI with 11 digits.
 */
#define PI 3.1415926535

#endif
