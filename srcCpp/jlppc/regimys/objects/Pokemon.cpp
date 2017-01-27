#include "Pokemon.hpp"

Pokemon::Pokemon(){

}

bool Pokemon::captured(I_Pokeball pokeball){
    Status listeUnCinq[] = {Status.PARALYSIE, Status.POISON, Status.BRULURE};
    Status listeDeux[] = {Status.SOMMEIL, Status.GEL};
    int a = round((((3 * statPV - 2 * PV) * tauxCapture * pokeball.getTauxCapture() * (Comparaisons.muliEgal(status, listeUnCinq, 3) ? 1.5f : (Comparaisons.muliEgal(status, listeDeux, 2) ? 2 : 1)))/(3 * statPV)));
}
