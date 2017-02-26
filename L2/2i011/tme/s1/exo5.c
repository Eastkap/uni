#include <stdio.h>
#include <stdint.h>

int appels=0;

uint64_t multi(uint64_t a, uint64_t b){
  appels++;
  uint64_t resultat=0,aide=a;
  int i;
  for(i=0;i<64;i++){
    if(b & 1u)
      resultat+=aide;
    aide+=aide;
    b=b >> 1;
  }
  return resultat;
}

uint64_t exp_droite_gauche_recursive(uint64_t n, unsigned int k){
  if(k==0)
    return 1u;
  else if(k==1)
    return n;
  uint64_t aide,facteur2;
  if(k%2){
    facteur2=exp_droite_gauche_recursive(multi(n,n),(k-1)/2);
    aide=n;
  }
  else{
    facteur2=exp_droite_gauche_recursive(multi(n,n),k/2);
    aide=1u;
  }
  return multi(aide,facteur2);

}

uint64_t exp_gauche_droite_recursive(uint64_t n, unsigned int k){
  if(k==0)
    return 1u;
  else if(k==1)
    return n;
  uint64_t aide,facteur2;
  if(k%2){
    facteur2=exp_droite_gauche_recursive(n,(k-1)/2);
    facteur2=multi(facteur2,facteur2);
    aide=n;
  }
  else{
    facteur2=exp_droite_gauche_recursive(n,k/2);
    facteur2=multi(facteur2,facteur2);
    aide=1;
  }
  return multi(facteur2,aide);
}

uint64_t exp_gauche_droite_iterative(uint64_t n, unsigned int k){
  uint64_t resultat=1u;
  int i, timesquare=0,multiresultat=0;
  if(k==0)
    return resultat;
  resultat=n;
  if(k>=7){
    multiresultat++;
  }
  k--;
  while(k>0){
    if(k%2==1){
      k--;
      multiresultat++;
    }
    if(k!=0)
      timesquare++;
    k=k/2;
  }
  for(i=0;i<timesquare;i++){
    resultat=multi(resultat,resultat);
  }
  for(i=0;i<multiresultat;i++){
    resultat=multi(n,resultat);
  }
  return resultat;
}

uint64_t exp_droite_gauche_iterative(uint64_t n, unsigned int k){
  uint64_t resultat=1u;
  int i, timesquare=0,multiresultat=0;
  if(k==0)
    return resultat;
  resultat=n;
  if(k>=7){
    multiresultat=1;
  }
  k--;
  while(k>0){
    if(k%2==1){
      k--;
      multiresultat++;
    }
    if(k!=0){
      timesquare++;
      resultat=multi(resultat,resultat);
    }
    k=k/2;
  }
  for(i=0;i<multiresultat;i++){
    resultat=multi(n,resultat);
  }
  return resultat;
}


int main(){
  printf("%llu\n",exp_gauche_droite_recursive(3u,7));
  printf("gauche droite recursive fait %d multiplications\n",appels);
  appels=0;
  printf("%llu\n",exp_droite_gauche_recursive(3u,7));
  printf("droite gauche recursive fait %d multiplications \n",appels);
  appels=0;
  printf("%llu\n",exp_droite_gauche_iterative(3u,7));
  printf("droite gauche iterative fait %d multiplications \n",appels);
  appels=0;
  printf("%llu\n",exp_gauche_droite_iterative(3u,7));
  printf("gauche droite iterative fait %d multiplications \n",appels);
  appels=0;
  return 0;
}
/*
Pour 3**0:
1
gauche droite recursive fait 0 multiplications
1
droite gauche recursive fait 0 multiplications
1
droite gauche iterative fait 0 multiplications
1
gauche droite iterative fait 0 multiplications

Pour 3**1: 1 multiplications
Pour 3*+2: 2-2-1-1
POur 3**4: 4-4-3-3
Pour 3**17: 8-8-6-6
Pour 3**23: 8-8-8-8
Pour 3**42:10-10-9-9
Pour 3**1664: 20-20-20-20- ?
*/
