package jlppc.regimys.gui.game;

import javax.swing.JPanel;

import jlppc.regimys.objects.Pokemon;

import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public final class BattlePanel extends JPanel {
	JLabel pokeAdverse;
	JLabel minePoke;
	JLabel background;
	public BattlePanel(Image backeground) {
		super();
		setLayout(null);
		
		pokeAdverse = new JLabel("");
		pokeAdverse.setBounds(297, 36, 154, 220);
		add(pokeAdverse);
		
		minePoke = new JLabel("");//Non, non, je n'ai jamais fait Allemand.
		minePoke.setBounds(40, 236, 143, 244);
		add(minePoke);
		
		background = new JLabel("");
		background.setBounds(0, 0, 512, 512);
		background.setIcon(new ImageIcon(backeground));
		add(background);
	}
	
	public void setPokeAdverse(Pokemon poke){
		pokeAdverse.setIcon(new ImageIcon(poke.getEspece().getSpriteBattleFace()));
	}
	public void setPoke(Pokemon poke){
		minePoke.setIcon(new ImageIcon(poke.getEspece().getSpriteBattleFace()));
	}
}
