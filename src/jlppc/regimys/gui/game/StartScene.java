package jlppc.regimys.gui.game;

import javax.swing.JPanel;

import java.awt.Image;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

public final class StartScene extends JPanel {
	public StartScene(Image img) {
		super();
		setLayout(null);
		
		JLabel prof = new JLabel("");
		prof.setBounds(131, 53, 249, 406);
		prof.setIcon(new ImageIcon(img));
		add(prof);
		
		JPanel backround = new JPanel();
		backround.setBounds(0, 0, 512, 512);
		add(backround);
	}
}
