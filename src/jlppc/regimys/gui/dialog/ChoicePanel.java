package jlppc.regimys.gui.dialog;

import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JScrollPane;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;

public final class ChoicePanel extends JPanel {
	
	protected int choice = -1;
	final JButton choix1;
	final JButton choix2;
	JButton choix3;
	Thread actionListeners;
	
	public ChoicePanel(String question,String choix1S, String choix2S, String choix3S, boolean threechoices) {
		super();
		setLayout(null);
		
		JLabel text = new JLabel(question);
		text.setBounds(10, 0, 275, 178);
		add(text);
		
		JPanel panel = new JPanel();
		panel.setBounds(295, 0, 207, 178);
		add(panel);
		panel.setLayout(null);
		
		choix1 = new JButton(choix1S);
		choix1.setBounds(10, 11, 187, 45);
		panel.add(choix1);
		
		choix2 = new JButton(choix2S);
		choix2.setBounds(10, 67, 187, 45);
		panel.add(choix2);
		if(threechoices){
			choix3 = new JButton(choix3S);
			choix3.setBounds(10, 123, 187, 45);
			panel.add(choix3);
		}
		
		
		actionListeners = new Thread(new Runnable(){

			@Override
			public void run() {
				choix1.addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						choice = 1;
						
					}
				});
				
				choix2.addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						choice = 2;
						
					}
				});
				if(threechoices){
					choix3.addActionListener(new ActionListener() {
						
						@Override
						public void actionPerformed(ActionEvent e) {
							choice = 3;
							
						}
					});
				}
				
				
			}
			
		});
		actionListeners.start();
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 512, 200);
		add(background);
	}
	
	public int getChoice(){
		return choice;
	}
	
	public void setChoice(int ch){
		this.choice = ch;
	}
	
	
}


