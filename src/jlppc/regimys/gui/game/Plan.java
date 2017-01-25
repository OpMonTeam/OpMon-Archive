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
					lbls[i][j][k].setBounds(j*16, k*16, 16, 16);
					
				}
			}
		}
	}
	
	public JLabel getLabel(int couche, int x, int y){
		return lbls[couche][x][y];
	}
	
	
}
