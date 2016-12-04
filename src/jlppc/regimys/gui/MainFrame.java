package jlppc.regimys.gui;

import javax.swing.JFrame;
import javax.swing.JPanel;

import jlppc.regimys.gui.dialog.DialogWindow;
import jlppc.regimys.gui.game.GameWindow;

import javax.swing.JLabel;

public final class MainFrame extends JFrame {
	public static MainFrame frame;
	protected JPanel contentPane;
	protected GameWindow gw;
	protected DialogWindow dw;

	public MainFrame() {
		super();
		getContentPane().setLayout(null);
		
		JLabel fond = new JLabel("");
		fond.setBounds(524, 0, 290, 633);
		getContentPane().add(fond);
		
		gw = new GameWindow();
		gw.setBounds(10, 10, 512, 512);
		getContentPane().add(gw);
		
		dw = new DialogWindow();
		dw.setBounds(10, 532, 512, 200);
		getContentPane().add(dw);
		
		this.setVisible(true);
	}

	/**
	 * Launch the application.
	 */
	public static void open() {
		
	}
	
	public GameWindow getGameWindow(){
		return gw;
	}
	
	public void setGameWindowPanel(JPanel panel){
		gw.setPanel(panel);
	}
	
	
}
