#include <stdio.h>

struct Result{
  int index;
  int comparisons;
};

struct Result binarySearch(int arr[], int n, int target){
  int start = 0;
  int end = n-1;
  int comparisions = 0;

  

  while(start <= end){
    int mid = start + (end-start)/2;
    comparisions++;
    if(target==arr[mid]){
      return (struct Result){mid, comparisions};
    } else if (target < arr[mid]){
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  return (struct Result){-1, comparisions};
}

int main(){
  int arr[] = {1,2,3,4,5,6,7,8};
  struct Result res = binarySearch(arr, 8, 4);
  printf("Index = %d, Comparisons = %d\n", res.index, res.comparisons);

  return 0;
}