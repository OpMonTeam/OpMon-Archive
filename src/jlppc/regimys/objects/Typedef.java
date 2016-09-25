package jlppc.regimys.objects;

import jlppc.regimys.launch.Start;
import jlppc.regimys.util.text.StringKey;
import jlppc.utils.FormattedString;

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
}
