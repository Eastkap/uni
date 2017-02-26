#include <stdio.h>
#include <stdint.h>

int bits1(uint64_t n){
  int i,resultat=0;
  for(i=0;i<64;i++){
    if( (1u&n) ==1){
      resultat++;
    }
    n=n >> 1;
  }
  return resultat;
}

int main(){
  printf("%d\n",bits1(2));
  return 0;
}
