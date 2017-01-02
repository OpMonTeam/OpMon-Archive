package jlppc.regimys.util.text;


import java.util.Vector;



import jlppc.utils.FormattedString;

/**
 * Utilitaire permettant de faire des clées de chaines de caractéres, permettant de les réutiliser plus facilement par la suite.
 * @author Jlppc
 *
 */
public final class StringKey {
	static{
		//Load ici les stringKeys du fichier quand le programme sera en gui
	}
	/**
	 * Liste des clées
	 */
	public static Vector<StringKey> keys = new Vector<>();
	
	/**
	 * La clée
	 */
	protected String key;
	/**
	 * La chaine de caractére associée a la clée
	 */
	protected String string;
	/**
	 * 
	 * @param key {@link #key}
	 * @param str {@link #str}
	 */
	protected StringKey(String key, String str){
		this.key = key;
		string = str;
	}
	
	public String getString(Object...objects){
		return new FormattedString(string, objects).toString();
	}
	
	public FormattedString getFormattedString(Object...objects){
		return new FormattedString(string, objects);
	}
	
	public String getKey(){
		return key;
	}
	
	public static String getString(String key, Object...objects){
		StringKey searched = null;
		for(StringKey actual : keys){
			if(actual.getKey().equalsIgnoreCase(key)){
				searched = actual;
				break;
			}
		}
		return (searched != null) ? searched.getString(objects) : null;
		
	}
	/**
	 * Exception se lancant lors d'une recherche de clée qui n'a pas aboutie.
	 * @author Jlppc
	 *
	 */
	public static class KeyNotFoundException extends Exception{
		public KeyNotFoundException(String str){
			super(str);
		}
		public KeyNotFoundException(){
			
		}
	}

	public static StringKey getStringKey(String key) throws KeyNotFoundException{
		StringKey searched = null;
		for(StringKey actual : keys){
			if(actual.getKey().equalsIgnoreCase(key)){
				searched = actual;
				break;
			}
		}
		if(searched == null){
			throw new KeyNotFoundException(key);
		}
		return searched;
		
	}
	/**
	 * Affiche une chaine de caractére StringKey dans la sortie principale du programme.
	 * @param key - La clée
	 * @param objects - Les objets qui remplissent les %o
	 */
	public static void outStringKey(StringKey key, Object...objects){
		try{
			System.out.println(key.getString(objects));
		}catch(Exception e){
			System.out.println("Erreur.");
			e.printStackTrace();
		}
		
	}
	/**
	 * Initialise les clées.
	 */
	public static void initialisateKeys(){
		//Items
		keys.add(new StringKey("fight.item.used", "%o utilise un(e) %o!"));
		//Stats
		keys.add(new StringKey("effects.stats.atk.low", "L'attaque de %o baisse!"));
		keys.add(new StringKey("effects.stats.atk.lowtwo", "L'attaque de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.atk.cantlow", "L'attaque de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.atk.add", "L'attaque de %o augmente!"));
		keys.add(new StringKey("effects.stats.atk.addtwo", "L'attaque de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.atk.cantadd", "L'attaque de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.def.low", "La défense de %o baisse!"));
		keys.add(new StringKey("effects.stats.def.lowtwo", "La défense de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.def.cantlow", "La défense de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.def.add", "La défense de %o augmente!"));
		keys.add(new StringKey("effects.stats.def.addtwo", "La défense de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.def.cantadd", "La défense de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.atkspe.low", "L'attaque spéciale de %o baisse!"));
		keys.add(new StringKey("effects.stats.atkspe.lowtwo", "L'attaque spéciale de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.atkspe.cantlow", "L'attaque spéciale de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.atkspe.add", "L'attaque spéciale de %o augmente!"));
		keys.add(new StringKey("effects.stats.atkspe.addtwo", "L'attaque spéciale de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.atkspe.cantadd", "L'attaque spéciale de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.defspe.low", "La défense spéciale de %o baisse!"));
		keys.add(new StringKey("effects.stats.defspe.lowtwo", "La défense spéciale de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.defspe.cantlow", "La défense spéciale de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.defspe.add", "La défense spéciale de %o augmente!"));
		keys.add(new StringKey("effects.stats.defspe.addtwo", "La défense spéciale de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.defspe.cantadd", "La défense spéciale de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.vit.low", "La vitesse de %o baisse!"));
		keys.add(new StringKey("effects.stats.vit.lowtwo", "La vitesse de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.vit.cantlow", "La vitesse de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.vit.add", "La vitesse de %o augmente!"));
		keys.add(new StringKey("effects.stats.vit.addtwo", "La vitesse de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.vit.cantadd", "La vitesse de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.esq.low", "L'esquive de %o baisse!"));
		keys.add(new StringKey("effects.stats.esq.lowtwo", "L'esquive de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.esq.cantlow", "L'esquive de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.esq.add", "L'esquive de %o augmente!"));
		keys.add(new StringKey("effects.stats.esq.addtwo", "L'esquive de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.esq.cantadd", "L'esquive de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.pre.low", "La précision de %o baisse!"));
		keys.add(new StringKey("effects.stats.pre.lowtwo", "La précision de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.pre.cantlow", "La précision de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.pre.add", "La précision de %o augmente!"));
		keys.add(new StringKey("effects.stats.pre.addtwo", "La précision de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.pre.cantadd", "La précision de %o ne peut plus augmenter!"));
		//status
		keys.add(new StringKey("effects.status.fail", "%o a déjà un status!"));
		keys.add(new StringKey("effects.status.para", "%o est paralysé!"));
		keys.add(new StringKey("effects.status.poison", "%o est empoisonné!"));
		keys.add(new StringKey("effects.status.brulure", "%o est brûlé!"));
		keys.add(new StringKey("effects.status.gel", "%o est gelé!"));
		keys.add(new StringKey("effects.status.sommeil", "%o s'endort profondémement."));
		//sous-status
		keys.add(new StringKey("effects.status.peur", "%o est apeuré!"));
		keys.add(new StringKey("effects.status.confus", "%o tombe dans la confusion!"));
		keys.add(new StringKey("effects.status.love", "%o tombe amoureux de %o!"));
		//effets
		keys.add(new StringKey("effects.stats.pv.ctrcoup", "%o prend le contrecoup et perd %o pv!"));
		//attaque
		keys.add(new StringKey("attack.pkmn.attacked", "%o a perdu %o pv. Il lui reste %o pv."));
		keys.add(new StringKey("attack.pkmn.absorb", "La vie %o est absorbée! %o gagne %o pv!"));
		keys.add(new StringKey("attack.fail", "Mais cela échoue!"));
		//types
		keys.add(new StringKey("attack.types.tpe", "Ce n'est vraiment pas trés efficace..."));
		keys.add(new StringKey("attack.types.in", "C'est inefficace!"));
		keys.add(new StringKey("attack.types.te", "C'est trés efficace!"));
		keys.add(new StringKey("attack.types.se", "C'est super efficace!"));
		//Heal
		keys.add(new StringKey("items.heal", "%o récupére des pv!"));
		keys.add(new StringKey("items.status.heal", "%o n'a plus de problémes de status!"));
		keys.add(new StringKey("status.poison.heal", "%o n'est plus empoisonné!"));
		keys.add(new StringKey("status.para.heal", "%o n'est plus paralysé!"));
		keys.add(new StringKey("status.gel.heal", "%o n'est plus gelé!"));
		keys.add(new StringKey("status.sommeil.heal", "%o se reveille!"));
		keys.add(new StringKey("status.brulure.heal", "%o n'est plus brulé!"));
	}
 
	
}
