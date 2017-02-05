#include "Enums.hpp"

float TableTypes::calcEfficacite(Type atk, Type def1, Type def2){
	int atkI(atk), type1I(def1), type2I(def2);
	if(def2 == Type::AUCUN){
		return tabUnType[type1I][atkI];
	}else{
		return tableDeuxTypes[type1I][type2I][atkI];
	}
}
