#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findSecondMax(int array[], int n){
   if (n < 2) {
        printf("Need at least 2 elements to find second largest.\n");
        return;
    }

  int max = INT_MIN;
  int scndMax = INT_MIN;

  for(int i=0; i<n; i++){
    if(array[i] > max){
      scndMax = max;
      max = array[i];
    } else if(array[i] > scndMax && array[i] != max){
      scndMax = array[i];
    }
  }
  printf("second largest: %d\n", scndMax);
}

void findSecondMin(int array[], int n){

  if (n < 2) {
        printf("Need at least 2 elements to find second smallest.\n");
        return;
  }

  int min = INT_MAX;
  int scndMin = INT_MAX;

  for(int i=0; i<n; i++){
    if(array[i] < min){
      scndMin = min;
      min = array[i];
    } else if(array[i] != min && array[i] < scndMin){
      scndMin = array[i];
    }
  }
  printf("second smallest: %d\n", scndMin);
}

int main(){
  FILE *fp = fopen("input.txt", "r");

  int n;
  printf("Size of array: ");
  scanf("%d", &n);

  int* array = malloc(n*sizeof(int));

  for(int i=0; i<n; i++){
    fscanf(fp, "%d", &array[i]);
  }
  fclose(fp);

  //int i = 0;
  //while(fscanf(fp, "%d", &array[i])!=EOF){
  //      i++;
  //}

  findSecondMax(array, n);
  findSecondMin(array, n);

  return 0;
}