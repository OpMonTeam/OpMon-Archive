/**
 * Utilities for everything time-related.
 */
#pragma once


namespace Utils {

  /**
   * Set (or reset) the reference clock to zero.
   */
  void initClock();

  /**
   * Return the number of elapsed milliseconds since the beginning of the program
   * @return
   */
  int getElapsedMilliseconds();

}
