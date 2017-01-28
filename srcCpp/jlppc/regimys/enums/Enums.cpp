#include "Enums.hpp"

float TableTypes::calcEfficacite(Type atk, Type def1, Type def2){
	if(def2 == Type::AUCUN){
		return tabUnType[def1][atk];
	}else{
		return tableDeuxTypes[def1][def2][atk];
	}
}

