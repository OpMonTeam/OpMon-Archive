#include "evolutions.hpp"


namespace Evolutions {
	E_Level::E_Level(int evo, int level) : Evolution(evo) {
		this->level = level;
	}

	bool E_Level::checkEvolve(OpMon const &toCheck) const {
		return (toCheck.getLevel() >= level);
	}
}


