/*
Enums.hpp
Author : Jlppc
File under GPL-3.0 license
http://opmon-game.ga
Define lot of enumerations
*/
#ifndef ENUMS_HPP
#define ENUMS_HPP

/**Defines permettant de rendre plus pratique l'écriture des tables des types*/
#define NE 0.5  //Not efficient
#define NM 1    //Normal
#define IN 0    //Inefficient
#define VL 0.25 //Very little (Efficiency)
#define VE 2    //Very efficient
#define SE 4    //Super efficient

namespace OpMon {
    namespace Model {

        /**
       Enumerate the OPMons statues
    */
        //->Enum
        enum class Status {
            BURNING,
            PARALYSED,
            SLEEPING,
            FROZEN,
            POISONED,
            NOTHING
        };
        /**
       Enumerate the OPMons stats
    */
        //->Enum
        enum class Stats : int {
            ATK = 6,
            DEF = 1,
            ATKSPE = 2,
            DEFSPE = 3,
            SPE = 4,
            HP = 5,
            ACC = 7,
            EVA = 8,
            NOTHING = 0
        };
        /**
       Enumerate the bag categories
    */
        //->Enum
        enum class BagCat {
            SOIN,
            OBJETS,
            RARES,
            CTS,
            BAIES
        };
        /**
       Enumerate the OPMons types
    */
        //->Enum
        enum class Type : int {
            EAU = 3,
            FEU = 6,
            PLANTE = 10,
            ELECTRIQUE = 4,
            PSY = 12,
            TENEBRES = 16,
            DRAGON = 2,
            COMBAT = 1,
            ROCHE = 13,
            SOL = 14,
            NORMAL = 9,
            FEE = 5,
            SPECTRE = 15,
            POISON = 11,
            ACIER = 0,
            INSECTE = 8,
            VOL = 17,
            GLACE = 7,
            NOTHING = -1
        };
        /**
       Enumère les types de contacts entre un evènement et le joueur.
    */
        //->Enum
        enum class ActionType {
            ENTER,
            TOUCH,
            IN_,
            VIEW
        };
        /**
       Enumère les directions des sprites.
    */
        //->Enum
        enum class Side : int {
            TO_DOWN = 0,
            TO_RIGHT = 1,
            TO_LEFT = 2,
            TO_UP = 3,
            NO_MOVE = -1,
            STAY = -2
        };

        /**
       Enumère les differents encodages
    */
        //->Enum
        enum class Encoding {
            LATIN,
            UNICODE,
            UTF8
        };

        bool operator==(Side side, int integer);
        bool operator!=(Side side, int integer);
        bool operator>=(Side, int);
        bool operator>(Side, int);
        bool operator<=(Side, int);
        bool operator<(Side, int);
        int operator+(Side, int);
        int operator-(Side, int);
        Side getSide(int);
        /**
       Gère la table des types
    */
        namespace ArrayTypes {

            /**Calcule l'efficacité des types selon les paramètres donnés, et la renvoie.
	   * Les paramètres attendent une énumération du namespace Type
	   */
            float calcEfficacite(Type atk, Type def1, Type def2);

        } // namespace ArrayTypes
    }     // namespace Model
} // namespace OpMon

#endif /* ENUMS_HPP */
