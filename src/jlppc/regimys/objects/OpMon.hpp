/*
OpMon.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0. Le nom Pok�mon appartient a Nintendo(r).
http://regimys.tk
Contient la d�finition du namepsace CalcCourbes et de la classe OpMon
*/
#ifndef OPMON_HPP
#define OPMON_HPP


#include <iostream>
#include <cmath>
#include "../enums/Caractere.hpp"
#include "Espece.hpp"
#include "../../utils/Utils.hpp"
#include "item/Item.hpp"
#include "item/IOpball.hpp"

/**
Namespace permettant de faire des calculs sur les courbes d'experience. D'ou son nom, j'ai envie de dire...
*/
namespace CalcCourbes {
	float p(int x);
	int erratique(int n);
	int fluctuante(int n);
	int lente(int n);
	int moyenne(int n);
	int parabolique(int n);
	int rapide(int n);
};

class Attaque;
/**
Classe définissant un pokémon en particulier. Pour voir la classe qui définit une espece, voir Espece.hpp
*/
class OpMon {

	protected:


	private:
		std::string surnom;
		int atkIV = Utils::randU(32);
		int defIV = Utils::randU(32);
		int atkSpeIV = Utils::randU(32);
		int defSpeIV = Utils::randU(32);
		int vitIV = Utils::randU(32);
		int pvIV = Utils::randU(32);
		int atkEV = 0;
		int defEV = 0;
		int atkSpeEV = 0;
		int defSpeEV = 0;
		int vitEV = 0;
		int pvEV = 0;

		//Les statistiques en general
		int statATK;
		int statDEF;
		int statATKSPE;
		int statDEFSPE;
		int statVIT;
		//Les autrees stats.
		int statESQ;
		float statPRE;
		int statPV;
		int statLove;
		//Les variables indiquant le niveau de changement.
		int atkChange = 0;
		int defChange = 0;
		int defSpeChange = 0;
		int atkSpeChange = 0;
		int esqChange = 0;
		int preChange = 0;
		int vitChange = 0;

		int level;

		CaractereClass caractere;

		Attaque *attaques[4];

		Espece *espece;
        /**Attention : Cette variable contient les PV actuels du pokémon, la classe statPV contient les PV max*/
		int PV;
        //->WaitEnum->Status
		int status = Status::AUCUN;
        //->WaitEnum->Type
		int type1;
        //->WaitEnum->Type
		int type2;

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
		//->DontUse
		OpMon() {};
		OpMon(std::string surnom, Espece *espece, int level, Attaque *attaques[], CaractereClass caractere);
        /**Renvoie true si le pokémon est bien capturé.*/
		bool captured(I_Opball const &Opball);
		/**Permet de changer une stat, les possibilités d'entrées dans le paramètre stat sont "ATK" "DEF" "ATKSPE" "DEFSPE" "VIT" "PV"*/
		void setStat(std::string const &stat, int newStat);
		/**Methode appellée lors d'une montée de niveau*/
		void levelUp();
		bool isHoldingItem() const {return (held == NULL);}
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
		void setStats(int stats[], Attaque *attacks[], Espece *espece, int types[]);
		/**Fait perdre des pv*/
		void attacked(int pvPerdus);
		/**Les methode suivantes modifient les stats en fonction des niveaux. Cela ne modifie pas directement la stat*/
		bool changeATK(int power);
		bool changePRE(int power);
		bool changeESQ(int power);
		bool changeDEF(int power);
		bool changeATKSPE(int power);
		bool changeDEFSPE(int power);
		bool changeVIT(int power);
		/**Change le status*/
		bool setStatus(int status);
		int getStatPV() const {return statPV;}
		int getStatLove() const {return statLove;}
		int getPV() const {return PV;}
		/**Soigne le pokémon*/
		void heal(int PV);
		bool getLevel() const {return level;}
		Attaque **getAttaques() {return attaques;}
		int getStatESQ() const {return statESQ;}
		int getStatPRE() const {return statPRE;}
		void getEvs(OpMon const &vaincu);
		int getType1() const {return type1;}
		int getType2() const {return type2;}
		int getStatATK() const {return statATK;}
		int getStatATKSPE() const {return statATKSPE;}
		int getStatDEF() const {return statDEF;}
		int getStatDEFSPE() const {return statDEFSPE;}
		Espece *getEspece() const {return espece;}
		//Attention! Les opérateurs == et != ne comparent pas deux pok�mons! Ils comparent si les pok�mons sont falsifs ou non (voir falsif)
		bool operator==(OpMon const &a) {return (falsif == a.falsif);}
		bool operator!=(OpMon const &a) {return !(falsif == a.falsif);}
		Item *itemHeld() const {return held;} //C'est un getteur. Y'a pas get mais je m'en fous. C'est un getteur.
};



#endif // OpMon_HPP
