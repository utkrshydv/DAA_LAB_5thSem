#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function for merge sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, 10 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 10, cpu_time_used);

    //2. Random array for 1000 elements
    start = clock();
    mergeSort(arr, 0, 1000 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 1000, cpu_time_used);

    //3. Random array for 10000 elements
    start = clock();
    mergeSort(arr, 0, 10000 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 10000, cpu_time_used);

    //4. Random array for 100000 elements
    start = clock();
    mergeSort(arr, 0, 100000 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", 100000, cpu_time_used);

    //4. Random array for n elements
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d random elements: %f seconds\n", n, cpu_time_used);


    //5. Already sorted (ascending)
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d ascending elements: %f seconds\n", n, cpu_time_used);

    //6. Descending (reverse sorted)
    reverseArray(arr, n);
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d descending elements: %f seconds\n", n, cpu_time_used);

    free(arr);
    return 0;
}


