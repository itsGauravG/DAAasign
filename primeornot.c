#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;  // Not prime
    }

    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            return 0;  // Not prime
        }
    }

    return 1;  // Prime
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("%d is prime.\n", num);
    } else {
        printf("%d is not prime.\n", num);
    }

    return 0;
}
