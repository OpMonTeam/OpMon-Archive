#ifndef ESPECE_HPP
#define ESPECE_HPP

#include <iostream>
#include "srcCpp/jlppc/regimys/evolution/Evolution.hpp"
#include "srcCpp/jlppc/regimys/enums/Type.hpp"
#include "srcCpp/jlppc/utils/HashArray.hpp"
#include "srcCpp/jlppc/regimys/start/main.hpp"

using namespace std;

class Espece
{
    public:
        Espece(int atk, int def, int atkSpe, int defSpe, int vit, int pv, string name, Type type1, Type type2,int maniereEvolution, int niveauEvolution, Evolution evolType, HashArray attacksByLevels[],CT ctCombatibles[], Stats EVGiven[], float taille, float poids, string entreePokedex, int expGiven,int expMax, int tauxDeCapture);
        void checkEvol();
        void checkAtkLvls();
        static int pokedexNumberInit = 0;
    protected:

    private:
        string nom;
        int numeroPokedex;
        Espece evolution;
        int niveauEvolution;
        Evolution evolType;
        Type type1;
        Type type2;
        HashArray atksByLevels[];
        string entreePokedex;
        float taille;
        float poids;
        CT ctCompatibles[];
        int baseAtk;
        int baseDef;
        int baseAtkSpe;
        int baseDefSpe;
        int baseVit;
        int basePV;
        CourbeExp courbe;
        int expMax;
        Stats EVgiven[];
        //Images
        int expGiven;
        int tauxDeCapture;

};

#endif // ESPECE_HPP
