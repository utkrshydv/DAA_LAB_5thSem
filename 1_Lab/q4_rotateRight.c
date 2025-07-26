#include <stdio.h>
#include <stdlib.h>

void EXCHANGE(int *p, int *q){
  int temp = *p;
  *p = *q;
  *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2){
  for(int i = p2-1; i>0; i--){
    EXCHANGE(&p1[i], &p1[i-1]);
  }
}

int main(){
  int n;
  
  printf("enter array size: ");
  scanf("%d", &n);

  int* array = malloc(n*sizeof(int));

  printf("Enter elements: \n");

  for(int i = 0; i<n; i++){
    printf("array[%d]: ",i);
    scanf("%d", &array[i]);
  }

  int toRotate;
  printf("No of elements to rotate: ");
  scanf("%d", &toRotate);

  toRotate = toRotate%n;

  printf("Before Rotating: ");
  for(int i=0; i<n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  ROTATE_RIGHT(array, toRotate);

  printf("After Rotating: ");
  for(int i=0; i<n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array);
  return 0;
}