#include <stdio.h>
#include <math.h>

double archimedes(unsigned int k){// avec la premiere recurrence
    double L=sqrt(2);
    unsigned int bornesup=pow(2,k),i;
    for (i=4;i<bornesup;i=i*2){
        L=2*(1-sqrt(1-(L/4)));
    }
    return sqrt(L);
}

double archimedesf2(unsigned int k){ // avec la deuxieme recurrence
    double L=sqrt(2);
    unsigned int bornesup=pow(2,k),i;
    for (i=4;i<bornesup;i=i*2){
        L=sqrt(pow(L,2)/(2*(1+sqrt(1-(pow(L,2)/4)))));
    }
    return L;
}

int main(){
    // on verifie lerreur relative avec M_pi
    int i;
    double calcul, calcul2;
    unsigned int puissance;
    for (i=10;i<=30;i++){
        printf("On rappelle π=%.20f.\n",M_PI);
        puissance=pow(2,i-1);
        calcul=archimedes(i)*puissance;
        calcul2=archimedesf2(i)*puissance;
        printf("Pour 2**%d, on a avec la premiere recurrence π=%.20f, \n\t avec la 2e π=%.20f.\n",i,calcul, calcul2);
        printf("Erreur relative (respectivement): %.20f et \n\t %.20f.\n",((calcul-M_PI)/M_PI),((calcul2-M_PI)/M_PI));
    }
    //perte de precision très forte avec la premiere recurrence, depassament de variable dès i=26 ( moins precise).
    return 0;
}
