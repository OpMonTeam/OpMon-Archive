/*
  OpMon.hpp
  Author : Jlppc
  Fichier sous licence GPL-3.0. Le nom Pok�mon appartient a Nintendo(r).
  http://opmon-game.ga
  Contient la d�finition du namepsace CalcCourbs et de la classe OpMon
*/
#ifndef OPMON_HPP
#define OPMON_HPP


#include <iostream>
#include <cmath>
#include "Nature.hpp"
#include "Species.hpp"
#include "src/utils/misc.hpp"
#include "item/Item.hpp"
#include "item/IOpball.hpp"

namespace OpMon{
  namespace Model{

    class Species;

    /**
       Namespace permettant de faire des calculs sur les courbes d'experience. D'ou son nom, j'ai envie de dire...
    */
    namespace CalcCourbs {
      float p(int x);
      int erratic(int n);
      int fluctuating(int n);
      int slow(int n);
      int normal(int n);
      int parabolic(int n);
      int quick(int n);
    }

    class Attack;
    /**
       Classe définissant un pokémon en particulier. Pour voir la classe qui définit une species, voir Species.hpp
    */
    class OpMon {

    protected:


    private:
      std::string nickname;
      int atkIV = Utils::Misc::randU(32);
      int defIV = Utils::Misc::randU(32);
      int atkSpeIV = Utils::Misc::randU(32);
      int defSpeIV = Utils::Misc::randU(32);
      int speIV = Utils::Misc::randU(32);
      int hpIV = Utils::Misc::randU(32);
      int atkEV = 0;
      int defEV = 0;
      int atkSpeEV = 0;
      int defSpeEV = 0;
      int speEV = 0;
      int hpEV = 0;

      //Les statistiques en general
      int statATK;
      int statDEF;
      int statATKSPE;
      int statDEFSPE;
      int statSPE;
      //Les autrees stats.
      int statEVA;
      float statACC;
      int statHP;
      int statLove;
      //Les variables indiquant le niveau de changement.
      int atkChange = 0;
      int defChange = 0;
      int defSpeChange = 0;
      int atkSpeChange = 0;
      int evaChange = 0;
      int accChange = 0;
      int speChange = 0;

      int level;

      Nature nature;

      std::vector<Attack*> attacks;

      const Species *species;
      /**Attention : Cette variable contient les PV actuels du pokémon, la classe statPV contient les PV max*/
      int HP;
      //->ExpectEnum->Status
      Status status = Status::NOTHING;
      //->ExpectEnum->Type
      Type type1;
      //->ExpectEnum->Type
      Type type2;

      int exp;
      /**L'experience a avoir pour le prochain niveau*/
      int toNextLevel;
      float expBoost = 1;

      /**L'item tenu*/
      Item *held;

      int tauxCapture;
    public:
      /**Permet de savoir si un pokémon est un pok�mon initialisé avec un initilialiseur par défaut*/
      bool falsif = true;

      bool confus = false;
      bool peur = false;
      bool amour = false;
      bool vampigraine = false;
      bool malediction = false;

      virtual ~OpMon();

      OpMon(const std::string &nickname, const Species &species, int level, const std::vector<Attack*> &attacks, Nature nature);
  
      /**
	 Merci d'utiliser ce constructeur dans le cadre du chargement et UNIQUEMENT dans ce cas, sinon cela pourrait
	 conduire a des bugs. Explication : Ce constructeur est concu pour marcher dans un shema bien particulier.
	 Si le shema est incorrect, cela génèrera des erreurs de segmentation ou des données corrompues.
      */
      OpMon(std::ifstream &in);
      /**Renvoie true si le pokémon est bien capturé.*/
      bool captured(I_Opball const &Opball);
      /**Permet de changer une stat, les possibilités d'entrées dans le paramètre stat sont "ATK" "DEF" "ATKSPE" "DEFSPE" "SPE" "PV"*/
      void setStat(Stats stat, int newStat);
      /**Methode appellée lors d'une montée de niveau*/
      void levelUp();
      bool isHoldingItem() const {
        return (held == nullptr);
      }
      /**Methode appelée lors d'une victoire*/
      int win(OpMon const &vaincu);
      /**Recalcule les stats*/
      void calcStats();
      /**Methode appelée lors de l'utilisation d'un item. Renvoie true si l'item est a supprimer*/
      bool itemUsed(Item *used);
      Item *hold(Item *item);//Cette est un setteur, en gros.
      /**Methode appelée lors d'un échange*/
      void traded();
      /**SPOILERSµµµ*/
      void toolEvTrade();//SPOILERS!
      /**Methode appelée lors de l'évolution*/
      void evolve();
      /**Permet de completement changer le pokémon*/
      void setStats(int stats[], Attack *attacks[], const Species &species, Type types[]);
      /**Fait perdre des pv*/
      void attacked(int hpPerdus);
      /**Les methode suivantes modifient les stats en fonction des niveaux. Cela ne modifie pas directement la stat*/
      bool changeATK(int power);
      bool changeACC(int power);
      bool changeEVA(int power);
      bool changeDEF(int power);
      bool changeATKSPE(int power);
      bool changeDEFSPE(int power);
      bool changeSPE(int power);
      Status getStatus() {
        return status;
      }
      /**Change le status*/
      bool setStatus(Status status);
      int getStatHP() const {
        return statHP;
      }
      int getStatLove() const {
        return statLove;
      }
      int getHP() const {
        return HP;
      }
      std::string getNickname() {
        return nickname;
      }
      /**Soigne le pokémon*/
      void heal(int HP);
      int getLevel() const {
        return level;
      }
      std::vector<Attack*> getAttacks() {
        return attacks;
      }
      int getStatEVA() const {
        return statEVA;
      }
      int getStatACC() const {
        return statACC;
      }
      void getEvs(OpMon const &vaincu);
      Type getType1() const {
        return type1;
      }
      Type getType2() const {
        return type2;
      }
      void setType1(Type type);
      void setType2(Type type);
      int getStatATK() const {
        return statATK;
      }
      int getStatATKSPE() const {
        return statATKSPE;
      }
      int getStatDEF() const {
        return statDEF;
      }
      int getStatDEFSPE() const {
        return statDEFSPE;
      }
      int getStatSPE() const{
        return statSPE;
      }
      const Species &getSpecies() const {
        return *species;
      }
      //Attention! Les opérateurs == et != ne comparent pas deux pok�mons! Ils comparent si les pok�mons sont falsifs ou non (voir falsif)
      bool operator==(OpMon const &a) {
        return (falsif == a.falsif);
      }
      bool operator!=(OpMon const &a) {
        return !(falsif == a.falsif);
      }
      Item *itemHeld() const {
        return held;   //C'est un getteur. Y'a pas get mais je m'en fous. C'est un getteur.
      }
      std::string save();
    };

  }
}

#endif // OpMon_HPP
