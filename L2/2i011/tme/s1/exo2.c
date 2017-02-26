#include <stdio.h>
#include <stdint.h>

void conversionVersBinaire(unsigned int r[64], uint64_t n){
	unsigned int i=64;
	while(i>0){
		i--;
		if(n==0)
		{
			r[i]=0;}
		else{
			r[i]= n%2;
			n=(n-r[i])/2;
			printf("%ld\n", n);
		}
	}
}

void afficher(unsigned int tab[64]){
	int i;
	for(i=0;i<64;i++){
		printf("%u", tab[i]);
	}
}

int main(){
	unsigned int tab[64];
	conversionVersBinaire(tab, 588);
	afficher(tab);

	return 0;
}
