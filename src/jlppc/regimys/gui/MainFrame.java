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

import jlppc.regimys.gui.dialog.DialogWindow;
import jlppc.regimys.gui.game.GameWindow;
import jlppc.regimys.gui.game.StartScene;
import jlppc.regimys.launch.Start;
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
		
		Log.writeT(Entry.INFO, "Creation de la fenetre principale");
		
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

	
	public static synchronized void open() {
		frame = new MainFrame();
		Log.writeT(Entry.INFO, "Lancement des listeners");
		listeners.start();
		play();
		
		
	}
	
	public static synchronized void play(){
		player = new Thread(new Runnable(){

			@Override
			public void run() {
				StartScene ss;
				try {
					ss = new StartScene(ImageIO.read(new File("ressources" + Start.sep + "sprites" + Start.sep + "chara" + Start.sep + "jlppc" + Start.sep + "jlppc.png")));
				} catch (IOException e) {
					// TODO Auto-generated catch block
					Start.gererException(e, false);
					Log.writeT(Entry.ERROR, "L'image du professeur n'a pu etre chargée, elle ne s'affichera donc pas.");
					ss = new StartScene(null);
				}
				frame.gw.setPanel(ss);
				
				frame.dw.printText("Bonjour! Bienvenue dans le monde inachevé des pokemon!");
				frame.dw.printText("Je suis le professeur... Heu non, je suis Jlppc, le developpeur du jeu.");
				frame.dw.printText("Désolé si ce monde est un peu vide... Comme tu peux le voir, je n'ai pas fini de developper le jeu.");
				frame.dw.printText("Sinon, je blablate, la, mais j'en ai oublié les bonnes maniéres! Quel est ton nom?");
				String nom = JOptionPane.showInputDialog("Quel est ton nom?");
				int essais = 0;
				boolean aBout = false;;
				String[] phrases = new String[]{"Bon alors, en vrai, c'est quoi ton nom?", "Oui, bon, c'est drôle, mais quel est ton nom?", "Les blagues les plus courtes sont les meilleures. Quel est ton nom?", "Bon, quel est ton nom enfin!", "Ce n'est plus drôle la.", "..."};
				boolean ok = false;
				while(!ok){
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
				while(true){
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
				frame.dw.printText("Bon maintenant plus qu'a attendre que je rajoute des trucs! Amuse toi bien dans ce vide interspacial!");
				System.exit(0);
			}
			
		});
		Log.writeT(Entry.INFO, "Lancement du jeu.");
		player.start();
		
	}
	
	public GameWindow getGameWindow(){
		return gw;
	}
	
	public void setGameWindowPanel(JPanel panel){
		gw.setPanel(panel);
	}
	
	
}
