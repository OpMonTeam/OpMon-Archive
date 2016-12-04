package jlppc.regimys.gui.game;

import javax.swing.JPanel;
import javax.swing.JLabel;

public final class StartScene extends JPanel {
	public StartScene() {
		super();
		setLayout(null);
		
		JLabel prof = new JLabel("");
		prof.setBounds(131, 53, 249, 406);
		add(prof);
		
		JPanel backround = new JPanel();
		backround.setBounds(0, 0, 512, 512);
		add(backround);
	}
}
