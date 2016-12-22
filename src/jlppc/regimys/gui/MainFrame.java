package jlppc.regimys.gui;

import javax.swing.JFrame;
import javax.swing.JPanel;

import jlppc.regimys.gui.dialog.DialogWindow;
import jlppc.regimys.gui.game.GameWindow;
import jlppc.regimys.gui.game.StartScene;
import jlppc.utils.Log;

import javax.swing.JLabel;
import javax.swing.JOptionPane;

public final class MainFrame extends JFrame {
	public static MainFrame frame;
	protected JPanel contentPane;
	protected GameWindow gw;
	protected DialogWindow dw;
	public static Thread listeners = new Thread(new ListenersThread());
	public static String saut = "<br/>";

	public MainFrame() {
		super();
		getContentPane().setLayout(null);
		
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
		
		this.setVisible(true);
	}

	
	public static synchronized void open() {
		frame = new MainFrame();
		listeners.start();
		play();
		
		
	}
	
	public static synchronized void play(){
		StartScene ss = new StartScene();
		frame.gw.setPanel(ss);

		frame.dw.printText("Bonjour! Bienvenue dans le monde inachevé des pokemon!");
		frame.dw.printText("Je suis le professeur... Heu non, je suis Jlppc, le developpeur du jeu.");
		frame.dw.printText("Désolé si ce monde est un peu vide... Comme tu peux le voir, je n'ai pas fini de developper le jeu.");
		frame.dw.printText("Sinon, je blablate, la, mais j'en ai oublié les bonnes manières! Quel est ton nom?");
		String nom = JOptionPane.showInputDialog("Quel est ton nom?");
		boolean ok = false;
		while(!ok){
			int choix = frame.dw.printQuestion(nom + " est bien ton nom?", "Oui", "Non", null);
			if(choix == 2){
				frame.dw.printText("Bien alors quel est ton nom?");
				nom = JOptionPane.showInputDialog("Quel est ton nom?");
			}else{
				ok = true;
			}
		}
		frame.dw.printText("Content pour toi, " + nom + "! Aller salut!");
		System.exit(0);
	}
	
	public GameWindow getGameWindow(){
		return gw;
	}
	
	public void setGameWindowPanel(JPanel panel){
		gw.setPanel(panel);
	}
	
	
}
