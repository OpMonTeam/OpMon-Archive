package jlppc.regimys.util;

public final class VarUtil{
  private HashArray[] hash;
  
  public VarUtil(HashArray...hashArrays){
    hash = hashArrays;
  }
  
  public Object getVar(String name){
    for(HashArray ha : hash){
      if(ha.getValue("nom").equals(name)){
        return ha.getValue("valeur");
      }
    }
    return null;
  }
  
  public void setVar(String name, Object value){
    for(HashArray ha : hash){
      if(ha.getValue("nom").equals(name)){
        ha.setValue("valeur", value);
      }
    }
    
  }
  
  public HashArray[] listVars(){
    return hash;
  }
}
