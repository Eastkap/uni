#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

double integralDirect(unsigned int n){
    double einv=exp(-1);
    double izero=(double)1-einv;
    int i;
    for(i=1;i<=n;i++){
        izero=-einv+i*izero;
    }
    return izero;
}

/* sur [0;1] on peut encadrer x^n.e^-x par [0;1/e]*/
double integralIndirect(unsigned int n, unsigned int m, double Im){
    double einv=exp(-1);
    for(m=m;m>n;m--){
        Im=(Im+einv)/m;
    }
    return Im;
}

void erreurabs(double pratique, double teorique){
    printf("Erreur absolue : %.20lf\n", fabs(pratique-teorique)/teorique);
}

int main(){
    double calcul=integralDirect(5);
    printf("%.20f\n",calcul);
    erreurabs(calcul,(double)0.071302178109803159860);
    printf("on fixe n à 5\n");
    calcul=integralIndirect(5,10,15);
    printf("Pour m=10, on %.20f\n",calcul);
    erreurabs(calcul,(double)0.071302178109803159860);
    calcul=integralIndirect(5,20,15);
    printf("Pour m=20, on %.20lf\n",calcul);
    erreurabs(calcul,(double)0.071302178109803159860);
    calcul=integralIndirect(5,50,15);
    printf("Pour m=50, on %.20lf\n",calcul);
    erreurabs(calcul,(double)0.071302178109803159860);
    calcul=integralIndirect(5,100,15);
    printf("Pour m=100, on %.20lf\n",calcul);
    erreurabs(calcul,(double)0.071302178109803159860);
    return 0;
}
// commentaire sur n fixé
/*
on fixe n à 5
Pour m=10, on 0.08793528905906242144
Pour m=20, on 0.08783632385624924599
Pour m=50, on 0.08783632385624909333
Pour m=100, on 0.08783632385624909333

Ainsi on remarque à partir de m=20, on integralIndirect devient plus precise que integralDirect
De plus à partir de m=50, l'erreur relative est infiniment petite.
*/

//erreur relative abs(calcul-teorigque)/teorique

/*pourquoi avec des valeurs aleatoires on trouve la meme chose?
 La récurrence est faite de telle manière que la valeur choisie (aléatoirement ou pas)
 devient négligeable. Ainsi e**-1, reprend du poids à chaque itération. On se retrouve
 avec une récurrence semblable à l'initiale. (perte de précision)
*/
