package jlppc.regimys.objects.attacks;

import jlppc.regimys.enums.Type;
import jlppc.regimys.objects.*;

public class Morphing extends Attaque{
  public Morphing(){
    super("Morphing", 0, Type.NORMAL, 100, false, true, -1, true, 10);
  }
  
  public void effetAvant(Pokemon atk, Pokemon def){}
  
  public void effetApres(Pokemon atk, Pokemon def){
    atk.setStats(new int[]{def.getStatATK(), def.getStatDEF(), def.getStatATKSPE(), def.getStatDEFSPE(), def.getStatVIT()}, def.getAttaques(), def.getEspece(), new Type[]{def.getType1(), def.getType2()});
    fosout("%o se transforme en %o!", atk.getSurnom(), def.getSurnom());
  }
}
