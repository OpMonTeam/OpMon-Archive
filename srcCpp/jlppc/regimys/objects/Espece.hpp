#ifndef ESPECE_HPP
#define ESPECE_HPP

#include <iostream>
#include "srcCpp/jlppc/regimys/evolution/Evolution.hpp"

using namespace std;

class Espece
{
    public:
        Espece();

    protected:

    private:
        string nom;
        int numeroPokedex;
        Espece evolution;
        int niveauEvolution;
        Evolution evolType;

};

#endif // ESPECE_HPP
