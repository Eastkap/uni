public class TestTrianglePascal{
    public static void main(String[] args) {
        TrianglePascal triangle[]=new TrianglePascal[10];
        for(int i=0;i<triangle.length;i++){
            triangle[i]=new TrianglePascal(i+1);
            triangle[i].remplirTriangle();
            System.out.println(triangle[i].toString());
        }
    }
}
