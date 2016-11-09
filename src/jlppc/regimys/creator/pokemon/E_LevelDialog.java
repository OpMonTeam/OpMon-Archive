package jlppc.regimys.creator.pokemon;
import javax.swing.JLabel;
import javax.swing.JSpinner;

public class E_LevelDialog extends EvolutionDialog {
	JSpinner spinnerLevel;
	public E_LevelDialog() {
		super();
		
		spinnerLevel = new JSpinner();
		spinnerLevel.setBounds(226, 43, 70, 20);
		getContentPane().add(spinnerLevel);
		
		JLabel lblNiveauDvolution = new JLabel("Niveau d'évolution");
		lblNiveauDvolution.setBounds(12, 45, 196, 15);
		getContentPane().add(lblNiveauDvolution);
	}
}
