package jlppc.regimys.core.save;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import jlppc.utils.FileUtils;
import jlppc.utils.Log;

public class Param{
	private String name;
	private String value;
	private String comment;
	public Param(String name, String value){
		this.name = name;
		this.value = value;
		this.comment = "nope";
	}
	public Param(String name, String value, String comment){
		this.name = name;
		this.value = value;
		this.comment = comment;
	}
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
	
	public void writeObject(File toWrite) throws IOException {
		PrintWriter pw = new PrintWriter(toWrite);
		pw.print(toString());
		pw.close();
	}
	
	public Param readObject(File toRead) throws IOException {
		FileReader fr = new FileReader(toRead);
		String toString = FileUtils.readFile(fr);
		String[] values = toString.split("=");
		return new Param(values[0], values[1]);
	}
}
