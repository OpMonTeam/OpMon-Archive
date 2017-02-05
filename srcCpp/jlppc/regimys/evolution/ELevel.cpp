
#include "ELevel.hpp"

E_Level::E_Level(int evo, int level) : Evolution(evo){
	this->level = level;
}

bool E_Level::checkEvolve(Pokemon toCheck) const{
	return (toCheck.getLevel() >= level);
}

