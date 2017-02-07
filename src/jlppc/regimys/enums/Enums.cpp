#include "Enums.hpp"

float TableTypes::calcEfficacite(int atk, int def1, int def2){
	int atkI(atk), type1I(def1), type2I(def2);
	if(def2 == Type::AUCUN){
		return tabUnType[type1I][atkI];
	}else{
		return tableDeuxTypes[type1I][type2I][atkI];
	}
}
