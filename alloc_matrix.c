/*
    - dynamic allocation of matrix, using the function malloc;
    - generate a random matrix;
    - find the max/min element of the matrix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int **mat, i, j, lin, col, max, min, i_max, j_max, i_min, j_min;

  printf("Insert the number of lines and columns, respectively: \n");
  scanf("%d %d",&lin, &col);

  // allocate the matrix
  mat = malloc(lin * sizeof(int*));
  
  for(i = 0; i < lin; i++){
    mat[i] = malloc(col * sizeof(int));
  }

  // random matrix
  srand(time(NULL));
  for(i = 0; i < lin;i++){
    for(j = 0; j < col; j++)
      mat[i][j] = rand() % 1000;
  }

  // find the max element
  max = mat[0][0];
  for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
      if(mat[i][j] > max){
        max = mat[i][j];
        i_max = i;
        j_max = j;
      }
    }
  }
  
  // find the min element
  min = mat[0][0];
  for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
      if(mat[i][j] < min){
        min = mat[i][j];
        i_min = i;
        j_min = j;
      } 
    }
  }
  printf("\n");
  
  // print matrix
  for(i = 0; i < lin;i++){
    for(j = 0; j < col; j++)
      printf("%d ", mat[i][j]);  
    printf("\n");
  }
  printf("\n");

  // print the max/min element and its position
  printf("max[%d][%d] = %d", i_max, j_max, max);
  printf("\nmin[%d][%d] = %d", i_min, j_min, min);
  
  return 0;
}