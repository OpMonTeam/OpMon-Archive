/*
time.hpp
Author : BAKFR
File under GNU GPL v3.0
*/
#pragma once

namespace Utils {
    /**
   * Utilities for everything time-related.
   */
    namespace Time {

        /**
	 * Set (or reset) the reference clock to zero.
	 */
        void initClock();

        /**
	 * Return the number of elapsed milliseconds since the beginning of the program
	 */
        int getElapsedMilliseconds();

        /**
         * Return the number of elapsed seconds since the beginning of the program
         */
        float getElapsedSeconds();

        /**
	 * Sleep for determined duration.
	 * @param duration - time to wait, in milliseconds
	 */
        void wait(int duration);

    } // namespace Time
} // namespace Utils
