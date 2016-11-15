package jlppc.regimys.objects.items;

public I_Pokeball extends Item{
    float tauxCapture;
    public I_Pokeball(String nom, float tauxCapture){
      super(nom, false, true, true, BagCat.OBJETS);
      this.tauxCapture = tauxCapture;
    }
    
    public int getTauxCapture(){
      return tauxCapture;
    }
    
    public static void initPokeballs(){
       itemList.add(new I_Pokeball("Pokeball", 1f));
       itemList.add(new I_Pokeball("Super Ball", 1.5f));
       itemList.add(new I_Pokeball("Hyper Ball", 2f));
       itemList.add(new I_Pokeball("Master Ball", 9999f));
    }
}
