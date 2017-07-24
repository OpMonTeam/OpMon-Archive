/*
Enums.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Définit plusieurs énumérations
*/
#ifndef ENUMS_HPP
#define ENUMS_HPP

/**Defines permettant de rendre plus pratique l'écriture des tables des types*/
#define PE 0.5
#define NE 1
#define IN 0
#define TP 0.25
#define TE 2
#define SE 4

/**
Enumère les status des Pokémons
*/
//->Enum
namespace Status {
    const int BURNING = 0, PARALYSED = 1, SLEEPING = 2, FROZEN = 3, POISONED = 4, NOTHING = 5;
};
/**
Enumère les statistiques des Pokémons
*/
//->Enum
namespace Stats {
    const int ATK(6), DEF(1), ATKSPE(2), DEFSPE(3), VIT(4), PV(5), NOTHING(0);
};
/**
Enumère les catégories du sac
*/
//->Enum
namespace BagCat {
    const int SOIN(0), OBJETS(1), RARES(2), CTS(3), BAIES(4);
};
/**
Enumère les types
*/
//->Enum
namespace Type {
    const int EAU = 3, FEU = 6, PLANTE = 10, ELECTRIQUE = 4, PSY = 12, TENEBRES = 16, DRAGON = 2, COMBAT = 1, ROCHE = 13, SOL = 14, NORMAL = 9, FEE = 5, SPECTRE = 15, POISON = 11, ACIER = 0, INSECTE = 8, VOL = 17, GLACE = 7, NOTHING = -1;
};
/**
Enumère les types de contacts entre un evènement et le joueur.
*/
//->Enum
namespace ActionType {
    const int ENTER = 0, TOUCH = 1, IN_ = 2, VIEW = 3;
}
/**
Enumère les directions des sprites.
*/
//->Enum
namespace Side {
    const int TO_DOWN = 0, TO_RIGHT = 1, TO_LEFT = 2, TO_UP = 3;
}

/**
Enumère les differents encodages
*/
//->Enum
namespace Encoding {
    const int LATIN = 0, UNICODE = 1, UTF8 = 2;
}
/**
Gère la table des types
*/
namespace TableTypes {



    /**Calcule l'efficacité des types selon les paramètres donnés, et la renvoie.
     * Les paramètres attendent une énumération du namespace Type
     */
    float calcEfficacite(int atk, int def1, int def2);

}



#endif /* ENUMS_HPP */
