package jlppc.regimys.objects;
import java.io.Serializable;

import jlppc.regimys.fight.EndOfTurn;
/**
 * La base du talent des pokemon. La plupart des talents seront traitï¿½s au cas-par-cas dans Fight ou autre.
 * @author Jlppc
 * @warning Ne sera peut-être pas utilisé!!!
 */
public abstract class Talent implements Serializable {
	public static final int ACTIVE_ON_LIFE_LOW = 0;
	public static final int ALWAYS_ACTIVE = 1;
	public static final int ACTIVE_ON_ATTACK_TAKEN = 2;
	public static final int ACTIVE_ON_ATTACK = 3;
	public static final int ACTIVE_ON_BATTLE_START = 4;
	public static final int ACTIVE_BETWEEN_TOURS = 5;
	protected int whenActive;
	/**
	 * L'effet du talent.
	 * @param owner - Celui qui a le talent.
	 * @param adverse - Le pokemon adverse
	 * @throws EndOfTurn
	 */
	public abstract void effet(Pokemon owner, Pokemon adverse) throws EndOfTurn;
	
	public final int getActivationContext(){
		return whenActive;
	}
}
