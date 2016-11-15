package jlppc.regimys.util.math;

import jlppc.utils.Static;

@Static
public class Maths{
  public static float racine(float dessous, float exposant){
    return (float) Math.pow(dessous, 1/exposant);
  }
  
  public static double racine(double dessous, double exposant){
    return Math.pow(dessous, 1/exposant);
  }
}
