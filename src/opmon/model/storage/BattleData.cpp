/*
BattleData.cpp
Author : Cyrielle
File under GNU GPL v3.0 license
*/
#include "BattleData.hpp"
#include "ResourceLoader.hpp"

namespace OpMon::Model {

    BattleData::BattleData(UiData *data, Player *player)
      : uidata(data)
      , player(player) {
        ResourceLoader::load(backgrounds["grass"], "backgrounds/battle_bkg/background_grass.png");
        ResourceLoader::load(dialog, "backgrounds/dialog/battle_dialog.png");

        ResourceLoader::load(cursor, "sprites/misc/arrBattle.png");

        charaBattleTextures["player"].push_back(sf::Texture());
        ResourceLoader::load(charaBattleTextures["player"][0], "sprites/chara/pp/pp_battle.png");
        //charaBattleTextures["cyrielle"].push_back(sf::Texture());
        //ResourceLoader::load(charaBattleTextures["cyrielle"][0], "sprites/chara/cyrielle/cyrielle_battle.png");
        charaBattleTextures["beta"].push_back(sf::Texture());
        ResourceLoader::load(charaBattleTextures["beta"][0], "sprites/chara/beta/beta_battle.png");
        battlePlayerAnim.push_back(charaBattleTextures["player"][0]);
        ResourceLoader::load(infoboxPlayer, "sprites/battle/square_1.png");
        ResourceLoader::load(infoboxTrainer, "sprites/battle/square_2.png");
        ResourceLoader::load(healthbar1, "sprites/battle/health_bar.png");
        ResourceLoader::load(healthbar2, "sprites/battle/health_jauge.png");
        ResourceLoader::load(shadowPlayer, "sprites/battle/shadow_2.png");
        ResourceLoader::load(shadowTrainer, "sprites/battle/shadow_1.png");

        ResourceLoader::load(attackDialog, "backgrounds/dialog/attacks_dialog.png");
    }

} // namespace OpMon::Model
