public class Tracteur {
  private Cabine c;
  private Roue r1, r2, r3, r4;

  public Tracteur(Cabine c, Roue r1, Roue r2, Roue r3, Roue r4){
    this.c = c;
    this.r1 = r1;
    this.r2 = r2;
    this.r3 = r3;
    this.r4 = r4;
  }

  public String toString(){
    return c.toString();
  }

  public void peindre(String couleur){
    c.setCouleur(couleur);
  }

  public Tracteur copie(){
    Tracteur n = new Tracteur(new Cabine((this.c).v,(this.c).v),r1,r2,r3,r4 );
    return n;
  }
}
