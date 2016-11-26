package jlppc.regimys.fight;

import jlppc.regimys.enums.Type;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;
import jlppc.regimys.objects.Espece;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.objects.Pokemon.Status;
import jlppc.regimys.objects.items.Item;
import jlppc.regimys.playercore.Equipe;
import jlppc.regimys.objects.items.I_Pokeball;
import jlppc.utils.FormattedString;
/**
 * La classe qui s'occupe de tout ce qui est combat.
 * @author Jlppc
 * TODO : Faire vampigraine
 */
public class Fight {
	public static int oldStats[][] = new int[2][5];
	public static Type oldTypes[][] = new Type[2][2];
	public static Espece oldEspece[] = new Espece[2];
	public static Attaque oldAttacks[][] = new Attaque[2][4];

	private static Object[] pokeFight(Pokemon atk, Pokemon def){
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
		
		oldTypes[0][0] = atk.getType1();
		oldTypes[0][1] = atk.getType2();
		oldTypes[1][0] = def.getType1();
		oldTypes[1][1] = def.getType2();
		oldEspece[0] = atk.getEspece();
		oldEspece[1] = def.getEspece();
		
		oldAttacks[0] = atk.getAttaques();
		oldAttacks[1] = def.getAttaques();
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
		boolean captured = false;
		int attaqueDef = 0; 
		while(!endOfMatch){
			FormattedString.outPrintln("%o a %o pv.", atk.getSurnom(), atk.getPV());
			FormattedString.outPrintln("%o a %o pv.", def.getSurnom(), def.getPV());
			if(!sameAtk){
				System.out.println("Choisissez une action (1 pour attaque, 2 pour Objet) :");
				int choix = Start.sc.nextInt();
				while(choix <= 0 || choix > 2){
					System.out.println("Action incorrecte, reesayez (1 pour attaque, 2 pour Objet): ");
					choix = Start.sc.nextInt();
				}

				if(choix == 1){
					boolean ok = false;
					System.out.print("Attaquant, choisissez votre attaque ( 1 a 4) : ");
					attaqueAtk = Start.sc.nextInt() - 1;
					while(!ok){
						if(((attaqueAtk < atk.getAttaques().length && attaqueAtk > -1) ? (atk.getAttaques()[attaqueAtk].getPp() <= 0) : true)){
							System.out.println("Vous devez choisir entre 1 et 4, ressayez :");
							attaqueAtk = Start.sc.nextInt() - 1;
						}else{
							break;
						}
					}
				}else if(choix == 2){
					System.out.println("Liste des items : ");
					int i = 0;
					for(int tem : Start.joueur.bag){
						if(tem != 0){
							System.out.println("Nom : " + Item.itemList.get(i).getName() + " ID : " + i + " Nombre : " + tem);
						}
						i++;
					}
					System.out.println("Entrez l'ID de l'item a utiliser :");
					int id = Start.sc.nextInt();
					while(Start.joueur.checkItem(id) == 0 || !Item.getItem(id).isUsableInFight()){;
					System.out.println("Item indisponible ou inutilisable en combat. Retentez : ");
					id = Start.sc.nextInt();
					}
					if(Item.getItem(id) instanceof I_Pokeball){
						I_Pokeball pkmn = (I_Pokeball) Item.getItem(id);
						if(def.captured(pkmn)){
							captured = true;
							break;
						}else{
							System.out.println("Oh non! Presque!");
						}
					}else{
						atk.itemUsed(Item.getItem(id));
					}

					Start.joueur.deleteItem(id);
					attaqueAtk = -1;
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



			if(atk.getStatVIT() > def.getStatVIT() || ((attaqueAtk == -1) ? false : atk.getAttaques()[attaqueAtk].getPriorite() > def.getAttaques()[attaqueDef].getPriorite())){

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
							System.out.println(atk.getSurnom() + " se réveille!");
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
							System.out.println(atk.getSurnom() + " se réveille!");
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
				}else if(atk.vampigraine){
					FormattedString.outPrintln("Vampigraine draine l'energie de %o!", atk.getSurnom());
					atk.attacked(atk.getPV() / 8);
					def.heal(atk.getPV() / 8);

				}
				if(attaqueAtk == -1){
					atkCanAttack = false;
				}
				if(atkCanAttack){
					try {
						atk.getAttaques()[attaqueAtk].attack(atk, def);
					}  catch (SameAtkPartTwo e) {
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
							System.out.println(def.getSurnom() + " se réveille!");
							defCanAttack = true;
							def.setStatus(Status.AUCUN);
						}else{
							System.out.println(def.getSurnom() + " dort profondement.");
							defCanAttack = false;
							atkCountDownSommeil--;
						}
					}else if(defSommeil == true){
						if(defCountDownSommeil <= 0){
							System.out.println(def.getSurnom() + " se réveille!");
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
					FormattedString.outPrintln("%o a trop peur pour bouger!", def.getSurnom());
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
				}else if(def.vampigraine){
					FormattedString.outPrintln("Vampigraine draine l'énergie de %o!", def.getSurnom());
					def.attacked(def.getPV() / 8);
					atk.heal(def.getPV() / 8);

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
							System.out.println(def.getSurnom() + " se réveille!");
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
							System.out.println(def.getSurnom() + " se réveille!");
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
						System.out.println("Malgré sa parlysie, " + def.getSurnom() + " parvient à attaquer!");
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
				}else if(def.vampigraine){
					FormattedString.outPrintln("Vampigraine draine l'énergie de %o!", def.getSurnom());
					def.attacked(def.getPV() / 8);
					atk.heal(def.getPV() / 8);

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
							System.out.println(atk.getSurnom() + " se réveille!");
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
							System.out.println(atk.getSurnom() + " se réveille!");
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
					FormattedString.outPrintln("%o a trop peur pour bouger!", atk.getSurnom());
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
				}else if(atk.vampigraine){
					FormattedString.outPrintln("Vampigraine draine l'energie de %o!", atk.getSurnom());
					atk.attacked(atk.getPV() / 8);
					def.heal(atk.getPV() / 8);

				}

				if(attaqueAtk == -1){
					atkCanAttack = false;
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
		return new Object[]{atk, def, captured};
	}

	public static void fight(Equipe atk, Equipe def){
		int attaquantID = 0, defenseurID = 0;
		while(!(atk.isKo() || def.isKo())){
			FormattedString.outPrintln("%o niveau %o vs %o niveau %o", atk.getPokemon(attaquantID).getSurnom(),atk.getPokemon(attaquantID).getLevel(), def.getPokemon(defenseurID).getSurnom(), def.getPokemon(defenseurID).getLevel());

			Object[] data = pokeFight(atk.getPokemon(attaquantID), def.getPokemon(defenseurID));
			Pokemon[] beligerants = {(Pokemon) data[0], (Pokemon) data[1]};
			if((boolean) data[2]){
				System.out.println(beligerants[1].getSurnom() + " est capturé!");
				if(!Start.joueur.addPokeToEquipe(beligerants[1])){
					System.out.println(beligerants[1].getSurnom() + " est envoyé dans le PC!");
				}
				beligerants[1].attacked(beligerants[1].getStatPV());
				if(def.isKo()){
					System.out.println("Le combat est terminé!");
					break;
				}else{
					boolean ok = false;
					while(!ok){
						int choix = Start.rand.nextInt(6);
						int i = 0;
						try{
							Pokemon pkmn = def.getEquipe()[choix];
							pkmn.getSurnom();
							if((pkmn.getPV() <= 0)){
								throw new NullPointerException();
							}
							defenseurID = choix;
							ok = true;
							
						}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
							i++;
							if(i >= 250){
								System.out.println("L'attaquant " + atk.getNom() + " a gagné!");
								return;
							}
						}
					}
				}
			}else{
				if(beligerants[1].getPV() <= 0 && beligerants[0].getPV() <= 0){
					beligerants[1].setStats(oldStats[1], oldAttacks[1], oldEspece[1], oldTypes[1]);
					beligerants[0].setStats(oldStats[0], oldAttacks[0], oldEspece[0], oldTypes[0]);
					System.out.println("Egalité!");
					if(def.isKo() && atk.isKo()){
						System.out.println("Personne n'a gagné!");
					}
					if(def.isKo()){
						System.out.println("L'attaquant " + atk.getNom() + " a gagné!");
					}else{
						boolean ok = false;
						while(!ok){
							int choix = Start.rand.nextInt(6);
							int i = 0;
							try{
								Pokemon pkmn = def.getEquipe()[choix];
								pkmn.getSurnom();
								if(pkmn.getPV() <= 0){
									throw new NullPointerException();
								}
								defenseurID = choix;
								ok = true;
							}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
								i++;
								if(i >= 250){
									System.out.println("L'attaquant " + atk.getNom() + " a gagné!");
									return;
								}
							}
						}
					}
					if(atk.isKo()){
						System.out.println("Le défenseur " + def.getNom() + " a gagné!");
					}else{
						boolean ok = false;
						System.out.println("Pokemons restants : ");
						int i = 0;
						for(Pokemon pkmn : atk.getEquipe()){
							if(pkmn != null){
								if(!(pkmn.getPV() <= 0)){
									System.out.println(pkmn.getSurnom() + " ID : " + i);
								}
							}
							i++;
						}
						while(!ok){
							System.out.println("Entrez l'ID du pokemon a choisir : ");
							int choix = Start.sc.nextInt();
							try{
								Pokemon pkmn = atk.getEquipe()[choix];
								pkmn.getSurnom();
								if(pkmn.getPV() <= 0){
									throw new NullPointerException();
								}
								attaquantID = choix;
								ok = true;
							}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
								System.out.println("Pokemon non valide. Recommencez.");
							}
						}
					}
				}
				else if(beligerants[1].getPV() <= 0 && beligerants[0].getPV() > 0){
					beligerants[1].setStats(oldStats[1], oldAttacks[1], oldEspece[1], oldTypes[1]);
					System.out.println(beligerants[1].getSurnom() + " est K.O");
					if(def.isKo()){
						System.out.println("L'attaquant " + atk.getNom() + " a gagné!");
					}else{
						boolean ok = false;
						while(!ok){
							int choix = Start.rand.nextInt(6);
							int i = 0;
							try{
								Pokemon pkmn = def.getEquipe()[choix];
								pkmn.getSurnom();
								if(pkmn.getPV() <= 0){
									throw new NullPointerException();
								}
								defenseurID = choix;
								ok = true;
							}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
								i++;
								if(i >= 250){
									System.out.println("L'attaquant " + atk.getNom() + " a gagné!");
									return;
								}
							}
						}
					}
					
					beligerants[0].win(beligerants[1]);
				}else if(beligerants[0].getPV() <= 0 && beligerants[1].getPV() > 0){
					beligerants[0].setStats(oldStats[0], oldAttacks[0], oldEspece[0], oldTypes[0]);
					System.out.println(beligerants[0].getSurnom() + " est K.O");
					beligerants[1].win(beligerants[0]);
					if(atk.isKo()){
						System.out.println("Le défenseur " + def.getNom() + " a gagné!");
					}else{
						boolean ok = false;
						System.out.println("Pokemons restants : ");
						int i = 0;
						for(Pokemon pkmn : atk.getEquipe()){
							if(pkmn != null){
								if(!(pkmn.getPV() <= 0)){
									System.out.println(pkmn.getSurnom() + " ID : " + i);
								}
							}
							i++;
						}
						while(!ok){
							System.out.println("Entrez l'ID du pokemon a choisir : ");
							int choix = Start.sc.nextInt();
							try{
								Pokemon pkmn = atk.getEquipe()[choix];
								pkmn.getSurnom();
								if(pkmn.getPV() <= 0){
									throw new NullPointerException();
								}
								attaquantID = choix;
								ok = true;
							}catch(ArrayIndexOutOfBoundsException | NullPointerException e){
								System.out.println("Pokemon non valide. Recommencez.");
							}
						}
					}


				}else{
					System.out.println("BUG. On sait pas qui a gagné (Cela ne devrait pas arriver...)");
				}
			}

		}


	}


}
