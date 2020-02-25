/*
  Battle.cpp
  Author : Cyrielle
  Contributors : Navet56, torq
  File under GNU GPL v3.0
*/
#include "Battle.hpp"

#include <SFML/Graphics/Rect.hpp>
#include <ext/alloc_traits.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>
#include <algorithm>
#include <map>
#include <memory>
#include <vector>

#include "../../utils/StringKeys.hpp"
#include "../objects/Attack.hpp"
#include "BattleData.hpp"
#include "src/opmon/core/Player.hpp"
#include "src/opmon/core/UiData.hpp"
#include "src/opmon/objects/OpMon.hpp"
#include "src/opmon/objects/Species.hpp"
#include "src/opmon/views/objects/Turn.hpp"
#include "src/opmon/views/ui/Dialog.hpp"
#include "src/opmon/views/ui/Elements.hpp"
#include "src/opmon/views/ui/Jukebox.hpp"
#include "src/utils/CycleCounter.hpp"
#include "src/utils/OpString.hpp"
#include "src/utils/defines.hpp"

namespace OpMon {

    void Battle::draw(sf::RenderTarget& frame, sf::RenderStates states) const {

        frame.setView(frame.getDefaultView());

        frame.draw(background);
        frame.draw(playerSpr);
        frame.draw(trainerSpr);
        frame.draw(atk, atkTr);
        frame.draw(def, defTr);
        frame.draw(infoboxPlayer);
        frame.draw(infoboxTrainer);

        for(unsigned int i = 0; i < 2; i++) {
            frame.draw(healthbar1[i]);
            frame.draw(healthbar2[i]);
        }

        frame.draw(opName[0]);
        frame.draw(opName[1]);
        frame.draw(opLevel[0]);
        frame.draw(opLevel[1]);
        frame.draw(opHp);


        if(!turnLaunched)
            frame.draw(dialogSpr);

        if(drawDialog)
            frame.draw(*dialog);

        if(drawMainDialog){
            for(sf::Text txt : choicesTxt) {
                frame.draw(txt);
            }
            frame.draw(waitText);
        }

        if(drawAttacks){
            for(unsigned int i = 0; i < 4; i++) {
                frame.draw(attacks[i]);
            }
            if(drawType){
                frame.draw(type);
            }

            frame.draw(ppTxt);
            frame.draw(ppStrTxt);
        }

        if(!turnLaunched) {
            frame.draw(cursor);
        }
    }

    void Battle::initialize(Elements::TurnData const &atkTurn, Elements::TurnData const &defTurn){
        data.getUiDataPtr()->getJukebox().play("Wild Battle");
        initNewOp(atkTurn.opmon, defTurn.opmon);
        initialized = true;
    }

    void Battle::initNewOp(OpMon const* atk, OpMon const* def){
        //Prints OpMon data info (Hp, name...)
        opLevel[0].setString("Lv. " + std::to_string(atk->getLevel()));
        opLevel[1].setString("Lv. " + std::to_string(def->getLevel()));

        opName[0].setString(atk->getNickname());
        opName[1].setString(def->getNickname());

        this->atk.setTexture(data.getUiDataPtr()->getOpSprite(atk->getSpecies().getOpdexNumber(), false));
        this->def.setTexture(data.getUiDataPtr()->getOpSprite(def->getSpecies().getOpdexNumber(), true));

        atkHp = atk->getHP();
        defHp = def->getHP();
    }

    GameStatus Battle::update(Elements::TurnData const &atkTurn, Elements::TurnData const &defTurn, std::queue<Elements::TurnAction> &actionQueue, bool *turnActivated, bool atkFirst) {

        drawDialog = false;
        drawMainDialog = false;
        drawAttacks = false;
        drawType = false;

        if(!initialized){
            initialize(atkTurn, defTurn);
        }

         //Resizes heath bars to print the correct colors
        healthbar2[0].setTextureRect(sf::IntRect(0, 0, (defHp * data.getHealthbar2().getSize().x) / defTurn.opmon->getStatHP(), data.getHealthbar2().getSize().y));
        healthbar2[1].setTextureRect(sf::IntRect(0, 0, (atkHp * data.getHealthbar2().getSize().x) / atkTurn.opmon->getStatHP(), data.getHealthbar2().getSize().y));

        //Checks if the turn is launched or not
        /* During the battle, two phases alternate:
           - Action selection (Menu with different actions)
           - Turn action (Attack, item and other actions)
           When the turn is launched, the variable turnActivated is set to true in BattleCtrl.
           When the turn is over, the variable turnActivated is set to false in BattleCtrl.
           Battle have its own variable, allowing to know when the variable has changed, and do this code.
        */
        if(!turnLaunched && *turnActivated) {
            phase = 1;
            turnLaunched = true;
        } else if(turnLaunched && !(*turnActivated)) {
            phase = 0;
            turnLaunched = false;
        }

        if(*turnActivated && turnNber <= 1) { //If it's turn phase
            //Organizes the turns priority
            const Elements::TurnData *turns[2];
            if(atkFirst) {
                turns[0] = &atkTurn;
                turns[1] = &defTurn;
            } else {
                turns[0] = &defTurn;
                turns[1] = &atkTurn;
            }

            if(!actionQueue.empty()) {
                /* Handles the actions which can happen on screen */
                Elements::TurnAction &turnAct = actionQueue.front();

                if(turnAct.type == Elements::TurnActionType::DIALOG) { //If a dialog must be printed
                    if(dialogOver) {                         //A new dialog is created
                        if(dialog != nullptr) {
                            delete(dialog);
                            dialog = nullptr;
                        }
                        dialogOver = false;
                        sf::String dialogs = turnAct.dialog.getString();
                        dialog = new Ui::Dialog(dialogs, data.getUiDataPtr());
                    } else { //Continuing an old dialog
                        dialog->updateTextAnimation();
                        if(dialog->isDialogOver()) { //If the dialog is over, go to the next action in the queue
                            actionQueue.pop();
                            dialogOver = true;
                        }
                    }
                } else if(turnAct.type == Elements::TurnActionType::ATK_UPDATE_HBAR || turnAct.type == Elements::TurnActionType::DEF_UPDATE_HBAR) { //Updates the player's OpMon's healthbar.
                    data.getUiDataPtr()->getJukebox().playSound("hit");
                    auto &opmonHp = (turnAct.type == Elements::TurnActionType::ATK_UPDATE_HBAR) ? atkHp : defHp;
                    opmonHp -= turnAct.hpLost;
                    opmonHp = (opmonHp < 0) ? 0 : opmonHp; //Don't drop below 0
                    actionQueue.pop();
                } else if(turnAct.type == Elements::TurnActionType::ATK_STAT_MOD || turnAct.type == Elements::TurnActionType::DEF_STAT_MOD) { //When an OpMon's stat is modified

                    //Animation part
                    if(currentOpAnims == nullptr) {
                        currentOpAnims = new std::queue<Ui::Transformation>();
                        currentOpAnims->push(Ui::Transformation(40, Ui::MovementData(), Ui::RotationData(), Ui::Transformation::newScaleData(Ui::FormulaMode::MULTIFUNCTIONS, Ui::FormulaMode::MULTIFUNCTIONS, (turnAct.statCoef > 0) ? std::vector<double>{2, 0.1, 2 * PI / 20, 0, 0, 0.9} : std::vector<double>{2, -0.1, 2 * PI / 20, 0, 0, 1.1}, (turnAct.statCoef <= 0) ? std::vector<double>{2, 0.1, 2 * PI / 20, 0, 0, 0.9} : std::vector<double>{2, -0.1, 2 * PI / 20, 0, 0, 1.1}, Ui::Transformation::spriteCenter(atk))));
                    }
                    if(currentOpAnims->front().empty()) {
                        currentOpAnims->front().attach((turnAct.type == Elements::TurnActionType::ATK_STAT_MOD) ? &atkTr : &defTr);
                    }

                    //Dialog part
                    auto &opTurn = (turnAct.type == Elements::TurnActionType::ATK_STAT_MOD) ? atkTurn : defTurn;
                    if(dialogOver) {
                        if(dialog != nullptr) {
                            delete(dialog);
                            dialog = nullptr;
                        }
                        dialogOver = false;
                        dialog = new Ui::Dialog(Utils::OpString::quickString("battle.stat." + std::to_string((int)turnAct.statMod) + "." + std::to_string(turnAct.statCoef), {opTurn.opmon->getNickname()}), data.getUiDataPtr());
                    } else {
                        dialog->updateTextAnimation();
                    }

                    //Checking part
                    if(!currentOpAnims->front().apply() && dialog->isDialogOver()) { //If the dialog is over, go to the next action in the queue
                        actionQueue.pop();
                        dialogOver = true;
                        delete(currentOpAnims);
                        currentOpAnims = nullptr;
                    }
                } else if(turnAct.type == Elements::TurnActionType::VICTORY) {
                    if(dialogOver) {
                        if(dialog != nullptr) {
                            delete(dialog);
                            dialog = nullptr;
                        }
                        dialogOver = false;
                        dialog = new Ui::Dialog(Utils::OpString::quickString("battle.victory", {data.getPlayer().getName()}), data.getUiDataPtr());
                    } else {
                        dialog->updateTextAnimation();
                        if(dialog->isDialogOver()) {
                            actionQueue.pop();
                            delete(dialog);
                            dialog = nullptr;
                            return GameStatus::PREVIOUS;
                        }
                    }
                } else if(turnAct.type == Elements::TurnActionType::DEFEAT) {
                    if(dialogOver) {
                        if(dialog != nullptr) {
                            delete(dialog);
                            dialog = nullptr;
                        }
                        dialogOver = false;
                        dialog = new Ui::Dialog(Utils::OpString::quickString("battle.defeat", {data.getPlayer().getName()}), data.getUiDataPtr());
                    } else {
                        dialog->updateTextAnimation();
                        if(dialog->isDialogOver()) {
                            actionQueue.pop();
                            delete(dialog);
                            dialog = nullptr;
                            return GameStatus::PREVIOUS;
                        }
                    }
                } else if(turnAct.type == Elements::TurnActionType::OPANIM) {
                    if(currentOpAnims == nullptr) {
                        currentOpAnims = new std::queue<Ui::Transformation>(((atkFirst && (turnNber == 0)) || (!atkFirst && (turnNber == 1))) /* Is it player's turn */ ? turns[turnNber]->attackUsed->getOpAnimsAtk() : turns[turnNber]->attackUsed->getOpAnimsDef());
                    }
                    if(currentOpAnims->front().empty()) {
                        currentOpAnims->front().attach(((atkFirst && (turnNber == 0)) || (!atkFirst && (turnNber == 1))) /* Is it player's turn */ ? &atkTr : &defTr);
                    }
                    if(!currentOpAnims->front().apply()) {
                        currentOpAnims->pop();
                        actionQueue.pop();
                        if(currentOpAnims->empty()) {
                            delete(currentOpAnims);
                            currentOpAnims = nullptr;
                        }
                    }
                } else if(turnAct.type == Elements::TurnActionType::NEXT) {
                    turnNber++;
                    actionQueue.pop();
                } else {
                    actionQueue.pop();
                }
            } else {
                *turnActivated = false;
                turnNber = 0;
            }

            if(dialog == nullptr) { //Always show the dialog box (if possible)
                dialog = new Ui::Dialog(" ", data.getUiDataPtr());
            }
            drawDialog = true;

        } else if(!attackChoice) { // Main battle menu
            std::queue<sf::String> waitTxt = Utils::StringKeys::autoNewLine(Utils::StringKeys::get("battle.wait"), data.getUiDataPtr()->getFont(), 22, 192);
            sf::String str = waitTxt.front() + sf::String('\n');
            waitTxt.pop();
            str += waitTxt.front();
            waitText.setString(str);
            drawMainDialog = true;
            cursor.setPosition(posChoices[curPos.getValue()] + sf::Vector2f((choicesTxt[curPos.getValue()].getGlobalBounds().width / 2) - 10, 25));

        } else { //Attacks menu

            for(unsigned int i = 0; i < 4; i++) {
                if(atkTurn.opmon->getAttacks()[i] != nullptr) {
                    attacks[i].setString(atkTurn.opmon->getAttacks()[i]->getName());
                } else {
                    attacks[i].setString("----"); //Text to print if there is no attack
                }
                drawAttacks = true;
            }

            if(atkTurn.opmon->getAttacks()[curPos.getValue()] != nullptr) {

                //Changes the text's color according to the number of PP left
                if(atkTurn.opmon->getAttacks()[curPos.getValue()]->getPP() <= (atkTurn.opmon->getAttacks()[curPos.getValue()]->getPPMax() / 5) && atkTurn.opmon->getAttacks()[curPos.getValue()]->getPP() > 0) {
                    ppTxt.setSfmlColor(sf::Color::Yellow);
                } else if(atkTurn.opmon->getAttacks()[curPos.getValue()]->getPP() == 0) {
                    ppTxt.setSfmlColor(sf::Color::Red);
                } else {
                    ppTxt.setSfmlColor(sf::Color::Black);
                }
                ppTxt.setString(std::to_string(atkTurn.opmon->getAttacks()[curPos.getValue()]->getPP()) + " / " + std::to_string(atkTurn.opmon->getAttacks()[curPos.getValue()]->getPPMax()));
                type.setTexture(data.getUiDataPtr()->getTypeTexture(atkTurn.opmon->getAttacks()[curPos.getValue()]->getType()));
                drawType = true;
            } else { //If there is no attack, print this
                ppTxt.setSfmlColor(sf::Color::Red);
                ppTxt.setString("0 / 0");
            }


            cursor.setPosition(posChoices[curPos.getValue()] + sf::Vector2f((attacks[curPos.getValue()].getGlobalBounds().width / 2) - 10, 30));
        }

        
        return GameStatus::CONTINUE;
    }

    void Battle::toggleAttackChoice() {
        attackChoice = !attackChoice;
        if(attackChoice) {
            dialogSpr.setTexture(data.getAttackDialog());
            posChoices[0].x = 35;
            posChoices[0].y = 382;
            posChoices[1].x = 135;
            posChoices[1].y = 382;
            posChoices[2].x = 35;
            posChoices[2].y = 437;
            posChoices[3].x = 135;
            posChoices[3].y = 437;
            for(unsigned int i = 0; i < 4; i++) {
                attacks[i].setPosition(posChoices[i]);
                attacks[i].setFont(data.getUiDataPtr()->getFont());
                attacks[i].setCharacterSize(22);
                attacks[i].setSfmlColor(sf::Color::Black);
            }
            curPos = 0;

        } else {
            posChoices[0].x = 300 + (99 - choicesTxt[0].getGlobalBounds().width) / 3;
            posChoices[0].y = 392;
            posChoices[1].x = 400 + (99 - choicesTxt[1].getGlobalBounds().width) / 2;
            posChoices[1].y = 392;
            posChoices[2].x = 300 + (99 - choicesTxt[2].getGlobalBounds().width) / 2;
            posChoices[2].y = 457;
            posChoices[3].x = 400 + (99 - choicesTxt[3].getGlobalBounds().width) / 2;
            posChoices[3].y = 457;
            dialogSpr.setTexture(data.getDialog());
            curPos = 0;
        }
    }

    Battle::Battle(const OpTeam *atkTeam, const OpTeam *defTeam, std::string trainerClass, std::string background, BattleData &data)
        : atkTeam(atkTeam)
        , defTeam(defTeam)
        , data(data) {
        this->background.setTexture(data.getBackground(background));
        playerSpr.setTexture(data.getCharaBattleTextures("player")[0]);
        playerSpr.setPosition(20, 218);
        playerSpr.setScale(2, 2);
        trainerSpr.setTexture(data.getCharaBattleTextures(trainerClass)[0]);
        trainerSpr.setPosition(400, 20);

        choicesTxt[0].setString(Utils::StringKeys::get("battle.attack"));
        choicesTxt[1].setString(Utils::StringKeys::get("battle.bag"));
        choicesTxt[2].setString(Utils::StringKeys::get("battle.opmon"));
        choicesTxt[3].setString(Utils::StringKeys::get("battle.run"));

        for(unsigned int i = 0; i < 4; i++) {
            choicesTxt[i].setFont(data.getUiDataPtr()->getFont());
            choicesTxt[i].setCharacterSize(20);

            choicesTxt[i].setSfmlColor(sf::Color::White);
        }

        posChoices[0].x = 300 + (99 - choicesTxt[0].getGlobalBounds().width) / 2;
        posChoices[0].y = 392;
        posChoices[1].x = 400 + (99 - choicesTxt[1].getGlobalBounds().width) / 2;
        posChoices[1].y = 392;
        posChoices[2].x = 300 + (99 - choicesTxt[2].getGlobalBounds().width) / 2;
        posChoices[2].y = 457;
        posChoices[3].x = 400 + (99 - choicesTxt[3].getGlobalBounds().width) / 2;
        posChoices[3].y = 457;

        for(unsigned int i = 0; i < 4; i++) {
            choicesTxt[i].setPosition(posChoices[i]);
        }

        //ppText.setPosition(326, 380);

        dialogSpr.setTexture(data.getDialog());
        dialogSpr.setPosition(0, 512 - 150);
        cursor.setTexture(data.getCursor());
        cursor.setPosition(posChoices[0] + sf::Vector2f((choicesTxt[0].getGlobalBounds().width / 2) - 10, 25));
        curPos = 0;
        cursor.setScale(2, 2);
        atkTr.translate(107, 230);
        defTr.translate(305, 120);
        atkTr.scale(2, 2);

        infoboxPlayer.setTexture(data.getInfoboxPlayer());
        infoboxPlayer.setPosition(277, 252);
        infoboxTrainer.setTexture(data.getInfoboxTrainer());
        infoboxTrainer.setPosition(17, 148);
        shadowPlayer.setTexture(data.getShadowPlayer());
        shadowPlayer.setPosition(130, 281);
        shadowTrainer.setTexture(data.getShadowTrainer());
        shadowTrainer.setPosition(320, 175);
        for(unsigned int i = 0; i < 2; i++) {
            healthbar1[i].setTexture(data.getHealthbar1());
            healthbar2[i].setTexture(data.getHealthbar2());
        }

        infoboxTrainer.setPosition(17, 148);
        healthbar1[0].setPosition(30, 130);
        healthbar2[0].setPosition(30, 130);

        infoboxPlayer.setPosition(277, 252);
        healthbar1[1].setPosition(335, 230);
        healthbar2[1].setPosition(335, 230);

        opName[0].setPosition(332, 289);
        opLevel[0].setPosition(332, 314);
        opName[1].setPosition(22, 160);
        opLevel[1].setPosition(22, 185);

        for(unsigned int i = 0; i < 2; i++) {
            opName[i].setFont(data.getUiDataPtr()->getFont());
            opLevel[i].setFont(data.getUiDataPtr()->getFont());
            opName[i].setCharacterSize(22);
            opLevel[i].setCharacterSize(22);
            opName[i].setSfmlColor(sf::Color::Black);
            opLevel[i].setSfmlColor(sf::Color::Black);
        }

        opHp.setFont(data.getUiDataPtr()->getFont());
        opHp.setCharacterSize(14);
        opHp.setSfmlColor(sf::Color::Black);
        opHp.setPosition(332, 264);

        waitText.setFont(data.getUiDataPtr()->getFont());
        waitText.setCharacterSize(22);
        waitText.setSfmlColor(sf::Color::White);
        waitText.setPosition(65, 410);

        ppStrTxt.setPosition(326, 380);
        ppStrTxt.setString("PP :");
        ppTxt.setPosition(326, 405);
        ppStrTxt.setFont(data.getUiDataPtr()->getFont());
        ppTxt.setFont(data.getUiDataPtr()->getFont());
        ppStrTxt.setCharacterSize(26);
        ppTxt.setCharacterSize(26);
        ppStrTxt.setSfmlColor(sf::Color::Black);
        ppTxt.setSfmlColor(sf::Color::Black);

        type.setPosition(326, 450);
    }

    void Battle::moveCur(Side where) {
        switch(where) {
        case Side::TO_LEFT:
            curPos -= 1;
            break;
        case Side::TO_RIGHT:
            curPos += 1;
            break;
        case Side::TO_UP:
            curPos -= 2;
            break;
        case Side::TO_DOWN:
            curPos += 2;
            break;
        default:
            break;
        }
    }
} // namespace OpMon
