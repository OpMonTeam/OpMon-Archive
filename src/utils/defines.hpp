/*
defines.hpp
Author : Cyriel
Contributor : BAKFR
File under GNU GPL v3.0 license
*/
#ifndef DEFINES_HPP
#define DEFINES_HPP

#include "config.hpp"

#ifdef __GNUC__
#define OP_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define OP_DEPRECATED __declspec(deprecated)
#else
#define OP_DEPRECATED
#endif

#ifdef SFML_COMPATIBILITY
#define setSfmlColor setColor
#else
#define setSfmlColor setFillColor
#endif

#include <string>

/* location of the save folder */
#define SAVE_PATH Utils::Path::getSavePath()

#define FONT_SIZE_DEFAULT 25

#endif
