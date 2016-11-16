package jlppc.regimys.playercore;

import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.RegimysObject;

public final class Equipe extends RegimysObject {
	private Pokemon[] equipe = new Pokemon[6];
	
	public Equipe(Pokemon...pokemons){
		int i = 0;
		for(Pokemon pkmn : pokemons){
			equipe[i] = pkmn;
			i++;
			if(i > 5){
				break;
			}
		}
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
		return (i == 5);
	}
	
	
}
