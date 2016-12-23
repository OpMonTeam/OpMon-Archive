package jlppc.regimys.objects;

import jlppc.regimys.launch.Start;
import jlppc.regimys.util.text.StringKey;
import jlppc.regimys.util.text.StringKey.KeyNotFoundException;
import jlppc.utils.FormattedString;
import jlppc.utils.HashArray;
import jlppc.utils.Useless;
/**
 * La classe de base aux objets de regimys. Tous les objets du jeu ne l'héritent pas, mais elle est plutot pratique.
 * @author Jlppc
 *
 */
public abstract class RegimysObject {
	
	
	
	/**
	 * Typedef of {@linkplain Random.nextInt} of {@linkplain Start.rand}
	 */
	public int rand(int limit){
		return Start.rand.nextInt(limit);
	}
	/**Classe qui ne représente rien. Permet d'utiliser un Null plus facilement, avec moins de NullPointerException<br/>
	 * Useless pour l'instant*/
	@Useless//Pour l'instant
	public static class Null{
		
	}
	/**
	 * L'objet NULL de base.
	 */
	protected final Null NULL = new Null();
	/**
	 * Typedef de {@linkplain FormattedString.outPrintln}
	 */
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
	/**
	 * Typedef of {@linkplain StringKey.getStringKey}
	 */
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
