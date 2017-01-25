package jlppc.regimys.gui.game;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.plaf.basic.BasicInternalFrameUI;

import jlppc.utils.Log;
import jlppc.utils.Log.Entry;

public final class GameWindow extends JInternalFrame {
	
	public GameWindow() {
		super();
		Log.writeT(Entry.INFO, "Création de la fenetre de jeu.");
		BasicInternalFrameUI bi = (BasicInternalFrameUI) this.getUI();
		bi.setNorthPane(null);
	}
	
	public void setPanel(JPanel panel){
		this.setContentPane(panel);
		this.repaint();
	}

	
	
}
