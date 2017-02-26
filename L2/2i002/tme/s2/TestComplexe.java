public class TestComplexe{
  public static void main(String[] args){
    Complexe a= new Complexe(1,1);
    Complexe b= new Complexe(2,2);
    Complexe c= new Complexe(3,1);
    System.out.println(a.toString());
    System.out.println(b.toString());
    System.out.println(a.estReel());
    System.out.println(b.estReel());
    c=a.addition(b);
    System.out.println(c.toString());
    c=a.multiplication(b);
    System.out.println(c.toString());
  }
}
/*
1.0 + 1.0 i
2.0 + 2.0 i
false
false
3.0 + 3.0 i
0.0 + 4.0 i
*/
