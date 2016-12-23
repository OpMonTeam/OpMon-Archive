package jlppc.regimys.objects;

import java.awt.Image;
import java.io.Serializable;
import java.util.Arrays;

import jlppc.regimys.enums.Type;
import jlppc.regimys.evolution.Evolution;
import jlppc.regimys.exceptions.IncorrectValueException;
import jlppc.regimys.objects.items.CT;
import jlppc.regimys.enums.Caractere.Stats;
import jlppc.utils.HashArray;

/**
 * La classe qui définit une espèce de Pokémon.
 * 
 * @author Jlppc
 *
 */
public class Espece implements Serializable{

	/**
	 * Le nom de l'espéce. Pourquoi surnom? Je sais pas.
	 */
	protected final String surnom;
	/**
	 * Le numéro pokedex. Je ne repéte que ce qui est dit dans le nom.
	 */
	protected int numeroPokedex;
	/**
	 * Voir nom. Tellement évident.
	 */
	protected Espece evolution;
	/**
	 * Le niveau auquel le pokemon évolue.
	 */
	protected int niveauEvolution;
	/**
	 * La manière dont le pokemon évolue. Peut prendre les valeurs :<br/>
	 * <br/>
	 * {@link #EVOLUTION_BY_LEVEL}<br/>
	 * <br/>
	 * {@link #EVOLUTION_BY_LOVE}<br/>
	 * <br/>
	 * {@link #EVOLUTION_BY_OBJECT}
	 */
	protected int maniereEvolution;
	/**
	 * Signale que l'évolution est par le niveau. Voir {@link #niveauEvolution}
	 * pour savoir lequel.
	 */
	public static final int EVOLUTION_BY_LEVEL = 0;
	/**
	 * Signale que l'évolution est par un objet (Pierre, truc bizzare qui permet
	 * d'évoluer lors d'un échange... ect)
	 */
	public static final int EVOLUTION_BY_OBJECT = 1;
	/**
	 * Signale que l'évolution dépend du stade d'attachement avec son pokemon.
	 */
	public static final int EVOLUTION_BY_LOVE = 2;
	public static final int NO_EVOLUTION = 3;

	public static final int EVOLUTION_BY_TRADE = 4;
	public static final int EVOLUTION_BY_PLACE = 5;
	/**
	 * Va remplacer les autres déclaration d'évolution
	 */
	public Evolution evolType;
	/**
	 * Voir nom. Tellement évident.
	 */
	protected final Type type1;
	/**
	 * Voir nom. Tellement évident. Mettre Type.AUCUN si il n'a pas de second
	 * type.
	 */
	protected final Type type2;
	/**
	 * Les attaques apprises par niveau. Qu'est qu'un {@link HashArray}? Allez
	 * voir! Les tags sont : Attaque, Niveau pour chaque case de ce tableau.
	 */
	protected HashArray[] atksByLevels;
	/**
	 * L'entrée du pokedex (La description)
	 */
	protected String entreePokedex;
	/**
	 * Voir nom. Tellement évident.
	 */
	protected float taille;
	/**
	 * Voir nom. Tellement évident.
	 */
	protected float poids;
	/**Liste des CT combatibles avec le Pokémon*/
	protected CT[] ctCompatibles;
	// Les statistiques de l'espece. Les noms sont evidents.
	protected final int baseAtk;
	protected final int baseDef;
	protected final int baseAtkSpe;
	protected final int baseDefSpe;
	protected final int baseVit;
	protected final int basePV;
	/**
	 * Le hashCode de l'espece
	 */
	protected int hashCode;
	/**
	 * La coubre d'experience du pokémon
	 */
	protected CourbeExp courbe;
	/**
	 * L'exp du pokémon au niveau 100
	 */
	protected int expMax;
	/**
	 * Les EV données en fin de combat.
	 */
	protected Stats[] EVgiven;
	// Les sprites. Les noms sont toujours evidents. Ceux qui finissent par S
	// sont les sprites Shiney.
	protected Image miniSprite;
	protected Image spriteBattleFace;
	protected Image spriteBattleFront;
	protected Image spriteMap;
	protected Image spriteBattleFaceS;
	protected Image spriteBattleFrontS;
	protected Image spriteMapS;
	protected Image resume;
	protected Image resumeS;
	protected int expGiven;
	protected int tauxDeCapture;
    /**
     * Les differentes courbes d'experiences.
     * @author Jlppc
     *
     */
	public enum CourbeExp implements Serializable{
		RAPIDE, MOYENNE, PARABOLIQUE, LENTE, ERRATIQUE, FLUCTUANTE;
	}
	
	

	
	

	/**
	 * 
	 * @param atk
	 * @param def
	 * @param atkSpe
	 * @param defSpe
	 * @param vit
	 * @param pv
	 * @param name
	 * @param type1
	 * @param type2
	 * @param maniereEvolution
	 * @param niveauEvolution
	 * @param evolution
	 * @param attacksByLevels
	 * @param ctCombatibles
	 * @param EVGiven
	 * @param taille
	 * @param poids
	 * @param entreePokedex
	 */
	public Espece(int atk, int def, int atkSpe, int defSpe, int vit, int pv, String name, Type type1, Type type2,
			int maniereEvolution, int niveauEvolution, Evolution evolType, HashArray[] attacksByLevels,
			CT[] ctCombatibles, Stats[] EVGiven, float taille, float poids, String entreePokedex, int expGiven,
			int expMax, int tauxDeCapture) {
		if(atk < 0 || def < 0 || atkSpe < 0 || defSpe < 0 || vit < 0 || pv < 0){
			throw new IncorrectValueException("Stats in Espece execution");
		}
		if(expGiven < 0){
			throw new IncorrectValueException(expGiven, "In Espece initializer");
		}
		this.tauxDeCapture = tauxDeCapture;
		baseAtk = atk;
		baseDef = def;
		baseAtkSpe = atkSpe;
		baseDefSpe = defSpe;
		baseVit = vit;
		surnom = name;
		basePV = pv;
		this.type1 = type1;
		this.type2 = type2;
		this.maniereEvolution = maniereEvolution;
		this.niveauEvolution = niveauEvolution;
		this.evolType = evolType;
		this.evolution = this.evolType.getEvolution();
		this.atksByLevels = attacksByLevels;
		this.EVgiven = EVGiven;
		this.poids = poids;
		this.taille = taille;
		this.entreePokedex = entreePokedex;
		this.ctCompatibles = ctCombatibles;
		this.expGiven = expGiven;
		hashCode = hashCode();
		
		this.expMax = expMax;
		switch (this.expMax) {
		case 800000:
			courbe = CourbeExp.RAPIDE;
			break;
		case 1000000:
			courbe = CourbeExp.MOYENNE;
			break;
		case 1059860:
			courbe = CourbeExp.PARABOLIQUE;
			break;
		case 1250000:
			courbe = CourbeExp.LENTE;
			break;
		case 600000:
			courbe = CourbeExp.ERRATIQUE;
			break;
		case 1640000:
			courbe = CourbeExp.FLUCTUANTE;
			break;
		default:
			courbe = CourbeExp.MOYENNE;
		}
	}

	// Les getters. Rien de plus a expliquer.
	public synchronized final String getSurnom() {
		return surnom;
	}
	
	public Stats[] getEVgiven(){
		return EVgiven;
	}
	
	public Evolution getEvolType() {
		return evolType;
	}

	public synchronized final int getNumeroPokedex() {
		return numeroPokedex;
	}

	public synchronized final Espece getEvolution() {
		return evolution;
	}

	public synchronized final int getNiveauEvolution() {
		return niveauEvolution;
	}

	public synchronized final int getManiereEvolution() {
		return maniereEvolution;
	}

	public synchronized final Type getType1() {
		return type1;
	}

	public synchronized final Type getType2() {
		return type2;
	}

	public synchronized final HashArray[] getAtksByLevels() {
		return Arrays.<HashArray>copyOf(atksByLevels, atksByLevels.length);
	}

	public synchronized final String getEntreePokedex() {
		return new String(entreePokedex);
	}

	public synchronized final float getTaille() {
		return new Float(taille);
	}

	public synchronized final float getPoids() {
		return new Float(poids);
	}

	public synchronized final CT[] getCtCompatibles() {
		return Arrays.<CT>copyOf(ctCompatibles, ctCompatibles.length);
	}

	public synchronized final int getBaseAtk() {
		return new Integer(baseAtk);
	}

	public synchronized final int getBaseDef() {
		return new Integer(baseDef);
	}

	public synchronized final int getBaseAtkSpe() {
		return new Integer(baseAtkSpe);
	}

	public synchronized final int getBaseDefSpe() {
		return new Integer(baseDefSpe);
	}

	public synchronized final int getBaseVit() {
		return new Integer(baseVit);
	}

	public synchronized final int getBasePV() {
		return new Integer(basePV);
	}
	
	@Override
	public String toString() {
		return new String(this.surnom);
	}

	public CourbeExp getCourbe(){
		return courbe;
	}
	

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + Arrays.hashCode(EVgiven);
		result = prime * result + Arrays.hashCode(atksByLevels);
		result = prime * result + baseAtk;
		result = prime * result + baseAtkSpe;
		result = prime * result + baseDef;
		result = prime * result + baseDefSpe;
		result = prime * result + basePV;
		result = prime * result + baseVit;
		result = prime * result + ((courbe == null) ? 0 : courbe.hashCode());
		result = prime * result + Arrays.hashCode(ctCompatibles);
		result = prime * result + ((entreePokedex == null) ? 0 : entreePokedex.hashCode());
		result = prime * result + ((evolType == null) ? 0 : evolType.hashCode());
		//result = prime * result + ((evolution == null) ? 0 : evolution.hashCode());
		result = prime * result + expGiven;
		result = prime * result + expMax;
		result = prime * result + hashCode;
		result = prime * result + maniereEvolution;
		result = prime * result + ((miniSprite == null) ? 0 : miniSprite.hashCode());
		result = prime * result + niveauEvolution;
		result = prime * result + numeroPokedex;
		result = prime * result + Float.floatToIntBits(poids);
		result = prime * result + ((resume == null) ? 0 : resume.hashCode());
		result = prime * result + ((resumeS == null) ? 0 : resumeS.hashCode());
		result = prime * result + ((spriteBattleFace == null) ? 0 : spriteBattleFace.hashCode());
		result = prime * result + ((spriteBattleFaceS == null) ? 0 : spriteBattleFaceS.hashCode());
		result = prime * result + ((spriteBattleFront == null) ? 0 : spriteBattleFront.hashCode());
		result = prime * result + ((spriteBattleFrontS == null) ? 0 : spriteBattleFrontS.hashCode());
		result = prime * result + ((spriteMap == null) ? 0 : spriteMap.hashCode());
		result = prime * result + ((spriteMapS == null) ? 0 : spriteMapS.hashCode());
		result = prime * result + ((surnom == null) ? 0 : surnom.hashCode());
		result = prime * result + Float.floatToIntBits(taille);
		result = prime * result + ((type1 == null) ? 0 : type1.hashCode());
		result = prime * result + ((type2 == null) ? 0 : type2.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null) {
			return false;
		}
		if (!(obj instanceof Espece)) {
			return false;
		}
		Espece other = (Espece) obj;
		if (!Arrays.equals(EVgiven, other.EVgiven)) {
			return false;
		}
		if (!Arrays.equals(atksByLevels, other.atksByLevels)) {
			return false;
		}
		if (baseAtk != other.baseAtk) {
			return false;
		}
		if (baseAtkSpe != other.baseAtkSpe) {
			return false;
		}
		if (baseDef != other.baseDef) {
			return false;
		}
		if (baseDefSpe != other.baseDefSpe) {
			return false;
		}
		if (basePV != other.basePV) {
			return false;
		}
		if (baseVit != other.baseVit) {
			return false;
		}
		if (courbe != other.courbe) {
			return false;
		}
		if (!Arrays.equals(ctCompatibles, other.ctCompatibles)) {
			return false;
		}
		if (entreePokedex == null) {
			if (other.entreePokedex != null) {
				return false;
			}
		} else if (!entreePokedex.equals(other.entreePokedex)) {
			return false;
		}
		if (evolType == null) {
			if (other.evolType != null) {
				return false;
			}
		} else if (!evolType.equals(other.evolType)) {
			return false;
		}
		if (evolution == null) {
			if (other.evolution != null) {
				return false;
			}
		} else if (!evolution.equals(other.evolution)) {
			return false;
		}
		if (expGiven != other.expGiven) {
			return false;
		}
		if (expMax != other.expMax) {
			return false;
		}
		if (hashCode != other.hashCode) {
			return false;
		}
		if (maniereEvolution != other.maniereEvolution) {
			return false;
		}
		if (miniSprite == null) {
			if (other.miniSprite != null) {
				return false;
			}
		} else if (!miniSprite.equals(other.miniSprite)) {
			return false;
		}
		if (niveauEvolution != other.niveauEvolution) {
			return false;
		}
		if (numeroPokedex != other.numeroPokedex) {
			return false;
		}
		if (Float.floatToIntBits(poids) != Float.floatToIntBits(other.poids)) {
			return false;
		}
		if (resume == null) {
			if (other.resume != null) {
				return false;
			}
		} else if (!resume.equals(other.resume)) {
			return false;
		}
		if (resumeS == null) {
			if (other.resumeS != null) {
				return false;
			}
		} else if (!resumeS.equals(other.resumeS)) {
			return false;
		}
		if (spriteBattleFace == null) {
			if (other.spriteBattleFace != null) {
				return false;
			}
		} else if (!spriteBattleFace.equals(other.spriteBattleFace)) {
			return false;
		}
		if (spriteBattleFaceS == null) {
			if (other.spriteBattleFaceS != null) {
				return false;
			}
		} else if (!spriteBattleFaceS.equals(other.spriteBattleFaceS)) {
			return false;
		}
		if (spriteBattleFront == null) {
			if (other.spriteBattleFront != null) {
				return false;
			}
		} else if (!spriteBattleFront.equals(other.spriteBattleFront)) {
			return false;
		}
		if (spriteBattleFrontS == null) {
			if (other.spriteBattleFrontS != null) {
				return false;
			}
		} else if (!spriteBattleFrontS.equals(other.spriteBattleFrontS)) {
			return false;
		}
		if (spriteMap == null) {
			if (other.spriteMap != null) {
				return false;
			}
		} else if (!spriteMap.equals(other.spriteMap)) {
			return false;
		}
		if (spriteMapS == null) {
			if (other.spriteMapS != null) {
				return false;
			}
		} else if (!spriteMapS.equals(other.spriteMapS)) {
			return false;
		}
		if (surnom == null) {
			if (other.surnom != null) {
				return false;
			}
		} else if (!surnom.equals(other.surnom)) {
			return false;
		}
		if (Float.floatToIntBits(taille) != Float.floatToIntBits(other.taille)) {
			return false;
		}
		if (type1 != other.type1) {
			return false;
		}
		if (type2 != other.type2) {
			return false;
		}
		return true;
	}

	public int getExp() {

		return expGiven;
	}
	/**
	 * Permet d'enregistrer l'évolution. Doit être lancé après la déclaration de tous les pokémon.
	 */
	public void checkEvol() {
		evolType.checkEvo();
		this.evolution = evolType.getEvolution();
		
	}

	public int getHashCode() {
		return hashCode;
	}

	public int getExpMax() {
		return expMax;
	}

	public Image getMiniSprite() {
		return miniSprite;
	}

	public Image getSpriteBattleFace() {
		return spriteBattleFace;
	}

	public Image getSpriteBattleFront() {
		return spriteBattleFront;
	}

	public Image getSpriteMap() {
		return spriteMap;
	}

	public Image getSpriteBattleFaceS() {
		return spriteBattleFaceS;
	}

	public Image getSpriteBattleFrontS() {
		return spriteBattleFrontS;
	}

	public Image getSpriteMapS() {
		return spriteMapS;
	}

	public Image getResume() {
		return resume;
	}

	public Image getResumeS() {
		return resumeS;
	}

	public int getExpGiven() {
		return expGiven;
	}

	public int getTauxDeCapture() {
		return tauxDeCapture;
	}

}
