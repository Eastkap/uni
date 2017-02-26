/*Exercice 2 tme 2I011 : Arithmetique flottante*/

#include <stdio.h>

/*Calcul la valeur absolue*/
float absolueFloat(float num){
	if(num<0)
		return -num;
	return num;
}
/*...pour les double*/
double absolueDouble(float num){
	if(num<0)
		return -num;
	return num;
}


/*Calcul l'erreur relative*/
float erreurRelative(float trouvee, float reelle){
	float erreur =(float) (trouvee-reelle)/reelle;
	return absolueFloat(erreur);
}
/*... pour les double*/
double erreurRelativeDouble(double trouvee, double reelle){
	double erreur =(double) (trouvee-reelle)/reelle;
	return absolueDouble(erreur);
}

/*Calcul Jn en utilisant IEEE 32 et en commancant la sommation avec les termes plus grands*/
float sumJFloatDecreasing(unsigned int n){
	int i;
	float somme=0;

	for(i=1; i<n; i++){
		somme += (float) 1/i;
	}
	return somme;
		
}

/*Calcul Jn en utilisant IEEE 32 et en commancant la sommation avec les termes plus petits*/	
float sumJFloatIncreasing(unsigned int n){
	
	int i;
	float somme=0;
	for(i=n; i>0; i--){
		somme += (float) 1/i;
	}
	return somme;
}

/*Calcul Jn en utilisant IEEE 64 et en commancant la sommation avec les termes plus grands*/
double sumJDoubleDecreasing(unsigned int n){
	int i;
	double somme=0;

	for(i=n; i>0; i--){
		somme += (double) 1/i;
	}
	return somme;
		
}
/*Calcul Jn en utilisant IEEE 64 et en commancant la sommation avec les termes plus petits*/
double sumJDoubleIncreasing(unsigned int n){
	int i;
	double somme=0;

	for(i=1; i<n; i++){
		somme += (double) 1/i;
	}
	return somme;
		
}

int main(){
	
	unsigned int n;
	float t_f;
	double t_d;
	double reelle=0;
		
	printf("Saisir n :\n");
	scanf("%u", &n);
	
	if(n==10) reelle = 2.92896825396825396825;
	if(n==100) reelle = 5.18737751763962026080;
	if(n==1000) reelle = 7.48547086055034491265;
	if(n==10000) reelle = 9.78760603604438226417;
	if(n==100000) reelle = 12.09014612986342794736;
	if(n==1000000) reelle = 14.39272672286572363138;
	
	
	printf("\nTest sumJFloatDecreasing :\n");
	t_f =sumJFloatDecreasing(n);
	printf("J(%u) = %.20f\n", n, t_f);
	
	//si c'est une des valeurs dont on connait la valeur exacte
	if(reelle!=0) {printf("Erreur relative = %.20f\n", erreurRelative(reelle, t_f));}
	
	printf("Test sumJFloatIncreasing :\n");
	t_f=sumJFloatIncreasing(n);
	printf("J(%u) = %.20f\n", n, t_f);
	
	if(reelle!=0) {printf("Erreur relative = %.20f\n", erreurRelative(reelle, t_f));}
	
	
	printf("Test sumJDoubleDecreasing :\n");
	t_d= sumJDoubleDecreasing(n);
	printf("J(%u) = %.20f\n", n,t_d);
	if(reelle!=0) {printf("Erreur relative = %.20f\n", erreurRelativeDouble(reelle, t_d));}
	
	
	printf("Test sumJDoubleIncreasing :\n");
	t_d=sumJDoubleIncreasing(n);
	printf("J(%u) = %.20f\n", n, t_d);
	if(reelle!=0) {printf("Erreur relative = %.20f\n", erreurRelativeDouble(reelle, t_d));}
	
	
	return 0;
	
}

