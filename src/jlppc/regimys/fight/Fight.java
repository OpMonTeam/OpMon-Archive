package jlppc.regimys.fight;

import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.utils.FormattedString;
/**
 * La classe qui s'occupe de tout ce qui est combat.
 * @author Jlppc
 *
 */
public class Fight {
	public static int oldStats[][] = new int[2][5];
	public static void fight(Pokemon atk, Pokemon def){
		oldStats[0][0] = new Integer(atk.getStatATK());
		oldStats[0][1] = new Integer(atk.getStatDEF());
		oldStats[0][2] = new Integer(atk.getStatATKSPE());
		oldStats[0][3] = new Integer(atk.getStatDEFSPE());
		oldStats[0][4] = new Integer(atk.getStatVIT());

		oldStats[1][0] = new Integer(def.getStatATK());
		oldStats[1][1] = new Integer(def.getStatDEF());
		oldStats[1][2] = new Integer(def.getStatATKSPE());
		oldStats[1][3] = new Integer(def.getStatDEFSPE());
		oldStats[1][4] = new Integer(def.getStatVIT());
		atk.setStatESQ(100);
		atk.setStatPRE(100);
		def.setStatESQ(100);
		def.setStatPRE(100);
		boolean sameAtk = false;
		boolean sameDef = false;
		System.out.println("Combat : " + atk.getSurnom() + " contre " + def.getSurnom());
		boolean atkCanAttack = true;
		boolean defCanAttack = true;
		int atkCountDownSommeil = 0;
		boolean atkSommeil = false;
		int defCountDownSommeil = 0;
		boolean defSommeil = false;
		int atkCountDownConf = 0;
		boolean atkConf = false;
		int defCountDownConf = 0;
		boolean defConf = false;
		boolean endOfMatch = false;
		int attaqueAtk = 0;
		int attaqueDef = 0; 
		while(!endOfMatch){

			if(!sameAtk){
				boolean ok = false;
				System.out.print("Attaquant, choisissez votre attaque ( 1 a 4) : ");
				attaqueAtk = Start.sc.nextInt() - 1;
				while(!ok){
					if(((attaqueAtk < atk.getAttaques().length && attaqueAtk > -1) ? (atk.getAttaques()[attaqueAtk].getPp() <= 0) : true)){
						System.out.println("Mauvaise attaque ou plus de PP. Reesayez :");
						attaqueAtk = Start.sc.nextInt() - 1;
					}else{
						break;
					}
				}

			}else{
				sameAtk = false;
			}

			if(!sameDef){
				attaqueDef = Start.rand.nextInt(def.getAttaques().length);
				boolean ok = false;
				while(!ok){
					if(def.getAttaques()[attaqueDef].getPp() <= 0){
						attaqueDef = Start.rand.nextInt(def.getAttaques().length);
					}else{
						break;
					}
				}
			}


			System.out.println(atk.getStatVIT() > def.getStatVIT());
			System.out.println(atk.getAttaques()[attaqueAtk].getPriorite() > def.getAttaques()[attaqueDef].getPriorite());
			if(atk.getStatVIT() > def.getStatVIT() || atk.getAttaques()[attaqueAtk].getPriorite() > def.getAttaques()[attaqueDef].getPriorite()){
				atkCanAttack = true;
				if(atk.getStatus() == Status.GEL){
					if(Start.rand.nextInt(5) == 2){
						System.out.println(atk.getSurnom() + " est degelé!");
						atk.setStatus(Status.AUCUN);
						atkCanAttack = true;
					}else{
						System.out.println(atk.getSurnom() + " est gelé. Il ne peut pas attaquer.");
						atkCanAttack = false;
					}
				}else if(atk.getStatus() == Status.SOMMEIL){
					if(atkCountDownSommeil <= 0 && atkSommeil == false){
						atkCountDownSommeil = Start.rand.nextInt(3);
						atkSommeil = true;
						if(atkCountDownSommeil <= 0){
							System.out.println(atk.getSurnom() + " se reveille!");
							atkCanAttack = true;
							atkSommeil = false;
							atk.setStatus(Status.AUCUN);
						}else{
							System.out.println(atk.getSurnom() + " dort profondement.");
							atkCanAttack = false;
							atkCountDownSommeil--;
						}
					}else if(atkSommeil == true){
						if(atkCountDownSommeil <= 0){
							System.out.println(atk.getSurnom() + " se reveille!");
							atkCanAttack = true;
							atkSommeil = false;
							atk.setStatus(Status.AUCUN);
						}else{
							System.out.println(atk.getSurnom() + " dort profondement.");
							atkCanAttack = false;
							atkCountDownSommeil--;
						}
					}

				}else if(atk.getStatus() == Status.PARALYSIE){
					if(Start.rand.nextInt(4) == 2){
						System.out.println(def.getSurnom() + " est paralysé, il ne peut pas attaquer.");
						atkCanAttack = false;
					}else{
						System.out.println("Malgré sa parlysie, " + def.getSurnom() + " parvient a attaquer!");
					}
				}else if(atk.confus){
					if(atkCountDownConf == 0 && atkConf == false){
						atkCountDownConf = Start.rand.nextInt(4);
						atkConf = true;
						if(atkCountDownConf <= 0){
							System.out.println(atk.getSurnom() + " n'est plus confus!");
							atkCanAttack = true;
							atkConf = false;
							atk.setStatus(Status.AUCUN);
						}else{
							System.out.println(atk.getSurnom() + " est confus. Il pert " + (atk.getStatPV() / 8) + " pv.");
							atk.attacked(atk.getStatPV() / 8);
							atkCanAttack = false;
							atkCountDownConf--;
						}
					}else if(atkConf == true){
						if(atkCountDownConf <= 0){
							System.out.println(atk.getSurnom() + " n'est plus confus!");
							atkCanAttack = true;
							atkConf = false;
							atk.setStatus(Status.AUCUN);
						}else{
							if(Start.rand.nextInt(2) == 1){
								System.out.println(atk.getSurnom() + " est confus. Il pert " + (atk.getStatPV() / 8) + " pv.");
								atk.attacked(atk.getStatPV() / 8);
								atkCanAttack = false;
							}else{
								FormattedString.outPrintln("Malgré sa confusion, %o peut attaquer!", atk.getSurnom());
							}

							atkCountDownConf--;
						}
					}
				}
				if(atkCanAttack){
					try {
						atk.getAttaques()[attaqueAtk].attack(atk, def);
					} catch (SameAtkPartTwo e) {
						sameAtk = true;
					}finally{
						if(def.getPV() <= 0 || atk.getPV() <= 0){
							endOfMatch = true;
							break;
						}
					}


				}

				defCanAttack = true;
				if(def.getStatus() == Status.GEL){
					if(Start.rand.nextInt(5) == 2){
						System.out.println(def.getSurnom() + " est degelé!");
						def.setStatus(Status.AUCUN);
						defCanAttack = true;
					}else{
						System.out.println(def.getSurnom() + " est gelé. Il ne peut pas attaquer.");
						defCanAttack = false;
					}
				}else if(def.getStatus() == Status.SOMMEIL){
					if(defCountDownSommeil <= 0 && defSommeil == false){
						defCountDownSommeil = Start.rand.nextInt(3);
						if(defCountDownSommeil <= 0){
							System.out.println(def.getSurnom() + " se reveille!");
							defCanAttack = true;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " dort profondement.");
							defCanAttack = false;
							atkCountDownSommeil--;
						}
					}else if(defSommeil == true){
						if(defCountDownSommeil <= 0){
							System.out.println(def.getSurnom() + " se reveille!");
							defCanAttack = true;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " dort profondement.");
							defCanAttack = false;
							atkCountDownSommeil--;
						}
					}else if(atk.getStatus() == Status.PARALYSIE){
						if(Start.rand.nextInt(4) == 2){
							System.out.println(def.getSurnom() + " est paralysé, il ne peut pas attaquer.");
							defCanAttack = false;
						}else{
							System.out.println("Malgré sa parlysie, " + def.getSurnom() + " parvient a attaquer!");
						}
					}

				}else if(def.getStatus() == Status.PARALYSIE){
					if(Start.rand.nextInt(4) == 2){
						System.out.println(def.getSurnom() + " est paralysé, il ne peut pas attaquer.");
						defCanAttack = false;
					}else{
						System.out.println("Malgré sa parlysie, " + def.getSurnom() + " parvient a attaquer!");
						defCanAttack = true;
					}
				}else if(def.peur){
					defCanAttack = false;
					FormattedString.outPrintln("%o à trop peur pour bouger!", def.getSurnom());
					def.peur = false;
				}else if(def.confus){
					if(defCountDownConf == 0 && defConf == false){
						defCountDownConf = Start.rand.nextInt(4);
						defConf = true;
						if(defCountDownConf <= 0){
							System.out.println(def.getSurnom() + " n'est plus confus!");
							defCanAttack = true;
							defConf = false;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " est confus. Il pert " + (def.getStatPV() / 8) + " pv.");
							def.attacked(def.getStatPV() / 8);
							defCanAttack = false;
							defCountDownConf--;
						}
					}else if(defConf == true){
						if(defCountDownConf <= 0){
							System.out.println(def.getSurnom() + " n'est plus confus!");
							defCanAttack = true;
							defConf = false;
							def.setStatus(Status.AUCUN);
						}else{
							if(Start.rand.nextInt(2) == 1){
								System.out.println(def.getSurnom() + " est confus. Il pert " + (def.getStatPV() / 8) + " pv.");
								def.attacked(def.getStatPV() / 8);
								defCanAttack = false;
							}else{
								FormattedString.outPrintln("Malgré sa confusion, %o peut attaquer!", def.getSurnom());
							}

							defCountDownConf--;
						}
					}
				}
				if(defCanAttack){

					try {
						def.getAttaques()[attaqueDef].attack(def, atk);
					} catch (SameAtkPartTwo e) {
						sameDef = true;
					}

				}








			}else{
				defCanAttack = true;
				if(def.getStatus() == Status.GEL){
					if(Start.rand.nextInt(5) == 2){
						System.out.println(def.getSurnom() + " est degelé!");
						def.setStatus(Status.AUCUN);
						defCanAttack = true;
					}else{
						System.out.println(def.getSurnom() + " est gelé. Il ne peut pas attaquer.");
						defCanAttack = false;
					}
				}else if(def.getStatus() == Status.SOMMEIL){
					System.err.println(defCountDownSommeil);
					if(defCountDownSommeil <= 0 && defSommeil == false){
						defCountDownSommeil = Start.rand.nextInt(3);
						System.err.println(defCountDownSommeil);
						defSommeil = true;
						if(defCountDownSommeil <= 0){
							System.out.println(def.getSurnom() + " se reveille!");
							defCanAttack = true;
							defSommeil = false;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " dort profondement.");
							defCanAttack = false;
							atkCountDownSommeil--;
						}
					}else if(defSommeil == true){
						System.err.println(defCountDownSommeil);
						if(defCountDownSommeil <= 0){
							System.out.println(def.getSurnom() + " se reveille!");
							defCanAttack = true;
							defSommeil = false;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " dort profondement.");
							defCanAttack = false;
							defCountDownSommeil--;

						}
					}

				}else if(def.getStatus() == Status.PARALYSIE){
					if(Start.rand.nextInt(4) == 2){
						System.out.println(def.getSurnom() + " est paralysé, il ne peut pas attaquer.");
						defCanAttack = false;
					}else{
						System.out.println("Malgré sa parlysie, " + def.getSurnom() + " parvient a attaquer!");
					}
				}else if(def.confus){
					if(defCountDownConf == 0 && defConf == false){
						defCountDownConf = Start.rand.nextInt(4);
						defConf = true;
						if(defCountDownConf <= 0){
							System.out.println(def.getSurnom() + " n'est plus confus!");
							defCanAttack = true;
							defConf = false;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " est confus. Il pert " + (def.getStatPV() / 8) + " pv.");
							def.attacked(def.getStatPV() / 8);
							defCanAttack = false;
							defCountDownConf--;
						}
					}else if(defConf == true){
						if(defCountDownConf <= 0){
							System.out.println(def.getSurnom() + " n'est plus confus!");
							defCanAttack = true;
							defConf = false;
							def.setStatus(Status.AUCUN);
						}else{
							if(Start.rand.nextInt(2) == 1){
								System.out.println(def.getSurnom() + " est confus. Il pert " + (def.getStatPV() / 8) + " pv.");
								def.attacked(def.getStatPV() / 8);
								defCanAttack = false;
							}else{
								FormattedString.outPrintln("Malgré sa confusion, %o peut attaquer!", def.getSurnom());
							}

							defCountDownConf--;
						}
					}
				}
				if(defCanAttack){
					try {
						def.getAttaques()[attaqueDef].attack(def, atk);
					} catch (SameAtkPartTwo e) {
						sameDef = true;
					}finally{
						if(def.getPV() <= 0 || atk.getPV() <= 0){
							endOfMatch = true;
							break;
						}
					}



				}

				atkCanAttack = true;
				if(atk.getStatus() == Status.GEL){
					if(Start.rand.nextInt(5) == 2){
						System.out.println(atk.getSurnom() + " est degelé!");
						atk.setStatus(Status.AUCUN);
						atkCanAttack = true;
					}else{
						System.out.println(atk.getSurnom() + " est gelé. Il ne peut pas attaquer.");
						atkCanAttack = false;
					}
				}else if(atk.getStatus() == Status.SOMMEIL){
					if(atkCountDownSommeil == 0 && atkSommeil == false){
						atkCountDownSommeil = Start.rand.nextInt(3);
						atkSommeil = true;
						if(atkCountDownSommeil <= 0){
							System.out.println(atk.getSurnom() + " se reveille!");
							atkCanAttack = true;
							atkSommeil = false;
							atk.setStatus(Status.AUCUN);
						}else{
							System.out.println(atk.getSurnom() + " dort profondement.");
							atkCanAttack = false;
							atkCountDownSommeil--;
						}
					}else if(atkSommeil == true){
						if(atkCountDownSommeil <= 0){
							System.out.println(atk.getSurnom() + " se reveille!");
							atkCanAttack = true;
							atkSommeil = false;
							atk.setStatus(Status.AUCUN);
						}else{
							System.out.println(atk.getSurnom() + " dort profondement.");
							atkCanAttack = false;
							atkCountDownSommeil--;
						}
					}

				}else if(atk.getStatus() == Status.PARALYSIE){
					if(Start.rand.nextInt(4) == 2){
						System.out.println(def.getSurnom() + " est paralysé, il ne peut pas attaquer.");
						defCanAttack = false;
					}else{
						System.out.println("Malgré sa parlysie, " + def.getSurnom() + " parvient a attaquer!");
					}
				}else if(atk.peur){
					atkCanAttack = false;
					FormattedString.outPrintln("%o à trop peur pour bouger!", atk.getSurnom());
					atk.peur = false;
				}else if(atk.confus){
					if(atkCountDownConf == 0 && atkConf == false){
						atkCountDownConf = Start.rand.nextInt(4);
						atkConf = true;
						if(atkCountDownConf <= 0){
							System.out.println(atk.getSurnom() + " n'est plus confus!");
							atkCanAttack = true;
							atkConf = false;
							atk.setStatus(Status.AUCUN);
						}else{
							System.out.println(atk.getSurnom() + " est confus. Il pert " + (atk.getStatPV() / 8) + " pv.");
							atk.attacked(atk.getStatPV() / 8);
							atkCanAttack = false;
							atkCountDownConf--;
						}
					}else if(atkConf == true){
						if(atkCountDownConf <= 0){
							System.out.println(atk.getSurnom() + " n'est plus confus!");
							atkCanAttack = true;
							atkConf = false;
							atk.setStatus(Status.AUCUN);
						}else{
							if(Start.rand.nextInt(2) == 1){
								System.out.println(atk.getSurnom() + " est confus. Il pert " + (atk.getStatPV() / 8) + " pv.");
								atk.attacked(atk.getStatPV() / 8);
								atkCanAttack = false;
							}else{
								FormattedString.outPrintln("Malgré sa confusion, %o peut attaquer!", atk.getSurnom());
							}

							atkCountDownConf--;
						}
					}
				}

				if(atkCanAttack){

					try {
						atk.getAttaques()[attaqueAtk].attack(atk, def);
					} catch (SameAtkPartTwo e) {
						sameAtk = true;
					}



				}
				if(def.getPV() <= 0 || atk.getPV() <= 0){
					endOfMatch = true;
					break;
				}
				switch(atk.getStatus()){
				case AUCUN:
					break;
				case BRULURE:
					atk.attacked((atk.getStatPV() / 8));
					System.out.println(atk.getSurnom() + " souffre de sa brulure! Il perd " + (atk.getStatPV() / 8) + " pv!");
					break;
				case GEL:
					break;
				case PARALYSIE:
					break;
				case POISON:
					atk.attacked((atk.getStatPV() / 8));
					System.out.println(atk.getSurnom() + " souffre de son empoisonnement! Il perd " + (atk.getStatPV() / 8) + " pv!");
					break;
				case SOMMEIL:
					break;
				default:
					break;

				}
				


			}
			if(def.getPV() <= 0 || atk.getPV() <= 0){
				endOfMatch = true;
				break;
			}
		}
		if(def.getPV() <= 0 && atk.getPV() <= 0){
			System.out.println("Egalité!");
		}
		else if(def.getPV() <= 0 && atk.getPV() > 0){
			System.out.println(def.getSurnom() + " est K.O");
			System.out.println("L'attaquant " + atk.getSurnom() + " a gagné!");
		}else if(atk.getPV() <= 0 && def.getPV() > 0){
			System.out.println(atk.getSurnom() + " est K.O");
			System.out.println("Le defenseur " + def.getSurnom() + " a gagné!");
		}else{
			System.out.println("BUG. On sait pas qui a gagné.");
		}
		atk.setStats(oldStats[0]);
		def.setStats(oldStats[1]);
	}
}
