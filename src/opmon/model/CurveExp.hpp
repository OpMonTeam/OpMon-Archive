/*!
 * \file CurveExp.hpp
 * \authors torq
 * \authors Cyrielle
 * \copyright GNU GPL v3.0
 */
#ifndef COURB_EXP_HPP
#define COURB_EXP_HPP

namespace OpMon {

    /*!
     * \class CurveExp
     * \brief Defines the function used for the experience curves.
     */
    class CurveExp {
      public:
        /*!
         * \return The total experience points at the given level.
         * \param n The level.
         */
        virtual int getNeededExp(int n) = 0;
        virtual ~CurveExp() {};
    };

    class CurveExpErratic : public CurveExp {
      private:
        /*!
         * \brief A intermediary function to calculate the needed exp.
         */
        float p(int x);

      public:
        /*!
         * \copydoc CurveExp::getNeededExp()
         */
        int getNeededExp(int n);
    };

    class CurveExpFluctuating : public CurveExp {
      public:
        /*!
         * \copydoc CurveExp::getNeededExp()
         */
        int getNeededExp(int n);
    };

    class CurveExpSlow : public CurveExp {
      public:
        /*!
         * \copydoc CurveExp::getNeededExp()
         */
        int getNeededExp(int level);
    };

    class CurveExpNormal : public CurveExp {
      public:
        /*!
         * \copydoc CurveExp::getNeededExp()
         */
        int getNeededExp(int level);
    };

    class CurveExpParabolic : public CurveExp {
      public:
        /*!
         * \copydoc CurveExp::getNeededExp()
         */
        int getNeededExp(int level);
    };

    class CurveExpQuick : public CurveExp {
      public:
        /*!
         * \copydoc CurveExp::getNeededExp()
         */
        int getNeededExp(int level);
    };
} // namespace OpMon
#endif // ESPECE_HPP
