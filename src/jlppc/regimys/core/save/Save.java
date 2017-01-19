package jlppc.regimys.core.save;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import jlppc.regimys.launch.Start;

public class Save {
	static int[] magicNumber = new byte[]{0xFA,0xCE,0xAF,0xAC,0xE0};
	static int sep = 0x88;
	static int sepC = 0xAA;
	static int sepV = 0xFF;
	public static void save() throws IOException{
		Start.playerSave.delete();
		Start.playerSave.createNewFile();
		BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(Start.playerSave));
		write(magicNumber);
		bos.write(sep);
		int[] toSave = Start.joueur.getSave();
		write(toSave, bos);
		
	}
	
	public static void write(int[] ints, BufferedOutputStream bos){
		for(int inte : ints){
			bos.write(inte);
		}
	}
}
