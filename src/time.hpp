/*!
 * \file time.hpp
 * \brief Time-related utilities.
 * \author BAKFR
 * \date 08/01/18
 * \copyright GNU GPL v3.0
 */
#pragma once

/*! \namespace Utils
 *  \brief Contains different utilities.
 */
namespace Utils {
    /*!
	 * \namespace Utils::Time
     * \brief Contains time-related utilities.
	 */
    namespace Time {

        /*!
		 *  \brief Set (or reset) the reference clock to zero.
		 */
        void initClock();

        /*!
		 *  \return The number of elapsed milliseconds since the beginning of the program.
		 */
        int getElapsedMilliseconds();

        /*!
         *  \return The number of elapsed seconds since the beginning of the program.
         */
        float getElapsedSeconds();

        /*!
		*   \brief Pauses the program for a determined duration.
		*   \param duration Time to wait, in milliseconds
		*/
        void wait(int duration);

    } // namespace Time
} // namespace Utils
