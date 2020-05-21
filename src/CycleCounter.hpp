/*!
 * \file CycleCounter.hpp
 * \brief A cycling counter.
 * \author Cyrielle
 * \date 14/02/19
 * \copyright GNU GPL v3.0
 */
#pragma once

/*! \namespace Utils
 *  \brief Contains different utilities.
 */
namespace Utils {
    /*!
     * \class CycleCounter "CycleCounter.hpp"
     * \brief Represents a counter cycling in the interval between two values.
     * \details When the counter reaches the upper value, it goes to the lower value, and vice versa. The class is designed to work with the most common operators, allowing to manipulate an objet as simply as if it were a number.
     */
    class CycleCounter {
      private:
        /*!
         * \brief The value of the counter.
         */
        int value = 0;

        /*!
         * \brief The lower limit.
         */
        int limitDown;
        /*!
         * \brief The upper limit.
         */
        int limitUp;
        /*!
         * \brief The range of the counter (number of values it can take).
         */
        int range;

      public:

        /*!
         * \param limitUp The upper limit of the counter.
         * \param limitDown The lower limit of the counter.
         * \param value The value of the counter.
         */
        CycleCounter(int limitUp, int limitDown = 0, int value = 0)
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

        /*!
         * \return The value of the counter.
         */
        int getValue() const { return value; }
    };
} // namespace Utils
