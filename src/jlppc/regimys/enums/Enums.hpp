/*
Enums.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
D�finit plusieurs �num�rations
*/
#ifndef ENUMS_HPP
#define ENUMS_HPP

/**Defines permettant de rendre plus pratique l'�criture des tables des types*/
#define PE 0.5
#define NE 1
#define IN 0
#define TP 0.25
#define TE 2
#define SE 4

/**
Enum�re les status des Pok�mons
*/
//->Enum
namespace Status {
const int BRULURE = 0, PARALYSIE = 1, SOMMEIL = 2, GEL = 3, POISON = 4, AUCUN = 5;
};
/**
Enum�re les statistiques des Pok�mons
*/
//->Enum
namespace Stats {
const int ATK(6), DEF(1), ATKSPE(2), DEFSPE(3), VIT(4), PV(5), RIEN(0);
};
/**
Enum�re les cat�gories du sac
*/
//->Enum
namespace BagCat {
const int SOIN(0), OBJETS(1), RARES(2), CTS(3), BAIES(4);
};
/**
Enum�re les types
*/
//->Enum
namespace Type {
const int EAU = 3, FEU = 6, PLANTE = 10, ELECTRIQUE = 4, PSY = 12, TENEBRES = 16, DRAGON = 2, COMBAT = 1, ROCHE = 13, SOL = 14, NORMAL = 9, FEE = 5, SPECTRE = 15, POISON = 11, ACIER = 0, INSECTE = 8, VOL = 17, GLACE = 7, AUCUN = -1;
};
/**
Enum�re les types de contacts entre un ev�nement et le joueur.
*/
//->Enum
namespace ActionType{
const int ENTER = 0, TOUCH = 1, INE = 2, VIEW = 3;
}
/**
G�re la table des types
*/
namespace TableTypes {



/**Calcule l'efficacit� des types selon les param�tres donn�s, et la renvoie.
 * Les param�tres attendent une �num�ration du namespace Type
 */
float calcEfficacite(int atk, int def1, int def2);

}



#endif /* ENUMS_HPP */
