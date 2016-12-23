package jlppc.regimys.gui.dialog;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import jlppc.regimys.core.GameState;
import jlppc.utils.Fonts;
import jlppc.utils.Log;
import jlppc.utils.Fonts.Police;

public final class DialogWindow extends JInternalFrame {
	JLabel text;
	JPanel defaultPanel;
	public DialogWindow() {
		super();
		defaultPanel = new JPanel();
		defaultPanel.setLayout(null);
		this.setContentPane(defaultPanel);
		text = new JLabel("");
		text.setBounds(10, 11, 476, 98);
		defaultPanel.add(text);
		text.setFont(Fonts.font(Police.ARIAL, 20));
		text.setVerticalTextPosition(JLabel.TOP);
		text.setHorizontalTextPosition(JLabel.LEADING);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 496, 120);
		defaultPanel.add(background);
		
		
	}
	
	public JPanel getDefaultPanel(){
		return defaultPanel;
	}
	
	public void continuer(){
		if(GameState.state == GameState.DIALOGUE){
			text.setText("");
			GameState.state = GameState.MARCHE;	
		}
		
	}
	
	public void printText(String text){
		setContentPane(defaultPanel);
		repaint();
		this.text.setText("<HTML>" + text + "</HTML>");
		GameState.state = GameState.DIALOGUE;
		while(GameState.state != GameState.MARCHE){
			System.out.println("Wait...");
		}
	}
	
	public int printQuestion(String question, String choix1, String choix2, String choix3){
		ChoicePanel cp = new ChoicePanel(question, choix1, choix2, choix3, (choix3 != null));
		setContentPane(cp);
		repaint();
		while(cp.getChoice() == -1){
			System.out.println("Wait...");
		}
		return cp.getChoice();
	}
	
	
}
