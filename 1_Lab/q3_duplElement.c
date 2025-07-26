#include <stdio.h>

int main(){
  FILE *fp = fopen("input.txt","r");
  int array[100];

  int i=0; 
  while(fscanf(fp, "%d", &array[i])!=EOF){
    i++;
  }
  fclose(fp);

  int visited[100] = {0};

  for(int j=0; j<i; j++){
    if(visited[j] == 1){
      continue;
    }
    int count = 0;
    for(int m=0; m<i; m++){
      if(array[m] == array[j]){
        visited[m] = 1;
        count++;
      }
    }
    if(count > 1){
        printf("Duplicate element: %d | Count: %d\n", array[j], count);
    }
  }
  return 0;
}