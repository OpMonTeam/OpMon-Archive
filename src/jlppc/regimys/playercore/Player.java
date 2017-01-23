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
import java.io.UnsupportedEncodingException;
import java.util.Vector;

import jlppc.regimys.core.save.Parameters;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.items.Item;
import jlppc.utils.HashArray;
import jlppc.utils.WIP;
/**
 * Définit le joueur
 * @author Jlppc
 *
 */
@WIP
public final class Player implements Serializable {
	/**
	 * Le nom du joueur
	 */
	private String name;
	/**
	 * L'ID de dresseur (9 chiffres)
	 */
	@WIP
	private int dressID;
	

	
	/**
	 * Le sac du joueur
	 */
	public int[] bag = new int[Item.getItemNumber()];
	/**
	 * Le PC du joueur
	 */
	private Vector<Pokemon> pc = new Vector<>();
	/**
	 * L'equipe du joueur
	 */
	private Equipe equipe;
	
	public Equipe getEquipe(){
		return equipe;
	}
	/**
	 * Ajoute un item au sac
	 * @param itemID - L'ID de l'item a ajouter
	 */
	@WIP
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
	/**
	 * Verifie si un item est présent dans le sac ou pas
	 * @param itemID - L'ID de l'item a verifier
	 * @return le nombre d'items disponibles dans le sac
	 */
	public int checkItem(int itemID){
		try{
			int toReturn = bag[itemID];
			return toReturn;
		}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
			e.printStackTrace();
			return 0;
		}
	}
	/**
	 * Supprime un exemplaire de l'item dans le sac
	 * @param itemID - L'ID de l'item a supprimer
	 * @return true si l'item a bien été supprimé
	 */
	public boolean deleteItem(int itemID){
		if(bag[itemID] != 0){
			bag[itemID]--;
			return true;
		}else{
			return false;
		}
	}
	/**
	 * 
	 * @param name {@link #name}
	 */
	public Player(String name) {
		this.name = name;
		this.equipe = new Equipe(this.name);
		this.dressID = Start.rand.nextInt(999999999);
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
		return equipe.getPokemon(ID);
	}
	/**
	 * Soigne toute l'equipe, les PP des attaques et tout.
	 */
	public void healPoke(){
		for(Pokemon pkmn : equipe.getEquipe()){
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
	 * @return true si le pokemon a Ã©tÃ© ajoutÃ© dans l'equipe, false si dans le PC
	 */
	public boolean addPokeToEquipe(Pokemon toAdd){
		if(equipe.addPokemon(toAdd)){
			return true;
			
		}else{
			addPokemonToPC(toAdd);
			return false;
		}
		
	}
	/**
	 * Retourne les données du joueur dans le fichier donné
	 * @param fle - Le fichier ou se situe le joueur
	 * @return Le joueur
	 * @throws FileNotFoundException Si le fichier n'est pas trouvé
	 * @throws IOException Heu... En cas de problème.
	 * @throws ClassNotFoundException En cas d'incompatibilité de sauvegarde
	 */
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
	/**
	 * Sauvegarde le joueur dans un fichier
	 * @param file - Le fichier dans lequel sauvegarder.
	 * @throws FileNotFoundException Dafuck. <¨^¨> JE VIENS DE LE CREER DANS LA METHODE LE FICHIER COMMENT TU PEUX NE PAS LE TROUVER???§§§§§§!!!§§§§!!!!
	 * @throws IOException Problème?
	 */
	public static void savePlayer(File file) throws FileNotFoundException, IOException{
		file.delete();
		file.createNewFile();
		ObjectOutputStream oos = new ObjectOutputStream(new BufferedOutputStream(new FileOutputStream(file)));
		oos.writeObject(Start.joueur);
		oos.close();
	}
	
	public int[] getSave() throws UnsupportedEncodingException{
		Vector<Integer> vecToReturn = new Vector<Integer>();
		int i = 0;
		vecToReturn.add(0xAA);
		for(byte bte : name.getBytes("UTF-8")){
			vecToReturn.add((int)bte);
			i++;
		}
		vecToReturn.add(0xFF);
		i++;
		vecToReturn.add(dressID);
		vecToReturn.add(0xAA);
		for(Pokemon pkmn : equipe.getEquipe()){
			for(int ite : pkmn.toSave()){
				vecToReturn.add(ite);
			}
			vecToReturn.add(0xAA);
		}
		vecToReturn.add(pc.size());
		vecToReturn.add(0xAA);
		if(pc.size() > 0){
			for(Pokemon pkmn : pc){
				for(int ite : pkmn.toSave()){
					vecToReturn.add(ite);
				}
				vecToReturn.add(0xAA);
			}
		}
		
		for(int ite : bag){
			vecToReturn.add(ite);
			vecToReturn.add(0xFF);
		}
		Integer[] toReturn = null;
		toReturn = vecToReturn.toArray(toReturn);
		int[] realToReturn = new int[toReturn.length];
		for(int j = 0 ; i < toReturn.length; i++) {
			realToReturn[j] = toReturn[j].intValue();
		}
		
		return realToReturn;
		
		
		
	}
	
	private Player(String name, int dressID){
		this.name = name;
		this.dressID = dressID;
		this.equipe = new Equipe(this.name);
	}
	
	public static Player load(String[] classes){
		String[] infos = classes[0].split(new String(new byte[]{(byte)0xFF}));
		Player toReturn = new Player(infos[0], (int) infos[1].charAt(0));
		return toReturn;
		
	}
	
	
}
