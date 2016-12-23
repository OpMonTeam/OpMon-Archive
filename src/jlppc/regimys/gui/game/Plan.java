package jlppc.regimys.gui.game;

import javax.swing.JLabel;
import javax.swing.JPanel;

public final class Plan extends JPanel{
	
	JLabel lbls[][][];
	
	public Plan(JLabel[][][] plan) {
		super();
		lbls = plan.clone();
		int i, j, k;
		for(i = 0; i < 5; i++){
			for(j = 0; j < 16; j++){
				for(k = 0; k < 16; k++){
					add(lbls[i][j][k]);
					lbls[i][j][k].setBounds(k*16, j*16, 16, 16);
					
				}
			}
		}
	}
	
	
}
