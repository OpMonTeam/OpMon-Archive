package jlppc.regimys.objects;

import jlppc.regimys.launch.Start;
import jlppc.regimys.util.text.StringKey;
import jlppc.regimys.util.text.StringKey.KeyNotFoundException;
import jlppc.utils.FormattedString;
import jlppc.utils.HashArray;

public abstract class Typedef {
	
	
	
	/**
	 * Typedef of {@linkplain Random.nextInt} of {@linkplain Start.rand}
	 */
	public int rand(int limit){
		return Start.rand.nextInt(limit);
	}
	/**
	 * Typedef of {@linkplain FormattedString.outPrintln}
	 * @param text
	 * @param args
	 *
	 */
	/**Classe qui ne représente rien. Permet d'utiliser un Null plus facilement, avec moins de NullPointerException*/
	public static class Null{
		
	}

	protected final Null NULL = new Null();
	
	public void fosout(String text, Object...args){
		FormattedString.outPrintln(text, args);
	}
	/**
	 * Typedef of {@linkplain StringKey.outStringKey}
	 * @param key
	 * @param objects
	 */
	public void keyout(StringKey key, Object...objects){
		StringKey.outStringKey(key, objects);
	}
	
	public StringKey key(String key){
		try{
			return StringKey.getStringKey(key);
		}catch(KeyNotFoundException e){
			e.printStackTrace();
			System.exit(1);
		}
		return null;
		
	}
	
	
	
	
}
