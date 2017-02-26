public class TestVillageois{

	public static void main(String[] jaco){
		Villageois v1 = new Villageois("Jacobo");
		Villageois v2 = new Villageois("Jul");
		Villageois v3 = new Villageois("Castor");
		Villageois v4 = new Villageois("X");
		System.out.println(v1.presentation());
		System.out.println(v2.presentation());
		System.out.println(v3.presentation());
		System.out.println(v4.presentation());
		System.out.println(v1.getNom());
		System.out.println(v1.getPoids());
		System.out.println(v1.poidsSouleve());
		System.out.println(v1.getMalade());
		System.out.println(v1.toString());
		if(v1.poidsSouleve()+v2.poidsSouleve()+v3.poidsSouleve()+v4.poidsSouleve()>=100)
			System.out.println("Les 4 villageois ont réussi à soulever le rocher.");
		else
			System.out.println("Les 4 villageois n'ont pas réussi à soulever le rocher.");
	}
}
