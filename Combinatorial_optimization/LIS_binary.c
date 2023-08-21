#include <stdio.h>
#include<limits.h>

int lisAlgorithm(int a[], int n, int L[], int L_prime[], int prev[]) {
    L[0] = INT_MIN; // Sentinel value
    L_prime[0] = -1; // Sentinel value
    prev[0] = -1;    // Sentinel value

    int len = 0;
    for (int i = 1; i < n; i++) {
        if (L[len] < a[i]) {
            len++;
            L[len] = a[i];
            L_prime[len] = i;
            prev[i] = L_prime[len - 1];
        } 
        else {
            int s = 0, h = len;
            while (s < h) {
                int m = (s + h) / 2;
                if (L[m] < a[i]) {
                    s = m + 1;
                } else {
                    h = m;
                }
            }
            L[s] = a[i];
            L_prime[s] = i;
            prev[i] = L_prime[s - 1];
        }
    }

    return len; // Return the length of LIS
}

int main() {
    
    int a[] = {0, 2, 5, 3, 6, 1, 2, 10, 7, 9, 1};
    int n = sizeof(a)/sizeof(int);
    int L[n];
    int L_prime[n];
    int prev[n];

    int lisLength = lisAlgorithm(a, n, L, L_prime, prev);

    printf("Length of Longest Increasing Subsequence: %d\n", lisLength);

    printf("Longest Increasing Subsequence:\n");
    int lisSequence[lisLength]; // Create an array to store LIS sequence
    int ind = L_prime[lisLength];
    int i = 0;
    while (ind != -1) {
        lisSequence[i++] = a[ind];
        ind = prev[ind];
    }
    for (int j = lisLength - 1; j >= 0; j--) {
        printf("%d ", lisSequence[j]);
    }
    printf("\n");

    return 0;
}
