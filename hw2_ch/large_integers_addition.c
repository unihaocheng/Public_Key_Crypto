/*
**  Author : Hao CHENG
**  Date : 9th Mar 2018
**  Description : The addition of two large integers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "large_integers_addition.h"

#define NUM 50 //Max number of digits

struct bignum sum, num1, num2;
char num_a[NUM],num_b[NUM];


struct bignum construct(char input_num[], struct bignum big_interger){

  int i;
  big_interger.size = strlen(input_num);
  big_interger.tab = (int*)malloc(big_interger.size * sizeof(int));

  for (i = 0; i < big_interger.size; i++)
  big_interger.tab[big_interger.size - 1 -i] = (input_num[i] - '0') ;

  return big_interger;

}


struct bignum addition(struct bignum a, struct bignum b){

  struct bignum c;
  int carry = 0, length = 0, i;

  if ( a.size > b.size ) length = a.size;
  else length = b.size;

  c.tab = (int*)malloc((length + 1) * sizeof(int));

  for (i = 0; i < length; i++){
     c.tab[i] = (a.tab[i] + b.tab[i] + carry) % 10;
     carry = (a.tab[i] + b.tab[i] + carry) / 10;
  }

  if (carry == 1){
    c.tab[length] = 1;
    c.size = length + 1;
  }
  else c.size = length;
  return c;

}


int main(){

  puts("\nPlesase input 1st integer:");
  scanf("%s", num_a);
  puts("\nPlesase input 2nd integer");
  scanf("%s", num_b);
  printf("\nWe will caculate %s + %s \n", num_a, num_b);

  num1 = construct(num_a, num1);
  num2 = construct(num_b, num2);

  sum = addition(num1, num2);

  char output[NUM] = "";

  for (int i = 0; i < sum.size; i++){
  output[sum.size - 1 - i] = (sum.tab[i] + '0');
  }

  printf("\nThe SUM is: %s\n", output);

  return 0;

}
