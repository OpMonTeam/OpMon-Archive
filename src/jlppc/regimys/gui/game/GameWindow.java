package jlppc.regimys.gui.game;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public final class GameWindow extends JInternalFrame {
	
	public GameWindow() {
		super();
	}
	
	public void setPanel(JPanel panel){
		this.setContentPane(panel);
		this.repaint();
	}

	
	
}
