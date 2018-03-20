/*
**  Author : Hao CHENG
**  Date : 12th Mar 2018
**  Description : The multiplication of two large integers
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "large_integers_multiplication.h"



#define NUM 50

char num_a[NUM],num_b[NUM];
struct bignum num1, num2, num_product;

struct bignum construct(char input_num[], struct bignum big_interger){

  int i;
  big_interger.size = strlen(input_num);
  big_interger.tab = (int*)malloc(big_interger.size * sizeof(int));

  for (i = 0; i < big_interger.size; i++)
  big_interger.tab[big_interger.size - 1 -i] = (input_num[i] - '0') ;

  return big_interger;

}


struct bignum multiplication(struct bignum a, struct bignum b){
  struct bignum c;
  int carry, i, j, tmp;

  c.size = a.size + b.size;
  c.tab = (int*)malloc(c.size * sizeof(int));
  memset(c.tab, 0, c.size * sizeof(int));

  for(i = 0; i <= a.size - 1; i++){
    carry = 0;
    for(j = 0; j<= b.size - 1; j++){
      tmp = a.tab[i] * b.tab[j] + c.tab[i + j] + carry;
      carry = tmp / 10;
      c.tab[i + j] = tmp % 10;
    }
    c.tab[i + b.size] = carry;
  }
  if(c.tab[c.size - 1] == 0) c.size--;

  return c;
}


int main(){
  puts("\nPlesase input 1st integer:");
  scanf("%s", num_a);
  puts("\nPlesase input 2nd integer:");
  scanf("%s", num_b);
  printf("\nWe will caculate %s * %s \n",num_a, num_b);

  num1 = construct(num_a, num1);
  num2 = construct(num_b, num2);

  num_product = multiplication(num1, num2);

  char output[NUM] = "";

  for (int i = 0; i < num_product.size; i++){
  output[num_product.size - 1 - i] = (num_product.tab[i] + '0');
  }

  printf("\nThe PRODUCT is: %s\n", output);

  return 0;
}
