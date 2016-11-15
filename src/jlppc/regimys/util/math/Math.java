package jlppc.regimys.util.math;

import jlppc.utils.static;

@Static
public class Math extends java.util.Math{
  public static float racine(float dessous, float exposant){
    return pow(dessous, 1/exposant);
  }
  
  public static double racine(double dessous, double exposant){
    return pow(dessous, 1/exposant);
  }
}
