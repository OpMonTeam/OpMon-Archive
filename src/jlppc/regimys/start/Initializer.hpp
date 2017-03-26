/*
Initializer.hpp
Auteur : Jlppc
Contributeurs au fichier .cpp: Navet56, Aerzia
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la définition des methodes qui permettent d'initialiser les éléments du jeu
*/
#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP
#define OP_NUMBER 50

#include <iostream>
#include <vector>
#include "../../utils/NumberedArray.hpp"
#include "../objects/Espece.hpp"
#include "../evolution/evolutions.hpp"

#define ATK_LIST(OpId) AtkArray tab##OpId[]
#define ATK_ADD_LIST(OpID, atkLength) pb(atkOpLvl[(OpId)], tab##OpId , (atkLength) )
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../gui/Elements.hpp"
//->NoDoc
namespace Initializer {
extern Espece *listeOp[OP_NUMBER];
extern std::vector<NumberedArray> opOpLvl[OP_NUMBER]; //100 attaques max / poké
extern Evolutions::E_Nope *ne;//ne = No Evolution
extern SDL_Texture *world[285];
extern SDL_Texture *grass[104];
extern SDL_Texture *objects[500];
extern Plan *fauxBourgEuvi;
extern std::vector<std::vector<int> > tabs[1];
//std::string backgrounds[];
extern std::vector<int> evs[OP_NUMBER];
void initEvs();
void initOpMons();
void initAtkLvls();
void initSprites();
void initBackgrounds();
void initKeys();
void initPlans();
void init();





};

#endif // INITIALIZER_HPP
