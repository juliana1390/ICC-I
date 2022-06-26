#include <stdio.h>

// countaDigits function prototype
int countDigits(int n, int d);

// main function
int main() {

  int a, b, digits_a, digits_b;

  printf("Insert two numbers:\n");
  scanf("%d %d", &a, &b);

  for(int i = 1; i <= 9; i++) {
    digits_a = countDigits(a, i);
    digits_b = countDigits(b, i);
    if (digits_a != digits_b) {
      printf("It is not swap!\n");
      return(0);
    }
  }

  printf("It is swap!\n");
  return(0);
}

// countaDigits function
int countDigits(int n, int d) {

  int i, remainder;

  i = 0;

  // count digits
  while (n > 0) {
    remainder = n % 10;
    n = (n - remainder)/10;
    if (remainder == d) {
      i++;
    }
  }

  return(i);
}