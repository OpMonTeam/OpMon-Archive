/*
  Initializer.hpp
  Author : Jlppc
  Contributors: Navet56, Aerzia, BAKFR
  Fichier sous licence GPL-3.0
  http://opmon-game.ga
  Contains the methods definitions that allows to initialize the game elements
*/
#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

namespace OpMon {

    //->NoDoc
    namespace Initializer {
        void initOpMons();
        void initAtkLvls();
        void initSprites();
        void initBackgrounds();
        void initKeys();
        void initMaps();
        void initAnims();

        void initPlayer();

        void initGui();

        void initMusics();

        void initOverworld();
        void initStartScene();
        void initMenu();

        void initMenuStrings();
        void initStartSceneStrings();

        void initControls();

        //void deleteAnims();
        void init();
    } // namespace Initializer

} // namespace OpMon
#endif // INITIALIZER_HPP
