
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
     * Sleep for determined duration.
     * @param duration - time to wait, in milliseconds
     */
        void wait(int duration);

    } // namespace Time
} // namespace Utils
