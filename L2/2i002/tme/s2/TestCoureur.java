public class TestCoureur{
  public static void main(String[] args){
    Coureur c1=new Coureur();
    Coureur c2=new Coureur();
    Coureur c3=new Coureur();
    Coureur c4=new Coureur();
    if(!c1.getALeTemoin())
        c1.setALeTemoin(true);
    c2.setALeTemoin(false);
    c3.setALeTemoin(false);
    c4.setALeTemoin(false);
    c1.courir();
    c1.passeTemoin(c2);
    c2.courir();
    c2.passeTemoin(c3);
    c3.courir();
    c3.passeTemoin(c4);
    c4.courir();
    double temps=c1.getTempsAu100()+c2.getTempsAu100()+c3.getTempsAu100()+c4.getTempsAu100();
    System.out.println("Temps du 400: "+String.format("%.1f",temps));
  }
}
