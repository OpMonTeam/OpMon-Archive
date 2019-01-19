/*
CurveExp.cpp
Author : torq
File under GNU GPL v3.0 license
*/
#include "CurveExp.hpp"
#include "../../start/Core.hpp"
#include "math.h"

namespace OpMon {
    namespace Model {
        float CurveExpErratic::p(int x) {
            switch(x) {
            case 0:
                return 0;
            case 2:
                return 0.014;
            default:
                return 0.008;
            }
        }

        int CurveExpErratic::getNeededExp(int n) {
            if(0 < n && n <= 50) {
                return round(pow(n, 3) * ((100 - n) / 50));
            } else if(51 <= n && n <= 68) {
                return round(pow(n, 3) * ((150 - n) / 50));
            } else if(69 <= n && n <= 98) {
                return round(1.274f - ((1 / 50) * (n / 3)) - p(n % 3));
            } else if(n >= 99) {
                return round(pow(n, 3) * ((160 - n) / 100));
            } else {
                handleError("Error when calculating exp : level <= 0", true);
                return 0;
            }
        }

        int CurveExpFluctuating::getNeededExp(int n) {
            if(0 < n && n <= 15) {
                return round(pow(n, 3) * ((24 + ((n + 1) / 3) / 50)));
            } else if(16 <= n && n <= 35) {
                return round(pow(n, 3) * ((14 + n) / 50));
            } else if(n >= 36) {
                return round(pow(n, 3) * ((32 + (n / 2)) / 50));
            } else {
                handleError("Error when calculating exp : level <= 0", true);
                return 0;
            }
        }

        int CurveExpSlow::getNeededExp(int n) {
            return round(1.25f * pow(n, 3));
        }

        int CurveExpNormal::getNeededExp(int n) {
            return round(pow(n, 3));
        }

        int CurveExpParabolic::getNeededExp(int n) {
            return round(1.2f * pow(n, 3) - 15 * pow(n, 2) + (100 * n) - 140);
        }

        int CurveExpQuick::getNeededExp(int n) {
            return round(0.8f * pow(n, 3));
        }
    } // namespace Model
} // namespace OpMon
