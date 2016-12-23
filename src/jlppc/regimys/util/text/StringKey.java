package jlppc.regimys.util.text;


import java.util.Vector;



import jlppc.utils.FormattedString;

/**
 * Utilitaire permettant de faire des cl�es de chaines de caract�res, permettant de les r�utiliser plus facilement par la suite.
 * @author Jlppc
 *
 */
public final class StringKey {
	/**
	 * Liste des cl�es
	 */
	public static Vector<StringKey> keys = new Vector<>();
	
	/**
	 * La cl�e
	 */
	protected String key;
	/**
	 * La chaine de caract�re associ�e a la cl�e
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
	 * Exception se lancant lors d'une recherche de cl�e qui n'a pas aboutie.
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
	 * Affiche une chaine de caract�re StringKey dans la sortie principale du programme.
	 * @param key - La cl�e
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
	 * Initialise les cl�es.
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
		
		keys.add(new StringKey("effects.stats.def.low", "La d�fense de %o baisse!"));
		keys.add(new StringKey("effects.stats.def.lowtwo", "La d�fense de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.def.cantlow", "La d�fense de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.def.add", "La d�fense de %o augmente!"));
		keys.add(new StringKey("effects.stats.def.addtwo", "La d�fense de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.def.cantadd", "La d�fense de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.atkspe.low", "L'attaque sp�ciale de %o baisse!"));
		keys.add(new StringKey("effects.stats.atkspe.lowtwo", "L'attaque sp�ciale de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.atkspe.cantlow", "L'attaque sp�ciale de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.atkspe.add", "L'attaque sp�ciale de %o augmente!"));
		keys.add(new StringKey("effects.stats.atkspe.addtwo", "L'attaque sp�ciale de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.atkspe.cantadd", "L'attaque sp�ciale de %o ne peut plus augmenter!"));
		
		keys.add(new StringKey("effects.stats.defspe.low", "La d�fense sp�ciale de %o baisse!"));
		keys.add(new StringKey("effects.stats.defspe.lowtwo", "La d�fense sp�ciale de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.defspe.cantlow", "La d�fense sp�ciale de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.defspe.add", "La d�fense sp�ciale de %o augmente!"));
		keys.add(new StringKey("effects.stats.defspe.addtwo", "La d�fense sp�ciale de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.defspe.cantadd", "La d�fense sp�ciale de %o ne peut plus augmenter!"));
		
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
		
		keys.add(new StringKey("effects.stats.pre.low", "La pr�cision de %o baisse!"));
		keys.add(new StringKey("effects.stats.pre.lowtwo", "La pr�cision de %o baisse beaucoup!"));
		keys.add(new StringKey("effects.stats.pre.cantlow", "La pr�cision de %o ne peut plus baisser!"));
		keys.add(new StringKey("effects.stats.pre.add", "La pr�cision de %o augmente!"));
		keys.add(new StringKey("effects.stats.pre.addtwo", "La pr�cision de %o augmente beaucoup!"));
		keys.add(new StringKey("effects.stats.pre.cantadd", "La pr�cision de %o ne peut plus augmenter!"));
		//status
		keys.add(new StringKey("effects.status.fail", "%o est d�ja %o!"));
		keys.add(new StringKey("effects.status.para", "%o est paralys�!"));
		keys.add(new StringKey("effects.status.poison", "%o est empoisonn�"));
		keys.add(new StringKey("effects.status.brulure", "%o est brûl�!"));
		keys.add(new StringKey("effects.status.gel", "%o est gel�!"));
		keys.add(new StringKey("effects.status.sommeil", "%o s'endort profond�mement."));
		//sous-status
		keys.add(new StringKey("effects.status.peur", "%o est apeur�!"));
		keys.add(new StringKey("effects.status.confus", "%o tombe dans la confusion!"));
		keys.add(new StringKey("effects.status.love", "%o tombe amoureux de %o!"));
		//effets
		keys.add(new StringKey("effects.stats.pv.ctrcoup", "%o prend le contrecoup et perd %o pv!"));
		//attaque
		keys.add(new StringKey("attack.pkmn.attacked", "%o a perdu %o pv. Il lui reste %o pv."));
		keys.add(new StringKey("attack.pkmn.absord", "La vie %o est absorb�e! %o gagne %o pv!"));
		keys.add(new StringKey("attack.fail", "Mais cela �choue!"));
		//types
		keys.add(new StringKey("attack.types.tpe", "Ce n'est vraiment pas tr�s efficace..."));
		keys.add(new StringKey("attack.types.in", "C'est inefficace!"));
		keys.add(new StringKey("attack.types.te", "C'est tr�s efficace!"));
		keys.add(new StringKey("attack.types.se", "C'est super efficace!"));
		//Heal
		keys.addElement(new StringKey("items.heal", "%o r�cup�re des pv!"));
		keys.add(new StringKey("items.status.heal", "%o n'a plus de probl�mes de status!"));
		keys.add(new StringKey("status.poison.heal", "%o n'est plus empoisonn�!"));
		keys.add(new StringKey("status.para.heal", "%o n'est plus paralys�!"));
		keys.add(new StringKey("status.gel.heal", "%o n'est plus gel�!"));
		keys.add(new StringKey("status.sommeil.heal", "%o se reveille!"));
		keys.add(new StringKey("status.brulure.heal", "%o n'est plus brul�!"));
	}
	
}
