/*
**  Author : Hao CHENG
**  Date : 9th Mar 2018
**  Description : The addition of two large integers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bignum{
  int size;  // the number of digits
  int *tab;  // actual data
} ;

struct bignum construct(char input_num[], struct bignum big_interger);
struct bignum addition(struct bignum a, struct bignum b);
