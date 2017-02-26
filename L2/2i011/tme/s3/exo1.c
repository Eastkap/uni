#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

double suitemuller(int n){
    double azero=(double)11/(double)2, aun=(double)61/(double)11, tmp;
    if(n==0) return azero;
    int i;
    for(i=2;i<=n;i++){
        tmp=(double)3000/azero;
        tmp=(double)1130-tmp;
        tmp=tmp/aun;
        tmp=(double)111-tmp;
        azero=aun;
        aun=tmp;
        //printf("%lf\n",aun);
    }
    return aun;
}

int main(){
    int i;
    printf("arithmetique flottante:\n");
    for(i=5;i<=20;i+=5){
        printf("Pour n = %d, An est egale a :\n", i);
        printf("%lf\n", suitemuller(i));
    }
    // arithmetique rationnelle (exo2 tme 2)

    /* en arithmetique flottante on perd de la precision
    très rapidement par rapport à en arithmetique rationnelle
    La limite semble tendre vers 100, le resultat obtenu diffère
    de celui obtenu en arithmetique rationnelle (6).
    */
    return 0;
}
