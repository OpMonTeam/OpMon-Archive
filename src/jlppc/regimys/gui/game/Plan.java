package jlppc.regimys.gui.game;

import javax.swing.JLabel;
import javax.swing.JPanel;

public final class Plan extends JPanel{
	/**
	* Liste des COUCHES
	* 1 : Premier plan
	* 2 : Plan des evenements
	* 3 : Plan des personnages
	* 4 : Deuxieme plan (Impassable)
	* 5 : Troisième plan (Passable en dessous)
	*/
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
