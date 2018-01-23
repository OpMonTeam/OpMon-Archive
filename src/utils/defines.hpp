#ifndef DEFINES_HPP
#define DEFINES_HPP

#ifdef __GNUC__
#define OP_DEPRECATED __attribute__((deprecated))
#elif defined(_MSC_VER)
#define OP_DEPRECATED __declspec(deprecated)
#else
#define OP_DEPRECATED
#endif

#include <string>

/**
Shortcuts
*/
#define UNS using namespace std;


/* location of the save folder */
#define SAVE_PATH std::string("saves/")


#define FONT_SIZE_DEFAULT 25


#endif
