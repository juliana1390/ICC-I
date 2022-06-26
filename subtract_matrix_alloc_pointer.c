#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void read_matrix(int **mat1, int **mat2, int lin, int col);
int subtract_matrix(int **mat1, int **mat2, int **mat3, int lin, int col);
int print_matrix(int **mat3, int lin, int col);
void setfree_matrix(int **mat1, int **mat2, int **mat3, int lin);

// funcao main
int main(void) {  
  int **mat1, **mat2, **mat3, lin, col, i, j;

  printf("Insert the number of lines and columns, respectively: \n");
  scanf("%d %d",&lin, &col);

  printf("\n");

  // allocate the matrices
  mat1 = malloc(lin * sizeof(int*));
  mat2 = malloc(lin * sizeof(int*));
  mat3 = malloc(lin * sizeof(int*));

  for(i = 0; i < lin; i++){
    mat1[i] = malloc(col * sizeof(int));
    mat2[i] = malloc(col * sizeof(int));
    mat3[i] = malloc(col * sizeof(int));
  }
  
  read_matrix(mat1, mat2, lin, col);

  subtract_matrix(mat1, mat2, mat3, lin, col);
  print_matrix(mat3, lin, col);
  setfree_matrix(mat1, mat2, mat3, lin);
  
  return 0;
}

// read_matrix function
void read_matrix(int **mat1, int **mat2, int lin, int col){
  
  int i, j;
  
  /*
  srand(time(NULL));
  // random numbers from 0 to (lin*col)
  for(i = 0; i < lin;i++){
    for(j = 0; j < col; j++){
      mat1[i][j] = rand() % (lin*col);
      mat2[i][j] = rand() % (lin*col);
    }
  }
  */

  // input matrix 1
  printf("Insert the 1st matrix: \n");
  for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
      scanf("%d ", &mat1[i][j]);
    } 
  }
  //printf("\n");
  
  // input matrix 2
  printf("Insert the 2nd matrix: \n");
  for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
      scanf("%d ", &mat2[i][j]);
    }
    printf("\n");
  }
  /*
  printf("Matrix 1: \n");
  for(i = 0; i < lin;i++){
    for(j = 0; j < col; j++) printf("%d ", mat1[i][j]);
    printf("\n");
  }
  printf("\n");
  
  printf("Matrix 2: \n");
  for(i = 0; i < lin;i++){
    for(j = 0; j < col; j++) printf("%d ", mat2[i][j]);
    printf("\n");
  }*/
}

// subtract_matrix function
int subtract_matrix(int **mat1, int **mat2, int **mat3, int lin, int col){
  int i, j;

  // subtract
  for(i = 0; i < lin;i++){
    for(j = 0; j < col; j++) mat3[i][j] = mat1[i][j] - mat2[i][j];
  }
  return **mat3;
}

// print_matrix function
int print_matrix(int **mat3, int lin, int col){
  int i, j;

  printf("\nResulting subtraction matrix:\n");
  for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++) printf("%d ", mat3[i][j]);
    printf("\n");
  }
}

// setfree_matrix function
void setfree_matrix(int **mat1, int **mat2, int **mat3, int lin){
  int i, j;
  
  for(i = 0; i < lin; i++) {
    free(mat1[i]);
    free(mat2[i]);
    free(mat3[i]);
  }
}