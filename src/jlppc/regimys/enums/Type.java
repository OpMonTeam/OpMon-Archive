package jlppc.regimys.enums;
/**
 * Tout ce qui attrait au type.
 * @author Jlppc
 *
 */
public enum Type {
	
	EAU(3, "Eau"), FEU(6, "Feu"), PLANTE(10, "Plante"), ELECTRIQUE(4, "Electrique"), PSY(12, "Psy"), TENEBRES(16,"Ténèbres"), DRAGON(2, "Dragon"), COMBAT(1, "Combat"), ROCHE(13, "Roche"), SOL(14,"Sol"), NORMAL(9, "Normal"), FEE(5, "Fée"), SPECTRE(15, "Spectre"), POISON(11, "Poison"), ACIER(0, "Acier"), INSECTE(8, "Insecte"), VOL(17, "Vol"), GLACE(7, "Glace"), AUCUN(-1, "Aucun");
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
	
	
	
	public static float[][] tableAcier = {
			{TP, SE, TP, NE, NE, TP, SE, TP, TP, TP, TP, IN, TP, TP, SE, NE, NE, TP},//Acier + Acier
			{PE, TE, PE, NE, NE, NE, TE, PE, TP, PE, PE, IN, NE, TP, TE, NE, PE, NE},//Acier + Combat
			{PE, TE, NE, PE, PE, NE, NE, NE, PE, PE, TP, IN, PE, PE, TE, NE, NE, PE},//Acier + Dragon
			{TP, TE, PE, PE, TE, PE, NE, TP, PE, PE, NE, IN, PE, PE, TE, NE, NE, PE},//Acier + Eau
			{TP, TE, PE, NE, PE, PE, TE, PE, PE, PE, PE, IN, PE, PE, SE, NE, NE, TP},//Acier + Electrique
			{NE, NE, IN, NE, NE, PE, TE, PE, TP, PE, PE, IN, PE, PE, TE, NE, PE, PE},//Acier + Fee
			{TP, TE, PE, TE, NE, TP, NE, TP, TP, PE, TP, IN, PE, NE, SE, NE, NE, PE},//Acier + Feu
			{NE, SE, PE, NE, NE, PE, SE, TP, PE, PE, PE, IN, PE, NE, TE, NE, NE, PE},//Acier + Glace
			{PE, NE, PE, NE, NE, TP, SE, PE, PE, PE, TP, IN, NE, NE, NE, PE, PE, NE},//Acier + Insecte
			{PE, SE, PE, NE, NE, PE, TE, PE, PE, PE, PE, IN, PE, PE, TE, IN, NE, PE},//Acier + Normal
			{PE, TE, PE, PE, PE, PE, SE, NE, NE, PE, TP, IN, PE, PE, NE, NE, NE, NE},//Acier + Plante
			{PE, NE, PE, NE, NE, TP, TE, PE, TP, PE, TP, IN, NE, PE, SE, NE, NE, PE},//Acier + Poison
			{PE, NE, PE, NE, NE, PE, TE, PE, NE, PE, PE, IN, TP, PE, TE, TE, TE, PE},//Acier + Psi
			{NE, SE, PE, TE, NE, PE, NE, PE, PE, TP, NE, IN, PE, PE, SE, NE, NE, TP},//Acier + Roche
			{PE, TE, PE, TE, IN, PE, TE, NE, PE, PE, NE, IN, PE, TP, TE, NE, NE, PE},//Acier + Sol
			{PE, IN, PE, NE, NE, PE, TE, PE, TP, IN, PE, IN, PE, PE, TE, TE, TE, PE},//Acier + Spectre
			{PE, SE, PE, NE, NE, NE, TE, PE, NE, PE, PE, IN, IN, PE, TE, PE, PE, PE},//Acier + Ténèbres
			{PE, NE, PE, NE, TE, PE, TE, NE, TP, PE, TP, IN, PE, NE, IN, NE, NE, PE}//Acier + Vol
			
			
	};
	
	public static float[][] tableCombat = {
			
			{PE, TE, PE, NE, NE, NE, TE, PE, TP, PE, PE, IN, NE, TP, TE, NE, PE, NE},//Combat + Acier
			{NE, NE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, NE, PE, TE},//Combat
			{NE, NE, TE, PE, PE, SE, PE, TE, PE, NE, PE, NE, TE, PE, NE, NE, PE, TE},//Combat + Dragon
			{PE, NE, NE, PE, TE, TE, PE, PE, PE, NE, TE, NE, TE, PE, NE, NE, PE, TE},//Combat + Eau
			{PE, NE, NE, NE, PE, TE, NE, NE, PE, NE, NE, NE, TE, PE, TE, NE, PE, NE},//Combat + Electrique
			{TE, PE, IN, NE, NE, TE, NE, NE, TP, NE, NE, TE, TE, PE, NE, NE, TP, TE},//Combat + Fée
			{PE, NE, NE, TE, NE, NE, PE, PE, TP, NE, PE, NE, TE, NE, TE, NE, PE, TE},//Combat + Feu
			{TE, TE, NE, NE, NE, TE, TE, PE, PE, NE, NE, NE, TE, NE, NE, NE, PE, TE},//Combat + Glace
			{NE, PE, NE, NE, NE, TE, TE, NE, PE, NE, PE, NE, TE, NE, PE, NE, PE, SE},//Combat + Insecte
			{NE, TE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, IN, PE, TE},//Combat + Normal
			{NE, NE, NE, PE, PE, TE, TE, TE, NE, NE, PE, TE, TE, PE, PE, NE, PE, SE},//Combat + Plante
			{NE, PE, NE, NE, NE, NE, NE, NE, TP, NE, PE, PE, SE, PE, TE, NE, PE, TE},//Combat + Poison
			{NE, PE, NE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE, PE, NE, TE, NE, TE},//Combat + Psy
			{TE, TE, NE, TE, NE, TE, PE, NE, PE, PE, TE, PE, TE, PE, TE, NE, PE, NE},//Combat + Roche
			{NE, NE, NE, TE, IN, TE, NE, TE, PE, NE, TE, PE, TE, TP, NE, NE, PE, TE},//Combat + Sol
			{NE, IN, NE, NE, NE, TE, NE, NE, TP, IN, NE, PE, TE, PE, NE, TE, NE, TE},//Combat + Spectre
			{NE, TE, NE, NE, NE, SE, NE, NE, NE, NE, NE, NE, IN, PE, NE, PE, TP, TE},//Combat + Ténèbres
			{NE, PE, NE, NE, TE, TE, NE, TE, TP, NE, PE, NE, TE, NE, IN, NE, PE, TE}//Combat + Vol
			
	};
	
	public static float[][] tableDragon = {
			
			{PE, TE, NE, PE, PE, NE, NE, NE, PE, PE, TP, IN, PE, PE, TE, NE, NE, PE},
			{NE, NE, TE, PE, PE, SE, PE, TE, PE, NE, PE, NE, TE, PE, NE, NE, PE, TE},
			{NE, NE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE},
			{PE, NE, TE, TP, NE, TE, TP, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE},
			{PE, NE, TE, PE, TP, TE, PE, TE, NE, NE, PE, NE, NE, NE, TE, NE, NE, PE},
			{TE, PE, IN, PE, PE, TE, PE, TE, PE, NE, PE, TE, NE, NE, NE, NE, PE, NE},
			{PE, NE, TE, NE, PE, NE, TP, NE, PE, NE, TP, NE, NE, TE, TE, NE, NE, NE},
			{TE, TE, TE, PE, PE, TE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
			{NE, PE, TE, PE, PE, TE, NE, TE, NE, NE, TP, NE, NE, TE, PE, NE, NE, TE},
			{NE, TE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, IN, NE, NE},
			{NE, NE, TE, TP, TP, TE, NE, SE, TE, NE, TP, TE, NE, NE, PE, NE, NE, TE},
			{NE, PE, TE, PE, PE, NE, PE, TE, PE, NE, TP, PE, TE, NE, TE, NE, NE, NE},
			{NE, PE, TE, PE, PE, TE, PE, TE, TE, NE, PE, NE, PE, NE, NE, TE, TE, NE},
			{TE, TE, TE, NE, PE, TE, TP, TE, NE, PE, NE, PE, NE, NE, TE, NE, NE, PE},
			{NE, NE, TE, NE, IN, TE, PE, SE, NE, NE, NE, PE, NE, PE, NE, NE, NE, NE},
			{NE, IN, TE, PE, PE, TE, PE, TE, PE, IN, PE, PE, NE, NE, NE, TE, TE, NE},
			{NE, IN, TE, PE, PE, TE, PE, TE, PE, IN, PE, PE, NE, NE, NE, TE, TE, NE},
			{NE, PE, TE, PE, NE, TE, PE, SE, PE, NE, TP, NE, NE, TE, IN, NE, NE, NE}
			
	};
	
	public static float[][] tableEau = {
			
			{TP, TE, PE, PE, TE, PE, NE, TP, PE, PE, NE, IN, PE, PE, TE, NE, NE, PE},
			{PE, NE, NE, PE, TE, TE, PE, PE, PE, NE, TE, NE, TE, PE, NE, NE, PE, TE},
			{PE, NE, TE, TP, NE, TE, TP, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE},
			{PE, NE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE},
			{TP, NE, NE, PE, NE, NE, PE, PE, NE, NE, TE, NE, NE, NE, TE, NE, NE, PE},
			{NE, PE, IN, PE, TE, NE, PE, PE, PE, NE, TE, TE, NE, NE, NE, NE, PE, NE},
			{TP, NE, NE, NE, TE, PE, TP, TP, PE, NE, NE, NE, NE, TE, TE, NE, NE, NE},
			{NE, TE, NE, PE, TE, NE, NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, NE, NE},
			{PE, PE, NE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE},
			{PE, TE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, IN, NE, NE},
			{PE, NE, NE, TP, NE, NE, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, NE, TE},
			{PE, PE, NE, PE, TE, PE, PE, PE, PE, NE, NE, PE, TE, NE, TE, NE, NE, NE},
			{PE, PE, NE, PE, TE, NE, PE, PE, TE, NE, TE, NE, PE, NE, NE, TE, TE, NE},
			{NE, TE, NE, NE, TE, NE, TP, PE, NE, PE, SE, PE, NE, NE, TE, NE, NE, PE},
			{PE, NE, NE, NE, IN, NE, PE, NE, NE, NE, SE, PE, NE, PE, NE, NE, NE, NE},
			{PE, IN, NE, PE, TE, NE, PE, PE, PE, IN, TE, PE, NE, NE, NE, TE, TE, NE},
			{PE, TE, NE, PE, TE, TE, PE, PE, TE, NE, TE, NE, IN, NE, NE, PE, PE, NE},
			{PE, PE, NE, PE, SE, NE, PE, NE, PE, NE, NE, NE, NE, TE, IN, NE, NE, NE}
	};
	
	public static float[][] tableauElectrique = {
			{TP, TE, PE, NE, PE, PE, TE, PE, PE, PE, PE, IN, PE, PE, SE, NE, NE, TP},
			{PE, NE, NE, NE, PE, TE, NE, NE, PE, NE, NE, NE, TE, PE, TE, NE, PE, NE},
			{PE, NE, TE, PE, TP, TE, PE, TE, NE, NE, PE, NE, NE, NE, TE, NE, NE, PE},
			{TP, NE, NE, PE, NE, NE, PE, PE, NE, NE, TE, NE, NE, NE, TE, NE, NE, PE},
			{PE, NE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, PE},
			{NE, PE, IN, NE, PE, NE, NE, NE, PE, NE, NE, TE, NE, NE, TE, NE, PE, PE},
			{TP, NE, NE, TE, PE, PE, PE, PE, PE, NE, PE, NE, NE, TE, SE, NE, NE, PE},
			{NE, TE, NE, NE, PE, NE, TE, PE, NE, NE, NE, NE, NE, TE, TE, NE, NE, PE},
			{PE, PE, NE, NE, PE, NE, TE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
			{PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, IN, NE, PE},
			{PE, NE, NE, PE, TP, NE, TE, TE, TE, NE, PE, TE, NE, NE, NE, NE, NE, NE},
			{PE, PE, NE, NE, PE, PE, NE, NE, PE, NE, PE, PE, TE, NE, SE, NE, NE, PE},
			{PE, PE, NE, NE, PE, NE, NE, NE, TE, NE, NE, NE, PE, NE, TE, TE, TE, PE},
			{NE, TE, NE, TE, PE, NE, PE, NE, NE, PE, TE, PE, NE, NE, SE, NE, NE, TP},
			{PE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, TE, NE, NE, PE},
			{PE, IN, NE, NE, PE, NE, NE, NE, PE, IN, NE, PE, NE, NE, TE, TE, TE, PE},
			{PE, TE, NE, NE, PE, TE, NE, NE, TE, NE, NE, NE, IN, NE, TE, PE, PE, PE},
			{PE, PE, NE, NE, NE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, PE}
	};
	
	public static float[][] tableauFee = {
			{NE, NE, IN, NE, NE, PE, TE, PE, TP, PE, PE, IN, PE, PE, TE, NE, PE, PE},
			{TE, PE, IN, NE, NE, TE, NE, NE, TP, NE, NE, TE, TE, PE, NE, NE, TP, TE},
			{TE, PE, IN, PE, PE, TE, PE, TE, PE, NE, PE, TE, NE, NE, NE, NE, PE, NE},
			{NE, PE, IN, PE, TE, NE, PE, PE, PE, NE, TE, TE, NE, NE, NE, NE, PE, NE},
			{NE, PE, IN, NE, PE, NE, NE, NE, PE, NE, NE, TE, NE, NE, TE, NE, PE, PE},
			{TE, PE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE, PE, NE},
			{NE, PE, IN, TE, NE, PE, PE, PE, TP, NE, PE, TE, NE, TE, TE, NE, PE, NE},
			{SE, NE, IN, NE, NE, NE, TE, PE, PE, NE, NE, TE, NE, TE, NE, NE, PE, NE},
			{TE, TP, IN, NE, NE, NE, TE, NE, PE, NE, PE, TE, NE, TE, PE, NE, PE, TE},
			{TE, NE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, IN, PE, NE},
			{TE, PE, IN, PE, PE, NE, TE, TE, NE, NE, PE, SE, NE, NE, PE, NE, PE, TE},
			{TE, TP, IN, NE, NE, PE, NE, NE, TP, NE, PE, NE, TE, NE, TE, NE, PE, NE},
			{TE, TP, IN, NE, NE, NE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE, NE, PE},
			{SE, NE, IN, TE, NE, NE, PE, NE, PE, PE, TE, NE, NE, NE, TE, NE, PE, PE},
			{TE, NE, IN, TE, IN, NE, NE, TE, PE, NE, TE, NE, NE, PE, NE, NE, PE, NE},
			{TE, IN, IN, NE, NE, NE, NE, NE, TP, IN, NE, NE, NE, NE, NE, TE, NE, NE},
			{TE, NE, IN, NE, NE, TE, NE, NE, NE, NE, NE, TE, IN, NE, NE, PE, TP, NE},
			{TE, TP, IN, NE, TE, NE, NE, TE, TP, NE, PE, TE, NE, TE, IN, NE, PE, NE}
	};
	
	public static float[][] tableauFeu = {
			{TP, TE, PE, TE, NE, TP, NE, TP, TP, PE, TP, IN, PE, NE, SE, NE, NE, PE},
			{PE, NE, NE, TE, NE, NE, PE, PE, TP, NE, PE, NE, TE, NE, TE, NE, PE, TE},
			{PE, NE, TE, NE, PE, NE, TP, NE, PE, NE, TP, NE, NE, TE, TE, NE, NE, NE},
			{TP, NE, NE, NE, TE, PE, TP, TP, PE, NE, NE, NE, NE, TE, TE, NE, NE, NE},
			{TP, NE, NE, TE, PE, PE, PE, PE, PE, NE, PE, NE, NE, TE, SE, NE, NE, PE},
			{NE, PE, IN, TE, NE, PE, PE, PE, TP, NE, PE, TE, NE, TE, TE, NE, PE, NE},
			{PE, NE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, NE, NE, NE},
			{NE, TE, NE, TE, NE, PE, NE, TP, PE, NE, PE, NE, NE, SE, TE, NE, NE, NE},
			{PE, PE, NE, TE, NE, PE, NE, PE, PE, NE, TP, NE, NE, SE, NE, NE, NE, TE},
			{PE, TE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, IN, NE, NE},
			{PE, NE, NE, NE, PE, PE, NE, NE, NE, NE, TP, TE, NE, TE, NE, NE, NE, TE},
			{PE, PE, NE, TE, NE, TP, PE, PE, TP, NE, TP, PE, TE, TE, SE, NE, NE, NE},
			{PE, PE, NE, TE, NE, PE, PE, PE, NE, NE, PE, NE, PE, TE, TE, TE, TE, NE},
			{NE, TE, NE, SE, NE, PE, TP, PE, PE, PE, NE, PE, NE, TE, SE, NE, NE, PE},
			{PE, NE, NE, SE, IN, PE, PE, NE, PE, NE, NE, PE, NE, NE, TE, NE, NE, NE},
			{PE, IN, NE, TE, NE, PE, PE, PE, TP, IN, PE, PE, NE, TE, TE, TE, TE, NE},
			{PE, TE, NE, TE, NE, NE, PE, PE, NE, NE, PE, NE, IN, TE, TE, PE, PE, NE},
			{PE, PE, NE, TE, TE, PE, PE, NE, TP, NE, TP, NE, NE, SE, IN, NE, NE, NE}
	};
	
	public static float[][] tableauGlace = {
			{NE, SE, PE, NE, NE, PE, SE, TP, PE, PE, PE, IN, PE, NE, TE, NE, NE, PE},
			{TE, TE, NE, NE, NE, TE, TE, PE, PE, NE, NE, NE, TE, NE, NE, NE, PE, TE},
			{TE, TE, TE, PE, PE, TE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
			{NE, TE, NE, PE, TE, NE, NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, NE, NE},
			{NE, TE, NE, NE, PE, NE, TE, PE, NE, NE, NE, NE, NE, TE, TE, NE, NE, PE},
			{SE, NE, IN, NE, NE, NE, TE, PE, PE, NE, NE, TE, NE, TE, NE, NE, PE, NE},
			{NE, TE, NE, TE, NE, PE, NE, TP, PE, NE, PE, NE, NE, SE, TE, NE, NE, NE},
			{TE, TE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, NE, NE, NE},//Glace
			{TE, NE, NE, NE, NE, NE, SE, PE, NE, NE, PE, NE, NE, SE, PE, NE, NE, TE},
			{TE, SE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, IN, NE, NE},
			{TE, TE, NE, PE, PE, NE, SE, NE, TE, NE, PE, TE, NE, TE, PE, NE, NE, TE},
			{TE, NE, NE, NE, NE, PE, TE, PE, PE, NE, PE, PE, TE, TE, TE, NE, NE, NE},
			{TE, NE, NE, NE, NE, NE, TE, PE, TE, NE, NE, NE, PE, TE, NE, TE, TE, NE},
			{SE, SE, NE, TE, NE, NE, NE, PE, NE, PE, TE, PE, NE, TE, TE, NE, NE, PE},
			{TE, TE, NE, TE, IN, NE, TE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, NE},
			{TE, IN, NE, NE, NE, NE, TE, PE, PE, IN, NE, PE, NE, TE, NE, TE, TE, NE},
			{TE, SE, NE, NE, NE, TE, TE, PE, TE, NE, NE, NE, IN, TE, NE, PE, PE, NE},
			{TE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, NE, NE, SE, IN, NE, NE, NE}
	};
	
	public static float[][] tableauInsecte = {
			{PE, NE, PE, NE, NE, PE, SE, PE, PE, PE, TP, IN, PE, NE, NE, NE, NE, NE},
			{NE, PE, NE, NE, NE, TE, TE, NE, PE, NE, PE, NE, TE, NE, PE, NE, PE, SE},
			{NE, PE, TE, PE, PE, TE, NE, TE, NE, NE, TP, NE, NE, TE, PE, NE, NE, TE},
			{PE, PE, NE, PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE},
			{PE, PE, NE, NE, PE, NE, TE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, NE},
			{TE, TP, IN, NE, NE, NE, TE, NE, PE, NE, PE, TE, NE, TE, PE, NE, PE, TE},
			{PE, PE, NE, TE, NE, PE, NE, PE, PE, NE, TP, NE, NE, SE, NE, NE, NE, TE},
			{TE, NE, NE, NE, NE, NE, SE, PE, NE, NE, PE, NE, NE, SE, PE, NE, NE, TE},
			{NE, PE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, NE, NE, TE},
			{NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, IN, NE, TE},
			{NE, PE, NE, PE, PE, NE, SE, TE, TE, NE, TP, TE, NE, TE, TP, NE, NE, SE},
			{NE, TP, NE, NE, NE, PE, TE, NE, PE, NE, TP, PE, TE, TE, NE, NE, NE, TE},
			{NE, TP, NE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, TE, PE, TE, TE, TE},
			{TE, NE, NE, TE, NE, NE, NE, NE, NE, PE, NE, PE, NE, TE, NE, NE, NE, NE},
			{NE, PE, NE, TE, IN, NE, TE, TE, NE, NE, NE, PE, NE, NE, PE, NE, NE, TE},
			{NE, IN, NE, NE, NE, NE, TE, NE, PE, IN, PE, PE, NE, TE, PE, TE, TE, TE},
			{NE, NE, NE, NE, NE, TE, TE, NE, TE, NE, PE, NE, IN, TE, PE, PE, PE, TE},
			{NE, TP, NE, NE, TE, NE, TE, TE, PE, NE, TP, NE, NE, SE, IN, NE, NE, TE}
	};
	
	public static float[][] tableauNormal = {
			{PE, SE, PE, NE, NE, PE, TE, PE, PE, PE, PE, IN, NE, PE, TE, IN, PE, PE},
			{NE, TE, NE, NE, NE, TE, NE, NE, PE, NE, NE, NE, TE, PE, NE, IN, PE, TE},
			{NE, TE, TE, PE, PE, TE, PE, TE, NE, NE, PE, NE, NE, NE, NE, IN, NE, NE},
			{PE, TE, NE, PE, TE, NE, PE, PE, NE, NE, TE, NE, NE, NE, NE, IN, NE, NE},
			{PE, TE, NE, NE, PE, NE, NE, NE, NE, NE, NE, NE, NE, NE, TE, IN, NE, PE},
			{TE, NE, IN, NE, NE, NE, NE, NE, PE, NE, NE, TE, NE, NE, NE, IN, PE, NE},
			{PE, TE, NE, TE, NE, PE, PE, PE, PE, NE, PE, NE, NE, TE, TE, IN, NE, NE},
			{TE, SE, NE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, TE, NE, IN, NE, NE},
			{NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, PE, IN, NE, TE},
			{NE, TE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, IN, IN, IN},
			{NE, TE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, IN, NE, TE},
			{NE, NE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, IN, NE, NE},
			{NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, IN, TE, NE},
			{TE, SE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, IN, NE, PE},
			{NE, TE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, IN, NE, NE},
			{NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, IN, TE, NE},
			{NE, SE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, IN, PE, NE},
			{NE, NE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, IN, NE, NE}
	};
	
	public static float[][] tablePlante = {
			{PE, TE, PE, PE, PE, PE, SE, NE, NE, PE, TP, IN, PE, PE, NE, NE, NE, NE},
			{NE, NE, NE, PE, PE, TE, TE, TE, NE, NE, PE, TE, TE, PE, PE, NE, PE, SE},
			{NE, NE, TE, TP, TP, TE, NE, SE, TE, NE, TP, TE, NE, NE, PE, NE, NE, TE},
			{PE, NE, NE, TP, NE, NE, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, NE, TE},
			{PE, NE, NE, PE, TP, NE, TE, TE, TE, NE, PE, TE, NE, NE, NE, NE, NE, NE},
			{TE, PE, IN, PE, PE, NE, TE, TE, NE, NE, PE, SE, NE, NE, PE, NE, PE, TE},
			{PE, NE, NE, NE, PE, PE, NE, NE, NE, NE, TP, TE, NE, TE, NE, NE, NE, TE},
			{TE, TE, NE, PE, PE, NE, SE, NE, TE, NE, PE, TE, NE, TE, PE, NE, NE, TE},
			{NE, PE, NE, PE, PE, NE, SE, TE, TE, NE, TP, TE, NE, TE, TP, NE, NE, SE},
			{NE, TE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, IN, NE, TE},
			{NE, NE, NE, PE, PE, NE, TE, TE, TE, NE, PE, TE, NE, NE, PE, NE, NE, TE},
			{NE, PE, NE, PE, PE, PE, TE, TE, NE, NE, TP, NE, TE, NE, NE, NE, NE, TE},
			{NE, PE, NE, PE, PE, NE, TE, TE, SE, NE, PE, TE, PE, NE, PE, TE, TE, TE},
			{TE, TE, NE, NE, PE, NE, NE, TE, TE, PE, NE, NE, NE, NE, NE, NE, NE, NE},
			{NE, NE, NE, NE, IN, NE, TE, SE, TE, NE, NE, NE, NE, PE, PE, NE, NE, TE},
			{NE, IN, NE, PE, PE, NE, TE, TE, NE, IN, PE, NE, NE, NE, PE, TE, TE, TE},
			{NE, TE, NE, PE, PE, TE, TE, TE, SE, NE, PE, TE, IN, NE, PE, PE, PE, TE},
			{NE, PE, NE, PE, NE, NE, TE, SE, NE, NE, TP, TE, NE, TE, IN, NE, NE, TE}
		
	};
	
	public static float[][] tablePoison = {
			{PE, NE, PE, NE, NE, TP, TE, PE, TP, PE, TP, IN, NE, PE, SE, NE, NE, PE},
			{NE, PE, NE, NE, NE, NE, NE, NE, TP, NE, PE, PE, SE, PE, TE, NE, PE, TE},
			{NE, PE, TE, PE, PE, NE, PE, TE, PE, NE, TP, PE, TE, NE, TE, NE, NE, NE},
			{PE, PE, NE, PE, TE, PE, PE, PE, PE, NE, NE, PE, TE, NE, TE, NE, NE, NE},
			{PE, PE, NE, NE, PE, PE, NE, NE, PE, NE, PE, PE, TE, NE, SE, NE, NE, PE},
			{TE, TP, IN, NE, NE, PE, NE, NE, TP, NE, PE, NE, TE, NE, TE, NE, PE, NE},
			{PE, PE, NE, TE, NE, TP, PE, PE, TP, NE, TP, PE, TE, TE, SE, NE, NE, NE},
			{TE, NE, NE, NE, NE, PE, TE, PE, PE, NE, PE, PE, TE, TE, TE, NE, NE, NE},
			{NE, TP, NE, NE, NE, PE, TE, NE, PE, NE, TP, PE, TE, TE, NE, NE, NE, TE},
			{NE, NE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, IN, NE, NE},
			{NE, PE, NE, PE, PE, PE, TE, TE, NE, NE, TP, NE, TE, NE, NE, NE, NE, TE},
			{NE, PE, NE, NE, NE, PE, NE, NE, PE, NE, PE, PE, TE, NE, TE, NE, NE, NE},
			{NE, TP, NE, NE, NE, PE, NE, NE, NE, NE, PE, PE, NE, NE, TE, TE, TE, NE},
			{TE, NE, NE, TE, NE, PE, PE, NE, PE, PE, NE, TP, TE, NE, SE, NE, NE, PE},
			{NE, PE, NE, TE, IN, PE, NE, TE, PE, NE, NE, TP, TE, PE, TE, NE, NE, NE},
			{NE, IN, NE, NE, NE, PE, NE, NE, TP, IN, PE, TP, TE, NE, TE, TE, TE, NE},
			{NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, PE, PE, IN, NE, TE, PE, PE, NE},
			{NE, TP, NE, NE, TE, PE, NE, TE, TP, NE, TP, PE, TE, TE, IN, NE, NE, NE}
	};
	
	public static float[][] tableauPsy = {
			{PE, NE, PE, NE, NE, PE, TE, PE, NE, PE, PE, IN, TP, PE, TE, TE, TE, PE},
			{NE, PE, NE, NE, NE, TE, NE, NE, NE, NE, NE, NE, NE, PE, NE, TE, NE, TE},
			{NE, PE, TE, PE, PE, TE, PE, TE, TE, NE, PE, NE, PE, NE, NE, TE, TE, NE},
			{PE, PE, NE, PE, TE, NE, PE, PE, TE, NE, TE, NE, PE, NE, NE, TE, TE, NE},
			{PE, PE, NE, NE, PE, NE, NE, NE, TE, NE, NE, NE, PE, NE, TE, TE, TE, PE},
			{TE, TP, IN, NE, NE, NE, NE, NE, NE, NE, NE, TE, PE, NE, NE, TE, NE, PE},
			{PE, PE, NE, TE, NE, PE, PE, PE, NE, NE, PE, NE, PE, TE, TE, TE, TE, NE},
			{TE, NE, NE, NE, NE, NE, TE, PE, TE, NE, NE, NE, PE, TE, NE, TE, TE, NE},
			{NE, TP, NE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, TE, PE, TE, TE, TE},
			{NE, NE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, IN, TE, NE},
			{NE, PE, NE, PE, PE, NE, TE, TE, SE, NE, PE, TE, PE, NE, PE, TE, TE, TE},
			{NE, TP, NE, NE, NE, PE, NE, NE, NE, NE, PE, PE, NE, NE, TE, TE, TE, NE},
			{NE, PE, NE, NE, NE, NE, NE, NE, TE, NE, NE, NE, PE, NE, NE, TE, TE, NE},
			{TE, NE, NE, TE, NE, NE, PE, NE, TE, PE, TE, PE, PE, NE, TE, TE, TE, PE},
			{NE, PE, NE, TE, IN, NE, NE, TE, TE, NE, TE, PE, PE, PE, NE, TE, TE, NE},
			{NE, IN, NE, NE, NE, NE, NE, NE, NE, IN, NE, PE, PE, NE, NE, SE, SE, NE},
			{NE, NE, NE, NE, NE, TE, NE, NE, SE, NE, NE, NE, IN, NE, NE, IN, IN, IN},
			{NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, PE, TE, IN, TE, TE, NE}
	};
	
	public static float[][] tableauRoche = {
			{NE, SE, PE, TE, NE, PE, NE, PE, PE, TP, NE, IN, PE, PE, SE, NE, NE, TP},
			{TE, TE, NE, TE, NE, TE, PE, NE, PE, PE, TE, PE, TE, PE, TE, NE, PE, NE},
			{TE, TE, TE, NE, PE, TE, TP, TE, NE, PE, NE, PE, NE, NE, TE, NE, NE, PE},
			{NE, TE, NE, NE, TE, NE, TP, PE, NE, PE, SE, PE, NE, NE, TE, NE, NE, PE},
			{NE, TE, NE, TE, PE, NE, PE, NE, NE, PE, TE, PE, NE, NE, SE, NE, NE, TP},
			{SE, NE, IN, TE, NE, NE, PE, NE, PE, PE, TE, NE, NE, NE, TE, NE, PE, PE},
			{NE, TE, NE, SE, NE, PE, TP, PE, PE, PE, NE, PE, NE, TE, SE, NE, NE, PE},
			{SE, SE, NE, TE, NE, NE, NE, PE, NE, PE, TE, PE, NE, TE, TE, NE, NE, PE},
			{TE, NE, NE, TE, NE, NE, NE, NE, NE, PE, NE, PE, NE, TE, NE, NE, NE, NE},
			{TE, SE, NE, TE, NE, NE, PE, NE, NE, PE, TE, PE, NE, NE, TE, IN, NE, PE},
			{TE, TE, NE, NE, PE, NE, NE, TE, TE, PE, NE, NE, NE, NE, NE, NE, NE, NE},
			{TE, NE, NE, TE, NE, PE, PE, NE, PE, PE, NE, TP, TE, NE, SE, NE, NE, PE},
			{TE, NE, NE, TE, NE, NE, PE, NE, TE, PE, TE, PE, PE, NE, TE, TE, TE, PE},
			tabUnType[ROCHE.id],
			{TE, TE, NE, SE, IN, NE, PE, TE, NE, PE, SE, TP, NE, PE, TE, NE, NE, PE},
			{TE, IN, NE, TE, NE, NE, PE, NE, PE, IN, TE, TP, NE, NE, TE, TE, TE, PE},
			{TE, SE, NE, TE, NE, TE, PE, NE, TE, PE, TE, PE, IN, NE, TE, PE, PE, PE},
			{TE, NE, NE, TE, TE, NE, PE, TE, PE, PE, NE, PE, NE, TE, IN, NE, NE, PE}
	};
	
	public static float[][] tableauSol = {
			{PE, TE, PE, TE, IN, PE, TE, NE, PE, PE, NE, IN, PE, TP, TE, NE, NE, PE},
			{NE, NE, NE, TE, IN, TE, NE, TE, PE, NE, TE, PE, TE, TP, NE, NE, PE, TE},
			{NE, NE, TE, NE, IN, TE, PE, SE, NE, NE, NE, PE, NE, PE, NE, NE, NE, NE},
			{PE, NE, NE, NE, IN, NE, PE, NE, NE, NE, SE, PE, NE, PE, NE, NE, NE, NE},
			{PE, NE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, TE, NE, NE, PE},
			{TE, NE, IN, TE, IN, NE, NE, TE, PE, NE, TE, NE, NE, PE, NE, NE, PE, NE},
			{PE, NE, NE, SE, IN, PE, PE, NE, PE, NE, NE, PE, NE, NE, TE, NE, NE, NE},
			{TE, TE, NE, TE, IN, NE, TE, NE, NE, NE, TE, PE, NE, NE, NE, NE, NE, NE},
			{NE, PE, NE, TE, IN, NE, TE, TE, NE, NE, NE, PE, NE, NE, PE, NE, NE, TE},
			{NE, TE, NE, TE, IN, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, IN, NE, NE},
			{NE, NE, NE, NE, IN, NE, TE, SE, TE, NE, NE, NE, NE, PE, PE, NE, NE, TE},
			{NE, PE, NE, TE, IN, PE, NE, TE, PE, NE, NE, TP, TE, PE, TE, NE, NE, NE},
			{NE, PE, NE, TE, IN, NE, NE, TE, TE, NE, TE, PE, PE, PE, NE, TE, TE, NE},
			{TE, TE, NE, SE, IN, NE, PE, TE, NE, PE, SE, TP, NE, PE, TE, NE, NE, PE},
			tabUnType[SOL.id],
			{NE, IN, NE, TE, IN, NE, NE, TE, PE, IN, TE, TP, NE, PE, NE, TE, TE, NE},
			{NE, TE, NE, TE, IN, TE, NE, TE, TE, NE, TE, PE, IN, PE, NE, PE, PE, NE},
			{NE, PE, NE, TE, IN, NE, NE, SE, PE, NE, NE, PE, NE, NE, IN, NE, NE, NE}
	};
	
	public static float[][] tableSpectre = {
			{PE, IN, PE, NE, NE, PE, TE, PE, TP, IN, PE, IN, PE, PE, TE, TE, TE, PE},
			{NE, IN, NE, NE, NE, TE, NE, NE, TP, IN, NE, PE, TE, PE, NE, TE, NE, TE},
			{NE, IN, TE, PE, PE, TE, PE, TE, PE, IN, PE, PE, NE, NE, NE, TE, TE, NE},
			{PE, IN, NE, PE, TE, NE, PE, PE, PE, IN, TE, PE, NE, NE, NE, TE, TE, NE},
			{PE, IN, NE, NE, PE, NE, NE, NE, PE, IN, NE, PE, NE, NE, TE, TE, TE, PE},
			{TE, IN, IN, NE, NE, NE, NE, NE, TP, IN, NE, NE, NE, NE, NE, TE, NE, NE},
			{PE, IN, NE, TE, NE, PE, PE, PE, TP, IN, PE, PE, NE, TE, TE, TE, TE, NE},
			{TE, IN, NE, NE, NE, NE, TE, PE, PE, IN, NE, PE, NE, TE, NE, TE, TE, NE},
			{NE, IN, NE, NE, NE, NE, TE, NE, PE, IN, PE, PE, NE, TE, PE, TE, TE, TE},
			{NE, IN, NE, NE, NE, NE, NE, NE, PE, IN, NE, PE, NE, NE, NE, IN, TE, NE},
			{NE, IN, NE, PE, PE, NE, TE, TE, NE, IN, PE, NE, NE, NE, PE, TE, TE, TE},
			{NE, IN, NE, NE, NE, PE, NE, NE, TP, IN, PE, TP, TE, NE, TE, TE, TE, NE},
			{NE, IN, NE, NE, NE, NE, NE, NE, NE, IN, NE, PE, PE, NE, NE, SE, SE, NE},
			{TE, IN, NE, TE, NE, NE, PE, NE, PE, IN, TE, TP, NE, NE, TE, TE, TE, PE},
			{NE, IN, NE, TE, IN, NE, NE, TE, PE, IN, TE, TP, NE, PE, NE, TE, TE, NE},
			tabUnType[SPECTRE.id],
			{NE, IN, NE, NE, NE, TE, NE, NE, NE, IN, NE, PE, IN, NE, NE, NE, NE, NE},
			{NE, IN, NE, NE, TE, NE, NE, TE, TP, IN, PE, PE, NE, TE, IN, TE, TE, NE}
	};
	
	public static float[][] tableauTenebres = {
			{PE, SE, PE, NE, NE, NE, TE, PE, NE, PE, PE, IN, IN, PE, TE, PE, PE, PE},
			{NE, TE, NE, NE, NE, SE, NE, NE, NE, NE, NE, NE, IN, PE, NE, PE, TP, TE},
			{NE, TE, TE, PE, PE, SE, PE, TE, TE, NE, PE, NE, IN, NE, NE, PE, PE, NE},
			{PE, TE, NE, PE, TE, TE, PE, PE, TE, NE, TE, NE, IN, NE, NE, PE, PE, NE},
			{PE, TE, NE, NE, PE, TE, NE, NE, TE, NE, NE, NE, IN, NE, TE, PE, PE, PE},
			{TE, NE, IN, NE, NE, TE, NE, NE, NE, NE, NE, TE, IN, NE, NE, PE, TP, NE},
			{PE, TE, NE, TE, NE, NE, PE, PE, NE, NE, PE, NE, IN, TE, TE, PE, PE, NE},
			{TE, SE, NE, NE, NE, TE, TE, PE, TE, NE, NE, NE, IN, TE, NE, PE, PE, NE},
			{NE, NE, NE, NE, NE, TE, TE, NE, TE, NE, PE, NE, IN, TE, PE, PE, PE, TE},
			{NE, SE, NE, NE, NE, TE, NE, NE, TE, NE, NE, NE, IN, NE, NE, IN, PE, NE},
			{NE, TE, NE, PE, PE, TE, TE, TE, SE, NE, PE, TE, IN, NE, PE, PE, PE, TE},
			{NE, NE, NE, NE, NE, NE, NE, NE, NE, NE, PE, PE, IN, NE, TE, PE, PE, NE},
			{NE, NE, NE, NE, NE, TE, NE, NE, SE, NE, NE, NE, IN, NE, NE, IN, IN, IN},
			{TE, SE, NE, TE, NE, TE, PE, NE, TE, PE, TE, PE, IN, NE, TE, PE, PE, PE},
			{NE, TE, NE, TE, IN, TE, NE, TE, TE, NE, TE, PE, IN, PE, NE, PE, PE, NE},
			{NE, IN, NE, NE, NE, TE, NE, NE, NE, IN, NE, PE, IN, NE, NE, NE, NE, NE},
			tabUnType[TENEBRES.id],
			{NE, NE, NE, NE, TE, TE, NE, TE, NE, NE, PE, NE, IN, TE, IN, PE, PE, NE}
	};
	
	public static float[][] tableauVol = {
			{PE, NE, PE, NE, TE, PE, TE, NE, TP, PE, TP, IN, PE, NE, IN, NE, NE, PE},
			{NE, PE, NE, NE, TE, TE, NE, TE, TP, NE, PE, NE, TE, NE, IN, NE, PE, TE},
			{NE, PE, TE, PE, NE, TE, PE, SE, PE, NE, TP, NE, NE, TE, IN, NE, NE, NE},
			{PE, PE, NE, PE, SE, NE, PE, NE, PE, NE, NE, NE, NE, TE, IN, NE, NE, NE},
			{PE, PE, NE, NE, NE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, NE, NE, PE},
			{TE, TP, IN, NE, TE, NE, NE, TE, TP, NE, PE, TE, NE, TE, IN, NE, PE, NE},
			{PE, PE, NE, TE, TE, PE, PE, NE, TP, NE, TP, NE, NE, SE, IN, NE, NE, NE},
			{TE, NE, NE, NE, TE, NE, TE, NE, PE, NE, PE, NE, NE, SE, IN, NE, NE, NE},
			{NE, TP, NE, NE, TE, NE, TE, TE, PE, NE, TP, NE, NE, SE, IN, NE, NE, TE},
			{NE, NE, NE, NE, TE, NE, NE, TE, PE, NE, PE, NE, NE, TE, IN, IN, NE, NE},
			{NE, PE, NE, PE, NE, NE, TE, SE, NE, NE, TP, TE, NE, TE, IN, NE, NE, TE},
			{NE, TP, NE, NE, TE, PE, NE, TE, TP, NE, TP, PE, TE, TE, IN, NE, NE, NE},
			{NE, TP, NE, NE, TE, NE, NE, TE, NE, NE, PE, NE, PE, TE, IN, TE, TE, NE},
			{TE, NE, NE, TE, TE, NE, PE, TE, PE, PE, NE, PE, NE, TE, IN, NE, NE, PE},
			{NE, PE, NE, TE, IN, NE, NE, SE, PE, NE, NE, PE, NE, NE, IN, NE, NE, NE},
			{NE, IN, NE, NE, TE, NE, NE, TE, TP, IN, PE, PE, NE, TE, IN, TE, TE, NE},
			{NE, NE, NE, NE, TE, TE, NE, TE, NE, NE, PE, NE, IN, TE, IN, PE, PE, NE},
			tabUnType[VOL.id]
	};
	
	public static float[][][] tableDeuxTypes = {tableAcier, tableCombat, tableDragon, tableEau, tableauElectrique, tableauFee, tableauFeu, tableauGlace, tableauInsecte, tableauNormal, tablePlante, tablePoison, tableauPsy, tableauRoche, tableauSol, tableSpectre, tableauTenebres, tableauVol};
	
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
			return tableDeuxTypes[def1.id][def2.id][atk.id];
		}
	}
	
}
