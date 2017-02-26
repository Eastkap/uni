public class Personne{
    private String nom;
    private Personne conj;

    public Personne(){
        this("Individu");
        nom=nom +tirageLettre()+tirageLettre()+tirageLettre();
        conj=null;
    }
    public Personne(String nom){
        this.nom=nom;
        conj=null;
    }
    public String toString(){
        String phrase;
        if(this.conj!=null)
            phrase=", marié";
        else
            phrase=", célibataire";
        return nom+phrase;
    }
    public void epouser(Personne p){
        if(this.conj!=null || p.conj!=null)
            System.out.println("Ce mariage est impossible!");
        else{
            this.conj=p;
            p.conj=this;
        }
    }
    public void divorcer(){
        if(this.conj!=null){
            (this.conj).conj=null;
            this.conj=null;
        }
    }
    private char tirageLettre(){
        return (char)((int)(Math.random()*26)+'A');
    }
}
