#include <stdio.h>
#include <stdint.h>

int appels=0;

uint64_t multiplication1Bit(uint64_t a, uint64_t b)
{
	appels++;
	if ((a==0)||(b==0)){
		return 0;
	}
	else {
		return 1;
	}
	//return a&b;
}

uint64_t multiplicationNaive(uint64_t a, uint64_t b)
{

	if ((a==0)||(b==0)) { return multiplication1Bit(a,b); }
	if ((a==1)&&(b==1)) {return multiplication1Bit(a,b);}

	return multiplicationNaive(a&1u, b&1u)+(multiplicationNaive(a&1u,b>>1)<<1)+(multiplicationNaive(a>>1, b)<<1);
}

uint64_t multiplicationKaratsuba(uint64_t a, uint64_t b, int k){


	/*cas de base*/
	if(k==1){
		return multiplication1Bit(a,b);
	}
	else
	{
	uint64_t p, d, e, t, v, u;

	int t1=k/2;
	int t2=k-t1;

	uint64_t a1= a>>t1;
	uint64_t a0= a-(a1<<t1);
	int sa=1;

	uint64_t b1=b>>t1;
	uint64_t b0= b-(b1<<t1);
	int sb=1;

	if(a0 >= a1) {
		d=a0-a1;
	}
	else {
		d=a1-a0;
		sa=-1;
	}
	if(b0 >= b1){
		e=b0-b1;
		sb=-1;
	}
	else {
		e=b1-b0;
	}

	t=multiplicationKaratsuba(a1,b1,t2);
	u=multiplicationKaratsuba(a0,b0,t1);
	v=multiplicationKaratsuba(d,e,t2);

	v=(sa*sb)*v+t+u;
	p=(t<<k)+(v<<k/2)+u;

	return p;
	}
}


int main(){

	uint64_t a=8u, b=8u;

	printf("Test multiplication machine : %llu x %llu = %llu\n\n", a, b, a*b);
	printf("Test multiplication 1bit : %d x %d = %llu\n", 1, 0, multiplication1Bit(1u,0u));
	printf("nombre d'appels de la fonction 1Bit: %d\n\n", appels);
	appels=0;
	printf("Test multiplication naive : %llu x %llu = %llu\n", a, b, multiplicationNaive(a,b));
	printf("nombre d'appels de la fonction 1Bit: %d\n\n", appels);
	appels=0;
	printf("Test multiplication karatsuba: %llu x %llu = %llu\n", a, b, multiplicationKaratsuba(a,b,64));
	printf("nombre d'appels de la fonction 1Bit: %d\n\n", appels);

	return 0;
}
