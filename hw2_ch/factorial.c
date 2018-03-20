/*
**  Author : Hao CHENG
**  Date : 12th Mar 2018
**  Description : Factorial
**
**  40! = 815915283247897734345611269596115894272000000000
*/

#include "large_integers_multiplication.h"

struct bignum num_n;

struct bignum factorial(struct bignum n){
  if(n.size == 1 && n.tab[0] == 1){
    return n;
  }
  else{
    struct bignum num_minus_1;
    num_minus_1.tab = (int*)malloc(n.size * sizeof(int));
    for(int j = 0; j < n.size; j++){
      num_minus_1.tab[j] = n.tab[j];
    }

    if(n.tab[0] == 0){
      int i = 1;
      num_minus_1.size = n.size;
      num_minus_1.tab[0] = 9;
      while(num_minus_1.tab[i] == 0){
        num_minus_1.tab[i] = 9;
        i++;
      }
      num_minus_1.tab[i]--;
      if(num_minus_1.tab[num_minus_1.size - 1] == 0){
        num_minus_1.size--;
      }
    }
    else{
      num_minus_1.size = n.size;
      num_minus_1.tab[0]--;
    }
    return multiplication(n, factorial(num_minus_1));
  }
}

int main(){
  char n[10] = "";
  puts("Plesase input number n of Factorial:");
  scanf("%s", n);

  num_n = construct(n, num_n);
  num_n = factorial(num_n);

  char output[100] = "";
  for(int i = 0; i < num_n.size; i++){
    output[num_n.size - 1 - i] = (num_n.tab[i] + '0');
  }
  printf("The result is: %s\n", output);

}
