
#include "CT.hpp"

CT::CT(ClassAtk atk, int ctNumber, int ID) : Item(("CT" + ctNumber + atk.getName()), true, false,false, BagCat::CTS, ID) {
	this->atk = atk;
}

