package jlppc.regimys.creator.pokemon;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class E_LandDialog extends EvolutionDialog {
	JTextField textFieldPlace;
	public E_LandDialog() {
		super();
		
		JLabel lblEndroit = new JLabel("Endroit");
		lblEndroit.setBounds(12, 37, 70, 15);
		getContentPane().add(lblEndroit);
		
		textFieldPlace = new JTextField();
		textFieldPlace.setBounds(156, 35, 132, 19);
		getContentPane().add(textFieldPlace);
		textFieldPlace.setColumns(10);
	}
}
