#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Best Case: O(n)
//Average Case: O(n²)
//Worst Case: O(n²)

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void fillRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

int main() {
    int n = 1000000;
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;

    // 1. Random array for 10 elements
    fillRandomArray(arr, n);
    start = clock();
    insertionSort(arr, 10);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 10, cpu_time_used);

    // 2. Random array for 1000 elements
    fillRandomArray(arr, n);
    start = clock();
    insertionSort(arr, 1000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 1000, cpu_time_used);

    // 3. Random array for 10000 elements
    fillRandomArray(arr, n);
    start = clock();
    insertionSort(arr, 10000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 10000, cpu_time_used);

      // 4. Random array for 100000 elements
    fillRandomArray(arr, n);
    start = clock();
    insertionSort(arr, 100000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 100000, cpu_time_used);

    // 4. Random array for n elements
    fillRandomArray(arr, n);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", n, cpu_time_used);

    // 5. Already sorted (ascending)
    // Array is already sorted from last sort
    start = clock();
    insertionSort(arr, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d ascending elements: %f seconds\n", n, cpu_time_used);

    // 6. Descending (worst case)
    reverseArray(arr, n);
    start = clock();
    insertionSort(arr, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d descending elements: %f seconds\n", n, cpu_time_used);

    free(arr);
    return 0;
}
