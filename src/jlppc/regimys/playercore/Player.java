package jlppc.regimys.playercore;

import java.util.Vector;

import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.items.Item;
import jlppc.utils.HashArray;
import jlppc.utils.WIP;
@WIP
public class Player {
	
	private String name;
	private int dressID;
	

	

	public int[] bag = new int[Item.getItemNumber()];
	private Vector<Pokemon> pc = new Vector<>();
	private Pokemon[] equipe = new Pokemon[6];
	
	public void addItem(int itemID){
		
		switch(Item.getItem(itemID).getBagCat()){
		case BAIES:
			bag[itemID]++;
			break;
		case CTS:
			bag[itemID]++;
			break;
		case OBJETS:
			bag[itemID]++;
			break;
		case RARES:
			bag[itemID]++;
			break;
		case SOIN:
			bag[itemID]++;
			break;
		}
	}
	public int checkItem(int itemID){
		try{
			int toReturn = bag[itemID];
			return toReturn;
		}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
			e.printStackTrace();
			return 0;
		}
	}
	public boolean deleteItem(int itemID){
		if(bag[itemID] != 0){
			bag[itemID]--;
			return true;
		}else{
			return false;
		}
	}
	
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
	public void healPoke(){
		for(Pokemon pkmn : equipe){
			try{
				pkmn.heal(pkmn.getStatPV());
				for(Attaque atk : pkmn.getAttaques()){
					try{
						atk.healPP();
					}catch(NullPointerException e){
						
					}
					
				}
			}catch(NullPointerException e){
				
			}
			
		}
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
