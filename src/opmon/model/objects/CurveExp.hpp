/*
CurveExp.hpp
Author : torq
Contributor : Cyrielle
File under GNU GPL v3.0 license
*/
#ifndef COURB_EXP_HPP
#define COURB_EXP_HPP

namespace OpMon::Model {

    class CurveExp {
      public:
        virtual int getNeededExp(int) = 0;
        virtual ~CurveExp() = default;
    };

    class CurveExpErratic : public CurveExp {
      private:
        static float p(int x);

      public:
        int getNeededExp(int n) override;
    };

    class CurveExpFluctuating : public CurveExp {
      public:
        int getNeededExp(int n) override;
    };

    class CurveExpSlow : public CurveExp {
      public:
        int getNeededExp(int level) override;
    };

    class CurveExpNormal : public CurveExp {
      public:
        int getNeededExp(int level) override;
    };

    class CurveExpParabolic : public CurveExp {
      public:
        int getNeededExp(int level) override;
    };

    class CurveExpQuick : public CurveExp {
      public:
        int getNeededExp(int level) override;
    };
} // namespace OpMon::Model
#endif // ESPECE_HPP
