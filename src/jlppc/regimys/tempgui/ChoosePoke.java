package jlppc.regimys.tempgui;

import java.awt.EventQueue;

import javax.swing.JDialog;
import javax.swing.JComboBox;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import jlppc.regimys.launch.Initializer;
import jlppc.regimys.objects.Espece;

public class ChoosePoke extends JDialog {
	
	protected int espChoosen;
	JButton btnOk;
	JComboBox<Espece> comboBox;
	
	public int getEspChoosen(){
		return espChoosen;
	}
	
	JDialog ceci = this;
	
	public ChoosePoke() {
		setModal(true);
		getContentPane().setLayout(null);
		setSize(300, 220);
		
		
		
	
		
		
		
		btnOk = new JButton("OK");
		btnOk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(Initializer.listePoke[comboBox.getSelectedIndex()]);
				if(Initializer.listePoke[comboBox.getSelectedIndex()] == null){
					
					JOptionPane.showMessageDialog(null, "Le Pokémon choisi est incorrect", "Choisissez un Pokémon", JOptionPane.ERROR_MESSAGE);
				}else{
					espChoosen = comboBox.getSelectedIndex();
					ceci.dispose();
				}
			}
		});
		btnOk.setBounds(48, 142, 117, 25);
		getContentPane().add(btnOk);
		
		comboBox = new JComboBox<Espece>();
		comboBox.setBounds(12, 60, 263, 24);
		for(Espece esp : Initializer.listePoke){
			comboBox.addItem(esp);
		}
		comboBox.addKeyListener(new KeyListener() {
			
			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void keyReleased(KeyEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_ENTER){
					btnOk.doClick();
				}
				
			}
		});
		getContentPane().add(comboBox);
		JLabel lblChoisissezUnPokmon = new JLabel("Choisissez un Pokémon");
		lblChoisissezUnPokmon.setBounds(12, 12, 218, 15);
		getContentPane().add(lblChoisissezUnPokmon);
		setVisible(true);
		
	}
}
