package jlppc.regimys.launcher;

import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.SpringLayout;
import java.awt.Font;
import javax.swing.JComboBox;
import javax.swing.JLabel;

public class Launch {

	private JFrame frmPokmonRegimysLauncher;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Launch window = new Launch();
					window.frmPokmonRegimysLauncher.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Launch() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmPokmonRegimysLauncher = new JFrame();
		frmPokmonRegimysLauncher.setTitle("Pok\u00E9mon Regimys Launcher");
		frmPokmonRegimysLauncher.setBounds(100, 100, 690, 293);
		frmPokmonRegimysLauncher.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		SpringLayout springLayout = new SpringLayout();
		frmPokmonRegimysLauncher.getContentPane().setLayout(springLayout);
		
		JButton btnJouer = new JButton("JOUER");
		btnJouer.setFont(new Font("Tahoma", Font.PLAIN, 30));
		springLayout.putConstraint(SpringLayout.NORTH, btnJouer, -53, SpringLayout.SOUTH, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.WEST, btnJouer, 29, SpringLayout.WEST, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.SOUTH, btnJouer, -10, SpringLayout.SOUTH, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.EAST, btnJouer, -30, SpringLayout.EAST, frmPokmonRegimysLauncher.getContentPane());
		frmPokmonRegimysLauncher.getContentPane().add(btnJouer);
		
		JButton btnParamtres = new JButton("Param\u00E8tres");
		springLayout.putConstraint(SpringLayout.NORTH, btnParamtres, 10, SpringLayout.NORTH, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.WEST, btnParamtres, 10, SpringLayout.WEST, frmPokmonRegimysLauncher.getContentPane());
		frmPokmonRegimysLauncher.getContentPane().add(btnParamtres);
		
		JButton btnVerifierLesMises = new JButton("Verifier les mises a jour");
		springLayout.putConstraint(SpringLayout.SOUTH, btnVerifierLesMises, 0, SpringLayout.SOUTH, btnParamtres);
		springLayout.putConstraint(SpringLayout.EAST, btnVerifierLesMises, -10, SpringLayout.EAST, frmPokmonRegimysLauncher.getContentPane());
		frmPokmonRegimysLauncher.getContentPane().add(btnVerifierLesMises);
		
		JComboBox comboBox = new JComboBox();
		springLayout.putConstraint(SpringLayout.NORTH, comboBox, 6, SpringLayout.SOUTH, btnVerifierLesMises);
		springLayout.putConstraint(SpringLayout.WEST, comboBox, -153, SpringLayout.EAST, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.EAST, comboBox, -10, SpringLayout.EAST, frmPokmonRegimysLauncher.getContentPane());
		frmPokmonRegimysLauncher.getContentPane().add(comboBox);
		
		JLabel lblProfil = new JLabel("Profil");
		springLayout.putConstraint(SpringLayout.NORTH, lblProfil, -1, SpringLayout.NORTH, comboBox);
		springLayout.putConstraint(SpringLayout.WEST, lblProfil, -46, SpringLayout.WEST, comboBox);
		springLayout.putConstraint(SpringLayout.SOUTH, lblProfil, 61, SpringLayout.NORTH, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.EAST, lblProfil, -3, SpringLayout.WEST, comboBox);
		frmPokmonRegimysLauncher.getContentPane().add(lblProfil);
		
		JButton btnNouveauProfil = new JButton("Nouveau profil");
		springLayout.putConstraint(SpringLayout.NORTH, btnNouveauProfil, 6, SpringLayout.SOUTH, btnParamtres);
		springLayout.putConstraint(SpringLayout.WEST, btnNouveauProfil, 0, SpringLayout.WEST, btnParamtres);
		frmPokmonRegimysLauncher.getContentPane().add(btnNouveauProfil);
		
		JLabel logo = new JLabel("");
		springLayout.putConstraint(SpringLayout.NORTH, logo, 3, SpringLayout.SOUTH, btnNouveauProfil);
		springLayout.putConstraint(SpringLayout.WEST, logo, 20, SpringLayout.WEST, frmPokmonRegimysLauncher.getContentPane());
		springLayout.putConstraint(SpringLayout.SOUTH, logo, -6, SpringLayout.NORTH, btnJouer);
		springLayout.putConstraint(SpringLayout.EAST, logo, -10, SpringLayout.EAST, btnVerifierLesMises);
		frmPokmonRegimysLauncher.getContentPane().add(logo);
	}
}
