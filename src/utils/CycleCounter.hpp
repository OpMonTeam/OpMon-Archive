#pragma once

namespace Utils {
    /**
     * Represents a counter cycling in the interval between two values. When the counter reaches the upper value, it goes to the lower value, and vice versa.
     */
    class CycleCounter {
      private:
        /**
	 * The counter value.
	*/
        int value = 0;

        /**
	 * The lower limit.
	*/
        int limitDown;
        /**
	 * The upper limit.
	*/
        int limitUp;
        /**
	 * The range of the counter (number of values it can take).
	*/
        int range;

      public:
        explicit CycleCounter(int limitUp, int limitDown = 0, int value = 0)
          : value(value)
          , limitDown(limitDown)
          , limitUp(limitUp)
          , range(limitUp - limitDown) {}

        CycleCounter operator+(int number) { return CycleCounter(limitUp, limitDown, ((range + ((value + number) - limitDown)) % range) + limitDown); }
        CycleCounter operator-(int number) { return CycleCounter(limitUp, limitDown, ((range + ((value - number) - limitDown)) % range) + limitDown); }
        CycleCounter operator*(int number) { return CycleCounter(limitUp, limitDown, ((range + ((value * number) - limitDown)) % range) + limitDown); }
        CycleCounter operator/(int number) { return CycleCounter(limitUp, limitDown, ((range + ((value / number) - limitDown)) % range) + limitDown); }

        void operator++(int) { value = (*this + 1).value; }
        void operator--(int) { value = (*this - 1).value; }

        void operator+=(int number) { value = (*this + number).value; }
        void operator-=(int number) { value = (*this - number).value; }
        void operator*=(int number) { value = (*this * number).value; }
        void operator/=(int number) { value = (*this / number).value; }

        void operator=(int number) { value = ((range + (number - limitDown)) % range) + limitDown; }

        /**
	 * Return the counter value
	 */
        int getValue() { return value; }
    };
} // namespace Utils
