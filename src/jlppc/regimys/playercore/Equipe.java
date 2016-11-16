package jlppc.regimys.playercore;

import java.io.Serializable;

import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.RegimysObject;

public final class Equipe extends RegimysObject implements Serializable{
	private Pokemon[] equipe = new Pokemon[6];
	private String nom;
	
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
	
	public void heal(){
		for(Pokemon pkmn : equipe){
			if(pkmn != null){
				pkmn.heal(pkmn.getStatPV());
				pkmn.confus = false;
				pkmn.setStatus(Status.AUCUN);
			}
			
		}
	}
	
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
				toReturn+="null,";
			}else{
				toReturn+=(pkmn.getSurnom() + " - "  + pkmn.getPV() + ",");
			}
		}
		return toReturn;
	}

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
