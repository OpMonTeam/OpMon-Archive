package jlppc.regimys.gui;

import javax.swing.JFrame;
import javax.swing.JPanel;

import jlppc.regimys.gui.dialog.DialogWindow;
import jlppc.regimys.gui.game.GameWindow;
import jlppc.regimys.gui.game.StartScene;

import javax.swing.JLabel;

public final class MainFrame extends JFrame {
	public static MainFrame frame;
	protected JPanel contentPane;
	protected GameWindow gw;
	protected DialogWindow dw;
	public static Thread listeners = new Thread(new ListenersThread());

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
		System.out.println("Dialog1");
		frame.dw.printText("Bonjour! Bienvenue dans le monde des pokemon!");
		System.out.println("Fin Dialog1");
		System.out.println("Dialog 2");
		frame.dw.printText("Bravo! Le test a reussi! A plus!");
		System.out.println("Fin dialog 2");
		System.exit(0);
	}
	
	public GameWindow getGameWindow(){
		return gw;
	}
	
	public void setGameWindowPanel(JPanel panel){
		gw.setPanel(panel);
	}
	
	
}
