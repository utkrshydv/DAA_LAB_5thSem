#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key){
  int comparisons = 0;
  int low = 0;
  int high = n-1;
  int result = -1;

  while(low <= high){
    int mid = low + (high-low)/2;
    comparisons++;

    if(arr[mid] == key){
      result = mid;
      break;
    } else if (arr[mid] < key){
      low = mid + 1;
    } else {
      high = mid - 1; 
    }
  }


  if (comparisons == 1) {
    printf("\033[1;32m[   Best Case  ]:\033[0m ");      // Green
  } else if (result != -1) {
    printf("\033[1;33m[ Average Case ]:\033[0m ");   // Yellow
  }
  if (result == -1) {
      printf("\033[1;31m[  Worst Case  ]:\033[0m ");     // Red
  }

  printf("Searching for: %d | Comparisons made: %d | Index: %d\n", key, comparisons, result);

 
  return result;
}

int main(int argc, char *argv[]){


  FILE *src = fopen(argv[1], "r");

  int n = atoi(argv[2]);

  int *array = malloc(n * sizeof(int));

  int i = 0;
  while(i<n && fscanf(src, "%d", &array[i])==1){
    i++;
  }

  int best;
  int average;
  int worst;

  if(n == 10000){
    best = 4999;
    average = 5005;
    worst = 49999;
  } else if (n == 5000){
    best = 2499;
    average = 2505;
    worst = 49999;
  } else if(n == 1000){
    best = 499;
    average = 505;
    worst = 49999;
  }

  binarySearch(array, n, best);

  binarySearch(array, n, average);

  binarySearch(array, n, worst);


  free(array);
  fclose(src);


  return 0;

}