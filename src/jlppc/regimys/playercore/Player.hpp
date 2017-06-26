/*
Player.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la d�finition de la classe Player
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_

#include <iostream>
#include <vector>
#include "Equipe.hpp"
#include "../objects/item/Item.hpp"
#include <SFML/Graphics.hpp>
/**
Classe repr�sentant le joueur
*/
class Player {
public:
    Player(std::string name);
    Player();
    Equipe* getEquipe();
    /**Ajoute un item au sac*/
    void addItem(int itemID);
    /**Renvoie le nombre d'exemplaires dans le sac de l'item donn� en param�tres*/
    int checkItem(int itemID);
    /**Enl�ve un exemplaire de l'item dans le sac donn� en param�tres*/
    bool deleteItem(int itemID);
    std::string getName() const {
        return name;
    }
    void setName(std::string const& name){
        this->name = name;
    }
    int getDressID() const {
        return dressID;
    }
    void addOpMonToPC(OpMon *toAdd) {
        pc.push_back(toAdd);
    }
    OpMon* getOp(int ID) const {
        return equipe[ID];
    }
    OpMon* getPcOp(int ID) const {
        return pc[ID];
    }
    /**Soigne tous les Pok�*/
    void healOp();
    /**Essaie d'ajouter un pok�mon a l'equipe. Renvoie false si ce n'est pas possible*/
    bool addOpToEquipe(OpMon *toAdd);

    void save();
    Player(std::ifstream &in, std::string &name);

    void setPlan(int ID){planID = ID;}
    sf::Sprite& getSprite(){return persSprite;}
    /**Translation : pers(onnage) = character
    Sorry if I put it in public, I need it for in Overworld
    DON'T USE!!! Use getSprite instead!
    */
    //DontUse
    sf::Sprite persSprite;
private:
    std::string name;
    const unsigned int dressID;//jusqu'a 8 chiffres (Hexadecimal) (jusqu'a 16^8 soit 4 octets soit un int)
    int bag[ITEM_NUMBER];
    std::vector<OpMon*> pc = std::vector<OpMon*>();
    Equipe equipe = Equipe("temp");

    int planID = 0;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
