package jlppc.regimys.gui.game;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import jlppc.utils.Log;
import jlppc.utils.Log.Entry;

public final class GameWindow extends JInternalFrame {
	
	public GameWindow() {
		super();
		Log.writeT(Entry.INFO, "Création de la fenetre de jeu.");
	}
	
	public void setPanel(JPanel panel){
		this.setContentPane(panel);
		this.repaint();
	}

	
	
}
