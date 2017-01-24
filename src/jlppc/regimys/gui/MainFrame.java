package jlppc.regimys.gui;

import java.awt.Image;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.imageio.ImageReader;
import javax.swing.JFrame;
import javax.swing.JPanel;

import jlppc.regimys.core.save.Parameters;
import jlppc.regimys.core.save.Save;
import jlppc.regimys.enums.Caractere;
import jlppc.regimys.gui.dialog.DialogWindow;
import jlppc.regimys.gui.game.GameWindow;
import jlppc.regimys.gui.game.StartScene;
import jlppc.regimys.launch.Initializer;
import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Pokemon;
import jlppc.regimys.playercore.Player;
import jlppc.utils.Log;
import jlppc.utils.Log.Entry;

import javax.swing.JLabel;
import javax.swing.JOptionPane;

public final class MainFrame extends JFrame {
	public static MainFrame frame;
	protected JPanel contentPane;
	protected GameWindow gw;
	protected DialogWindow dw;
	public static Thread listeners = new Thread(new ListenersThread());
	public static Thread player;
	

	public MainFrame() {
		super();
		getContentPane().setLayout(null);
		
		Log.writeT(Entry.INFO, "Creation de la fenetre principale");//C'est bien vous avez les logs pour commentaires ;-)
		
		JLabel fond = new JLabel("");
		fond.setBounds(524, 0, 290, 633);
		getContentPane().add(fond);
		
		gw = new GameWindow();
		gw.setBounds(10, 10, 512, 512);
		gw.setVisible(true);
		getContentPane().add(gw);
		
		dw = new DialogWindow();
		dw.setBounds(10, 532, 512, 200);
		dw.setVisible(true);
		getContentPane().add(dw);
		
		this.setBounds(0,0,800,800);
		Log.writeT(Entry.INFO, "Ajout du WindowListener");
		addWindowListener(new WindowListener(){

			@Override
			public void windowActivated(WindowEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void windowClosed(WindowEvent arg0) {
				
				
			}

			@Override
			public void windowClosing(WindowEvent arg0) {
				Log.writeT(Entry.INFO, "Fermeture du jeu.");
				Start.exit();
				
			}

			@Override
			public void windowDeactivated(WindowEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void windowDeiconified(WindowEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void windowIconified(WindowEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void windowOpened(WindowEvent arg0) {
				// TODO Auto-generated method stub
				
			}
			
		});
		
		this.setVisible(true);
	}

	/**
	 * Methode permettant d'ouvrir la fenetre
	 */
	public static synchronized void open() {
		frame = new MainFrame();
		Log.writeT(Entry.INFO, "Lancement des listeners");
		listeners.start();
		play();
		
		
	}
	/**
	 * Methode lancant le jeu a proprement parler
	 */
	public static synchronized void play(){
		player = new Thread(new Runnable(){

			@Override
			public void run() {
				StartScene ss;
				try {//Chargement du sprite du "prof"
					ss = new StartScene(ImageIO.read(new File("ressources" + Start.sep + "sprites" + Start.sep + "chara" + Start.sep + "jlppc" + Start.sep + "jlppc.png")));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					Start.gererException(e, false);
					Log.writeT(Entry.ERROR, "L'image du professeur n'a pu etre chargée, elle ne s'affichera donc pas.");
					ss = new StartScene(null);
				}
				frame.gw.setPanel(ss);
				if((Parameters.checkParam("playerexists") ? Parameters.getParam("playerexists").getValue().equals("true") : false)){//Verfifie si un joueur n'est pas déjà sauvegardé
					try {
						Start.joueur = Save.load();
					} catch (InstantiationException | IllegalAccessException | ClassNotFoundException | IOException e) {
						Save.corrompue();
						Start.gererException(e, true);
					}
				}else {
					frame.dw.printText("Bonjour! Bienvenue dans le monde inachevé des pokemon!");
					frame.dw.printText("Je suis le professeur... Heu non, je suis Jlppc, le developpeur du jeu.");
					frame.dw.printText("Désolé si ce monde est un peu vide... Comme tu peux le voir, je n'ai pas fini de developper le jeu.");
					frame.dw.printText("Sinon, je blablate, la, mais j'en ai oublié les bonnes maniéres! Quel est ton nom?");
					String nom = JOptionPane.showInputDialog("Quel est ton nom?");
					int essais = 0;
					boolean aBout = false;
					String[] phrases = new String[]{"Bon alors, en vrai, c'est quoi ton nom?", "Oui, bon, c'est drôle, mais quel est ton nom?", "Les blagues les plus courtes sont les meilleures. Quel est ton nom?", "Bon, quel est ton nom enfin!", "Ce n'est plus drôle la.", "..."};
					boolean ok = false;
					while(!ok){//Boucle tant que le joueur n'aura pas dit oui
						int choix = frame.dw.printQuestion(nom + " est bien ton nom?", "Oui", "Non", null);
						if(choix == 2){
							frame.dw.printText(phrases[essais]);
							essais++;
							if(!(essais < phrases.length)){
								aBout = true;
								essais = 5;
							}
							nom = JOptionPane.showInputDialog("Quel est ton nom?");
						}else{
							ok = true;
						}
					}
					int pkmnStart = frame.dw.printQuestion("Bon bien alors. Maintenant, choisis un starter. Désolé, pour l'instant l'apparition du choix est nul mais on verra ça plus tard.", "Salamèche", "Carapuce", "Bulbizarre");
					String[] essaisChoixPoke = new String[]{"Bon, tu veux lequel en fait?", "Oui, bon, c'est cool mais tu veux lequel?", "Tu vas me faire poireauter combien de temps?", "Je veux bien avoir de l'humour mais là ce n'est pas drole...", "Bon stop.", "CHOISIS EN UN BON SANG!", "..."};
					String[] essaisABout = new String[]{"Pas encore!", "Tu ne vas pas t'y remettre?", "Non mais en fait tu es soulant!", "Je veux bien avoir de l'humour mais là ce n'est pas drole...", "Bon stop.", "CHOISIS EN UN BON SANG!", "..."};
					essais = 0;
					while(true){//Toujours la meme boucle...
						if(pkmnStart == 1){
							int choix = frame.dw.printQuestion("Tu veux donc Salamèche?", "Oui!", "Non en fait...", null);
							if(choix != 2){
								break;
							}
						}
						if(pkmnStart == 2){
							int choix = frame.dw.printQuestion("Tu veux donc Carapuce?", "Oui!", "Non en fait...", null);
							if(choix != 2){
								break;
							}
						}
						if(pkmnStart == 3){
							int choix = frame.dw.printQuestion("Tu veux donc Bulbizarre?", "Oui!", "Non en fait...", null);
							if(choix != 2){
								break;
							}
						}
						pkmnStart = frame.dw.printQuestion((aBout ? essaisABout[essais] : essaisChoixPoke[essais]), "Salamèche", "Carapuce", "Bulbizarre");
						essais++;
						if(!(essais < essaisChoixPoke.length)){
							essais = 5;
							aBout = true;
						}
						
					}
					frame.dw.printText("Très bon choix! (En fait je dis ça à tout le monde mais bon...)");
					int surnomI = frame.dw.printQuestion("Tu veux donner un surnom a ton pokemon?", "Oui", "Non", null);
					String surnom = null;
					if(surnomI == 1){//Si c'est ok pour le surnom
						surnom = JOptionPane.showInputDialog(null, "Entrez le surnom de votre pokémon", "Surnommer un pokémon");
					}else{
						frame.dw.printText("Comme tu veux!");
					}
					Start.joueur = new Player(nom);
					Pokemon starter;
					if(surnom == null){//Oui je sais y'a mieux mais bon j'ai la flemme de refaire.
						starter = new Pokemon((pkmnStart == 1) ? Initializer.listePoke[1] : ((pkmnStart == 2) ? Initializer.listePoke[7] : Initializer.listePoke[4]), 5, null, Caractere.random(), null);
					}else{
						starter = new Pokemon(surnom, (pkmnStart == 1) ? Initializer.listePoke[1] : ((pkmnStart == 2) ? Initializer.listePoke[7] : Initializer.listePoke[4]), 5, null, Caractere.random(), null);
					}
					Start.joueur.addPokeToEquipe(starter);
					frame.dw.printText("Bon, du coup, je vais te laisser combattre, hein. Aller c'est parti!");
					try {
						Save.save();
					} catch (IOException e) {
						Log.writeT(Entry.WARNING, "Erreur de la sauvegarde.");
						Start.gererException(e, false);
					}
				}
				
				
				
				System.exit(0);
			}
			
		});
		Log.writeT(Entry.INFO, "Lancement du jeu.");
		player.start();
		
	}
	
	public GameWindow getGameWindow(){
		return gw;
	}
	
	public DialogWindow getDialogWindow(){
		return dw;
	}
	
	public void setGameWindowPanel(JPanel panel){
		gw.setPanel(panel);
	}
	
	
}
