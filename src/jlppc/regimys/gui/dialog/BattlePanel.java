package jlppc.regimys.gui.dialog;

import javax.swing.JPanel;
import javax.swing.JLabel;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JSplitPane;
import javax.swing.SwingConstants;

import jlppc.regimys.launch.Start;

public class BattlePanel extends JPanel {
	int result = 0;
	public BattlePanel(String pokename) {
		super();
		setLayout(null);
		
		JLabel text = new JLabel("Que doit faire " + pokename);
		text.setBounds(10, 11, 257, 178);
		add(text);
		
		JPanel choicesPanel = new JPanel();
		choicesPanel.setBounds(277, 11, 225, 178);
		add(choicesPanel);
		choicesPanel.setLayout(null);
		
		JButton atkButton = new JButton("Attaque");
		atkButton.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent arg0) {
				result = 1;
				notify();
				
			}
			
		});
		atkButton.setBounds(10, 11, 98, 73);
		choicesPanel.add(atkButton);
		
		JButton itemButton = new JButton("Objets");
		itemButton.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent arg0) {
				result = 2;
				notify();
				
			}
			
		});
		itemButton.setBounds(118, 11, 97, 73);
		choicesPanel.add(itemButton);
		
		JButton pkmnButton = new JButton("Pok\u00E9mon");
		pkmnButton.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent arg0) {
				result = 3;
				notify();
				
			}
			
		});
		pkmnButton.setBounds(10, 95, 98, 73);
		choicesPanel.add(pkmnButton);
		
		JButton fleeButton = new JButton("Fuite");
		fleeButton.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent arg0) {
				result = 4;
				notify();
				
			}
			
		});
		fleeButton.setBounds(117, 95, 98, 73);
		choicesPanel.add(fleeButton);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 512, 200);
		add(background);
	}
	
	public synchronized int waitForAction(){
		try {
			wait();
		} catch (InterruptedException e) {
			Start.gererException(e, true);
		}
		return result;
	}
}
