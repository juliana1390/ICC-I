#include <stdio.h>

// readVector function prototype
void readVector(int *v, int n);

// biggestElement function prototype
void biggestElement(int *v, int n, int *biggest);

// main function
int main(void) {
  int n, biggest;
  scanf("%d", &n);

  int v[n];
  readVector(v, n);
  biggestElement(v, n, &biggest);
  printf("%d", biggest);  
  
  return 0;
  
}

// readVector function
void readVector(int *v, int n){
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);    
  }
}

// biggestElement function
void biggestElement(int *v, int n, int *biggest){
  (*biggest) = v[0]; 
  for(int i = 1; i < n; i++){
    if(v[i] > (*biggest)){ 
      (*biggest) = v[i];
    }
  }
}