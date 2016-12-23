package jlppc.regimys.creator.pokemon;

import java.awt.Component;
import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import jlppc.regimys.enums.Caractere.Stats;
import jlppc.regimys.enums.Type;
import jlppc.regimys.objects.items.Item;
import jlppc.utils.Comparaisons;
import jlppc.utils.Log;

import javax.swing.JComboBox;
import javax.swing.JSpinner;
import javax.swing.JButton;
import javax.swing.JEditorPane;
/**
 * Classe principale de la boite de dialogue de creation de pokémon.
 * @author Jlppc
 *
 */
public class Main {

	public JFrame frmCrateurDePokmon;
	private JTextField fieldNom;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
			
		
	}

	/**
	 * Create the application.
	 */
	public Main() {
		initialize();
	}

	EvolutionDialog evolDiag;
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		
		
		String[] evols = {"Niveau", "Objet", "Echange", "Echange objet", "Amour", "Lieu", "Non"};
		Type[] types2 = {Type.ACIER, Type.AUCUN, Type.COMBAT, Type.DRAGON, Type.EAU, Type.ELECTRIQUE, Type.FEE, Type.FEU, Type.GLACE, Type.INSECTE, Type.NORMAL, Type.PLANTE, Type.POISON, Type.PSY, Type.ROCHE, Type.SOL, Type.SPECTRE, Type.TENEBRES, Type.VOL};
		Type[] types1 = {Type.ACIER, Type.COMBAT, Type.DRAGON, Type.EAU, Type.ELECTRIQUE, Type.FEE, Type.FEU, Type.GLACE, Type.INSECTE, Type.NORMAL, Type.PLANTE, Type.POISON, Type.PSY, Type.ROCHE, Type.SOL, Type.SPECTRE, Type.TENEBRES, Type.VOL};

		frmCrateurDePokmon = new JFrame();
		frmCrateurDePokmon.setTitle("Créateur de Pokémon (Pokémon Regimys) (Pas a jour!!!)");
		frmCrateurDePokmon.setBounds(100, 100, 531, 350);
		frmCrateurDePokmon.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmCrateurDePokmon.getContentPane().setLayout(null);
		
		JLabel lblNom = new JLabel("Nom");
		lblNom.setBounds(12, 12, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblNom);
		
		fieldNom = new JTextField();
		fieldNom.setBounds(100, 10, 114, 19);
		frmCrateurDePokmon.getContentPane().add(fieldNom);
		fieldNom.setColumns(10);
		
		JLabel lblPremierType = new JLabel("Type 1");
		lblPremierType.setBounds(12, 39, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblPremierType);
		
		JComboBox<Type> comboBoxType1 = new JComboBox<>(types1);
		comboBoxType1.setBounds(100, 34, 114, 24);
		frmCrateurDePokmon.getContentPane().add(comboBoxType1);
		
		JLabel lblType = new JLabel("Type 2");
		lblType.setBounds(12, 66, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblType);
		
		JComboBox<Type> comboBoxType2 = new JComboBox<>(types2);
		comboBoxType2.setBounds(100, 61, 114, 24);
		frmCrateurDePokmon.getContentPane().add(comboBoxType2);
		
		JLabel lblAttaque = new JLabel("Attaque");
		lblAttaque.setBounds(12, 93, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblAttaque);
		
		JSpinner spinnerAtk = new JSpinner();
		spinnerAtk.setBounds(100, 91, 114, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerAtk);
		
		JLabel lblDfense = new JLabel("Défense");
		lblDfense.setBounds(12, 120, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblDfense);
		
		JSpinner spinnerDef = new JSpinner();
		spinnerDef.setBounds(100, 118, 114, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerDef);
		
		JLabel lblAttaqueSpcial = new JLabel("Attaque Spéciale");
		lblAttaqueSpcial.setBounds(12, 147, 132, 15);
		frmCrateurDePokmon.getContentPane().add(lblAttaqueSpcial);
		
		JSpinner spinnerAtkSpe = new JSpinner();
		spinnerAtkSpe.setBounds(162, 145, 52, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerAtkSpe);
		
		JLabel lblDfenseSpciale = new JLabel("Défense Spéciale");
		lblDfenseSpciale.setBounds(12, 174, 132, 15);
		frmCrateurDePokmon.getContentPane().add(lblDfenseSpciale);
		
		JSpinner spinnerDefSpe = new JSpinner();
		spinnerDefSpe.setBounds(162, 172, 52, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerDefSpe);
		
		JLabel lblVitesse = new JLabel("Vitesse");
		lblVitesse.setBounds(12, 201, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblVitesse);
		
		JSpinner spinnerVit = new JSpinner();
		spinnerVit.setBounds(100, 201, 114, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerVit);
		
		JLabel lblEvolution = new JLabel("Evolution");
		lblEvolution.setBounds(12, 228, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblEvolution);
		
		JComboBox<String> comboBoxEvo = new JComboBox<>(evols);
		comboBoxEvo.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				evolDiag = null;
				
			}
			
		});
		comboBoxEvo.setBounds(100, 223, 114, 24);
		frmCrateurDePokmon.getContentPane().add(comboBoxEvo);
		
		JButton btnParametresDeLvolution = new JButton("Parametres de l'évolution");
		btnParametresDeLvolution.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				if(evolDiag != null){
					evolDiag.setVisible(true);
				}else if(comboBoxEvo.getSelectedItem().equals(evols[0])){
					evolDiag = new E_LevelDialog();
				}else if(comboBoxEvo.getSelectedItem().equals(evols[1])){
					evolDiag = new E_ItemDialog();
				}else if(comboBoxEvo.getSelectedItem().equals(evols[2])){
					evolDiag = new E_TradeDialog();
				}else if(comboBoxEvo.getSelectedItem().equals(evols[3])){
					evolDiag = new E_TradeItemDialog();
				}else if(comboBoxEvo.getSelectedItem().equals(evols[4])){
					evolDiag = new E_LoveDialog();
				}
				else if(comboBoxEvo.getSelectedItem().equals(evols[5])){
					evolDiag = new E_LandDialog();
				}else{
					evolDiag = new No_Evol();
				}
				
				
				
			}
			
		});
		btnParametresDeLvolution.setBounds(226, 223, 262, 25);
		frmCrateurDePokmon.getContentPane().add(btnParametresDeLvolution);
		
		JLabel lblDescriptionPokdex = new JLabel("Description Pokédex");
		lblDescriptionPokdex.setBounds(232, 12, 167, 15);
		frmCrateurDePokmon.getContentPane().add(lblDescriptionPokdex);
		
		JEditorPane editorDescrPokedex = new JEditorPane();
		editorDescrPokedex.setBounds(226, 39, 262, 96);
		frmCrateurDePokmon.getContentPane().add(editorDescrPokedex);
		
		JLabel lblTaille = new JLabel("Taille");
		lblTaille.setBounds(232, 147, 43, 15);
		frmCrateurDePokmon.getContentPane().add(lblTaille);
		
		JSpinner spinnerTaille = new JSpinner();
		spinnerTaille.setBounds(293, 145, 43, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerTaille);
		
		JLabel lblPoid = new JLabel("Poids");
		lblPoid.setBounds(362, 147, 60, 15);
		frmCrateurDePokmon.getContentPane().add(lblPoid);
		
		JSpinner spinnerPoids = new JSpinner();
		spinnerPoids.setBounds(417, 145, 43, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerPoids);
		
		JLabel lblEvDonns = new JLabel("Ev donnés");
		lblEvDonns.setBounds(12, 255, 87, 15);
		frmCrateurDePokmon.getContentPane().add(lblEvDonns);
		
		Stats[] statsTab = {Stats.ATK, Stats.DEF, Stats.ATKSPE, Stats.DEFSPE, Stats.VIT, Stats.PV};
		
		JComboBox<Stats> comboBoxEvGiven = new JComboBox<>(statsTab);
		comboBoxEvGiven.setBounds(100, 250, 87, 24);
		frmCrateurDePokmon.getContentPane().add(comboBoxEvGiven);
		
		JSpinner spinnerNbreEvGiven = new JSpinner();
		spinnerNbreEvGiven.setBounds(226, 253, 28, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerNbreEvGiven);
		
		JLabel lblX = new JLabel("X");
		lblX.setBounds(205, 255, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblX);
		
		
		
		JLabel lblPv = new JLabel("PV");
		lblPv.setBounds(12, 282, 70, 15);
		frmCrateurDePokmon.getContentPane().add(lblPv);
		
		JSpinner spinnerPV = new JSpinner();
		spinnerPV.setBounds(100, 282, 114, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerPV);
		
		JLabel lblExpLv = new JLabel("Exp lv 100");
		lblExpLv.setBounds(232, 174, 81, 15);
		frmCrateurDePokmon.getContentPane().add(lblExpLv);
		
		JSpinner spinnerExpLv100 = new JSpinner();
		spinnerExpLv100.setBounds(331, 172, 129, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerExpLv100);
		
		JLabel lblStatxpBase = new JLabel("XP donnés");
		lblStatxpBase.setBounds(232, 201, 87, 15);
		frmCrateurDePokmon.getContentPane().add(lblStatxpBase);
		
		JSpinner spinnerExpGiven = new JSpinner();
		spinnerExpGiven.setBounds(331, 199, 129, 20);
		frmCrateurDePokmon.getContentPane().add(spinnerExpGiven);
		JButton btnValider = new JButton("Valider");
		
		btnValider.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				String toPrint = "new Espece(";
				if(evolDiag != null){
					if(!Comparaisons.andEgal(null, spinnerAtk.getValue(), spinnerDef.getValue(), spinnerAtkSpe.getValue(), spinnerDefSpe.getValue(), spinnerVit.getValue(), spinnerPV.getValue())){
						if((int) spinnerAtk.getValue() < 0 || (int)spinnerDef.getValue() < 0 || (int)spinnerAtkSpe.getValue() < 0 || (int)spinnerDefSpe.getValue() < 0 || (int)spinnerPV.getValue() < 0 ||(int)spinnerVit.getValue() < 0){
							JOptionPane.showMessageDialog(null, "Une statistique doit Ãªtre positive", "Erreur", JOptionPane.ERROR_MESSAGE);
							return;
						}else{
							toPrint = toPrint.concat(spinnerAtk.getValue() + ", " + spinnerDef.getValue() + ", " + spinnerAtkSpe.getValue() + ", " + spinnerDefSpe.getValue() + ", " + spinnerVit.getValue() + ", " + spinnerPV.getValue() + ", ");
							if(fieldNom.getText() != null){
								toPrint = toPrint.concat("\"" + fieldNom.getText().concat("\", "));
								if(comboBoxType1.getSelectedItem() != null & comboBoxType2.getSelectedItem() != null){
									toPrint = toPrint.concat("Type." + types1[comboBoxType1.getSelectedIndex()].enumName + ", Type." + types2[comboBoxType2.getSelectedIndex()].enumName + ", ");
									if(evolDiag instanceof E_LevelDialog){
										toPrint = toPrint.concat("Espece.EVOLUTION_BY_LEVEL, " + ((E_LevelDialog)evolDiag).spinnerLevel.getValue() + ",new E_Level(" + evolDiag.spinner.getValue() + ", " + ((E_LevelDialog)evolDiag).spinnerLevel.getValue() + "), ");
										
									}else if(evolDiag instanceof E_ItemDialog){
										toPrint = toPrint.concat("Espece.EVOLUTION_BY_OBJECT, -1, new E_Item(" + evolDiag.spinner.getValue() + ", Item.getItem(" + ((Item) ((E_ItemDialog)evolDiag).comboBoxItem.getSelectedItem()).getName() + ")), ");
									}else if(evolDiag instanceof E_TradeItemDialog){
										toPrint = toPrint.concat("Espece.EVOLUTION_BY_TRADE, -1, new E_TradeItem(" + evolDiag.spinner.getValue() + ", Item.getItem(\"" + ((Item) ((E_TradeItemDialog)evolDiag).comboBoxItem.getSelectedItem()).getName() + "\")), ");
									}else if(evolDiag instanceof E_TradeDialog){
										toPrint = toPrint.concat("Espece.EVOLUTION_BY_TRADE, -1, new E_Trade(" + evolDiag.spinner.getValue() + "), ");
									}else if(evolDiag instanceof E_LoveDialog){
										toPrint = toPrint.concat("Espece.EVOLUTION_BY_LOVE, -1, new E_Love(" + evolDiag.spinner.getValue() + "), ");
									}else if(evolDiag instanceof E_LandDialog){
										toPrint = toPrint.concat("Espece.EVOLUTION_BY_PLACE, -1, new E_Land(" + evolDiag.spinner.getValue() + ", " + ((E_LandDialog)evolDiag).textFieldPlace.getText() + "), ");	
									}else{
										toPrint = toPrint.concat("Espece.NO_EVOLUTION, -1, new E_Nope(), "); 
									}
									toPrint = toPrint.concat("null, null, new Stats[]{");
									if(comboBoxEvGiven.getSelectedItem() != null && ((int)spinnerNbreEvGiven.getValue()) > 0){
										int i = (int) spinnerNbreEvGiven.getValue();
										int j = 0;
										for(j = 0; j < i; j++){
											toPrint = toPrint.concat("Stats." + statsTab[comboBoxEvGiven.getSelectedIndex()].name());
											if(j != i - 1){
												toPrint = toPrint.concat(", ");
											}
										}
										toPrint = toPrint.concat("}, ");
										if(spinnerPoids.getValue() == null || spinnerTaille.getValue() == null || editorDescrPokedex.getText() == null){
											JOptionPane.showMessageDialog(null, "Vous devez rentrer une valeur dans tous les champs.", "Erreur", JOptionPane.ERROR_MESSAGE);
											return;
										}else{
											toPrint = toPrint.concat(spinnerTaille.getValue() + "f, " + spinnerPoids.getValue() + "f, \"" + editorDescrPokedex.getText() + "\", ");
											if( spinnerExpGiven.getValue() == null || spinnerExpLv100.getValue() == null){
												JOptionPane.showMessageDialog(null, "Vous devez rentrer une valeur dans tous les champs.", "Erreur", JOptionPane.ERROR_MESSAGE);
												return;
											}else{
												try {
													DialogFinal fin = new DialogFinal(toPrint.concat(spinnerExpGiven.getValue() + ", " + spinnerExpLv100.getValue() + ");"));
												} catch (IOException e1) {
													e1.printStackTrace();
													JOptionPane.showMessageDialog(null, "Le programme a eu une erreur inattendue et doit fermer. Merci de le reporter aux developpeurs.", "Crash", JOptionPane.ERROR_MESSAGE);
												}
											}
										}
									
									}else{
										JOptionPane.showMessageDialog(null, "Vous devez rentrer une valeur dans tous les champs." + Log.saut + "Les EV donnés ne doivent pas Ãªtre en dessous ou égal a 0.", "Erreur", JOptionPane.ERROR_MESSAGE);
										return;
									}
								}else{
									JOptionPane.showMessageDialog(null, "Vous devez rentrer une valeur dans tous les champs.", "Erreur", JOptionPane.ERROR_MESSAGE);
									return;
								}
							}else{
								JOptionPane.showMessageDialog(null, "Vous devez rentrer une valeur dans tous les champs.", "Erreur", JOptionPane.ERROR_MESSAGE);
								return;
							}
						}
					}else{
						JOptionPane.showMessageDialog(null, "Vous devez rentrer une valeur dans tous les champs.", "Erreur", JOptionPane.ERROR_MESSAGE);
						return;
					}
				}else{
					JOptionPane.showMessageDialog(null, "L'évolution est incorrecte. Merci de verifier de bien avoir reglé les paramÃ¨tres d'evolution.", "Erreur", JOptionPane.ERROR_MESSAGE);
					return;
				}
			}
			
		});
		btnValider.setBounds(400, 287, 117, 25);
		frmCrateurDePokmon.getContentPane().add(btnValider);
	}
}
