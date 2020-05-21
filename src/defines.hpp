/*!
 * \file defines.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0 license
 * \date 31/10/17
*/
#ifndef DEFINES_HPP
#define DEFINES_HPP

#define OPMON_VERSION "0.16.0"

//We have [[deprecated]] in c++14
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

/*!
 * \brief Contains the default size font.
 */
#define FONT_SIZE_DEFAULT 16

/*!
 * \brief Contains the number PI with 11 digits.
 */
#define PI 3.1415926535

#endif
