/*
  BattleData.cpp
  Author : Cyrielle
  File under GNU GPL v3.0 license
*/
#include "BattleData.hpp"

#include "src/utils/ResourceLoader.hpp"

namespace OpMon {
class Player;
class GameData;

    BattleData::BattleData(GameData *data, Player *player)
        : gamedata(data)
        , player(player) {
        Utils::ResourceLoader::load(backgrounds["grass"], "backgrounds/battle_bkg/background_grass.png");
        Utils::ResourceLoader::load(dialog, "backgrounds/dialog/battle_dialog.png");

        Utils::ResourceLoader::load(cursor, "sprites/misc/arrBattle.png");

        charaBattleTextures["player"].push_back(sf::Texture());
        Utils::ResourceLoader::load(charaBattleTextures["player"][0], "sprites/chara/pp/pp_battle.png");
        //charaBattleTextures["cyrielle"].push_back(sf::Texture());
        //Utils::ResourceLoader::load(charaBattleTextures["cyrielle"][0], "sprites/chara/cyrielle/cyrielle_battle.png");
        charaBattleTextures["beta"].push_back(sf::Texture());
        Utils::ResourceLoader::load(charaBattleTextures["beta"][0], "sprites/chara/beta/beta_battle.png");
        battlePlayerAnim.push_back(charaBattleTextures["player"][0]);
        Utils::ResourceLoader::load(infoboxPlayer, "sprites/battle/square_1.png");
        Utils::ResourceLoader::load(infoboxTrainer, "sprites/battle/square_2.png");
        Utils::ResourceLoader::load(healthbar1, "sprites/battle/health_bar.png");
        Utils::ResourceLoader::load(healthbar2, "sprites/battle/health_jauge.png");
        Utils::ResourceLoader::load(shadowPlayer, "sprites/battle/shadow_2.png");
        Utils::ResourceLoader::load(shadowTrainer, "sprites/battle/shadow_1.png");

        Utils::ResourceLoader::load(moveDialog, "backgrounds/dialog/moves_dialog.png");
    }

} // namespace OpMon
