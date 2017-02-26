public class TestTracteur{
//javac *.java && java TestTracteur
  public static void main(String[] args) {
    Roue g1 = new Roue(120);
    Roue g2 = new Roue(120);
    Roue p1 = new Roue();
    Roue p2 = new Roue();
    Cabine c = new Cabine(10, "bleu");
    Tracteur t1 = new Tracteur(c, g1, g2, p1, p2);
    System.out.println(t1.toString());
    //Tracteur t2  = (Tracteur)t1.clone(); c etant prive on ne peut pas
    Tracteur t2 = t1.copie();
    System.out.println(t1.toString());
    t2.peindre("jaune");
    System.out.println(t1.toString());
  }
}
