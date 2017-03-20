/*
Evolution.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la d�finition da la classe Evolution
*/
#ifndef EVOLUTION_HPP
#define EVOLUTION_HPP

#include <iostream>
#include "../objects/OpMon.hpp"
#include "../../utils/Class.hpp"

class Espece;
/**
Permet de d�finir un type d'�volution
*/
//->PureVirtual
class Evolution {
public:
    virtual ~Evolution() {}
    Evolution() {
        evo = -1;
    }
    Evolution(int evo);
    /**Permet de v�rifier si le pok�mon �volue. Renvoie true si il peut evoluer*/
    virtual bool checkEvolve(OpMon const &toCheck) const = 0;
    Espece *getEvolution() const;
    /**Check evo permet de r�cuperer l'espece d'�volution. Ne pas confondre avec checkEvolve*/
    void checkEvo();
    virtual int getEvolID() const {
        return evolID;
    }
    //->JustUse->E_Item
    virtual bool itemEvolve(Item *tem) const {
        return false;
    }


protected:
    static const int evolID = 0;
    Espece *toEvolve;
    int evo;
};

#endif /* EVOLUTION_HPP */
