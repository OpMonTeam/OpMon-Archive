#include "Species.hpp"
#include "./evolution/Evolution.hpp"
#include "./evolution/evolutions.hpp"

namespace OpMon {
	namespace Model {

		Species::Species(Species &&other) noexcept {
			name = other.name;
			numeroOpdex = other.numeroOpdex;
			evolution = other.evolution;
			niveauEvolution = other.niveauEvolution;
			evolType = other.evolType;
			type1 = other.type1;
			type2 = other.type2;
			entreeOpdex = other.entreeOpdex;
			height = other.height;
			weight = other.weight;
			baseAtk = other.baseAtk;
			baseDef = other.baseDef;
			baseAtkSpe = other.baseAtkSpe;
			baseDefSpe = other.baseDefSpe;
			baseVit = other.baseVit;
			baseHP = other.baseHP;
			curve = other.curve;
			expMax = other.expMax;
			EVgiven = other.EVgiven;
			expGiven = other.expGiven;
			tauxDeCapture = other.tauxDeCapture;
			evSize = other.evSize;

			other.evolType = nullptr;
		}

		Species::~Species() {
			delete(evolType);
		}

		Species::Species(unsigned int atk, unsigned int def, unsigned int atkSpe, unsigned int defSpe, unsigned int spe, unsigned int hp, std::string name, Type type1, Type type2, int maniereEvolution /*En fait faut mettre 0, il est la pour un souci de compatibilit�*/, int niveauEvolution, Evolution *evolType, std::vector<Stats> EVGiven, float height, float weight, std::string entreeOpdex, unsigned int expGiven, int expMax, int tauxDeCapture, int numeroOpdex) {
			if(evolType == nullptr) {
				evolType = new E_Nope();
			}
			this->numeroOpdex = numeroOpdex;
			this->tauxDeCapture = tauxDeCapture;
			this->baseAtk = atk;
			this->baseDef = def;
			this->baseAtkSpe = atkSpe;
			this->baseDefSpe = defSpe;
			this->baseVit = spe;
			this->name = name;
			this->baseHP = hp;
			this->type1 = type1;
			this->type2 = type2;
			this->niveauEvolution = niveauEvolution;
			this->evolType = evolType;
			this->evolution = this->evolType->getEvolution();
			this->weight = weight;
			this->height = height;
			this->entreeOpdex = entreeOpdex;
			this->expGiven = expGiven;
			this->EVgiven = EVGiven;
			//Mise en place des curves d'exp
			this->expMax = expMax;
			switch(this->expMax) {
			case 800000:
				curve = CurveExp::QUICK;
				break;
			case 1000000:
				curve = CurveExp::AVERAGE;
				break;
			case 1059860:
				curve = CurveExp::PARABOLIC;
				break;
			case 1250000:
				curve = CurveExp::SLOW;
				break;
			case 600000:
				curve = CurveExp::ERRATIC;
				break;
			case 1640000:
				curve = CurveExp::FLUCTUATING;
				break;
			default:
				curve = CurveExp::AVERAGE;
			}
			this->numeroOpdex = numeroOpdex;
		}

		void Species::checkEvol() {
			evolType->checkEvo();
			this->evolution = evolType->getEvolution();
		}

		void Species::checkAtkLvls() {
			//this->atksByLevels = Initializer::atkOpLvl[OpdexNumberInit];
		}
	} // namespace Model
} // namespace OpMon
