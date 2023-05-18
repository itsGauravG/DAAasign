#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into a single sorted array
int* mergeArrays(int* arr1, int n1, int* arr2, int n2) {
    int* mergedArray = (int*)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge the two arrays in sorted order
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k] = arr1[i];
            i++;
        } else {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1, if any
    while (i < n1) {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2, if any
    while (j < n2) {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }

    return mergedArray;
}

// Function to merge K sorted arrays using brute force
int* mergeKArrays(int** arrays, int k, int* sizes) {
    int* mergedArray = NULL;
    int mergedSize = 0;

    // Merge arrays one by one
    for (int i = 0; i < k; i++) {
        mergedArray = mergeArrays(mergedArray, mergedSize, arrays[i], sizes[i]);
        mergedSize += sizes[i];
    }

    return mergedArray;
}

int main() {
    // Example arrays
    int arrays[][5] = {
        {1, 3, 5, 7, 9},
        {2, 4, 6, 8, 10},
        {0, 11, 12, 13, 14}
    };
    int sizes[] = {5, 5, 5};
    int k = 3;

    int* mergedArray = mergeKArrays((int**)arrays, k, sizes);

    // Print the merged array
    for (int i = 0; i < k * sizes[0]; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    free(mergedArray);  // Free the dynamically allocated memory

    return 0;
}