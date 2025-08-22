#include <stdio.h>

void swap(int* arr, int a, int b){
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void insertionSort(int arr[], int n){
  for(int i = 0; i < n -1; i++){
    for(int j = i+1; j > 0; j--){
      if(arr[j] < arr[j-1]){
        swap(arr, j, j-1);
      } else {
        break;
      }
    }
  }
}

int main(){
  int arr[] = {5,4,6,7,8,9};
  insertionSort(arr, 6);

  for(int i= 0; i <6; i++){
    printf("%d ", arr[i]);
  }
}