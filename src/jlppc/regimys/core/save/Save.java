package jlppc.regimys.core.save;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import jlppc.regimys.launch.Start;

public class Save {
	static byte[] magicNumber = new byte[]{i(0xFA),i(0xCE),i(0xAF),i(0xAC),i(0xE0)};
	static byte sep = i(0xE1);
	public static void save() throws IOException{
		Start.playerSave.delete();
		Start.playerSave.createNewFile();
		BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(Start.playerSave));
		for(int c : magicNumber){
			bos.write(c);
		}
	}
	
	public static byte i(int i){
		return (byte) i;
	}
	
}
