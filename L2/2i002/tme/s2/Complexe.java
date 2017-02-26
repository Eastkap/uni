public class Complexe{
  private double reelle, imag;
  public Complexe(double reelle, double imag){
    this.reelle=reelle;
    this.imag=imag;
  }
  public Complexe(){
    this.reelle=-2+ Math.random() *4;
    this.imag=-2+Math.random()*4;
  }
  public String toString(){
    return this.reelle+" + "+this.imag+" i";
  }
  public Complexe addition(Complexe b){
    Complexe retour=new Complexe(reelle+b.reelle,this.imag+b.imag);
    return retour;
  }
  public Complexe multiplication(Complexe b){
    Complexe retour= new Complexe(this.reelle*b.reelle-(this.imag*b.imag),this.reelle*b.imag+this.imag*b.reelle);
    return retour;
  }
  public boolean estReel(){
    return (this.imag==0.0);
  }
}
