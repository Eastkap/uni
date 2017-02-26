public class Pile{
    private int espacepris;
    private Machin tab[];
    public Pile(int n){
        this.tailleMax=n;
        tab=new Machin[n];
    }
    public void empiler(Machin m){
        if(espacepris<tab.length){
            tab[espacepris]=m;
            espacepris++;
        }
        else{
            System.out.println("Impossible d'empiler");
        }
    }
    public Machine depiler
}
