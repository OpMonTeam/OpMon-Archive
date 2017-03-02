/*
Equipe.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la d�finition de la classe Equipe
*/
#ifndef SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_
#define SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_

#include <iostream>
#include "../objects/OpMon.hpp"
/**
Classe permettant de contenir l'equipe d'un joueur ou d'un dresseur.
*/
class Equipe {
	public:
		Equipe(std::string nom);
		std::string getNom() const {return nom;}
		OpMon *getEquipe()  {return equipe;}
		/**Soigne toute l'equipe*/
		void heal();
		/**
		Ajoute un pok�mon a l'equipe. Renvoie false si l'equipe est pleine
		*/
		bool addOpMon(OpMon toAdd);
		/**Suprime de numberi�me pok�mon dans l'�quipe*/
		void removeOp(int number);
		/**
		Operateur permettant de recuperer le Pok�mon a la place donn�e en parametre
		*/
		OpMon operator[](int id) const;
		/**Renvoie true si l'�quipe est K.O*/
		bool isKo() const ;
		int getSize() const ;
		//Op�rateurs non pratiques, mais je les met quand meme.Ils permettent de raccourcir l'utilisation de quelques methodes, mais ne sont surement pas conformes a leur utilisation de base.
		void operator+=(OpMon const &pkmn) {addOpMon(pkmn);}
		void operator-=(int id) {removeOp(id);}
		/**Opmon vide*/
		static OpMon PNULL;

	private:
		//->Useless
		int nbreOfOp = 6;
		OpMon equipe[6] = {PNULL, PNULL, PNULL, PNULL, PNULL, PNULL};
		std::string nom;
};

#endif /* SRCCPP_JLPPC_REGIMYS_PLAYERCORE_EQUIPE_HPP_ */
