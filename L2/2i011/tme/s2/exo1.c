#include <stdio.h>
#include <stdint.h>

void ext_eucl_div(int64_t *u, int64_t *v, int64_t *g, int64_t a, int64_t b){
	if(a==b){
		*u=1,*v=0,*g=a;
		return;
	}
	int64_t uant=0,vant=1,tmp,reste;
	*u=1,*v=-(int)a/b; // on initialise les cofacteurs
	while(b){
		reste=a%b;
		tmp=*u;
		a=b;
		b=reste;
		if(b!=0){
			*u=uant-(a/b)*(*u);
			uant=tmp;
			tmp=*v;
			*v=vant-(a/b)*(*v);
			vant=tmp;
		}
	}
	*v=vant;
	*u=uant;
	*g=a;
}

int64_t gcd(int64_t a, int64_t b){
	int64_t u, v,g;
	ext_eucl_div(&u,&v,&g,a,b);
	return  g;
}
int modular_inverse(int64_t *i, int64_t a, int64_t m){
	int64_t u, v,g;
	ext_eucl_div(&u,&v,&g,a,m);
	if(g!=1){
		printf("pas dinverse\n");
		return 0;
	}
	*i=u;
	return 1;
}

int main (){
	int64_t u, v,g;
	int64_t a=27u, b=6u, m=5;
	ext_eucl_div(&u,&v,&g,a, b);
	printf("Test fonctions ext_eucl_div: pgcd(%ld, %ld) = %ld * %ld + %ld * %ld \n", a,b,a,u,b,v); 
	printf("Test la fonction gcd : gcd(27,6)= %ld \n",gcd(a,b));
	modular_inverse(&g, m, a);
	printf("Test inverse modulaire : l'inverse modulaire de %ld modulo %ld est %ld.\n", m, a, g);
	return 0;
}
		
