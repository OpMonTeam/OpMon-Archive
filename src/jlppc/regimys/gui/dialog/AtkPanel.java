package jlppc.regimys.gui.dialog;

import javax.swing.JPanel;

import jlppc.regimys.launch.Start;
import jlppc.regimys.objects.Attaque;

import javax.swing.JLabel;
import java.awt.CardLayout;
import javax.swing.JButton;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AtkPanel extends JPanel {
	
	protected int atkChosen = -1;
	
	public AtkPanel(Attaque[] atks) {
		super();
		setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(10, 11, 492, 178);
		add(panel);
		panel.setLayout(null);
		
		JButton atk1 = new JButton(atks[0].getNom());
		atk1.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent e) {
				atkChosen = 0;
				notify();
			}
			
		});
		atk1.setBounds(10, 11, 232, 72);
		panel.add(atk1);
		
		JButton atk3 = new JButton(atks[2].getNom());
		atk3.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent e) {
				atkChosen = 2;
				notify();
			}
			
		});
		atk3.setBounds(252, 11, 232, 72);
		panel.add(atk3);
		
		JButton atk2 = new JButton(atks[1].getNom());
		atk2.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent e) {
				atkChosen = 1;
				notify();
			}
			
		});
		atk2.setBounds(10, 95, 232, 72);
		panel.add(atk2);
		
		JButton atk4 = new JButton(atks[3].getNom());
		atk4.addActionListener(new ActionListener(){

			@Override
			public synchronized void actionPerformed(ActionEvent e) {
				atkChosen = 3;
				notify();
			}
			
		});
		atk4.setBounds(252, 94, 232, 72);
		panel.add(atk4);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 0, 0);
		add(background);
	}
	
	public int getAtkChosen(){
		return atkChosen;
	}
	
	public synchronized int waitForAtkChosen(){
		try {
			wait();
		} catch (InterruptedException e) {
			Start.gererException(e, true);
		}
		return atkChosen;
	}
}
