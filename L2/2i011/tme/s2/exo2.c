#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
	int64_t num;
	int64_t den;
}ratio_t;

//Calcul du pgcd
int64_t gcd(int64_t a, int64_t b){
	int64_t reste;
	while(b){
		reste=a%b;
		a=b;
		b=reste;
	}
	return a;
}

//Construit le nb rationnel sous forme de fraction reduite
ratio_t createRatio(int64_t a, int64_t b){
	if(b==0){
		printf("fraction inexistante b=0!!!!!!\n");
		exit(1);
	}
	int64_t pgcd=gcd(a,b);
	ratio_t ratio={a/pgcd,b/pgcd};
	return ratio;
}

//Revoie Somme de deux fractions rationnelles
ratio_t addRatio(ratio_t a, ratio_t b){
	a.num=a.num*b.den+a.den*b.num;
	a.den=a.den*b.den;
	return createRatio(a.num,a.den);
}

//Renvoie la difference de deux fractions rationnelles
ratio_t subRatio(ratio_t a, ratio_t b){
	a.num=a.num*b.den-a.den*b.num;
	a.den=a.den*b.den;
	return createRatio(a.num,a.den);
}

//Renvoie le produit de deux fractions rationnelles
ratio_t mulRatio(ratio_t a, ratio_t b){
	a.num=a.num*b.num;
	a.den=a.den*b.den;
	return createRatio(a.num,a.den);
}

//renvoie la division de deux fractions rationnelles
ratio_t divRatio(ratio_t a, ratio_t b){
	a.num=a.num*b.den;
	a.den=a.den*b.num;
	return createRatio(a.num,a.den);
}

//Renvoie une approximation d'un nb rationnelle
double approxRatio(ratio_t a){
	return a.num/a.den;
}
//Affiche un nb rationnelle
void printRatio(ratio_t a){
	printf("%ld\t/\t",a.num);
	printf("%ld\n",a.den);
}

int factorielle(unsigned int a){
	int i;
	unsigned int f=1;
	if(a==0) return f;
	for(i=1; i<=a; i++)
	{
		f*=i;
	}
	return f;
}
//Renvoie la suite Sn
ratio_t computeS(unsigned int n){
	int i;
	ratio_t r = {1,1};
	if (n==0)
		return r;
	for (i=2; i<=n; i++){
		//printf("num = %lld denom = %lld\t\t tour i= %d\n", r.num, r.den, i);
		r.num = r.num * factorielle(i) + 1*r.den;
		r.den = r.den *factorielle(i);
	}
	return r;

}

ratio_t computeA(unsigned int n){
	unsigned int i;
	ratio_t azero={11,2},aun={61,11},tmp;
	if(n==0) return azero;
	if(n==1) return aun;
	for(i=1;i<n;i++){
		//tmp=subRatio(createRatio(111,1),divRatio(subRatio(createRatio(1130,1),divRatio(createRatio(3000,1),azero)),aun));
		tmp=divRatio(createRatio(3000,1),azero);
		tmp=subRatio(createRatio(1130,1),tmp);
		tmp=divRatio(tmp,aun);
		tmp=subRatio(createRatio(111,1),tmp);
		azero=aun;
		aun=tmp;

	}
	return aun;
}

int main(){
	int64_t a = 4, b=6;
	int64_t a2=2, b2=5;
	unsigned int n; //variable test question 2

	//Tests question 1
	ratio_t f = {a,b};
	ratio_t f2 = {a2, b2};
	printf("Fractions de depart :\n");
	printRatio(f);
	printRatio(f2);

	printf("Test createRatio\n");
	printRatio(createRatio(a,b));

	printf("Test addRatio\n");
	printRatio(addRatio(f,f2));

	printf("Test subRatio\n");
	printRatio(subRatio(f,f2));

	printf("Test mulRatio\n");
	printRatio(mulRatio(f,f2));

	printf("Test divRatio\n");
	printRatio(divRatio(f,f2));

	//Test question 2;
    n=10;
	printf("Test factorielle : %u! = %u\n", n, factorielle(n));

	printf("Test computeS :\n");
	printf("Pour n = %d, Sn est egale a :\n", n);
	ratio_t Sn = computeS(n);
	printRatio(Sn);
	printf("Et sous forme de fraction reduite Sn = :\n");
	printRatio(createRatio(Sn.num, Sn.den));

	printf("Test computeA :\n");
	// Q2+Q3
	ratio_t An = computeA(2);
	printRatio(An);
	int i;
	long double ca;
	for(i=5;i<=20;i+=5){
        printf("Pour n = %d, An est egale a :\n", i);
        ratio_t An = computeA(i);
        printRatio(An);
        ca=An.num/An.den;
        printf("soit ~ %Lf\n",ca);
	}
    // selon la boucle , An tend vers 5, puis 0. On en deduit que lon ecrase les valeurs des unsigned int et meme long double lors de la division
    // en programmant la boucle sur python, on peut voir que la suite a l'air de tenre vers 100.
	return 0;
}
