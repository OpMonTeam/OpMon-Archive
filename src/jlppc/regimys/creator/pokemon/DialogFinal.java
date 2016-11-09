package jlppc.regimys.creator.pokemon;

import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JEditorPane;
import java.awt.BorderLayout;
import java.io.IOException;

import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class DialogFinal extends JDialog {


	public DialogFinal(String command) throws IOException {
		setAlwaysOnTop(true);
		setSize(100, 100);
		getContentPane().setLayout(new BorderLayout(0, 0));
		setVisible(true);
		JLabel lblCommande = new JLabel("Commande");
		lblCommande.setHorizontalAlignment(SwingConstants.CENTER);
		getContentPane().add(lblCommande, BorderLayout.NORTH);
		
		JEditorPane editorPaneCommand = new JEditorPane();
		editorPaneCommand.setText(command);
		editorPaneCommand.setEditable(true);
		getContentPane().add(editorPaneCommand, BorderLayout.CENTER);
		
	}

	
}
