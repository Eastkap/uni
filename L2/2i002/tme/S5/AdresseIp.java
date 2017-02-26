public class AdresseIp{
    private static int[] tab={192,168,0,0};
    public static String getAdresseIP(){
        String a=new String();
        for(int i=3;i>=0;i--){
            if(tab[i]==255){
                tab[i]=0;
                continue;
            }
            else{
                tab[i]++;
                break;
            }
        }
        for(int i=0;i<4;i++){
            a+=Integer.valueOf(tab[i]);
            if(i!=3){
                a+='.';
            }
        }
        return a;
    }
    public static void main(String[] args) {
        for(int i=0;i<1000000;i++){
            System.out.println(AdresseIp.getAdresseIP());
        }
    }
}
