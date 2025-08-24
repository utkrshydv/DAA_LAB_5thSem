#include <stdio.h>

int main(int argc, char *argv[]){

  FILE *src = fopen(argv[1], "r");
  FILE *dest = fopen(argv[2], "w");
  int arr[100];
  int i = 0;

  while(fscanf(src, "%d", &arr[i]) == 1 ){
    i++;
  }
  fclose(src);

  for(int j = 0; j < i; j++){
    fprintf(dest, " %d", arr[j]);
  }
  
  printf("Numbers read from file: \n");
  for(int j =0; j<i; j++){
    printf("%d ", arr[j]);
  }

  return 0;
}