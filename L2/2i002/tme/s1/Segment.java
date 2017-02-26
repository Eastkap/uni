public class Segment{
  private int x,y;
  public Segment(int extX,int extY){
    x=extX;
    y=extY;
  }

  public int longueur(){
    if (x>y){
      return x-y;
    }
    return y-x;
  }
  public String toString(){
    return "segment ["+x+","+y+"]";
  }
}
