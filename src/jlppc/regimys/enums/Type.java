package jlppc.regimys.enums;
/**
 * Tout ce qui attrait au type.
 * @author Jlppc
 *
 */
public enum Type {
	
	EAU(3, "Eau"), FEU(6, "Feu"), PLANTE(10, "Plante"), ELECTRIQUE(4, "Electrique"), PSI(12, "Psy"), TENEBRES(16,"Ténèbres"), DRAGON(2, "Dragon"), COMBAT(1, "Combat"), ROCHE(13, "Roche"), SOL(14,"Sol"), NORMAL(9, "Normal"), FEE(5, "Fée"), SPECTRE(15, "Spectre"), POISON(11, "Poison"), ACIER(0, "Acier"), INSECTE(8, "Insecte"), VOL(17, "Vol"), GLACE(7, "Glace"), AUCUN(-1, "Aucun");
	/**
	 * L'ID du type.
	 */
	public final int id;
	//Variables de repere pour le tableau.
	public static final float PE = 0.5f;//Peu efficace
	public static final float NE = 1f;//Neutre
	public static final float IN = 0f;//INnefficace
	public static final float TP = 0.25f;//Très peu efficace
	public static final float TE = 2f;//Très efficace
	public static final float SE = 4f;//Super efficace
	/**
	 * Contient les resistance et faiblesses du types seuls.
	 * Le type defenseur est le premier IND, le type attaquant le 2e
	 */
	public static float[][] tabUnType = {
			{PE, TE, PE, NE, NE, PE, TE, PE, PE, PE, PE, IN, PE, PE, TE, NE, NE, PE},//Acier
			{NE, NE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, NE, PE, TE},//Combat
			{NE, NE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE},//Dragon
			{PE, NE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE},//Eau
			{PE, NE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, PE},//Electrique
			{TE, PE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE, PE, NE},//Fée
			{PE, NE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, NE, NE, NE},//Feu
			{TE, TE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, NE, NE, NE},//Glace
			{NE, PE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, NE, NE, TE},//Insecte
			{NE, TE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, IN, NE, NE},//Normal
			{NE, NE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE ,PE, NE, NE, TE},//Plante
			{NE, PE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, NE, NE, NE},//Poison
			{NE, PE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, TE, PE},//Psy
			{TE, TE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, NE, NE, PE},//Roche
			{NE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, NE, NE},//Sol
			{NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, TE, TE, NE},//Spectre
			{NE, TE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, PE, PE, NE},//Tenebres
			{NE, PE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, NE}//Vol
	};
	/**
	 * Le nom du type en String
	 */
	public final String nom;
	private Type(int id, String nom){
		this.id = id;
		this.nom = nom;
	}
	/**
	 * Calcule l'efficacité d'une type attaquant contre des types defenseurs.
	 * @param atk - Le type attaquant
	 * @param def1 - Le type defenseur 1
	 * @param def2 - Le type defenseur 2
	 * @return L'efficacité.
	 */
	public static float calcEfficacite(Type atk, Type def1, Type def2){
		if(def2 == AUCUN){
			return tabUnType[def1.id][atk.id];
		}else{
			return 1f;
		}
	}
	
}
