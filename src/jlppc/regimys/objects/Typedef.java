package jlppc.regimys.objects;

import jlppc.regimys.launch.Start;
import jlppc.regimys.util.text.StringKey;
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
		return StringKey.getStringKey(key);
	}
	
	public abstract Object getVar(String name);
	
	/**
	*Liste les variables publiques de la classe dans un HashArray sous la forme suivante :<br/>
	*Soit [] le hashArray, et () un element, séparé par des virgules. Chaque element est présenté comme ceci : (case, tag, element)<br/>
	*Pour un objet HashArray, une variable. Ici on considère la variable <code>public String nom = "Asriel";</code><br/>
	*[(0,nom,"nom"),(1,type, String.class),(2,valeur, "Asriel")]<br/>
	*On considère la variable <code>public float[] fl = {0.8f, 3f, 8.4f};</code><br/>
	*[(0,nom, "fl"),(1,type, "float[]"),(2, valeur, {0.8f, 3f, 8.4f})] (Pour les tableaux, un String est utilisé pour le type au lieu de la classe. Pour les types primitifs, la classe correspondante est utilisée (ex: Integer pour int, Double pour double))<br/>
	*Enfin, on considère la variable <code>public Espece espece;</code><br/>
	*[(0,nom,"espece"),(1,type,Espece.class),(2,valeur,new Null())]
	*Voila!
	*/
	public abstract HashArray[] listVar();
}
