package jlppc.regimys.gui.animation;

public class Animation{
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
    if(MainFrame.getGameWindow().getContentPane() instanceof Plan){
    Plan actuel = (Plan) MainFrame.getGameWindow().getContentPane();
       for(int i = 0; i < ((framesLabelA.length > framesLabelB.length) ? framesLabelA.length : framesLabelB.lenght); i++){
        Image frameLabelA = framesLabelA[i];
        Image frameLabelB = framesLabelB[i];
        if(frameLabelA == null){
          frameLabelA = ImageIO.read("TODO : Creer une image alpha total en 16x16");
        }
        if(frameLabelB == null){
          frameLabelB = ImageIO.read("IDEM");
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
