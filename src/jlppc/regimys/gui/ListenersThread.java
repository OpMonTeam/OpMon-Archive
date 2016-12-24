package jlppc.regimys.gui;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class ListenersThread implements Runnable {
	public ListenersThread() {
		super();
	}

	@Override
	public void run() {
		//Dialog
		KeyListener keylistenerDialog = new KeyListener(){

			@Override
			public void keyPressed(KeyEvent arg0) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void keyReleased(KeyEvent arg0) {
				if(arg0.getKeyCode() == KeyEvent.VK_Z){
					MainFrame.frame.dw.continuer();
				}
				
			}

			@Override
			public void keyTyped(KeyEvent arg0) {
				// TODO Auto-generated method stub
				
			}
			
		};
		MouseListener mouselistenerDialog = new MouseListener() {
			
			@Override
			public void mouseReleased(MouseEvent e) {
				MainFrame.frame.dw.continuer();
				
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
		};
		MainFrame.frame.addKeyListener(keylistenerDialog);
		//MainFrame.frame.dw.addKeyListener(keylistenerDialog);
		//MainFrame.frame.gw.addKeyListener(keylistenerDialog);
		
		MainFrame.frame.addMouseListener(mouselistenerDialog);
		MainFrame.frame.dw.addMouseListener(mouselistenerDialog);
		MainFrame.frame.gw.addMouseListener(mouselistenerDialog);
		
	
		
	}
}
