/*
    - function pointer;
    - find the max element in the vector.
 */

#include <stdio.h>

// readVector function prototype
void readVector(int *v, int n);

// maxElement function prototype
void maxElement(int *v, int n, int *max);

// main function
int main(void) {
  int n, max;
  
  printf("Insert the size of the vector: ");
  scanf("%d", &n);

  int v[n];
  readVector(v, n);
  maxElement(v, n, &max);
  printf("%d", max);
  
  return 0;
  
}

// readVector function
void readVector(int *v, int n){
  printf("Insert the vector:\n");
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);    
  }
}

// maxElement function
void maxElement(int *v, int n, int *max){
  (*max) = v[0];
  for(int i = 1; i < n; i++){
    if(v[i] > (*max)){
      (*max) = v[i];
    }
  }
}