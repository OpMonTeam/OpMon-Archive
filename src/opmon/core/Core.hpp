/*!
 * \file Core.hpp
 * \authors Cyrielle
 * \authors BAKFR
 * \copyright GNU GPL v3.0
 * \date 31/10/17
 * \brief The program core functions.
 */
#ifndef CORE_HPP
#define CORE_HPP

#include <string>

#include "../../utils/defines.hpp"
#include "GameStatus.hpp"

/*!
  \namespace OpMon
  \brief Base namespace of the program.
 */
namespace OpMon {

    /*!
     * \brief Function handling errors on the program.
     * \param errorName A description of the error
     * \param fatal If `true`, the program will stop.
     */
    void handleError(std::string const &errorName, bool fatal = false);
    /*!
     * \brief Function quitting the game, deleting the resources
     * \param returns The value returned by the program.
     * \return The parameter `returns`.
     */
    int quit(int const &returns);

} // namespace OpMon

#endif
