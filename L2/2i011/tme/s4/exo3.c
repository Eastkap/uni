// exercice 3: Resolution de systeme avec lalgorithme de  Gauss

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAILLE 3
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

void freeVector(double *v){
	free(v);
}

void freeMatrix(double *m){
	free(m);
}

/*Alloue matrice taille m*n*/
double *allocateMatrix(unsigned int m, unsigned int n){
	return allocateVector(m*n);

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

void readVector(double *v, unsigned int m){

	int i;
	printf("Saisir vecteur de taille %u :\n", m);

	for(i=0; i<m; i++){
		if(!scanf("%lf", v+i)) exit(1);

	}
}

void printVector(double *v, unsigned int m){
	int i;
	for(i=0;i<m;i++){
		printf("%+1.18e\n",v[i]);
	}
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

void scaleVector(double alpha, double *v, unsigned int m){
	unsigned int i;
	for(i=0;i<m;i++){
		v[i]=v[i]*alpha;
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

void addMatrix(double *C, double *A, double *B, unsigned int m, unsigned n){
	unsigned int i, bornesup=m*n;
	for(i=0;i<bornesup;i++){
		C[i]=A[i]+B[i];
	}
}

void addVector(double *w, double *u, double *v, unsigned int m){
	unsigned int i;
	for(i=0;i<m;i++){
		w[i]=u[i]+v[i];
	}
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

void gaussianElimination(double *A, double *b, unsigned int n){
    /*
    transforme la matrice A et le vecteur b en A' et b' tq
    Ax=b <=> A'x=b' et que A' triangulaire supérieure
    */
    // on itere de haut en bas, en evitant le ieme element le plus en hsuy
    unsigned int i,j, bsup=n-1,compteur=1,aide;
    double *v=allocateVector(n);
    for(i=0;i<n;i++){
        // on itere en fonction des colonnes
        for(j=i;j<bsup;j++){
            // on itere en focntion des lignes
            copyVector(v, A+(i*n),n);
            scaleVector(-(A[(j+1)*n+i]/A[(i*n)+i]),v,n);
            b[(j+1)]=b[(j+1)]-(A[(j+1)*n+i]/A[(i*n)+i]*b[i]);
            addVector(A+((j+1)*n),A+((j+1)*n),v,n);
        }
    }
}

void solveTriangularUpper(double *x, double *A, double *b, unsigned int n){
    /*
    calcule le vecteur x tq Ax=b
    */
    int i,j,k;
    for (i = n-1; i>= 0; i--) {
        x[i]=b[i];
        for(j=n-1;j>=i;j--){
            if(j==i){
                x[i]=x[i]/A[i*n+j];
            }
            else{
                x[i]-=A[i*n+j]*x[j];
            }
        }
    }
}

void solveSystemGauss(double *x, double *A, double *b, unsigned int n){
    /*
    trouve la solution du systeme
    */
    double *Matrice=allocateMatrix(n,n);
    double *vecteur=allocateVector(n);
    copyVector(vecteur,b,n);
    copyMatrix(Matrice,A,n,n);
    gaussianElimination(Matrice,vecteur,n);
    solveTriangularUpper(x,Matrice,vecteur,n);
    freeMatrix(Matrice);
    freeVector(vecteur);
}

int main(){
    srand(time(NULL));
    double *delta=allocateVector(TAILLE),*b=allocateVector(TAILLE), *A=allocateMatrix(TAILLE,TAILLE), *x=allocateVector(TAILLE),*c=allocateVector(TAILLE);
    randomMatrix(A,TAILLE,TAILLE);
    randomVector(c,TAILLE);
    matrixVectorProduct(b,A,c,TAILLE,TAILLE);
    solveSystemGauss(x,A,b,TAILLE);
    scaleVector(-1,x,TAILLE);
    addVector(delta,c,x,TAILLE);
    printVector(delta,TAILLE);
    printf("%.18e \n", maximumAbsVector(delta,TAILLE));
    freeVector(b);
    freeVector(x);
    freeVector(delta);
    freeVector(c);
    freeMatrix(A);
    return 0;

}
