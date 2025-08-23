#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
  int mix[end-start];
  
  int i = start;
  int j = mid; 
  int k =0;

  while(i < mid && j < end){
    if(arr[i] < arr[j]){
      mix[k] = arr[i];
      i++;
    } else {
      mix[k] = arr[j];
      j++;
    }
    k++;
  }

  while(i < mid){
    mix[k] = arr[i];
    i++;
    k++;
  }

  while(j < end){
    mix[k] = arr[j];
    k++;
    j++;
  }

  for(int l = 0; l < (end-start); l++){
    arr[start + l] = mix[l]; 
  }
}

void mergeSort(int arr[], int start, int end){

  if(end - start == 1){
    return;
  }

  int mid = start + (end - start)/2;

  mergeSort(arr, start, mid);
  mergeSort(arr, mid, end);
  merge(arr, start, mid, end);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}