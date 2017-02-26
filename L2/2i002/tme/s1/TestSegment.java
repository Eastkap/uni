public class TestSegment{
  public static void main (String[] args){
    int lseg1, lseg2;
    Segment s1= new Segment(6,8);
    Segment s2= new Segment(12,5);
    lseg2=s1.longueur();
    lseg2=s2.longueur();
    if (lseg1>lseg2){
      System.out.println("Le "+s1.toString()+" est plus long");
    }
    else{
      System.out.println("Le "+s2.toString()+" est plus long");
    }

  }
}
