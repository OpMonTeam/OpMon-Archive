package jlppc.regimys.gui.game;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public final class GameWindow extends JInternalFrame {
	public JLabel[][][] cases = new JLabel[5][16][16];
	public GameWindow() {
		super();
		for(JLabel[][] c1 : cases){
			for(JLabel[] c2 : c1){
				for(JLabel c3 : c2){
					c3 = new JLabel();
					this.add(c3);
				}
			}
		}
		
	}
	
	public void setPanel(JPanel panel){
		this.setContentPane(panel);
		this.repaint();
	}

	
	
}
