public class Alea{
    public static char lettre(){
        return (char)( 'a'+(char)(int)Math.round(Math.random()*25));
    }
    public static String chaine(){
        String retour=new String();
        for(int i=0;i<10;i++){
            retour+=lettre();
        }
        return retour;
    }
    public static void main(String[] args) {
        System.out.println(Alea.chaine());
    }
}


//methodes de clase: methodes qui sont definies a linterieur d'une classe
