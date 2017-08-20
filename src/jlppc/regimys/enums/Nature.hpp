/*
Nature.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Définit l'énumération des caractères
*/
#ifndef SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_
#define SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_

#include "Enums.hpp"
/**
Définit la classe des caractères
*/
//->EnumClass->Nature
class NatureClass {
    public:
        /**La stat que boost le caractère*/
        //->WaitEnum->Stats
        int bonus;
        /**La stat que réduit le caractère*/
        //->WaitEnum->Stats
        int malus;

        int id;
        NatureClass(int bonus, int malus, int id) : bonus(bonus), malus(malus), id(id) {};
        //->DontUse
        NatureClass() {};

};
/**
Enumère les caractères
*/
//->Enum
namespace Nature {
    const NatureClass ASSURE = NatureClass(Stats::DEF, Stats::ATK, 0),
                         BIZARRE = NatureClass(Stats::NOTHING, Stats::NOTHING, 1),
                         BRAVE = NatureClass(Stats::ATK, Stats::SPE, 2),
                         CALME = NatureClass(Stats::DEFSPE, Stats::ATK, 3),
                         DISCRET = NatureClass(Stats::ATKSPE, Stats::SPE, 4),
                         DOCILE = NatureClass(Stats::NOTHING, Stats::NOTHING, 5),
                         DOUX = NatureClass(Stats::ATKSPE, Stats::DEF, 6),
                         FOUFOU = NatureClass(Stats::ATKSPE, Stats::DEFSPE, 7),
                         GENTIL = NatureClass(Stats::DEFSPE, Stats::DEF, 8),
                         HARDI = NatureClass(Stats::NOTHING, Stats::NOTHING, 9),
                         JOVIAL = NatureClass(Stats::SPE, Stats::ATKSPE, 10),
                         LACHE = NatureClass(Stats::DEF, Stats::DEFSPE, 11),
                         MALIN = NatureClass(Stats::DEF, Stats::ATKSPE, 12),
                         MALPOLI = NatureClass(Stats::DEFSPE, Stats::SPE, 13),
                         MAUVAIS = NatureClass(Stats::ATK, Stats::DEFSPE, 14),
                         MODESTE = NatureClass(Stats::ATKSPE, Stats::ATK, 15),
                         NAIF = NatureClass(Stats::SPE, Stats::DEFSPE, 16),
                         PRESSE = NatureClass(Stats::SPE, Stats::DEF, 17),
                         PRUDENT = NatureClass(Stats::DEFSPE, Stats::ATKSPE, 18),
                         PUDIQUE = NatureClass(Stats::NOTHING, Stats::NOTHING, 19),
                         RELAX = NatureClass(Stats::DEF, Stats::SPE, 20),
                         RIGIDE = NatureClass(Stats::ATK, Stats::ATKSPE, 21),
                         SERIEUX = NatureClass(Stats::NOTHING, Stats::NOTHING, 22),
                         SOLO = NatureClass(Stats::ATK, Stats::DEF, 23),
                         TIMIDE = NatureClass(Stats::SPE, Stats::ATK, 24);
    extern const NatureClass *enumsList[25];
};

#endif /* SRCCPP_JLPPC_REGIMYS_ENUMS_CARACTERE_HPP_ */
