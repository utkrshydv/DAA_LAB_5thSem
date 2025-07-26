#include <stdio.h>
#include <stdlib.h>

void prefSum(int array[], int n){
  int* pref = malloc(n*sizeof(int));
  if(pref==NULL){
    fprintf(stderr, "Memory alloc for pref failed");
    return;
  }
  pref[0] = array[0];
  for(int i = 1; i < n; i++){
    pref[i] = array[i] + pref[i-1];
  }
  printf("pref array: ");
  for(int i=0; i<n; i++){
    printf("%d ", pref[i]);
  }
  free(pref);
}


int main(){
  
  int num;

  printf("array length: ");
  scanf("%d", &num);

  int* array = malloc(num * sizeof(int));

  if(array == NULL){
    fprintf(stderr, "Memory alloc for array failed");
    return 1;
  }

  for(int i=0; i<num; i++){
    printf("array[%d]: ", i);
    scanf("%d", &array[i]);
  }

  prefSum(array, num);
  free(array);


  return 0;
}