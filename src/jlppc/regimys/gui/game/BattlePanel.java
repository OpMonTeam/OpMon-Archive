package jlppc.regimys.gui.game;

import javax.swing.JPanel;
import javax.swing.JLabel;

public final class BattlePanel extends JPanel {
	public BattlePanel() {
		super();
		setLayout(null);
		
		JLabel pokeAdverse = new JLabel("");
		pokeAdverse.setBounds(297, 36, 154, 220);
		add(pokeAdverse);
		
		JLabel label = new JLabel("");
		label.setBounds(40, 236, 143, 244);
		add(label);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 512, 512);
		add(background);
	}
}
