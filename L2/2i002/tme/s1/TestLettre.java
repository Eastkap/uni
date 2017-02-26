public class TestLettre{
  public static void main(String[] args){
    Lettre l;
    int x=1;
    for (char c = 'a'; c<='z'; c++) {
      l=new Lettre(c);
      if(x%5==0)
        System.out.println(c);
      else{
        System.out.print(l.getCarac());
        System.out.print(' ');
      }
      x++;
    }
  }
}
