package jlppc.regimys.playercore;

import java.util.Vector;

import jlppc.regimys.objects.Pokemon;
import jlppc.utils.WIP;
@WIP
public class Player {
	
	private String name;
	private int dressID;
	private Vector<Pokemon> pc = new Vector<>();
	private Pokemon[] equipe = new Pokemon[6];
	
	public Player(String name) {
		this.name = name;
	}
	
	public String getName(){
		return new String(name);
	}
	
	public int getDressID(){
		return new Integer(dressID).intValue();
	}
	
	public void addPokemonToPC(Pokemon toAdd){
		pc.add(toAdd);
	}
	
	public Pokemon getPoke(int ID){
		return equipe[ID];
	}
	
	/**
	 * Ajoute un pokémon dans l'equipe
	 * @param toAdd
	 * @return true si le pokemon a été ajouté dans l'equipe, false si dans le PC
	 */
	public boolean addPokeToEquipe(Pokemon toAdd){
		if(equipe[5] == null){
			int i = 0;
			for(Pokemon eq : equipe){
				if(eq == null){
					equipe[i] = toAdd;
					return true;
				}
				i++;
			}
			return false;
			
		}else{
			addPokemonToPC(toAdd);
			return false;
		}
		
	}
	
	
}
