/*!
 * \file InternalFiles.hpp
 * \authors Cyrielle
 * \authors Navet56
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 * \todo Delete this and move what's left in the file elsewhere.
*/

#ifndef INTERNALFILES_HPP
#define INTERNALFILES_HPP

#include <iostream>
#include <sstream>
#include <vector>

namespace OpMon {
    namespace Model {
        /*!
         * \brief Contains the data of the collisions.
         */
        namespace Collisions {
            /*!
             * \brief Contains the collisions for each tile.
             */
            extern int colTile[4096];
        }
    } // namespace Model
} // namespace OpMon
#endif // INTERNALFILES_HPP
