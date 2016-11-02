package jlppc.regimys.tempgui;

import java.awt.EventQueue;

import javax.swing.JDialog;
import javax.swing.JComboBox;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import jlppc.regimys.launch.Initializer;
import jlppc.regimys.objects.Espece;

public class ChoosePoke extends JDialog {
	
	protected int espChoosen;
	
	public int getEspChoosen(){
		return espChoosen;
	}
	
	JDialog ceci = this;
	
	public ChoosePoke() {
		setModal(true);
		getContentPane().setLayout(null);
		setSize(300, 220);
		
		
		JComboBox<Espece> comboBox = new JComboBox<Espece>();
		comboBox.setBounds(12, 60, 263, 24);
		for(Espece esp : Initializer.listePoke){
			comboBox.addItem(esp);
		}
	
		
		getContentPane().add(comboBox);
		
		JButton btnOk = new JButton("OK");
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
		
		JLabel lblChoisissezUnPokmon = new JLabel("Choisissez un Pokémon");
		lblChoisissezUnPokmon.setBounds(12, 12, 218, 15);
		getContentPane().add(lblChoisissezUnPokmon);
		setVisible(true);
	}
}
