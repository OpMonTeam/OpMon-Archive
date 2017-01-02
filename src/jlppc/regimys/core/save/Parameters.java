package jlppc.regimys.core.save;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Vector;


import jlppc.utils.Log;
import jlppc.utils.Static;
import jlppc.utils.Useless;
/**
 * Classe permettant de gerer une liste de Paramètre dans un fichier
 * @author jlppc
 */
@Static
public final class Parameters {
	/**
	 * L'exception lancée si un paramètre cherché n'est pas trouvé
	 * @author Jlppc
	 */
	@Static
	private static class ParamNotFoundException extends NullPointerException{
		public ParamNotFoundException(String param){
			super(param);
		}
	}
	/**Le chemin (ou nom) du fichier de param�tre<br/>
	 * Le nom est en majuscules du fait que cette variable �tait anciennement statique*/
	@Useless//Avant elle �tait utile...
	private static String PARAMETERS_WAY = "params.rsave";
	/**Le fichier de param�tre<br/>
	 * Le nom est en majuscules du fait que cette variable �tait anciennement statique*/
	private static File SAVE_FILE = new File(PARAMETERS_WAY);
	/**Un scanner*/
	private static Scanner reader;
	/**Vector contenant tous les paramètres*/
	private static Vector<Param> params = new Vector<Param>();
	/*Charge les paramètres ou initialise le fichier si il n'existe pas.*/
	static{
		
		
		
		
	}
	
	public static void paramInit(File paramsFile){
		PARAMETERS_WAY = paramsFile.getAbsolutePath();
		SAVE_FILE = paramsFile.getAbsoluteFile();
		if(SAVE_FILE.exists() == false){
			try {
				SAVE_FILE.createNewFile();
				PrintWriter pw = new PrintWriter(SAVE_FILE);
				pw.println("#Fichier sauvegarde de Regimys. MERCI DE NE PAS Y TOUCHER... S.V.P... *ton suppliant*");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		String scanned;
		Scanner pw = null;
		try {
			pw = new Scanner(new FileReader(SAVE_FILE));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		if(pw != null){
			try{
			while((scanned = pw.nextLine()) != null){
				if(!scanned.startsWith("#")){
					String[] toSave = scanned.split("=");
					params.addElement(new Param(toSave[0], toSave[1]));
				}
				
			}
			}catch(Exception e){
				if(!(e instanceof NoSuchElementException)){
					e.printStackTrace();
				}
				
			}
			pw.reset();
			pw.close();
		}
	}
	
	
	/**Permet de récuperer un paramètre
	 * @param name : Le nom du paramètre
	 */
	public static Param getParam(String name) throws ParamNotFoundException{
		for(Param actual : params){
			if(actual.getName().equalsIgnoreCase(name)){
				return actual;
			}
		}
		throw new ParamNotFoundException(name);
	}
	/**
	 * Permet de verifier si un paramètre existe
	 * @param name : Le nom du paramètre
	 */
	public static boolean checkParam(String name){
		try{
			getParam(name);
			return true;
		}catch(ParamNotFoundException e){
			return false;
		}
	}
	/**
	 * Permet de modifier un paramètre, ou si il n'existe pas, de le creer
	 * @param name : Le nom du paramètre
	 * @param value : La nouvelle valeur du paramètre
	 */
	public static void modifyOrAddParam(String name, String value){
		try{
		getParam(name).setValue(value);
		}catch(ParamNotFoundException e){
			addParam(name, value);
		}
	}
	/**
	 * Permet de modifier un paramètre, ou si il n'existe pas, de le creer, le tout avec un commentaire
	 * @param name : Le nom du paramètre
	 * @param value : La nouvelle valeur du paramètre
	 * @param comment : Le commentaire du paramètre
	 */
	public static void modifyOrAddParam(String name, String value, String comment){
		try{
		getParam(name).setValue(value);
		getParam(name).setComment(comment);
		}catch(ParamNotFoundException e){
			addParam(name, value, comment);
		}
	}
	/**Permet de noter les changements de paramètres dans le fichier de paramètre. Si cette methode n'est pas appellée et que des modification ont été éffctuées, elles seront effacées a la fin du programme.
	*/
	public static void updateFile() throws IOException{
		SAVE_FILE.delete();
		SAVE_FILE.createNewFile();
		PrintWriter pw = new PrintWriter(SAVE_FILE);
		pw.println("#Fichier sauvegarde de Regimys. MERCI DE NE PAS Y TOUCHER... S.V.P... *ton suppliant*");
		for(Param actual : params){
			
			pw.println(actual.toString());
			
		}
		pw.close();
	}
	/**Permet d'ajouter un paramètre*/
	private static void addParam(String name, String value){
		params.addElement(new Param(name, value));
	}
	/**Permet d'ajouter un paramètre avec un commentaire*/
	private static void addParam(String name, String value, String comment){
		params.addElement(new Param(name, value, comment));
	}
	
	/**Supprime un paramètre*/
	public static Param removeParam(String name){
		int i = 0;
		for(Param actual : params){
			
			if(actual.getName().equalsIgnoreCase(name)){
				return params.remove(i);
			}
			i++;
		}
		throw new ParamNotFoundException(name);
	}
	/**Permet de donner touts les paramètres*/
	@SuppressWarnings("unchecked")
	public static Vector<Param> getParams(){
		return (Vector<Param>) params.clone();
	}
	
	
}
