/*
**  Author : Hao CHENG
**  Date : 12th Mar 2018
**  Description : Fibonacci Sequence
**
**  fibonacci(101) = 927372692193078999176
*/

#include "large_integers_addition.h"

struct bignum num_n;

struct bignum fibonacci(struct bignum n){

  if (n.size == 1 && n.tab[0] <= 1 ){
    n.tab[0] = 1;
    return n;
  }
  else{

    struct bignum num_a, num_b;
    num_a.tab = (int*)malloc(n.size * sizeof(int));
    num_b.tab = (int*)malloc(n.size * sizeof(int));
    for(int j = 0; j < n.size; j++){
      num_a.tab[j] = n.tab[j];
      num_b.tab[j] = n.tab[j];
    }

    if (n.tab[0] == 1){
      int i = 1;
      num_a.size = n.size;
      num_a.tab[0] = 0;

      num_b.size = n.size;
      num_b.tab[0] = 9;
      while (num_b.tab[i] == 0){
        num_b.tab[i] = 9;
        i++;
      }
      num_b.tab[i]--;
      if (num_b.tab[num_b.size - 1] == 0){
        num_b.size--;
      }
    }

    else if(n.tab[0] == 0){
      int i = 1;
      num_a.size = n.size;
      num_a.tab[0] = 9;
      while (num_a.tab[i] == 0){
        num_a.tab[i] = 9;
        i++;
      }
      num_a.tab[i]--;
      if (num_a.tab[num_a.size - 1] == 0){
        num_a.size--;
      }

      int j = 1;
      num_b.size = n.size;
      num_b.tab[0] = 8;
      while (num_b.tab[j] == 0){
        num_b.tab[j] = 9;
        j++;
      }
      num_b.tab[j]--;
      if (num_b.tab[num_b.size - 1] == 0){
        num_b.size--;
      }
    }
    else {
      num_a.size = n.size;
      num_a.tab[0]--;
      num_b.size = n.size;
      num_b.tab[0] -= 2;
    }
    return addition(fibonacci(num_a),fibonacci(num_b));
  }
}

int main(){
  char n[10] = "";
  puts("Plesase input number n of Fibonacci Sequence:");
  scanf("%s", n);
  num_n = construct(n, num_n);
  num_n = fibonacci(num_n);

  char output[50] = "";
  for(int i = 0; i < num_n.size; i++){
    output[num_n.size - 1 - i] = (num_n.tab[i] + '0');
  }
  printf("The result is: %s\n", output);
}
