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

public final class Parameters {
	private static class ParamNotFoundException extends NullPointerException{
		public ParamNotFoundException(String param){
			super(param);
		}
	}
	
	private static final String PARAMETERS_WAY = "params.rsave";
	private static final File SAVE_FILE = new File(PARAMETERS_WAY);
	private static Scanner reader;
	private static Vector<Param> params = new Vector<Param>();
	static{
		
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
	
	
	
	public static Param getParam(String name) throws ParamNotFoundException{
		for(Param actual : params){
			if(actual.getName().equalsIgnoreCase(name)){
				return actual;
			}
		}
		throw new ParamNotFoundException(name);
	}
	
	public static boolean checkParam(String name){
		try{
			getParam(name);
			return true;
		}catch(ParamNotFoundException e){
			return false;
		}
	}
	
	public static void modifyOrAddParam(String name, String value){
		try{
		getParam(name).setValue(value);
		}catch(ParamNotFoundException e){
			addParam(name, value);
		}
	}
	public static void modifyOrAddParam(String name, String value, String comment){
		try{
		getParam(name).setValue(value);
		getParam(name).setComment(comment);
		}catch(ParamNotFoundException e){
			addParam(name, value, comment);
		}
	}
	
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
	
	private static void addParam(String name, String value){
		params.addElement(new Param(name, value));
	}
	private static void addParam(String name, String value, String comment){
		params.addElement(new Param(name, value, comment));
	}
	
	
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
	
	@SuppressWarnings("unchecked")
	public static Vector<Param> getParams(){
		return (Vector<Param>) params.clone();
	}
	
	
}
