#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern float dotproduct(float sdot, float* A, float* B, int n);

float dot_product(float sdot, float* A, float* B, int n) {
    sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    return sdot;
}

// Function to generate a random float between min and max
float randomFloat(float min, float max) {
    return min + (float)rand() / ((float)RAND_MAX / max);
}

int main() {
    clock_t start_time, end_time;
    double cpu_time_used;

    int n = 0;
    printf("Enter length of the vector: ");
    scanf_s("%d", &n);

    // Seed the random number generator with current time
    srand((unsigned int)time(NULL));

    float* A = (float*)malloc(n * sizeof(float));
    float* B = (float*)malloc(n * sizeof(float));

    // Generate random numbers and store them in the arrays
    for (int i = 0; i < n; i++) {
        A[i] = randomFloat(0.0, 100.0); // Random float between 0.0 and 100.0
        B[i] = randomFloat(0.0, 100.0); // Random float between 0.0 and 100.0
    }
    /*
    printf("Enter Vector A: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &A[i]);
    }

    printf("Enter Vector B: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &B[i]);
    }
    */

    
    for (int i = 0; i < n; i++) {
        printf("%f %f = %f\n", A[i], B[i], A[i] * B[i]);
    }
    

    float sdot = 0;

    printf("\nx86_64\n");

    // Record the start time
    start_time = clock();
    // Get sdot
    sdot = dotproduct(sdot, A, B, n);
    // Record the end time
    end_time = clock();

    printf("\nDot product: %f\n", sdot);

    // Calculate the CPU time used
    cpu_time_used = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nCPU time used by x86-64 with vector length %d: %f seconds\n",n, cpu_time_used);

    sdot = 0;

    printf("\n\nC program\n");

    start_time = clock();
    // Get sdot
    sdot = dot_product(sdot, A, B, n);
    // Record the end time
    end_time = clock();

    printf("\nDot product: %f\n", sdot);

    // Calculate the CPU time used
    cpu_time_used = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nCPU time used by C program with vector length %d: %f seconds\n", n, cpu_time_used);


    // Free allocated memory
    free(A);
    free(B);

    return 0;
}


