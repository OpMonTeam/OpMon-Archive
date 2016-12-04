package jlppc.regimys.gui.dialog;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JButton;

public final class ChoicePanel extends JPanel {
	
	protected int choice = -1;
	
	public ChoicePanel(String choix1S, String choix2S, String choix3S, boolean threechoices) {
		super();
		setLayout(null);
		
		JLabel text = new JLabel("");
		text.setBounds(10, 11, 362, 178);
		add(text);
		
		JPanel panel = new JPanel();
		panel.setBounds(382, 11, 120, 178);
		add(panel);
		panel.setLayout(null);
		
		JButton choix1 = new JButton(choix1S);
		choix1.setBounds(10, 11, 100, 45);
		panel.add(choix1);
		
		JButton choix2 = new JButton(choix2S);
		choix2.setBounds(10, 67, 100, 45);
		panel.add(choix2);
		
		JButton choix3 = new JButton(choix3S);
		choix3.setBounds(10, 123, 100, 44);
		panel.add(choix3);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 512, 200);
		add(background);
	}
	
	public int getChoice(){
		return choice;
	}
	
	
}


