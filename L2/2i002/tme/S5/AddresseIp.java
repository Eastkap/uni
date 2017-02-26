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
        }
        return a;
    }
    public static void main(String[] args) {
        System.out.println(AddresseIp.getAdresseIP());
    }
}
