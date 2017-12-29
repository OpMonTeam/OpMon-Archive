/*
Player.hpp
Author : Jlppc
Fichier sous licence GPL-3.0
http://opmon-game.ga
Contient la définition de la classe Player
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_

namespace OpMon{
  namespace Model{

    class OpMon;
    class OpTeam;

    /**
       Classe représentant le joueur
    */
    class Player {
    public:
      Player(sf::String const& name);
      Player();
      OpTeam *getOpTeam();
      /**Ajoute un item au sac*/
      void addItem(int itemID);
      /**Renvoie le nombre d'exemplaires dans le sac de l'item donné en paramètres*/
      int checkItem(int itemID);
      /**Enlève un exemplaire de l'item dans le sac donné en paramètres*/
      bool deleteItem(int itemID);
      sf::String getName() const {
        return name;
      }
      const sf::String* getNameP() const {
        return &name;
      }
      void setName(sf::String const &name) {
        this->name = name;
      }
      int getTrainerID() const {
        return trainerID;
      }
      void addOpMonToPC(OpMon *toAdd) {
        pc.push_back(toAdd);
      }
      OpMon *getOp(int ID) const {
        return opteam[ID];
      }
      OpMon *getPcOp(int ID) const {
        return pc[ID];
      }
      /**Soigne tous les Poké*/
      void healOp();
      /**Essaie d'ajouter un pokémon a l'opteam. Renvoie false si ce n'est pas possible*/
      bool addOpToOpTeam(OpMon *toAdd);

      void save();
      Player(std::ifstream &in, std::string &name);
      
      bool isKo(){
	return opteam.isKo();
      }

      Position& getPosition(){
	return position;
      }

      std::string getMapId(){
	return mapID;
      }

      void setMapID(std::string mapID){
	this->mapID = mapID;
      }

      void tp(std::string mapToTp, sf::Vector2i position);
            
    private:
      sf::String name;
      const unsigned int trainerID;//jusqu'a 8 chiffres (Hexadecimal) (jusqu'a 16^8 soit 4 octets soit un int)
      int bag[ITEM_NUMBER];
      std::vector<OpMon *> pc = std::vector<OpMon *>();
      OpTeam opteam;
      std::string mapID = "Player's room";

      Position position;
      
    };
  }
}

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_PLAYER_HPP_ */
