package jlppc.regimys.core.save;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import jlppc.regimys.launch.Start;

public class Save {
	static byte[] magicNumber = new byte[]{0xFA,0xCE,0xAF,0xAC,0xE0};
	static byte sep = 0x88;
	static byte sepC = 0xAA;
	static byte sepV = 0xFF;
	public static void save() throws IOException{
		Start.playerSave.delete();
		Start.playerSave.createNewFile();
		BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(Start.playerSave));
		write(magicNumber);
		bos.write(sep);
		int[] toSave = Start.joueur.getSave();
		write(toSave, bos);
		bos.write(0x88);
		Vector<Byte> hashCodeB = new Vector<Byte>();
	
		for(int ite : toSave){
			hashCodeB.add((byte) ite);
		}
		String hashCode = new String(hashCodeB.toArray());
		bos.write(hashCode.hashCode());
		bos.close();
		
	}
	
	public static Player load(){
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream(Start.playerSave));
		String totalSave = FileUtils.read(bis);
		//Verification de la validité du fichier
		String[] totalSaveA = totalSave.split(new String(new byte[]{sepC}));
		String mn = totalSaveA[0].split(new String(new byte[]{sep}))[0];
		if(!mn.equals(new String(magicNumber))){
			//Lancer sauvegarde corrompue
		}
		int hc = (int) totalSaveA[totalSaveA.length - 1].split(new String(new byte[]{sep}))[1].charAt(0);
		if(!(hc == totalSave.hashCode())){
			//Lancer sauvegarde modifiée
		}
		//Loading
		String[] playerSave = totalSave.split(new String(new byte[]{sep}));
		String[] classes = playerSave[1].split(new String(new byte[]{sepC}));
		Player.load(classes);
		
	}
	
	public static void write(int[] ints, BufferedOutputStream bos){
		for(int inte : ints){
			bos.write(inte);
		}
	}
}
