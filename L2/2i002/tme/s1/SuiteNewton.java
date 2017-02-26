public class SuiteNewton{
  private int u;
  public SuiteNewton(int x){
    u=x;
  }
  public double GetRacine(double e){
    double uprecedent=u/2;
    double usuivant=(uprecedent+(u/uprecedent))/2;
    while (Math.abs(usuivant-uprecedent)>e){
      uprecedent=usuivant;
      usuivant=(uprecedent+(u/uprecedent))/2;
    }
    return usuivant;
  }
}
