
#include "CT.hpp"
template<typename Attke>
CT<Attke>::CT(Class<Attke> atk, int ctNumber, int ID) : Item("CT" + ctNumber + atk.getName(), true, false,false, BagCat::CTS, ID) {
	this->atk = atk;
}

