package jlppc.regimys.playercore;

import java.io.Serializable;

import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.RegimysObject;
/**
 * Définit une équipe de pokémon
 * @author Jlppc
 *
 */
public final class Equipe extends RegimysObject implements Serializable{
	/**
	 * L'équipe de pokémon
	 */
	private Pokemon[] equipe = new Pokemon[6];
	/**
	 * Le nom du propriétaire de l'equipe
	 */
	private String nom;
	/**
	 * 
	 * @param nom - {@link #nom}
	 * @param pokemons - {@link equipe}
	 */
	public Equipe(String nom, Pokemon...pokemons){
		this.nom = nom;
		int i = 0;
		for(Pokemon pkmn : pokemons){
			equipe[i] = pkmn;
			i++;
			if(i > 5){
				break;
			}
		}
	}
	
	public String getNom(){
		return nom;
	}
	
	public Pokemon[] getEquipe(){
		return equipe;
	}
	/**
	 * Soigne toute l'equipe
	 */
	public void heal(){
		for(Pokemon pkmn : equipe){
			if(pkmn != null){
				pkmn.heal(pkmn.getStatPV());
				pkmn.confus = false;
				pkmn.setStatus(Status.AUCUN);
			}
			
		}
	}
	/**
	 * Ajoute un pokémon a l'équipe
	 * @param toAdd - Le pokémon a ajouter
	 * @return false si l'equipe n'a plus de place
	 */
	public boolean addPokemon(Pokemon toAdd){
		int i = 0;
		for(Pokemon pkmn : equipe){
			if(pkmn == null){
				equipe[i] = toAdd;
				return true;
			}
			i++;
		}
		return false;
		
	}
	/**
	 * Supprime un pokémon de l'équipe
	 * @param number - le numéro du pokémon a supprimer
	 */
	public void removePokemon(int number){
		int i = 0;
		for(Pokemon pkmn : equipe){
			if(i >= number){
				if(i != 5){
					equipe[i] = equipe[i + 1];
				}else{
					equipe[5] = null;
				}
			}
		}
	}
	
	public Pokemon getPokemon(int id){
		return equipe[id];
	}
	/**
	 * Verifie si l'equipe est K.O
	 * @return true si oui, false si non
	 */
	public boolean isKo(){
		int i = 0;
		for(Pokemon pkmn : equipe){
			if(pkmn == null){
				i++;
			}else if(pkmn.getPV() <= 0){
				i++;
			}
		}
		return (i == 6);
	}
	
	public String toString(){
		String toReturn = new String("[");
		for(Pokemon pkmn : equipe){
			if(pkmn == null){
				toReturn+="Vide,";
			}else{
				toReturn+=(pkmn.getSurnom() + " - PV : "  + pkmn.getPV() + ",");
			}
		}
		toReturn = toReturn.substring(0, toReturn.length() - 1);
		return toReturn + "]";
	}
	/**
	 * 
	 * @return La taille de l'equipe (Et pas celle du tableau /!\)
	 */
	public int getSize() {
		int toReturn = 0;
		for(Pokemon pkmn : equipe){
			if(pkmn != null){
				toReturn++;
			}
		}
		return toReturn;
	}
}
