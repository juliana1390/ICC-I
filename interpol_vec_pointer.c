#include <stdio.h>
#define size 5

// readVector function prototype
int readVector(int *A, int *B);
// orderVector function prototype
int orderVector(int *A, int *B);
// interpolateVector function prototype
int interpolateVector(int *A, int *B, int *C);

// main function
int main(void) {
  int A[size], B[size], C[size*2];
  readVector(A, B);
  orderVector(A, B);
  interpolateVector(A, B, C);
  return 0;
}

// readVector function
int readVector(int *A, int *B){
  // read vector 1
  printf("Insert the 1st vector: \n");
  for(int i = 0; i < size; i++){
    scanf("%d", &A[i]);
  }
  // read vector 2
  printf("Insert the 2nd vector: \n");
  for(int i = 0; i < size; i++){
    scanf("%d", &B[i]);
  }
}

// orderVector function
int orderVector(int *A, int *B){
  int aux, i, j;
  
  // order vector 1
  for(i = 0; i < size; i++) {
    for(j = i; j < size; j++){
      if(A[i] > A[j]){
        aux = A[i];
        A[i] = A[j];
        A[j] = aux;
      }
    }
  }
  
  // order vector 2
  for(i = 0; i < size; i++) {
    for(j = i; j < size; j++){
      if(B[i] > B[j]){
        aux = B[i];
        B[i] = B[j];
        B[j] = aux;
      }
    }
  }
}

// interpolateVector function
int interpolateVector(int *A, int *B, int *C){
  // fullfil vector 3
  for (int i = 0; i < size; i++) { // A in even positions of C
    C[i*2] = A[i]; //c[0] = a[0], c[2] = a[1], c[4] = a[2]...
  }
  for (int i = 0; i < size; i++) { // B in odd positions of C
    C[i*2+1] = B[i]; //c[1] = b[0], c[3] = b[1], c[5] = b[2]...
  }
  // print vector 3
  for(int i = 0; i < size*2; i++){
    printf("C[%d]: %d\n", i, C[i]);
  }
}

 