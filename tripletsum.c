#include <stdio.h>

// Function to find a triplet that sums to a given value
int findTriplet(int arr[], int n, int targetSum) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == targetSum) {
                    printf("Triplet found: %d, %d, %d\n", arr[i], arr[j], arr[k]);
                    return 1;  // Triplet found
                }
            }
        }
    }
    return 0;  // Triplet not found
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 22;

    int found = findTriplet(arr, n, targetSum);

    if (!found) {
        printf("Triplet not found\n");
    }

    return 0;
}
