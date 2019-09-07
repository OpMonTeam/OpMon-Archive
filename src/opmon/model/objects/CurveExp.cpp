/*
CurveExp.cpp
Author : torq
File under GNU GPL v3.0 license
*/
#include "CurveExp.hpp"
#include "../../start/Core.hpp"
#include <cmath>

namespace OpMon::Model {
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
            return int(std::pow(n, 3) * ((100 - n) / 50));
        } else if(51 <= n && n <= 68) {
            return int(std::pow(n, 3) * ((150 - n) / 50));
        } else if(69 <= n && n <= 98) {
            return int(1.274f - 0.02f * float(n / 3) - p(n % 3));
        } else if(n >= 99) {
            return int(std::pow(n, 3) * ((160 - n) / 100));
        } else {
            handleError("Error when calculating exp : level <= 0", true);
            return 0;
        }
    }

    int CurveExpFluctuating::getNeededExp(int n) {
        if(0 < n && n <= 15) {
            return int(std::pow(n, 3) * ((24 + ((n + 1) / 3) / 50)));
        } else if(16 <= n && n <= 35) {
            return int(std::pow(n, 3) * ((14 + n) / 50));
        } else if(n >= 36) {
            return int(std::pow(n, 3) * ((32 + (n / 2)) / 50));
        } else {
            handleError("Error when calculating exp : level <= 0", true);
            return 0;
        }
    }

    int CurveExpSlow::getNeededExp(int n) {
        return int(1.25f * std::pow(n, 3));
    }

    int CurveExpNormal::getNeededExp(int n) {
        return int(std::pow(n, 3));
    }

    int CurveExpParabolic::getNeededExp(int n) {
        return int(1.2f * std::pow(n, 3) - 15 * std::pow(n, 2) + (100 * n) - 140);
    }

    int CurveExpQuick::getNeededExp(int n) {
        return int(0.8f * std::pow(n, 3));
    }
} // namespace OpMon::Model
