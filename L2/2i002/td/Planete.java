// anom, rayon (variables instance privees, methodes publiques)
//b n et r
// c) s
/* q2 a) lignes 5 a 8 (methode avec maj, meme nom que classe ne retourne rien)
Ça sert a initialiser les variables dinstance dune novuelle instance.


3) toString() getRayon()
4) public class SystemeSolaire{
  public static void main(String [] MABITEtmoncouto){
    Planete p= new Planete("Mercure",2439.7);
    Planete t= new Planete ("Terre", 6378.13)
    Planete p2=p;
    System.out.println(p.toString());
    System.out.println(t.getRayon());
  }
}

5)
 SystemeSolaire.java
 javac Plante.java SystemeSolaire.java
 java SystemeSolaire <- contient le main
  si private on peut pas acceer par le point

EXO 3:
  public class Personne{
  private String nom;
  private int age;
}

type: simple de base, int , float, char, double
    type-objet , type-classe: Planete, Prsonnne, String, File, Math

  public class Personne{
  private String nom;
  private int age;
  public Personne(String n, int a){
    nom=n;
    age=a;
  }
  public String toString(){
  return "Je m'appelle"+nom+"j'ai"+age+"ans";
}
private void sePresenter(){
  System.out.println(toString());
}

public class Presentation{
  public static void main(String [] args){
    Personne p1= new Personne("Paul",25);
    Personne p2= new Personne("Jean",37);
  }
}


3.4: Erreur de compilation
3.5: Seulement par toStrin(), mais on ne peut pas connaitre lage suelement
