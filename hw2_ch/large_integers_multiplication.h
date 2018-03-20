/*
**  Author : Hao CHENG
**  Date : 12th Mar 2018
**  Description : The multiplication of two big numbers
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bignum{
  int size;
  int *tab;
};

#define NUM 50

char num_a[NUM],num_b[NUM];
struct bignum num1, num2, num_product;

struct bignum construct(char input_num[], struct bignum big_interger);
struct bignum multiplication(struct bignum a, struct bignum b);
