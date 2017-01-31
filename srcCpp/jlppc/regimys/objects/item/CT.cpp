
#include "CT.hpp"

CT::CT(Class<Attke> atk, int ctNumber) : Item("CT" + ctnumber + atk.getName(), true, false,false, BagCat::CTS) {
	this->atk = atk;
}

