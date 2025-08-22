#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for quick sort
int partition(int arr[], int low, int high) {
    // Use median-of-three for better pivot selection
    int mid = low + (high - low) / 2;
    int pivot;
    // Find median of arr[low], arr[mid], arr[high]
    if ((arr[low] > arr[mid]) != (arr[low] > arr[high]))
        pivot = low;
    else if ((arr[mid] > arr[low]) != (arr[mid] > arr[high]))
        pivot = mid;
    else
        pivot = high;
    swap(&arr[pivot], &arr[high]); // Move pivot to end

    int pi = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pi) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(arr, 0, 10 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 10, cpu_time_used);

    //2. Random array for 1000 elements
    start = clock();
    quickSort(arr, 0, 1000 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 1000, cpu_time_used);

    //3. Random array for 10000 elements
    start = clock();
    quickSort(arr, 0, 10000 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 10000, cpu_time_used);

    //4. Random array for 100000 elements
    start = clock();
    quickSort(arr, 0, 100000 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 100000, cpu_time_used);

    //4. Random array for n elements
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", n, cpu_time_used);

    //5. Already sorted (ascending)
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d ascending elements: %f seconds\n", n, cpu_time_used);

    //6. Descending (reverse sorted)
    reverseArray(arr, n);
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d descending elements: %f seconds\n", n, cpu_time_used);

    free(arr);
    return 0;
}