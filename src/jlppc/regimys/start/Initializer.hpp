#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP
#define POKE_NUMBER 252

#include <iostream>
#include <vector>
#include "../../utils/NumberedArray.hpp"
#include "../objects/Espece.hpp"
#include "../evolution/evolutions.hpp"

namespace Initializer {
	extern Espece *listePoke[POKE_NUMBER];
	extern std::vector<NumberedArray<Class<Attaque *> > > atkPokeLvl[POKE_NUMBER]; //100 attaques max / pok�
	extern Evolutions::E_Nope ne;//ne = No Evolution
	//std::string backgrounds[];
	extern std::vector<int> evs[POKE_NUMBER];
	void initEvs();
	void initPokemons();
	void initAtkLvls();
	void initSprites();
	void initBackgrounds();
	void initKeys();
	void initItems();
	void init();





};

#endif // INITIALIZER_HPP
