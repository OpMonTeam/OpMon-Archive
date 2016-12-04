package jlppc.regimys.gui.dialog;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JSplitPane;
import javax.swing.SwingConstants;

public class BattlePanel extends JPanel {
	public BattlePanel() {
		super();
		setLayout(null);
		
		JLabel text = new JLabel("");
		text.setBounds(10, 11, 257, 178);
		add(text);
		
		JPanel choicesPanel = new JPanel();
		choicesPanel.setBounds(277, 11, 225, 178);
		add(choicesPanel);
		choicesPanel.setLayout(null);
		
		JButton atkButton = new JButton("Attaque");
		atkButton.setBounds(10, 11, 98, 73);
		choicesPanel.add(atkButton);
		
		JButton itemButton = new JButton("Objets");
		itemButton.setBounds(118, 11, 97, 73);
		choicesPanel.add(itemButton);
		
		JButton pkmnButton = new JButton("Pok\u00E9mon");
		pkmnButton.setBounds(10, 95, 98, 73);
		choicesPanel.add(pkmnButton);
		
		JButton fleeButton = new JButton("Fuite");
		fleeButton.setBounds(117, 95, 98, 73);
		choicesPanel.add(fleeButton);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 512, 200);
		add(background);
	}
}
