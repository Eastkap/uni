public class Coureur{
  private int nuDossard;
  private double tempsAu100;
  private boolean aLeTemoin;

  public Coureur(int a){
    nuDossard=a;
    tempsAu100=12+Math.random()*4;
    aLeTemoin=false;
  }
  public Coureur(){
    this((int)(1+Math.random()*1000));
  }
  public int getNuDossard(){
      return nuDossard;
  }
  public double getTempsAu100(){
      return tempsAu100;
  }
  public boolean getALeTemoin(){
      return aLeTemoin;
  }
  public void setALeTemoin(boolean b){
      aLeTemoin=b;
  }
  public String toString(){
      String a="non";
      if(aLeTemoin){
        a="oui";
    }
      return "Coureur "+nuDossard+" tempsAu100 : "+String.format("%.1f",tempsAu100)+"s au 100m aLeTemoin : "+a;
  }
  public void passeTemoin(Coureur c){
      System.out.println("moi, coureur "+nuDossard+", je passe le témoin au coureur "+c.nuDossard);
      aLeTemoin=false;
      c.aLeTemoin=true;
  }
  public void courir(){
      System.out.println("je suis le coureur "+nuDossard+" et je cours.");
  }
}
