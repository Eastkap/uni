/* Exo1 - Fonctions de base */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>



/*Alloue un vecteur de dimension m ou echoue si pas assez de memoire dispo*/
double *allocateVector(unsigned int m){

	int i;
	double *vect = calloc(m, sizeof(double));

	if (!vect) { exit(1); }
	for(i=0; i<m; i++){
		vect[i] = 0;
	}
	return vect;
}
/*Alloue matrine taille m*n*/
double *allocateMatrix(unsigned int m, unsigned int n){
	return allocateVector(m*n);

}

void freeVector(double *v){
	free(v);
}

void freeMatrix(double *m){
	free(m);
}

void copyVector(double *v, double *u, unsigned int  m){
	int i;
	for(i=0;i<m;i++){
		v[i]=u[i];
	}
}

void copyMatrix(double *B, double*A, unsigned int m, unsigned int n){

	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			B[j+i*n]=A[j+i*n];
		}
	}
}

void elementVector(double *v, unsigned int k, unsigned int m){
	int i;

	for(i=0;i<m;i++){
		if(i==k)
			v[i]=1;
		else
			v[i]=0;
	}
}

void identityMatrix(double *A, unsigned int m, unsigned int n){
	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i==j)
				A[j+i*n]=1;
			else
				A[j+i*n]=0;
		}
	}

}

/*valeur entre -1 et 1*/
double randomValue(){
	//printf("%ld\n",rand());
	return -1+2*((double)(rand())/(double)RAND_MAX);
}

/*valeur entre min et max*/
double randomValueDeux(double min, double max){
	return min+(max-min)*((double)(rand())/(double)RAND_MAX);
}

void randomVector(double *A, unsigned int m){

	int i;

	for(i=0;i<m;i++){
		//printf("AAA%f\n",randomValue());
		A[i]=randomValue();
	}

}

void randomMatrix(double *A, unsigned int m, unsigned int n){

	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i==j)
				A[j+i*n] = randomValueDeux(0.75, 1.25);
			else
				A[j+i*n] = randomValueDeux(-0.25, 0.25);
		}
	}
}

void readVector(double *v, unsigned int m){

	int i;
	printf("Saisir vecteur de taille %u :\n", m);

	for(i=0; i<m; i++){
		if(!scanf("%lf", v+i)) exit(1);

	}
}


void readMatrix(double *A, unsigned int m, unsigned int n){

	unsigned int i, bornesup=m*n;
	printf("Saisir matrice de taille %u x %u :\n", m, n);

	for(i=0; i<bornesup; i++){
		if(!scanf("%lf", A+i)) exit(1);

		//if(){ exit(1);}
	}
}

void printVector(double *v, unsigned int m){
	int i;
	for(i=0;i<m;i++){
		printf("%+1.18e\n",v[i]);
	}
}

void printMatrix(double *v, unsigned int m, unsigned int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%+1.18e\t",v[i*n+j]);
		}
		printf("\n");
	}
}

double maximumAbsVector(double *v, unsigned int m){
	double max=fabs(v[0]);
	unsigned int i;
	for(i=1;i<m;i++){
		if(fabs(v[i])>max)
			max=fabs(v[i]);
	}
	return max;
}

double maximumAbsMatrix(double *v, unsigned int m,unsigned int n){
	double max=fabs(v[0]);
	unsigned int i,bornesup=m*n;
	for(i=1;i<m*n;i++){
		if(fabs(v[i])>max)
			max=fabs(v[i]);
	}
	return max;
}

void setMatrixColumn(double *A, double *v, unsigned int k, unsigned int m, unsigned int n){
	unsigned int i, bornesup=m*n,compteur=0;
	for(i=k;i<bornesup;i+=m){
		A[i]=v[compteur];
		compteur++;
	}
}

void setMatrixRow(double *A,double *v, unsigned int k, unsigned int m, unsigned int n){
	unsigned int i, bornesup=(k+1)*n,compteur=0;
	for(i=k*n;i<bornesup;i++){
		A[i]=v[compteur];
		compteur++;
	}
}

void scaleVector(double alpha, double *v, unsigned int m){
	unsigned int i;
	for(i=0;i<m;i++){
		v[i]=v[i]*alpha;
	}
}

void scaleMatrix(double alpha, double *A, unsigned int m, unsigned int n){
	unsigned int i, bornesup=m*n;
	// on pourrait appeler scale vector mais ça a le meme runtime et complexite niveau code
	for(i=0;i<bornesup;i++){
		A[i]=A[i]*alpha;
	}
}

void addVector(double *w, double *u, double *v, unsigned int m){
	unsigned int i;
	for(i=0;i<m;i++){
		w[i]=u[i]+v[i];
	}
}

void addMatrix(double *C, double *A, double *B, unsigned int m, unsigned n){
	unsigned int i, bornesup=m*n;
	for(i=0;i<bornesup;i++){
		C[i]=A[i]+B[i];
	}
}

double scalarProduct(double *u, double *v, unsigned int m){
	double resultat;
	unsigned int i;
	for(i=0;i<m;i++){
		resultat+=u[i]*v[i];
	}
	return resultat;
}

void matrixVectorProduct(double *v, double *A, double *u, unsigned int m, unsigned int n){
	unsigned int i,j;
	double casee;
	for(i=0;i<m;i++){
		casee= (double)0;
		for(j=0;j<n;j++){
			casee+=A[j+i*n]*u[j];
		}
		v[i]=casee;
	}
}

void matrixMatrixProduct(double *C, double *A, double *B, unsigned int m, unsigned int n, unsigned int p){
	unsigned int i,j;
	double *vector=allocateVector(n), *aide=allocateVector(n);
	for(i=0;i<p;i++){
		// on recupere la ieme colonne de B
		for(j=0;j<n;j++){
			vector[j]=B[i+j*p];
		}/*
		printf("AAA\n");
		printVector(vector,n);
		printf("AAA\n");*/
		matrixVectorProduct(aide,A,vector,m,n);/*
		printf("BB\n");
		printVector(aide,n);
		printf("BB\n");*/
		setMatrixColumn(C,aide,i,m,n);
	}
	// on multiplie A par chaque colonne de B, le resultat ecrase donc la jieme colonne de C
	/* recupere la colonne de B p fois
	une fois quon la, on setMatrixColumn de C avec le produit de A par B*/
}

int main(){

	srand(time(NULL));

	double *u=allocateVector(4), *v=allocateVector(4);
	double *A=allocateMatrix(4,4),*B=allocateMatrix(4,4),*C=allocateMatrix(4,4);
	randomVector(u,4);
	copyVector(v,u,4);
	printf("On teste randomVector et copyVector \n");
	printVector(u,4);
	printf("\n");
	printVector(v,4);
	printf("-------------\n");
	printf("On teste randomMatrix et copyMatrix \n");
	randomMatrix(A,4,4);
	printMatrix(A,4,4);
	printf("\n");
	copyMatrix(B,A,4,4);
	printMatrix(B,4,4);
	printf("-------------\n");
	printf("On teste readVector/Matric et maximumAbsMatrix/vector \n");
	readVector(u,4);
	readMatrix(A,4,4);
	printVector(u,4);
	printMatrix(A,4,4);
	printf("maximumAbsMatrix: %.18e et maximumAbsVector: %.18e\n",maximumAbsMatrix(A,4,4),maximumAbsVector(u,4));
	printf("-------------\n");
	printf("On teste setMatrixRow scaleVector scaleMatrix addVector addMatrix\n");
	printMatrix(A,4,4);
	setMatrixRow(A,u,0,4,4);
	printMatrix(A,4,4);
	printf("\n");
	scaleVector((double)10, u, 4);
	printVector(u,4);
	scaleMatrix((double)10, A,4, 4);
	printMatrix(A,4,4);
	addVector(u,u,u,4);
	addMatrix(A,A,A,4,4);
	printf("-------------\n");
	identityMatrix(A,4,4);
	randomMatrix(B,4,4);
	randomVector(u,4);
	printVector(u,4);
	printMatrix(A,4,4);
	matrixVectorProduct(v,A,u,4,4);
	printVector(v,4);
	printf("\n");
	printMatrix(B,4,4);
	printf("\n");
	matrixMatrixProduct(C,A,B,4,4,4);
	printMatrix(C,4,4);
	freeVector(v);
	freeVector(u);
	freeMatrix(A);
	freeMatrix(B);
	freeMatrix(C);

	return 0;

}
