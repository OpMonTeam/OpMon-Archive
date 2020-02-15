/*
  BattleData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "BattleData.hpp"

#include "../core/system/ResourceLoader.hpp"

namespace OpMon {
class Player;
class UiData;

    BattleData::BattleData(UiData *data, Player *player)
        : uidata(data)
        , player(player) {
        System::ResourceLoader::load(backgrounds["grass"], "backgrounds/battle_bkg/background_grass.png");
        System::ResourceLoader::load(dialog, "backgrounds/dialog/battle_dialog.png");

        System::ResourceLoader::load(cursor, "sprites/misc/arrBattle.png");

        charaBattleTextures["player"].push_back(sf::Texture());
        System::ResourceLoader::load(charaBattleTextures["player"][0], "sprites/chara/pp/pp_battle.png");
        //charaBattleTextures["cyrielle"].push_back(sf::Texture());
        //System::ResourceLoader::load(charaBattleTextures["cyrielle"][0], "sprites/chara/cyrielle/cyrielle_battle.png");
        charaBattleTextures["beta"].push_back(sf::Texture());
        System::ResourceLoader::load(charaBattleTextures["beta"][0], "sprites/chara/beta/beta_battle.png");
        battlePlayerAnim.push_back(charaBattleTextures["player"][0]);
        System::ResourceLoader::load(infoboxPlayer, "sprites/battle/square_1.png");
        System::ResourceLoader::load(infoboxTrainer, "sprites/battle/square_2.png");
        System::ResourceLoader::load(healthbar1, "sprites/battle/health_bar.png");
        System::ResourceLoader::load(healthbar2, "sprites/battle/health_jauge.png");
        System::ResourceLoader::load(shadowPlayer, "sprites/battle/shadow_2.png");
        System::ResourceLoader::load(shadowTrainer, "sprites/battle/shadow_1.png");

        System::ResourceLoader::load(attackDialog, "backgrounds/dialog/attacks_dialog.png");
    }

} // namespace OpMon
