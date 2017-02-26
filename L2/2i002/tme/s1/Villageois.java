public class Villageois{
	private String nom;
	private double poids;
	private boolean malade;

	public Villageois(String nomVillageois){
		nom = nomVillageois;
		poids = Math.random()*100 + 50;
		malade = Math.random() < 0.20;
	}

	public String getNom(){
		return this.nom;
	}
	public double getPoids(){
		return this.poids;
	}
	public double poidsSouleve(){
		if(malade)
			return this.poids/4;
		return this.poids/3;
	}
	public boolean getMalade(){
		return this.malade;
	}public String toString(){
		if(this.malade)
			return "villageois : "+getNom()+", poids: "+getPoids()+" kg, malade : oui";
		return "villageois : "+getNom()+", poids: "+getPoids()+" kg, malade : non";
		//villageois : Eustache, poids : 95 kg, malade : non"
	}
	public String presentation(){
		if(malade){
			return "Le villageois "+nom+" pese "+poids+" kg et il est malade.";
		}
		return "Le villageois "+nom+" pese "+poids+" kg et il n'est pas malade.";
	}
}
