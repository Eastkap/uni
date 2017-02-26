#include <stdio.h>
#include <math.h>

double archimedes(unsigned int k){
    double L=sqrt(2);
    unsigned int bornesup=pow(2,k),i;
    for (i=2;i<bornesup;i=i*2){
        L=sqrt(2*(1-sqrt(1-(pow(L,2)/4))));
    }
    return L;
}

int main(){
    printf("%f\n",pow(2,19)*archimedes(20));
    return 0;
}
