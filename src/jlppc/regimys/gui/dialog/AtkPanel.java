package jlppc.regimys.gui.dialog;

import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.CardLayout;
import javax.swing.JButton;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;

public class AtkPanel extends JPanel {
	
	protected int atkChosen = -1;
	
	public AtkPanel() {
		super();
		setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(10, 11, 492, 178);
		add(panel);
		panel.setLayout(null);
		
		JButton atk1 = new JButton("New button");
		atk1.setBounds(10, 11, 232, 72);
		panel.add(atk1);
		
		JButton atk3 = new JButton("New button");
		atk3.setBounds(252, 11, 232, 72);
		panel.add(atk3);
		
		JButton atk2 = new JButton("New button");
		atk2.setBounds(10, 95, 232, 72);
		panel.add(atk2);
		
		JButton atk4 = new JButton("New button");
		atk4.setBounds(252, 94, 232, 72);
		panel.add(atk4);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 0, 0);
		add(background);
	}
	
	public int getAtkChosen(){
		return atkChosen;
	}
}
