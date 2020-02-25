/*
  Species.cpp
  Author : Cyrielle
  Contributor : BAKFR
  File under GNU GPL v3.0
*/
#include "Species.hpp"

#include "./Evolution.hpp"
#include "src/opmon/objects/CurveExp.hpp"
#include "src/opmon/objects/Enums.hpp"

namespace OpMon {

    Species::Species(Species &&other) noexcept {
        name = other.name;
        opdexNumber = other.opdexNumber;
        evolution = other.evolution;
        evolType = other.evolType;
        type1 = other.type1;
        type2 = other.type2;
        opdexEntry = other.opdexEntry;
        height = other.height;
        weight = other.weight;
        baseAtk = other.baseAtk;
        baseDef = other.baseDef;
        baseAtkSpe = other.baseAtkSpe;
        baseDefSpe = other.baseDefSpe;
        baseSpe = other.baseSpe;
        baseHP = other.baseHP;
        curve = other.curve;
        expMax = other.expMax;
        EVgiven = other.EVgiven;
        expGiven = other.expGiven;
        captureRate = other.captureRate;

        other.evolType = nullptr;
    }

    Species::~Species() {
        delete(evolType);
        delete(curve);
    }
#pragma GCC diagnostic ignored "-Wunused-parameter"
    Species::Species(unsigned int atk, unsigned int def, unsigned int atkSpe, unsigned int defSpe, unsigned int spe, unsigned int hp, std::string name, Type type1, Type type2, Evolution *evolType, std::vector<Stats> EVGiven, float height, float weight, std::string opdexEntry, unsigned int expGiven, int expMax, int captureRate, int opdexNumber) {
        this->opdexNumber = opdexNumber;
        this->captureRate = captureRate;
        this->baseAtk = atk;
        this->baseDef = def;
        this->baseAtkSpe = atkSpe;
        this->baseDefSpe = defSpe;
        this->baseSpe = spe;
        this->name = name;
        this->baseHP = hp;
        this->type1 = type1;
        this->type2 = type2;
        this->evolType = evolType;
        this->evolution = ((evolType != nullptr) ? this->evolType->getEvolution() : nullptr);
        this->weight = weight;
        this->height = height;
        this->opdexEntry = opdexEntry;
        this->expGiven = expGiven;
        this->EVgiven = EVGiven;
        this->expMax = expMax;

        //The curve is found according to the max OpMon's exp.
        switch(this->expMax) {
        case 800000:
            curve = new CurveExpQuick();
            break;
        case 1000000:
            curve = new CurveExpNormal();
            break;
        case 1059860:
            curve = new CurveExpParabolic();
            break;
        case 1250000:
            curve = new CurveExpSlow();
            break;
        case 600000:
            curve = new CurveExpErratic();
            break;
        case 1640000:
            curve = new CurveExpFluctuating();
            break;
        default:
            curve = new CurveExpNormal();
        }
    }
#pragma GCC diagnostic pop
} // namespace OpMon
