#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int **mat, i, j, lin, col, biggest, smallest, i_biggest, j_biggest, i_smallest, j_smallest;

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

  // find the smallest number
  biggest = mat[0][0];
  for(i = 1; i < lin; i++){
    for(j = 1; j < col; j++){
      if(mat[i][j] > biggest){
        biggest = mat[i][j];
        i_biggest = i;
        j_biggest = j;
      }
    }
  }
  
  // find the smallest number
  smallest = mat[0][0];
  for(i = 1; i < lin; i++){
    for(j = 1; j < col; j++){
      if(mat[i][j] < smallest){
        smallest = mat[i][j];
        i_smallest = i;
        j_smallest = j;
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

  // print the biggest/smallest number and its position
  printf("biggest[%d][%d] = %d", i_biggest, j_biggest, biggest);
  printf("\nsmallest[%d][%d] = %d", i_smallest, j_smallest, smallest);
  
  return 0;
}