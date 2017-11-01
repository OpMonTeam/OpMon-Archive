/*
  Initializer.hpp
  Author : Jlppc
  Contributeurs au fichier .cpp: Navet56, Aerzia
  Fichier sous licence GPL-3.0
  http://opmon-game.ga
  Contient la définition des methodes qui permettent d'initialiser les éléments du jeu
*/
#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

namespace OpMon{
  class Map;
  //->NoDoc
  namespace Initializer {
    void initOpMons();
    void initAtkLvls();
    void initSprites();
    void initBackgrounds();
    void initKeys();
    void initMaps();
    void initAnims();
    //void deleteAnims();
    void init();
  };

}
#endif // INITIALIZER_HPP
