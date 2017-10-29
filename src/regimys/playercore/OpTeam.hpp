/*
OpTeam.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la définition de la classe OpTeam
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <iostream>
#include "../objects/OpMon.hpp"

class OpMon;

/**
Classe permettant de contenir l'opteam d'un joueur ou d'un dresseur.
*/
class OpTeam {
public:
    OpTeam(std::string const& name);
    std::string getName() const {
        return name;
    }
    OpMon **getOpTeam() {
        return opteam;
    }
    /**Soigne toute l'opteam*/
    void heal();
    /**
    Ajoute un pokémon a l'opteam. Renvoie false si l'opteam est pleine
    */
    bool addOpMon(OpMon *toAdd);
    /**Suprime de numberième pokémon dans l'équipe*/
    OpMon* removeOp(int number);
    /**
    Operateur permettant de recuperer le Pokémon a la place donnée en parametre
    */
    OpMon *operator[](int id) const;
    OpMon *getOp(int id) const{
        return (*this)[id];
    }
    /**Renvoie true si l'équipe est K.O*/
    bool isKo() const ;
    int getSize() const ;
    void operator+=(OpMon *pkmn) {
        addOpMon(pkmn);
    }
    void operator-=(int id) {
        removeOp(id);
    }
    void save();

private:
    //->Useless
    int nbreOfOp = 6;
    OpMon *opteam[6] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::string name;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
