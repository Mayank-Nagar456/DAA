#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int (*A11)[k] = malloc(k * sizeof(*A11));
    int (*A12)[k] = malloc(k * sizeof(*A12));
    int (*A21)[k] = malloc(k * sizeof(*A21));
    int (*A22)[k] = malloc(k * sizeof(*A22));

    int (*B11)[k] = malloc(k * sizeof(*B11));
    int (*B12)[k] = malloc(k * sizeof(*B12));
    int (*B21)[k] = malloc(k * sizeof(*B21));
    int (*B22)[k] = malloc(k * sizeof(*B22));

    int (*P1)[k] = malloc(k * sizeof(*P1));
    int (*P2)[k] = malloc(k * sizeof(*P2));
    int (*P3)[k] = malloc(k * sizeof(*P3));
    int (*P4)[k] = malloc(k * sizeof(*P4));
    int (*P5)[k] = malloc(k * sizeof(*P5));
    int (*P6)[k] = malloc(k * sizeof(*P6));
    int (*P7)[k] = malloc(k * sizeof(*P7));

    int (*T1)[k] = malloc(k * sizeof(*T1));
    int (*T2)[k] = malloc(k * sizeof(*T2));

    if (!A11 || !A12 || !A21 || !A22 ||
        !B11 || !B12 || !B21 || !B22 ||
        !P1 || !P2 || !P3 || !P4 || !P5 || !P6 || !P7 ||
        !T1 || !T2)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    /* P1 = A11 * (B12 - B22) */
    subMatrix(k, B12, B22, T1);
    strassen(k, A11, T1, P1);

    /* P2 = (A11 + A12) * B22 */
    addMatrix(k, A11, A12, T1);
    strassen(k, T1, B22, P2);

    /* P3 = (A21 + A22) * B11 */
    addMatrix(k, A21, A22, T1);
    strassen(k, T1, B11, P3);

    /* P4 = A22 * (B21 - B11) */
    subMatrix(k, B21, B11, T1);
    strassen(k, A22, T1, P4);

    /* P5 = (A11 + A22) * (B11 + B22) */
    addMatrix(k, A11, A22, T1);
    addMatrix(k, B11, B22, T2);
    strassen(k, T1, T2, P5);

    /* P6 = (A12 - A22) * (B21 + B22) */
    subMatrix(k, A12, A22, T1);
    addMatrix(k, B21, B22, T2);
    strassen(k, T1, T2, P6);

    /* P7 = (A21 - A11) * (B11 + B12) */
    subMatrix(k, A21, A11, T1);
    addMatrix(k, B11, B12, T2);
    strassen(k, T1, T2, P7);

    /*
       C11 = P5 + P4 - P2 + P6
       C12 = P1 + P2
       C21 = P3 + P4
       C22 = P5 + P1 - P3 - P7
    */
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] =
                P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];

            C[i][j + k] =
                P1[i][j] + P2[i][j];

            C[i + k][j] =
                P3[i][j] + P4[i][j];

            C[i + k][j + k] =
                P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    free(A11);
    free(A12);
    free(A21);
    free(A22);

    free(B11);
    free(B12);
    free(B21);
    free(B22);

    free(P1);
    free(P2);
    free(P3);
    free(P4);
    free(P5);
    free(P6);
    free(P7);

    free(T1);
    free(T2);
}

void printMatrix(int n, int A[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d ", A[i][j]);

        printf("\n");
    }
}

int main()
{
    /*
       Strassen's method requires n to be a power of 2.
       These input sizes are used to experimentally observe
       the running time.

       No input file is required.
       result.txt is generated automatically for Gnuplot.
    */
    int sizes[] = {2, 4, 8, 16, 32, 64};
    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating result.txt\n");
        return 1;
    }

    fprintf(fp, "# n time_ms\n");

    printf("Strassen Matrix Multiplication\n\n");
    printf("%-12s %-20s\n", "Matrix Size", "Time (ms)");
    printf("----------------------------------\n");

    for (int s = 0; s < numberOfSizes; s++)
    {
        int n = sizes[s];

        int (*A)[n] = malloc(n * sizeof(*A));
        int (*B)[n] = malloc(n * sizeof(*B));
        int (*C)[n] = malloc(n * sizeof(*C));

        if (!A || !B || !C)
        {
            printf("Memory allocation failed for n = %d\n", n);
            fclose(fp);
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                A[i][j] = (i + j) % 10;
                B[i][j] = (i * j + 1) % 10;
                C[i][j] = 0;
            }
        }

        clock_t start = clock();

        strassen(n, A, B, C);

        clock_t end = clock();

        double time_ms =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

        printf("%-12d %-20.6f\n", n, time_ms);

        fprintf(fp, "%d %.6f\n", n, time_ms);

        if (n == 4)
        {
            printf("\nExample result for n = 4:\n");
            printf("Matrix A:\n");
            printMatrix(n, A);

            printf("\nMatrix B:\n");
            printMatrix(n, B);

            printf("\nA x B using Strassen:\n");
            printMatrix(n, C);
            printf("\n");
        }

        free(A);
        free(B);
        free(C);
    }

    fclose(fp);

    printf("result.txt generated automatically.\n");
    printf("\nStrassen recurrence:\n");
    printf("T(n) = 7T(n/2) + O(n^2)\n");
    printf("Time Complexity = O(n^log2(7)) approximately O(n^2.807)\n");

    return 0;
}