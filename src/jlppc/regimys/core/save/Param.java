package jlppc.regimys.core.save;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import jlppc.utils.FileUtils;
import jlppc.utils.Log;
/**
 * Classe permetant de définir un paramètre a utiliser dans Parameters
 * @author Jlppc
 */
public final class Param{
	/**Le nom du paramètre*/
	private String name;
	/**La valeur du paramètre*/
	private String value;
	/**Le commentaire du paramètre*/
	private String comment;
	/**Construit un paramètre sans commentaire*/
	public Param(String name, String value){
		this.name = name;
		this.value = value;
		this.comment = "nope";
	}
	/**Construit un paramètre avec commentaire*/
	public Param(String name, String value, String comment){
		this.name = name;
		this.value = value;
		this.comment = comment;
	}
	/**Renvoie la ligne a écrire dans un fichier*/
	public String toString(){
		return (comment.equals("nope") ? "" : ("#" + comment + Log.saut)) + name + "=" + value;
	}
	
	public void setValue(String newValue){
		value = newValue;
	}
	public String getName(){
		return name;
	}
	public String getValue(){
		return value;
	}
	public void setComment(String newComment){
		comment = newComment;
	}
	/**Permet d'inscrire l'objet dans le fichier donné en paramètre
	 * @param toWrite : Le fichier dans lequel écrire*/
	public void writeObject(File toWrite) throws IOException {
		PrintWriter pw = new PrintWriter(toWrite);
		pw.print(toString());
		pw.close();
	}
	/**Permet de lire l'objet dans le fichier donné en paramètre<br/>
	 * Si le fichier ne contient pas de paramètre, un ArrayIndexOutOfBoundsException sera lancée.
	 * @param toRead : Le fichier dans lequel lire.
	 */
	public Param readObject(File toRead) throws IOException {
		FileReader fr = new FileReader(toRead);
		String toString = FileUtils.readFile(fr);
		String[] values = toString.split("=");
		return new Param(values[0], values[1]);
	}
}
