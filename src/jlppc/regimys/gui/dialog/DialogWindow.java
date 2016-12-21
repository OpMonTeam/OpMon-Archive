package jlppc.regimys.gui.dialog;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import jlppc.regimys.core.GameState;

public final class DialogWindow extends JInternalFrame {
	JLabel text;
	JPanel defaultPanel;
	public static Thread keyListeners;
	public DialogWindow() {
		super();
		defaultPanel = new JPanel();
		defaultPanel.setLayout(null);
		this.setContentPane(defaultPanel);
		text = new JLabel("");
		text.setBounds(10, 11, 476, 98);
		defaultPanel.add(text);
		
		JLabel background = new JLabel("");
		background.setBounds(0, 0, 496, 120);
		defaultPanel.add(background);
		keyListeners = new Thread(new Runnable(){

			@Override
			public void run() {
				defaultPanel.addKeyListener(new KeyListener(){

					@Override
					public void keyPressed(KeyEvent arg0) {
						// TODO Auto-generated method stub
						
					}

					@Override
					public void keyReleased(KeyEvent arg0) {
						if(arg0.getKeyCode() == KeyEvent.VK_Z){
							continuer();
						}
						
					}

					@Override
					public void keyTyped(KeyEvent arg0) {
						// TODO Auto-generated method stub
						
					}
					
				});
				
				/*defaultPanel.addMouseListener(new MouseListener() {
					
					@Override
					public void mouseReleased(MouseEvent e) {
						continuer();
						
					}
					
					@Override
					public void mousePressed(MouseEvent e) {
						// TODO Auto-generated method stub
						
					}
					
					@Override
					public void mouseExited(MouseEvent e) {
						// TODO Auto-generated method stub
						
					}
					
					@Override
					public void mouseEntered(MouseEvent e) {
						// TODO Auto-generated method stub
						
					}
					
					@Override
					public void mouseClicked(MouseEvent e) {
						// TODO Auto-generated method stub
						
					}
				});*/
				
			}
			
		});
		keyListeners.start();
		
		
	}
	
	public void continuer(){
		if(GameState.state == GameState.DIALOGUE){
			text.setText("");
			GameState.state = GameState.MARCHE;	
		}
		
	}
	
	public void printText(String text){
		this.text.setText(text);
		GameState.state = GameState.DIALOGUE;
	}
}
