package jlppc.regimys.core.save;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Vector;

import jlppc.regimys.launch.Start;
import jlppc.regimys.playercore.Player;
import jlppc.utils.FileUtils;

public class Save {
	static byte[] magicNumber = new byte[]{(byte) 0xFA,(byte) 0xCE,(byte) 0xAF,(byte) 0xAC,(byte) 0xE0};
	static byte sep = (byte) 0x88;
	static byte sepC = (byte) 0xAA;
	static byte sepV = (byte) 0xFF;
	public static void save() throws IOException{
		Start.playerSave.delete();
		Start.playerSave.createNewFile();
		BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(Start.playerSave));
		bos.write(magicNumber);
		bos.write(sep);
		int[] toSave = Start.joueur.getSave();
		write(toSave, bos);
		bos.write(0x88);
		Vector<Byte> hashCodeB = new Vector<Byte>();
	
		for(int ite : toSave){
			hashCodeB.add((byte) ite);
		}
		Byte[] bte = (Byte[]) hashCodeB.toArray();
		byte[] bteTab = new byte[bte.length];
		int i = 0;
		for(Byte yolo : bte) {//J'avais plus d'idée
			bteTab[i] = yolo.byteValue();
			i++;
		}
		String hashCode = new String(bteTab);
		bos.write(hashCode.hashCode());
		bos.close();
		
	}
	
	public static Player load() throws IOException, InstantiationException, IllegalAccessException, ClassNotFoundException{
		
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream(Start.playerSave));
		String totalSave = FileUtils.readFile(bis);
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
		Player toReturn = Player.load(classes);
		return toReturn;
		
	}
	
	public static void write(int[] ints, BufferedOutputStream bos) throws IOException{
		for(int inte : ints){
			bos.write(inte);
		}
	}
}
