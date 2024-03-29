#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double dotproduct(float* A, float* B);

int main() {
    int n;
    printf("Enter length of the vector: ");
    scanf_s("%d", &n);
    float* A = (float*)malloc(n * sizeof(float));
    float* B = (float*)malloc(n * sizeof(float));

    printf("Enter Vector A: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &A[i]);
    }

    printf("Enter Vector B: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &B[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%f %f\n", A[i], B[i]);
    }

    double sdot = dotproduct(A, B);
    printf("Dot product: %lf\n", sdot);

    // Free allocated memory
    free(A);
    free(B);

    return 0;
}
