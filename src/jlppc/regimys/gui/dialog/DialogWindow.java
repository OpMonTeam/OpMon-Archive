package jlppc.regimys.gui.dialog;

import java.awt.EventQueue;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.border.MatteBorder;
import java.awt.Color;
import javax.swing.border.TitledBorder;
import javax.swing.border.BevelBorder;
import javax.swing.UIManager;
import javax.swing.border.EmptyBorder;

public final class DialogWindow extends JInternalFrame {
	public DialogWindow() {
		super();
		getContentPane().setLayout(null);
		
		JLabel text = new JLabel("");
		text.setBounds(10, 11, 476, 98);
		getContentPane().add(text);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 496, 120);
		getContentPane().add(background);
	}
}
