package jlppc.regimys.gui.animation;

import java.awt.Image;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

import jlppc.regimys.gui.MainFrame;
import jlppc.regimys.gui.game.Plan;
import jlppc.regimys.launch.Start;
import jlppc.utils.Log;
import jlppc.utils.Log.Entry;

public class Animation{
	public static final Image ALPHA;
	static{
		try {
			ImageIO.read(new File("TODO : Creer une image alpha total en 16x16"));
		} catch (IOException e) {
			Log.writeT(Entry.FATAL, "Erreur lors du chargement des animations. Impossible de continuer : Va causer trop d'erreurs.");
			Start.gererException(e, true);
		}finally{//Juste pour le compilateur...
			ALPHA = null;
		}
	}
	
  int timeBetweenFrames;//En millisecondes
  Image[] framesLabelA;
  Image[] framesLabelB;
  boolean player;
  String name;
  public Animation(String name, Image[] framesLabelA, Image[] framesLabelB, int timeBetweenFrames, boolean player){
    this.timeBetweenFrames = timeBetweenFrames;
    this.framesLabelA = framesLabelA;
    this.framesLabelB = framesLabelB;
    this.player = player;
    this.name = name;
  }
  
  public void animate(int labelAX, int labelAY, int labelBX, int labelBY){
    if(MainFrame.frame.getGameWindow().getContentPane() instanceof Plan){
    Plan actuel = (Plan) MainFrame.frame.getGameWindow().getContentPane();
       for(int i = 0; i < ((framesLabelA.length > framesLabelB.length) ? framesLabelA.length : framesLabelB.length); i++){
        Image frameLabelA = framesLabelA[i];
        Image frameLabelB = framesLabelB[i];
        if(frameLabelA == null){
          frameLabelA = ALPHA;
        }
        if(frameLabelB == null){
          frameLabelB = ALPHA;
        }
        actuel.getLabel((player ? 3 : 2), labelAX, labelAY).setIcon(new ImageIcon(frameLabelA));
        actuel.getLabel((player ? 3 : 2), labelBX, labelBY).setIcon(new ImageIcon(frameLabelB));
        try{
        wait(timeBetweenFrames);
        }catch(InterruptedException e){
        Log.writeT(Entry.WARNING, "Erreur lors de l'animation " + name);
        Start.gererException(e, false);
        break;
        
        }
        
        

      }
    }
  }
   
}
