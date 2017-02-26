public class Cabine{
  private double volume;
  private String couleur;

  public Cabine(double v, String c){
    volume = v;
    couleur = c;
  }

  public String toString(){
    return "Volume : "+volume+"m3, Couleur : "+couleur;
  }

  public void setCouleur(String couleur){
    this.couleur = couleur;
  }
}
