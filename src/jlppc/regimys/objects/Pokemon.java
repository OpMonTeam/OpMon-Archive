package jlppc.regimys.objects;

import java.io.Serializable;
import java.util.Arrays;

import jlppc.regimys.enums.Caractere;
import jlppc.regimys.enums.Type;
import jlppc.regimys.evolution.E_Item;
import jlppc.regimys.evolution.E_Trade;
import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.items.I_Heal;
import jlppc.regimys.objects.items.Item;
import jlppc.regimys.util.text.StringKey;
import jlppc.utils.HashArray;
import jlppc.utils.Static;
import jlppc.regimys.util.math.Math;
import jlppc.utils.WIP;
/**
 * Definit un pokemon.
 * @author Jlppc
 *
 */
public class Pokemon extends RegimysObject implements Serializable{
	/**
	 * Le nom / surnom du pokemon
	 */
	protected String surnom;
	//Les statistiques...
	//Les IV
	protected int atkIV = Start.rand.nextInt(32);
	protected int defIV = Start.rand.nextInt(32);
	protected int atkSpeIV = Start.rand.nextInt(32);
	protected int defSpeIV = Start.rand.nextInt(32);
	protected int vitIV = Start.rand.nextInt(32);
	protected int pvIV = Start.rand.nextInt(32);
	//Les EV
	protected int atkEV = 0;
	protected int defEV = 0;
	protected int atkSpeEV = 0;
	protected int defSpeEV = 0;
	protected int vitEV = 0;
	protected int pvEV = 0;
	//Les statistiques en general
	protected int statATK;
	protected int statDEF;
	protected int statATKSPE;
	protected int statDEFSPE;
	protected int statVIT;
	//Les autrees stats.
	protected int statESQ;
	protected float statPRE;
	protected int statPV;
	protected int statLove;
	//Les variables indiquant le niveau de changement.
	public int atkChange = 0;
	public int defChange = 0;
	public int defSpeChange = 0;
	public int atkSpeChange = 0;
	public int esqChange = 0;
	public int preChange = 0;
	public int vitChange = 0;
	/**
	 * Le niveau du pokemon
	 */
	protected int level;
	/**
	 * Le caractère du pokemon
	 */
	protected Caractere caractere;
	/**
	 * Les 4 attaques du pokemon
	 */
	protected Attaque[] attaques = new Attaque[4];
	/**
	 * L'espece du pokemon
	 */
	protected Espece espece;
	/**
	 * Les PV du pokemon (Pas les PV max)
	 */
	protected int PV;
	/**
	 * Le status du pokemon
	 */
	protected Status status = Status.AUCUN;
	/**
	 * Le talent du pokeon
	 */
	protected Talent talent;
	/**
	 * Le type 1
	 */
	protected Type type1;
	/**
	 * Le type 2
	 */
	protected Type type2;
	/**
	 * L'experience du pokemon
	 */
	protected int exp;
	/**
	 * Le nombre d'xp qu'il faut pour le niveau supérieur
	 */
	protected int toNextLevel;
	protected float expBoost = 1;
	//Les sous status
	public boolean confus = false;
	public boolean peur = false;
	public boolean amour = false;
	public boolean vampigraine = false;
	public boolean malediction = false;
	protected Stats malusCara;
	protected Stats bonusCara;
	
	protected Item held;
	
	protected int tauxCapture;
	
	
	public boolean captured(I_Pokeball pokeball){
		int a = Math.round((((3 * pvMax - 2 * PV) * tauxCapture * pokeball.getTauxCapture() * (Comparaisons.multiEgal(status, Status.PARALYSIE, Status.POISON, Status.BRULURE) ? 1.5f : (Comparaisons.multiEgal(status, Status.SOMMEIL, Status.GEL) ? 2 : 1)))/(3 * pvMax)));
		int b = Math.round((pow(2, 16) - 1) * Math.racine(a/(pow(2, 8) - 1),4));
		int[] c = {Start.rand.nextInt(65535), Start.rand.nextInt(65535), Start.rand.nextInt(65535), Start.rand.nextInt(65535)};
		int nbreOk;
		for(int nbre : c){
			if(nbre <= b){
				nbreOk++;
			}
		}
		if(nbreOk == 0){
			return false;
		}else{
			System.out.println("Remue...");
			if(nbreOk == 1){
				return false;
			}
			System.out.println("Remue...");
			if(nbreOk == 2){
				return false;
			}
			System.out.println("Remue...");
			if(nbreOk == 3){
				return false;
			}
			if(nbreOk != 4){
				throw new InternalException();
			}
			return true;
		}
	}
	
	@Static
	protected static class CalcCourbes implements Serializable{
		private static float p(int x){
			switch(x){
			case 0:
				return 0.000f;
			case 1:
				return 0.008f;
			case 2:
				return 0.014f;
			default:
				throw new ArithmeticException("Erreur dans le calcul de la courbe d'experience");
			}
		}
		public static float pow(float a, float b){
			return (float) Math.pow(a, b);
		}
		public static int erratique(int n){
			if(0 < n && n <= 50){
				return Math.round(pow(n, 3) * ((100 - n) / 50));
			}else if(51 <= n && n <= 68){
				return Math.round(pow(n, 3) * ((150 - n) / 50));
			}else if(69 <= n && n <= 98){
				return Math.round(1.274f - ((1/50) * (n/3)) - p(n % 3));
			}else if(n >= 99){
				return Math.round(pow(n, 3) * ((160 - n) / 100));
			}else{
				throw new ArithmeticException("Erreur dans le calcul d'experience : niveau <= 0");
			}
		}
		public static int fluctuante(int n){
			if(0 < n && n <= 15){
				return Math.round(pow(n, 3) * ((24 + ((n + 1) / 3) / 50)));	
			}else if(16 <= n && n <= 35){
				return Math.round(pow(n, 3) * ((14 + n) / 50));
			}else if(n >= 36){
				return Math.round(pow(n, 3) * ((32  + (n / 2)) / 50));
			}else{
				throw new ArithmeticException("Erreur dans le calcul d'experience : niveau <= 0");
			}
		}
		public static int lente(int n){
			return Math.round(1.25f * pow(n, 3));
		}
		public static int moyenne(int n){
			return Math.round(pow(n, 3));
		}
		public static int parabolique(int n){
			return Math.round(1.2f * pow(n, 3) - 15 * pow(n,2) + (100 * n) - 140);
		}
		public static int rapide(int n){
			return Math.round(0.8f * pow(n, 3));
		}
		
	}
	
	

	
	
	
	
	
	/**
	 * Le constructeur.
	 * @param espece - {@link #espece}
	 * @param level - {@link #level}
	 * @param attaques - {@link #attaques}
	 * @param caractere - {@link #caractere}
	 * @param talent - {@link #talent}
	 */
	public Pokemon(Espece espece, int level, Attaque[] attaques, Caractere caractere, Talent talent){
		statATK = (int) Math.round( ( ( ((2 * espece.getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.ATK) ? 1.1 : ((caractere.malus == Stats.ATK) ? 0.9 : 1)));
		statDEF = (int) Math.round( ( ( ((2 * espece.getBaseDef() + defIV + (defEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.DEF) ? 1.1 : ((caractere.malus == Stats.DEF) ? 0.9 : 1)));
		statATKSPE = (int) Math.round( ( ( ((2 * espece.getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.ATKSPE) ? 1.1 : ((caractere.malus == Stats.ATKSPE) ? 0.9 : 1)));
		statDEFSPE = (int) Math.round( ( ( ((2 * espece.getBaseDefSpe() + defSpeIV + (defSpeEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.DEFSPE) ? 1.1 : ((caractere.malus == Stats.DEFSPE) ? 0.9 : 1)));
		statVIT = (int) Math.round( ( ( ((2 * espece.getBaseVit() + vitIV + (vitEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.VIT) ? 1.1 : ((caractere.malus == Stats.VIT) ? 0.9 : 1)));
		statPV = Math.round(((2 * espece.getBasePV() + pvIV + (pvEV / 4)) * level) / 100) + level + 10;
		this.espece = espece;
		this.level = level;
		this.attaques = Arrays.copyOf(attaques, attaques.length);
		this.caractere = caractere;
		bonusCara = caractere.bonus;
		malusCara = caractere.malus;
		this.surnom = espece.getSurnom();
		
		PV = new Integer(statPV);
		this.talent = talent;
		type1 = espece.getType1();
		type2 = espece.getType2();
		switch(this.espece.getCourbe()){
		case ERRATIQUE:
			CalcCourbes.erratique(this.level + 1);
			break;
		case FLUCTUANTE:
			CalcCourbes.fluctuante(this.level + 1);
			break;
		case LENTE:
			CalcCourbes.lente(this.level + 1);
			break;
		case MOYENNE:
			CalcCourbes.moyenne(this.level + 1);
			break;
		case PARABOLIQUE:
			CalcCourbes.parabolique(this.level + 1);
			break;
		case RAPIDE:
			CalcCourbes.rapide(this.level + 1);
			break;
		
		
		}
		toNextLevel = toNextLevel - exp;
	}
	/**
	 * Le constructeur avec surnom
	 * @param surnom - {@link #surnom}
	 * @param espece - {@link #espece}
	 * @param level - {@link #level}
	 * @param attaques - {@link #attaques}
	 * @param caractere - {@link #caractere}
	 * @param talent - {@link #talent}
	 */
	public Pokemon(String surnom, Espece espece, int level, Attaque[] attaques, Caractere caractere, Talent talent){
		this.espece = espece;

		statATK = (int) Math.round( ( ( ((2 * espece.getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.ATK) ? 1.1 : ((caractere.malus == Stats.ATK) ? 0.9 : 1)));
		statDEF = (int) Math.round( ( ( ((2 * espece.getBaseDef() + defIV + (defEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.DEF) ? 1.1 : ((caractere.malus == Stats.DEF) ? 0.9 : 1)));
		statATKSPE = (int) Math.round( ( ( ((2 * espece.getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.ATKSPE) ? 1.1 : ((caractere.malus == Stats.ATKSPE) ? 0.9 : 1)));
		statDEFSPE = (int) Math.round( ( ( ((2 * espece.getBaseDefSpe() + defSpeIV + (defSpeEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.DEFSPE) ? 1.1 : ((caractere.malus == Stats.DEFSPE) ? 0.9 : 1)));
		statVIT = (int) Math.round( ( ( ((2 * espece.getBaseVit() + vitIV + (vitEV / 4)) * level) / 100 ) + 5 ) * ((caractere.bonus == Stats.VIT) ? 1.1 : ((caractere.malus == Stats.VIT) ? 0.9 : 1)));
		statPV = Math.round(((2 * espece.getBasePV() + pvIV + (pvEV / 4)) * level) / 100) + level + 10;
		this.level = level;
		this.attaques = Arrays.copyOf(attaques, attaques.length);
		this.caractere = caractere;
		this.surnom = surnom;
		PV = new Integer(statPV);
		this.talent = talent;
		type1 = espece.getType1();
		type2 = espece.getType2();
		switch(this.espece.getCourbe()){
		case ERRATIQUE:
			CalcCourbes.erratique(this.level + 1);
			break;
		case FLUCTUANTE:
			CalcCourbes.fluctuante(this.level + 1);
			break;
		case LENTE:
			CalcCourbes.lente(this.level + 1);
			break;
		case MOYENNE:
			CalcCourbes.moyenne(this.level + 1);
			break;
		case PARABOLIQUE:
			CalcCourbes.parabolique(this.level + 1);
			break;
		case RAPIDE:
			CalcCourbes.rapide(this.level + 1);
			break;
		
		
		}
		toNextLevel = toNextLevel - exp;
	}
	
	public void levelUp(){
		level++;
		System.out.println("Level up! Passage au niveau " + level + "!");
		switch(espece.getCourbe()){
		case ERRATIQUE:
			toNextLevel = CalcCourbes.erratique(level + 1);
			break;
		case FLUCTUANTE:
			toNextLevel = CalcCourbes.fluctuante(level + 1);
			break;
		case LENTE:
			toNextLevel = CalcCourbes.lente(level + 1);
			break;
		case MOYENNE:
			toNextLevel = CalcCourbes.moyenne(level + 1);
			break;
		case PARABOLIQUE:
			toNextLevel = CalcCourbes.parabolique(level + 1);
			break;
		case RAPIDE:
			toNextLevel = CalcCourbes.rapide(level + 1);
			break;
		
		
		}
		if(toNextLevel < exp){toNextLevel = exp - toNextLevel;}
		calcStats(this.espece);
		if(espece.getEvolType().checkEvolve(this)){
			if(!(espece.getEvolType() instanceof E_Trade)){
				evolve();
			}
			
		}
	}
	
	/**
	 * L'enumeration des status pokemon.
	 * @author Jlppc
	 *
	 */
	public enum Status implements Serializable{
		BRULURE, PARALYSIE, SOMMEIL, GEL, POISON, AUCUN;
	}
	
	
	
	
	
	public boolean isHoldingItem(){
		return (held == null);
	}
	
	public Item itemHeld(){
		return held;
	}
	
	/**
	 * Quand le pokemon a gagné
	 * @param vaincu
	 * @return l'exp gagnée
	 */
	@WIP
	public int win(Pokemon vaincu){
		fosout("%o a gagné %o!", surnom, ((vaincu.espece.getExp() * vaincu.level) / this.level) * expBoost);
		getEvs(vaincu);
		exp+=((vaincu.espece.getExp() * vaincu.level) / this.level) * expBoost;
		while(exp >= toNextLevel && level < 100){
			if(exp < toNextLevel){
				break;
			}
			levelUp();
			
		}
		calcStats(espece);
		return (int) (((vaincu.espece.getExp() * vaincu.level) / this.level) * expBoost);
		
		
	}
	
	protected void getEvs(Pokemon vaincu){
		if(!((atkEV + defEV + pvEV + atkSpeEV + defSpeEV + vitEV) > 510)){
			for(Stats stat : vaincu.getEspece().getEVgiven()){
				switch(stat){
				case ATK:
					if(atkEV < 252){
						atkEV++;
					}
					break;
				case ATKSPE:
					if(atkSpeEV < 252){
						atkSpeEV++;
					}
					break;
				case DEF:
					if(defEV < 252){
						atkEV++;
					}
					break;
				case DEFSPE:
					if(defSpeEV < 252){
						defSpeEV++;
					}
					break;
				case PV:
					if(pvEV < 252){
						pvEV++;
					}
					break;
				case RIEN:
					break;
				case VIT:
					if(vitEV < 252){
						vitEV++;
					}
					break;
				
				}
			}
			
		}
	}
	
	
	public void calcStats(Espece espece){
		statATK = (int) Math.round( ( ( ((2 * espece.getBaseAtk() + atkIV + (atkEV / 4)) * level) / 100 ) + 5 ) * ((bonusCara == Stats.ATK) ? 1.1 : ((malusCara == Stats.ATK) ? 0.9 : 1)));
		statDEF = (int) Math.round( ( ( ((2 * espece.getBaseDef() + defIV + (defEV / 4)) * level) / 100 ) + 5 ) * ((bonusCara == Stats.DEF) ? 1.1 : ((malusCara == Stats.DEF) ? 0.9 : 1)));
		statATKSPE = (int) Math.round( ( ( ((2 * espece.getBaseAtkSpe() + atkSpeIV + (atkSpeEV / 4)) * level) / 100 ) + 5 ) * ((bonusCara == Stats.ATKSPE) ? 1.1 : ((malusCara == Stats.ATKSPE) ? 0.9 : 1)));
		statDEFSPE = (int) Math.round( ( ( ((2 * espece.getBaseDefSpe() + defSpeIV + (defSpeEV / 4)) * level) / 100 ) + 5 ) * ((bonusCara == Stats.DEFSPE) ? 1.1 : ((malusCara == Stats.DEFSPE) ? 0.9 : 1)));
		statVIT = (int) Math.round( ( ( ((2 * espece.getBaseVit() + vitIV + (vitEV / 4)) * level) / 100 ) + 5 ) * ((bonusCara == Stats.VIT) ? 1.1 : ((malusCara == Stats.VIT) ? 0.9 : 1)));
		statPV = Math.round(((2 * espece.getBasePV() + pvIV + (pvEV / 4)) * level) / 100) + level + 10;
	}
	/**
	 * Permet d'utiliser un item sur le pokémon.
	 * @param used
	 * @return un booleen pour savoir si l'item doit être supprimé ou pas. (false si pas supprimé, true sinon)
	 */
	public boolean itemUsed(Item used){
		fosout("%o utilise un(e) %o!", this.getSurnom(), used.getName());
		if(espece.getEvolType() instanceof E_Item){
			if(((E_Item) espece.getEvolType()).itemEvolve(used)){
				evolve();
			}
		}
			if(used instanceof I_Heal){
				
				I_Heal usedI = (I_Heal) used;
				if(usedI.getPvHeal() > 0){
					this.heal(usedI.getPvHeal());
					keyout(key("items.heal"), surnom);
				}
				if(usedI.isHealAll() && status == Status.AUCUN){
					this.setStatus(Status.AUCUN);
					keyout(key("items.status.heal"), surnom);
				}else if(usedI.getStatusHeald() != Status.AUCUN && status == usedI.getStatusHeald()){
					setStatus(Status.AUCUN);
					switch(usedI.getStatusHeald()){
					case AUCUN:
						break;
					case BRULURE:
						keyout(key("status.brulure.heal"), surnom);
						break;
					case GEL:
						keyout(key("status.gel.heal"), surnom);
						break;
					case PARALYSIE:
						keyout(key("status.para.heal"), surnom);
						break;
					case POISON:
						keyout(key("status.poison.heal"), surnom);
						break;
					case SOMMEIL:
						keyout(key("status.sommeil.heal"), surnom);
						break;
					default:
						break;
					
					}
				}
				
				
			}
		
		
		return false;
	}
	
	public Item hold(Item item){
		Item ancien = (Item) held.clone();
		held = item;
		return ancien;
	}
	
	public void traded(){
		expBoost = 1.5f;
		if(espece.getEvolType() instanceof E_Trade){
			evolve();
		}
	}
	
	public void toolEvTrade(){
		if(espece.getEvolType() instanceof E_Trade){
			evolve();
		}
	}
	
	public void evolve(){
		boolean changeName = (surnom.equals(espece.getSurnom()));
		this.espece = this.espece.getEvolution();
		calcStats(espece);
		fosout("%o évolue en %o!", surnom, espece.getSurnom());
		if(changeName){
			surnom = espece.getSurnom();
		}
	}
	
	//Les getters
	
	public synchronized final String getSurnom() {
		return surnom;
	}
	public synchronized final int getAtkIV() {
		return atkIV;
	}
	public synchronized final int getDefIV() {
		return defIV;
	}
	public synchronized final int getAtkSpeIV() {
		return atkSpeIV;
	}
	public synchronized final int getDefSpeIV() {
		return defSpeIV;
	}
	public synchronized final int getVitIV() {
		return vitIV;
	}
	public synchronized final int getPvIV() {
		return pvIV;
	}
	public synchronized final int getAtkEV() {
		return atkEV;
	}
	public synchronized final int getDefEV() {
		return defEV;
	}
	public synchronized final int getAtkSpeEV() {
		return atkSpeEV;
	}
	public synchronized final int getDefSpeEV() {
		return defSpeEV;
	}
	public synchronized final int getVitEV() {
		return vitEV;
	}
	public synchronized final int getPvEV() {
		return pvEV;
	}
	public synchronized final int getStatATK() {
		return statATK;
	}
	public synchronized final int getStatDEF() {
		return statDEF;
	}
	public synchronized final int getStatATKSPE() {
		return statATKSPE;
	}
	public synchronized final int getStatDEFSPE() {
		return statDEFSPE;
	}
	public synchronized final int getStatVIT() {
		return statVIT;
	}
	public synchronized final int getStatESQ() {
		return statESQ;
	}
	public synchronized final float getStatPRE() {
		return statPRE;
	}
	public synchronized final int getStatPV() {
		return statPV;
	}
	public synchronized final int getStatLove() {
		return statLove;
	}
	public synchronized final int getLevel() {
		return level;
	}
	public synchronized final Caractere getCaractere() {
		return caractere;
	}
	public synchronized final Attaque[] getAttaques() {
		return attaques;
	}
	public synchronized final Espece getEspece() {
		return espece;
	}
	public synchronized final int getPV(){
		return PV;
	}

	//les setters
	
	public synchronized void setStatESQ(int newStat) {
		statESQ = newStat;
	}
	public synchronized void setStatPRE(float newStat) {
		statPRE = newStat;
	}
	//Permet de reset tout les stats.
	public synchronized void setStats(int[] stats){
		statATK = stats[0];
		statDEF = stats[1];
		statATKSPE = stats[2];
		statDEFSPE = stats[3];
		statVIT = stats[4];
		statPRE = 100;
		statESQ = 100;
		type1 = espece.getType1();
		type2 = espece.getType2();
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + PV;
		result = prime * result + atkIV;
		result = prime * result + atkSpeIV;
		result = prime * result + ((caractere == null) ? 0 : caractere.hashCode());
		result = prime * result + defIV;
		result = prime * result + defSpeIV;
		result = prime * result + ((espece == null) ? 0 : espece.hashCode());
		result = prime * result + pvIV;
		result = prime * result + ((surnom == null) ? 0 : surnom.hashCode());
		result = prime * result + ((talent == null) ? 0 : talent.hashCode());
		result = prime * result + ((type1 == null) ? 0 : type1.hashCode());
		result = prime * result + ((type2 == null) ? 0 : type2.hashCode());
		result = prime * result + vitIV;
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
		if (!(obj instanceof Pokemon)) {
			return false;
		}
		Pokemon other = (Pokemon) obj;
		if (PV != other.PV) {
			return false;
		}
		if (atkIV != other.atkIV) {
			return false;
		}
		if (atkSpeIV != other.atkSpeIV) {
			return false;
		}
		if (caractere != other.caractere) {
			return false;
		}
		if (defIV != other.defIV) {
			return false;
		}
		if (defSpeIV != other.defSpeIV) {
			return false;
		}
		if (espece == null) {
			if (other.espece != null) {
				return false;
			}
		} else if (!espece.equals(other.espece)) {
			return false;
		}
		if (pvIV != other.pvIV) {
			return false;
		}
		if (surnom == null) {
			if (other.surnom != null) {
				return false;
			}
		} else if (!surnom.equals(other.surnom)) {
			return false;
		}
		if (talent == null) {
			if (other.talent != null) {
				return false;
			}
		} else if (!talent.equals(other.talent)) {
			return false;
		}
		if (type1 != other.type1) {
			return false;
		}
		if (type2 != other.type2) {
			return false;
		}
		if (vitIV != other.vitIV) {
			return false;
		}
		return true;
	}
	//Oh! Un getter intrus! On peut dire qu'il a du... TALENT!
	public Talent getTalent() {
		return talent;
	}
	public void setTalent(Talent talent) {
		this.talent = talent;
	}
	public void setSurnom(String surnom) {
		this.surnom = surnom;
	}
	public void setType1(Type type1) {
		this.type1 = type1;
	}
	public void setType2(Type type2) {
		this.type2 = type2;
	}
	public synchronized Type getType1(){
		return type1;
	}
	public synchronized Type getType2(){
		return type2;
	}
	public synchronized void setATK(int newStat){
		statATK = newStat;
	}
	public synchronized void setDEF(int newStat){
		statDEF = newStat;
	}
	public synchronized void setATKSPE(int newStat){
		statATKSPE = newStat;
	}
	public synchronized void setDEFSPE(int newStat){
		statDEFSPE = newStat;
	}
	public synchronized void setVIT(int newStat){
		statVIT = newStat;
	}
	public synchronized void attacked(int pvPerdus){
		this.PV = PV  - pvPerdus;
		PV = (PV < 0) ? 0 : PV;
		
	}
	//Les methodes suivantes permettent de modifier les statistiques en suivant les niveaux prédefinis. Il retoure false si les statistiques étaient déjà au plus haut ou plus bas.
	public boolean changeATK(int power) {
		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(atkChange){
				case -6:
					return false;
				case -5:
					
					statATK = Math.round(statATK / 1.16f);
					atkChange--;
					break;
				case -4:
					
					statATK = Math.round(statATK * 0.878788f);
					atkChange--;
					break;
				case -3:
					
					statATK = Math.round(statATK * 0.825f);
					atkChange--;
					break;
				case -2:
					
					statATK = Math.round(statATK / 1.25f);
					atkChange--;
					break;
				case -1:
					
					statATK = Math.round(statATK / 1.34f);
					atkChange--;
					break;
				case 0:
					
					statATK = Math.round(statATK * 0.67f);
					atkChange--;
					break;
				case 1:
					
					statATK = Math.round(statATK / 1.5f);
					atkChange--;
					break;
				case 2:
					
					statATK = Math.round(statATK * 0.75f);
					atkChange--;
					break;
				case 3:
					
					statATK = Math.round(statATK / 1.25f);
					atkChange--;
					break;
				case 4:
					
					statATK = Math.round(statATK / 1.2f);
					atkChange--;
					break;
				case 5:
					
					statATK = Math.round(statATK / 1.1667f);
					atkChange--;
					break;
				case 6:
					
					statATK = Math.round(statATK * 0.875f);
					atkChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(atkChange){
				case -6:
					
					statATK = Math.round(statATK * 1.16f);
					atkChange++;
					break;
				case -5:
					
					statATK = Math.round(statATK / 0.878788f);
					atkChange++;
					break;
				case -4:
					
					statATK = Math.round(statATK / 0.825f);
					atkChange++;
					break;
				case -3:
					
					statATK = Math.round(statATK * 1.25f);
					atkChange++;
					break;
				case -2:
					
					statATK = Math.round(statATK * 1.34f);
					atkChange++;
					break;
				case -1:
					
					statATK = Math.round(statATK / 0.67f);
					atkChange++;
					break;
				case 0:
					
					statATK = Math.round(statATK * 1.5f);
					atkChange++;
					break;
				case 1:
					
					statATK = Math.round(statATK / 0.75f);
					atkChange++;
					break;
				case 2:
					
					statATK = Math.round(statATK * 1.25f);
					atkChange++;
					break;
				case 3:
					
					statATK = Math.round(statATK * 1.2f);
					atkChange++;
					break;
				case 4:
					
					statATK = Math.round(statATK * 1.1667f);
					atkChange++;
					break;
				case 5:
					
					statATK = Math.round(statATK / 0.875f);
					atkChange++;
					break;
				case 6:
					return false;
				default:

				}
			}

		}

		return true;
	}
	public boolean changePRE(int power) {
		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(preChange){
				case -6:
					return false;
				case -5:
					
					statPRE = Math.round(statPRE * 0.888f);
					preChange--;
					break;
				case -4:
					
					statPRE = Math.round(statPRE / 1.144f);
					preChange--;
					break;
				case -3:
					
					statPRE = Math.round(statPRE * 0.858f);
					preChange--;
					break;
				case -2:
					
					statPRE = Math.round(statPRE / 1.2f);
					preChange--;
					break;
				case -1:
					
					statPRE = Math.round(statPRE / 1.25f);
					preChange--;
					break;
				case 0:
					
					statPRE = Math.round(statPRE * 0.75f);
					preChange--;
					break;
				case 1:
					
					statPRE = Math.round(statPRE / 1.333f);
					preChange--;
					break;
				case 2:
					
					statPRE = Math.round(statPRE * 0.799640f);
					preChange--;
					break;
				case 3:
					
					statPRE = Math.round(statPRE * 0.8335f);
					preChange--;
					break;
				case 4:
					
					statPRE = Math.round(statPRE / 1.1665f);
					preChange--;
					break;
				case 5:
					
					statPRE = Math.round(statPRE * 0.8747657f);
					preChange--;
					break;
				case 6:
					
					statPRE = Math.round(statPRE * 0.889f);
					preChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(preChange){
				case -6:
					
					statPRE = Math.round(statPRE / 0.888f);
					preChange++;
					break;
				case -5:
					
					statPRE = Math.round(statPRE * 1.144f);
					preChange++;
					break;
				case -4:
					
					statPRE = Math.round(statPRE / 0.858f);
					preChange++;
					break;
				case -3:
					
					statPRE = Math.round(statPRE * 1.2f);
					preChange++;
					break;
				case -2:
					
					statPRE = Math.round(statPRE * 1.25f);
					preChange++;
					break;
				case -1:
					
					statPRE = Math.round(statPRE / 0.75f);
					preChange++;
					break;
				case 0:
					
					statPRE = Math.round(statPRE * 1.333f);
					preChange++;
					break;
				case 1:
					
					statPRE = Math.round(statPRE / 0.799640f);
					preChange++;
					break;
				case 2:
					
					statPRE = Math.round(statPRE / 0.8335f);
					preChange++;
					break;
				case 3:
					
					statPRE = Math.round(statPRE * 1.1665f);
					preChange++;
					break;
				case 4:
					
					statPRE = Math.round(statPRE / 0.8747657f);
					preChange++;
					break;
				case 5:
					
					statPRE = Math.round(statPRE / 0.889f);
					preChange++;
					break;
				case 6:
					return false;
				default:

				}
			}

		}

		return true;
	}
	public boolean changeESQ(int power) {
		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(esqChange){
				case -6:
					return false;
				case -5:
					
					statESQ = Math.round(statESQ / 1.16f);
					esqChange--;
					break;
				case -4:
					
					statESQ = Math.round(statESQ * 0.878788f);
					esqChange--;
					break;
				case -3:
					
					statESQ = Math.round(statESQ * 0.825f);
					esqChange--;
					break;
				case -2:
					
					statESQ = Math.round(statESQ / 1.25f);
					esqChange--;
					break;
				case -1:
					
					statESQ = Math.round(statESQ / 1.34f);
					esqChange--;
					break;
				case 0:
					
					statESQ = Math.round(statESQ * 0.67f);
					esqChange--;
					break;
				case 1:
					
					statESQ = Math.round(statESQ / 1.5f);
					esqChange--;
					break;
				case 2:
					
					statESQ = Math.round(statESQ * 0.75f);
					esqChange--;
					break;
				case 3:
					
					statESQ = Math.round(statESQ / 1.25f);
					esqChange--;
					break;
				case 4:
					
					statESQ = Math.round(statESQ / 1.2f);
					esqChange--;
					break;
				case 5:
					
					statESQ = Math.round(statESQ / 1.1667f);
					esqChange--;
					break;
				case 6:
					
					statESQ = Math.round(statESQ * 0.875f);
					esqChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(esqChange){
				case -6:
					
					statESQ = Math.round(statESQ * 1.16f);
					esqChange++;
					break;
				case -5:
					
					statESQ = Math.round(statESQ / 0.878788f);
					esqChange++;
					break;
				case -4:
					
					statESQ = Math.round(statESQ / 0.825f);
					esqChange++;
					break;
				case -3:
					
					statESQ = Math.round(statESQ * 1.25f);
					esqChange++;
					break;
				case -2:
					
					statESQ = Math.round(statESQ * 1.34f);
					esqChange++;
					break;
				case -1:
					
					statESQ = Math.round(statESQ / 0.67f);
					esqChange++;
					break;
				case 0:
					
					statESQ = Math.round(statESQ * 1.5f);
					esqChange++;
					break;
				case 1:
					
					statESQ = Math.round(statESQ / 0.75f);
					esqChange++;
					break;
				case 2:
					
					statESQ = Math.round(statESQ * 1.25f);
					esqChange++;
					break;
				case 3:
					
					statESQ = Math.round(statESQ * 1.2f);
					esqChange++;
					break;
				case 4:
					
					statESQ = Math.round(statESQ * 1.1667f);
					esqChange++;
					break;
				case 5:
					
					statESQ = Math.round(statESQ / 0.875f);
					esqChange++;
					break;
				case 6:
					return false;
				default:

				}
			}

		}

		return true;
	}
	public boolean changeDEF(int power) {
		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(defChange){
				case -6:
					return false;
				case -5:
					
					statDEF = Math.round(statDEF / 1.16f);
					defChange--;
					break;
				case -4:
					
					statDEF = Math.round(statDEF * 0.878788f);
					defChange--;
					break;
				case -3:
					
					statDEF = Math.round(statDEF * 0.825f);
					defChange--;
					break;
				case -2:
					
					statDEF = Math.round(statDEF / 1.25f);
					defChange--;
					break;
				case -1:
					
					statDEF = Math.round(statDEF / 1.34f);
					defChange--;
					break;
				case 0:
					
					statDEF = Math.round(statDEF * 0.67f);
					defChange--;
					break;
				case 1:
					
					statDEF = Math.round(statDEF / 1.5f);
					defChange--;
					break;
				case 2:
					
					statDEF = Math.round(statDEF * 0.75f);
					defChange--;
					break;
				case 3:
					
					statDEF = Math.round(statDEF / 1.25f);
					defChange--;
					break;
				case 4:
					
					statDEF = Math.round(statDEF / 1.2f);
					defChange--;
					break;
				case 5:
					
					statDEF = Math.round(statDEF / 1.1667f);
					defChange--;
					break;
				case 6:
					
					statDEF = Math.round(statDEF * 0.875f);
					defChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(defChange){
				case -6:
					
					statDEF = Math.round(statDEF * 1.16f);
					defChange++;
					break;
				case -5:
					
					statDEF = Math.round(statDEF / 0.878788f);
					defChange++;
					break;
				case -4:
					
					statDEF = Math.round(statDEF / 0.825f);
					defChange++;
					break;
				case -3:
					
					statDEF = Math.round(statDEF * 1.25f);
					defChange++;
					break;
				case -2:
					
					statDEF = Math.round(statDEF * 1.34f);
					defChange++;
					break;
				case -1:
					
					statDEF = Math.round(statDEF / 0.67f);
					defChange++;
					break;
				case 0:
					
					statDEF = Math.round(statDEF * 1.5f);
					defChange++;
					break;
				case 1:
					
					statDEF = Math.round(statDEF / 0.75f);
					defChange++;
					break;
				case 2:
					
					statDEF = Math.round(statDEF * 1.25f);
					defChange++;
					break;
				case 3:
					
					statDEF = Math.round(statDEF * 1.2f);
					defChange++;
					break;
				case 4:
					
					statDEF = Math.round(statDEF * 1.1667f);
					defChange++;
					break;
				case 5:
					
					statDEF = Math.round(statDEF / 0.875f);
					defChange++;
					break;
				case 6:
					return false;
					
				default:

				}
			}

		}
		return true;

	}
	public boolean changeATKSPE(int power) {
		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(atkSpeChange){
				case -6:
					return false;
				case -5:
					
					statATKSPE = Math.round(statATKSPE / 1.16f);
					atkSpeChange--;
					break;
				case -4:
					
					statATKSPE = Math.round(statATKSPE * 0.878788f);
					atkSpeChange--;
					break;
				case -3:
					
					statATKSPE = Math.round(statATKSPE * 0.825f);
					atkSpeChange--;
					break;
				case -2:
					
					statATKSPE = Math.round(statATKSPE / 1.25f);
					atkSpeChange--;
					break;
				case -1:
					
					statATKSPE = Math.round(statATKSPE / 1.34f);
					atkSpeChange--;
					break;
				case 0:
					
					statATKSPE = Math.round(statATKSPE * 0.67f);
					atkSpeChange--;
					break;
				case 1:
					
					statATKSPE = Math.round(statATKSPE / 1.5f);
					atkSpeChange--;
					break;
				case 2:
					
					statATKSPE = Math.round(statATKSPE * 0.75f);
					atkSpeChange--;
					break;
				case 3:
					
					statATKSPE = Math.round(statATKSPE / 1.25f);
					atkSpeChange--;
					break;
				case 4:
					
					statATKSPE = Math.round(statATKSPE / 1.2f);
					atkSpeChange--;
					break;
				case 5:
					
					statATKSPE = Math.round(statATKSPE / 1.1667f);
					atkSpeChange--;
					break;
				case 6:
					
					statATKSPE = Math.round(statATKSPE * 0.875f);
					atkSpeChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(atkSpeChange){
				case -6:
					
					statATKSPE = Math.round(statATKSPE * 1.16f);
					atkSpeChange++;
					break;
				case -5:
					
					statATKSPE = Math.round(statATKSPE / 0.878788f);
					atkSpeChange++;
					break;
				case -4:
					
					statATKSPE = Math.round(statATKSPE / 0.825f);
					atkSpeChange++;
					break;
				case -3:
					
					statATKSPE = Math.round(statATKSPE * 1.25f);
					atkSpeChange++;
					break;
				case -2:
					
					statATKSPE = Math.round(statATKSPE * 1.34f);
					atkSpeChange++;
					break;
				case -1:
					
					statATKSPE = Math.round(statATKSPE / 0.67f);
					atkSpeChange++;
					break;
				case 0:
					
					statATKSPE = Math.round(statATKSPE * 1.5f);
					atkSpeChange++;
					break;
				case 1:
					
					statATKSPE = Math.round(statATKSPE / 0.75f);
					atkSpeChange++;
					break;
				case 2:
					
					statATKSPE = Math.round(statATKSPE * 1.25f);
					atkSpeChange++;
					break;
				case 3:
					
					statATKSPE = Math.round(statATKSPE * 1.2f);
					atkSpeChange++;
					break;
				case 4:
					
					statATKSPE = Math.round(statATKSPE * 1.1667f);
					atkSpeChange++;
					break;
				case 5:
					
					statATKSPE = Math.round(statATKSPE / 0.875f);
					atkSpeChange++;
					break;
				case 6:
					return false;
				default:

				}
			}

		}
		return true;

	}
	public boolean changeDEFSPE(int power) {
		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(defSpeChange){
				case -6:
					return false;
				case -5:
					
					statDEFSPE = Math.round(statDEFSPE / 1.16f);
					defSpeChange--;
					break;
				case -4:
					
					statDEFSPE = Math.round(statDEFSPE * 0.878788f);
					defSpeChange--;
					break;
				case -3:
					
					statDEFSPE = Math.round(statDEFSPE * 0.825f);
					defSpeChange--;
					break;
				case -2:
					
					statDEFSPE = Math.round(statDEFSPE / 1.25f);
					defSpeChange--;
					break;
				case -1:
					
					statDEFSPE = Math.round(statDEFSPE / 1.34f);
					defSpeChange--;
					break;
				case 0:
					
					statDEFSPE = Math.round(statDEFSPE * 0.67f);
					defSpeChange--;
					break;
				case 1:
					
					statDEFSPE = Math.round(statDEFSPE / 1.5f);
					defSpeChange--;
					break;
				case 2:
					
					statDEFSPE = Math.round(statDEFSPE * 0.75f);
					defSpeChange--;
					break;
				case 3:
					
					statDEFSPE = Math.round(statDEFSPE / 1.25f);
					defSpeChange--;
					break;
				case 4:
					
					statDEFSPE = Math.round(statDEFSPE / 1.2f);
					defSpeChange--;
					break;
				case 5:
					
					statDEFSPE = Math.round(statDEFSPE / 1.1667f);
					defSpeChange--;
					break;
				case 6:
					
					statDEFSPE = Math.round(statDEFSPE * 0.875f);
					defSpeChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(defSpeChange){
				case -6:
					
					statDEFSPE = Math.round(statDEFSPE * 1.16f);
					defSpeChange++;
					break;
				case -5:
					
					statDEFSPE = Math.round(statDEFSPE / 0.878788f);
					defSpeChange++;
					break;
				case -4:
					
					statDEFSPE = Math.round(statDEFSPE / 0.825f);
					defSpeChange++;
					break;
				case -3:
					
					statDEFSPE = Math.round(statDEFSPE * 1.25f);
					defSpeChange++;
					break;
				case -2:
					
					statDEFSPE = Math.round(statDEFSPE * 1.34f);
					defSpeChange++;
					break;
				case -1:
					
					statDEFSPE = Math.round(statDEFSPE / 0.67f);
					defSpeChange++;
					break;
				case 0:
					
					statDEFSPE = Math.round(statDEFSPE * 1.5f);
					defSpeChange++;
					break;
				case 1:
					
					statDEFSPE = Math.round(statDEFSPE / 0.75f);
					defSpeChange++;
					break;
				case 2:
					
					statDEFSPE = Math.round(statDEFSPE * 1.25f);
					defSpeChange++;
					break;
				case 3:
					
					statDEFSPE = Math.round(statDEFSPE * 1.2f);
					defSpeChange++;
					break;
				case 4:
					
					statDEFSPE = Math.round(statDEFSPE * 1.1667f);
					defSpeChange++;
					break;
				case 5:
					
					statDEFSPE = Math.round(statDEFSPE / 0.875f);
					defSpeChange++;
					break;
				case 6:
					return false;
				default:

				}
			}

		}
return true;

	}
	public boolean changeVIT(int power) {

		if(power < 0){
			for(int i = 0; i > power; i--){
				switch(vitChange){
				case -6:
					return false;
				case -5:
					
					statVIT = Math.round(statVIT / 1.16f);
					
					vitChange--;
					break;
				case -4:
					
					statVIT = Math.round(statVIT * 0.878788f);
					vitChange--;
					break;
				case -3:
					
					statVIT = Math.round(statVIT * 0.825f);
					vitChange--;
					break;
				case -2:
					
					statVIT = Math.round(statVIT / 1.25f);
					vitChange--;
					break;
				case -1:
					
					statVIT = Math.round(statVIT / 1.34f);
					vitChange--;
					break;
				case 0:
					
					statVIT = Math.round(statVIT * 0.67f);
					vitChange--;
					break;
				case 1:
					
					statVIT = Math.round(statVIT / 1.5f);
					vitChange--;
					break;
				case 2:
					
					statVIT = Math.round(statVIT * 0.75f);
					vitChange--;
					break;
				case 3:
					
					statVIT = Math.round(statVIT / 1.25f);
					vitChange--;
					break;
				case 4:
					
					statVIT = Math.round(statVIT / 1.2f);
					vitChange--;
					break;
				case 5:
					
					statVIT = Math.round(statVIT / 1.1667f);
					vitChange--;
					break;
				case 6:
					
					statVIT = Math.round(statVIT * 0.875f);
					vitChange--;
					break;
				default:

				}
			}
		}else{

			for(int i = 0; i > power; i--){
				switch(vitChange){
				case -6:
					
					statVIT = Math.round(statVIT * 1.16f);
					vitChange++;
					break;
				case -5:
					
					statVIT = Math.round(statVIT / 0.878788f);
					vitChange++;
					break;
				case -4:
					
					statVIT = Math.round(statVIT / 0.825f);
					vitChange++;
					break;
				case -3:
					
					statVIT = Math.round(statVIT * 1.25f);
					vitChange++;
					break;
				case -2:
					
					statVIT = Math.round(statVIT * 1.34f);
					vitChange++;
					break;
				case -1:
					
					statVIT = Math.round(statVIT / 0.67f);
					vitChange++;
					break;
				case 0:
					
					statVIT = Math.round(statVIT * 1.5f);
					vitChange++;
					break;
				case 1:
					
					statVIT = Math.round(statVIT / 0.75f);
					vitChange++;
					break;
				case 2:
					
					statVIT = Math.round(statVIT * 1.25f);
					vitChange++;
					break;
				case 3:
					
					statVIT = Math.round(statVIT * 1.2f);
					vitChange++;
					break;
				case 4:
					
					statVIT = Math.round(statVIT * 1.1667f);
					vitChange++;
					break;
				case 5:
					
					statVIT = Math.round(statVIT / 0.875f);
					vitChange++;
					break;
				case 6:
					return false;
				default:

				}
			}

		}
		return true;

	}
	/**
	 * Permet de changer le status du pokemon en suivant certaines regles.
	 * @param status - Le nouveau status du pokemon
	 * @return - Si le status a bien été change
	 */
	public boolean setStatus(Status status){
		
		if(status == Status.BRULURE){
			changeATK(-1);
		}
		else if(status == Status.AUCUN && this.status == Status.BRULURE){
			changeATK(1);
		}
		else if(status == Status.BRULURE && this.status == Status.BRULURE){
			System.out.println(surnom + " est déjà brulé!");
			return false;		}
		else if(status == Status.PARALYSIE){
			changeVIT(-1);
		}else if(status == Status.AUCUN && this.status == Status.PARALYSIE){
			changeVIT(1);
		}else if(status == Status.SOMMEIL && this.status == Status.SOMMEIL){
			System.out.println("Mais " + surnom + " dort déjà!");
			return false;
		}else if(status == Status.PARALYSIE && this.status == Status.PARALYSIE){
			System.out.println(surnom + " est déjà paralysé!");
			return false;
		}else if(status == Status.GEL && this.status == Status.GEL){
			System.out.println(surnom + " est déjà gelé!");
			return false;
		}else if(status == Status.POISON && this.status == Status.POISON){
			System.out.println(surnom + " est déjà empoisonné!");
			return false;
		}else if(this.status != Status.AUCUN && status != Status.AUCUN){
			System.out.println("Mais " + surnom + " a déjà un status!");
			return false;
		}
		this.status = status;
		return true;
	}
	
	public Status getStatus(){
		return status;
	}
	public void heal(int PV){
		if((PV + this.PV) > statPV){
			this.PV = statPV;
		}else{
			this.PV+=PV;
		}
	}

	@Override
	public String toString() {
		return "Pokemon [surnom=" + surnom + ", atkIV=" + atkIV + ", defIV=" + defIV + ", atkSpeIV=" + atkSpeIV
				+ ", defSpeIV=" + defSpeIV + ", vitIV=" + vitIV + ", pvIV=" + pvIV + ", atkEV=" + atkEV + ", defEV="
				+ defEV + ", atkSpeEV=" + atkSpeEV + ", defSpeEV=" + defSpeEV + ", vitEV=" + vitEV + ", pvEV=" + pvEV
				+ ", statATK=" + statATK + ", statDEF=" + statDEF + ", statATKSPE=" + statATKSPE + ", statDEFSPE="
				+ statDEFSPE + ", statVIT=" + statVIT + ", statESQ=" + statESQ + ", statPRE=" + statPRE + ", statPV="
				+ statPV + ", statLove=" + statLove + ", atkChange=" + atkChange + ", defChange=" + defChange
				+ ", defSpeChange=" + defSpeChange + ", atkSpeChange=" + atkSpeChange + ", esqChange=" + esqChange
				+ ", preChange=" + preChange + ", vitChange=" + vitChange + ", level=" + level + ", caractere="
				+ caractere + ", attaques=" + Arrays.toString(attaques) + ", espece=" + espece + ", PV=" + PV
				+ ", status=" + status + ", talent=" + talent + ", type1=" + type1 + ", type2=" + type2 + ", exp=" + exp
				+ ", toNextLevel=" + toNextLevel + ", expBoost=" + expBoost + ", confus=" + confus + ", peur=" + peur
				+ ", amour=" + amour + ", vampigraine=" + vampigraine + ", malediction=" + malediction + ", held="
				+ held + "]";
	}
	

}
