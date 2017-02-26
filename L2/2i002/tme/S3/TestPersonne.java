public class TestPersonne{
    public static void main(String[] args) {
        Personne p1 =new Personne();
        Personne p2 =new Personne();
        Personne p3 =new Personne();
        System.out.println(p1.toString());
        System.out.println(p2.toString());
        System.out.println(p3.toString());
        //mariage de p1 et p2
        p1.epouser(p2);
        System.out.println(p1.toString());
        System.out.println(p2.toString());
        //essai de mariage entre p1 et p3
        p3.epouser(p1);
        //divorce entre p1 et p2
        p1.divorcer();
        System.out.println(p1.toString());
        System.out.println(p2.toString());
    }
}
