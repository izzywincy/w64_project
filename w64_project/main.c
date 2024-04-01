#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

extern float dotproduct(float sdot, float* A, float* B, int n);

float dot_product(float* A, float* B, int n) {
    float sdot = 0;
    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }
    return sdot;
}



int main() {
    clock_t start_time, end_time;
    double cpu_time_used;

    int n = 0;
    float cAverage = 0;
    float asmAverage = 0;
    printf("Enter length of the vector: ");
    scanf_s("%d", &n);

    srand((unsigned int)time(NULL));
    n = pow(2, n);

    for (int count = 0; count < 30; count++) {
        printf("Run %d", count + 1);
        float* A = (float*)malloc(n * sizeof(float));
        float* B = (float*)malloc(n * sizeof(float));

        // Generate random numbers and store them in the arrays
        for (int i = 0; i < n; i++) {
            A[i] = (float)rand() / RAND_MAX;;
            B[i] = (float)rand() / RAND_MAX;;
        }


        
        /*  for (int i = 0; i < n; i++) {
              printf("%f %f = %f\n", A[i], B[i], A[i] * B[i]);
          }
        */

        float sdot = 0.0;

        printf("\n- x86_64");

        // Record the start time
        start_time = clock();
        // Get sdot
        sdot = dotproduct(sdot, A, B, n);
        // Record the end time
        end_time = clock();

        printf("\nDot product: %f", sdot);
        
        // Calculate the CPU time used
        cpu_time_used = (double)(end_time - start_time) / CLOCKS_PER_SEC;


        printf("\nCPU time: %f seconds\n", cpu_time_used);

        asmAverage += cpu_time_used;

        sdot = 0.0;

        printf("\n- C program");

        start_time = clock();
        // Get sdot
        sdot = dot_product(A, B, n);
        // Record the end time
        end_time = clock();

        printf("\nDot product: %f", sdot);

        // Calculate the CPU time used
        cpu_time_used = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        printf("\nCPU time: %f seconds\n", cpu_time_used);
        cAverage += cpu_time_used;


        // Free allocated memory
        free(A);
        free(B);
    }
    printf("\nAverage run time of x86_64: %f", asmAverage / 30); 
    printf("\nAverage run time of C program: %f\n", cAverage / 30);
    return 0;
}


