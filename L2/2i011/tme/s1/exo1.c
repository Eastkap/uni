#include <stdio.h>
unsigned int factorielle(unsigned int n){
  unsigned int i=1, resultat=1;
  for(i=1;i<=n;i++){
    resultat=resultat*i;
  }
  return resultat;
}

int main(){
  printf("%u\n",factorielle(14));
  //printf("%lu",sizeof(unsigned int));
  return 0;
}

/* 11!=39916800
  12!=479001600
  13!=1932053504
  14!=1278945280 <13! ?? -->on remarque que 14!<13! ce qui est absurde.
  Du a un depassement de bits deja car 2^32 (nombre max qui peut etre representé sur un uint)<14!
  */
