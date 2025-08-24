#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandomArray(int arr[], int n){
  for(int i=0; i<n; i++){
    arr[i] = rand();
  }
}

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quickSort(int arr[], int low, int high){
  if(low >= high){
    return;
  }

  int start = low;
  int end = high;
  int mid = start + (end - start)/2;
  int pivot = arr[mid];

  while(start <= end){
    while(arr[start] < pivot){
      start++;
    }
    while(arr[end] > pivot){
      end--;
    }
    if(start <= end){
      swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
  }
  quickSort(arr, low, end);
  quickSort(arr, start, high);
}

int main(int argc, char* argv[]){

  int n = atoi(argv[1]);
  int *arr = (int *)malloc(n*sizeof(int));

  srand(time(NULL));
  clock_t start, end;
  double cpu_time_used;

  fillRandomArray(arr, n);
  start = clock();
  quickSort(arr, 0, n-1);
  end = clock();
  cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
   printf("Time taken to sort %d random elements: %f seconds\n", n, cpu_time_used);


  // for(int i =0; i < n; i++){
  //   printf("%d ", arr[i]);
  // }

  return 0;
}

