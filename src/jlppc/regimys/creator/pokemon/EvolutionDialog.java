package jlppc.regimys.creator.pokemon;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JDialog;
import javax.swing.JSpinner;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JButton;

public abstract class EvolutionDialog extends JDialog {
	//Ok, dans ces classes, je ne respecte pas les regles du protected blablabla. ET ALORS??? JE FAIS CE QUE JE VEUX, MERDE!
	JSpinner spinner;
	JLabel lblNPokdexDe;
	JButton btnOk;
	public EvolutionDialog() {
		setModal(true);
		getContentPane().setLayout(null);
		setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		spinner = new JSpinner();
		spinner.setBounds(226, 12, 69, 20);
		getContentPane().add(spinner);
		
		lblNPokdexDe = new JLabel("N° Pokédex de l'évolution");
		lblNPokdexDe.setBounds(12, 14, 180, 15);
		getContentPane().add(lblNPokdexDe);
		
		btnOk = new JButton("OK");
		btnOk.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				if(((int)spinner.getValue()) < 0){
					JOptionPane.showMessageDialog(null, "Les pokémon négatfs n'existent pas!", "Erreur", JOptionPane.ERROR_MESSAGE);
				}else{
					dispose();
				}
				
				
			}
			
		});
		btnOk.setBounds(178, 133, 117, 25);
		getContentPane().add(btnOk);
		setSize(310, 200);
		setVisible(true);
	}
	
	public void setVisible(boolean trueOrFalse){
		if(this instanceof No_Evol){
			JOptionPane.showMessageDialog(null, "Vous n'avez rien a configurer", "Info", JOptionPane.INFORMATION_MESSAGE);
		}else{
			super.setVisible(trueOrFalse);
		}
	}
}
