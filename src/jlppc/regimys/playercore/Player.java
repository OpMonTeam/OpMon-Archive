package jlppc.regimys.playercore;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InvalidClassException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Vector;

import jlppc.regimys.core.save.Parameters;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.items.Item;
import jlppc.utils.HashArray;
import jlppc.utils.WIP;
@WIP
public class Player implements Serializable {
	
	private String name;
	private int dressID;
	

	

	public int[] bag = new int[Item.getItemNumber()];
	private Vector<Pokemon> pc = new Vector<>();
	private Pokemon[] equipe = new Pokemon[6];
	
	public Pokemon[] getEquipe(){
		return equipe;
	}
	
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
				pkmn.setStatus(Status.AUCUN);
				pkmn.confus = false;
				pkmn.amour = false;
				pkmn.malediction = false;
				pkmn.vampigraine = false;
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
	
	public static Player getPlayer(File fle) throws FileNotFoundException, IOException, ClassNotFoundException{
		ObjectInputStream ois = new ObjectInputStream(new BufferedInputStream(new FileInputStream(fle)));
		Player player = null;
		try{
			player = (Player) ois.readObject();
		}catch(InvalidClassException e){
			System.out.println("Votre fichier de sauvegarde n'est plus valide. Merci de relancer le jeu.");
			fle.delete();
			Parameters.removeParam("playerexists");
			Parameters.updateFile();
			System.exit(1);
		}
		ois.close();
		return player;
	}
	
	public static void savePlayer(File file) throws FileNotFoundException, IOException{
		file.delete();
		file.createNewFile();
		ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(file)));
		oos.writeObject(Start.joueur);
		oos.close();
	}
	
	
}
