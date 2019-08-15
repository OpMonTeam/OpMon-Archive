/*
CurveExp.hpp
Author : torq
Contributor : Cyrielle
File under GNU GPL v3.0 license
*/
#ifndef COURB_EXP_HPP
#define COURB_EXP_HPP

namespace OpMon {
    namespace Model {

        class CurveExp {
          public:
            virtual int getNeededExp(int) = 0;
            virtual ~CurveExp(){};
        };

        class CurveExpErratic : public CurveExp {
          private:
            float p(int x);

          public:
            int getNeededExp(int n);
        };

        class CurveExpFluctuating : public CurveExp {
          public:
            int getNeededExp(int n);
        };

        class CurveExpSlow : public CurveExp {
          public:
            int getNeededExp(int level);
        };

        class CurveExpNormal : public CurveExp {
          public:
            int getNeededExp(int level);
        };

        class CurveExpParabolic : public CurveExp {
          public:
            int getNeededExp(int level);
        };

        class CurveExpQuick : public CurveExp {
          public:
            int getNeededExp(int level);
        };
    } // namespace Model
} // namespace OpMon
#endif // ESPECE_HPP
