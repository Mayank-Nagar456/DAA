#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20


void displayMatrix(double A[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%.2lf ", A[i][j]);
        }

        printf("\n");
    }
}


void matrixAddition(double A[MAX][MAX],
                    double B[MAX][MAX],
                    double C[MAX][MAX],
                    int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatrix Addition:\n");
    displayMatrix(C, n);
}

/* 2. Matrix Multiplication */
void matrixMultiplication(double A[MAX][MAX],
                          double B[MAX][MAX],
                          double C[MAX][MAX],
                          int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for(int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication:\n");
    displayMatrix(C, n);
}


void zeroMatrix(double Z[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Z[i][j] = 0;
        }
    }

    printf("\nZero Matrix:\n");
    displayMatrix(Z, n);
}


void checkSymmetric(double A[MAX][MAX], int n)
{
    int symmetric = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(A[i][j] != A[j][i])
            {
                symmetric = 0;
                break;
            }
        }

        if(!symmetric)
            break;
    }

    if(symmetric)
        printf("\nMatrix is Symmetric\n");
    else
        printf("\nMatrix is Not Symmetric\n");
}

/* 5. Determinant using Gaussian Elimination */
double determinant(double A[MAX][MAX], int n)
{
    double temp[MAX][MAX];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[i][j] = A[i][j];
        }
    }

    double det = 1;

    for(int i = 0; i < n; i++)
    {
        int pivot = i;

        for(int j = i + 1; j < n; j++)
        {
            if(fabs(temp[j][i]) > fabs(temp[pivot][i]))
                pivot = j;
        }

        if(fabs(temp[pivot][i]) < 1e-9)
            return 0;

        /* Swap rows */
        if(pivot != i)
        {
            for(int j = 0; j < n; j++)
            {
                double t = temp[i][j];
                temp[i][j] = temp[pivot][j];
                temp[pivot][j] = t;
            }

            det = -det;
        }

        det *= temp[i][i];

        /* Eliminate below */
        for(int j = i + 1; j < n; j++)
        {
            double factor = temp[j][i] / temp[i][i];

            for(int k = i; k < n; k++)
            {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    return det;
}

/* 6. In-place Transpose */
void transpose(double A[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            double temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    printf("\nIn-place Transpose:\n");
    displayMatrix(A, n);
}

/* 7. Dominant Eigenvalue and Eigenvector */
void eigenValueVector(double A[MAX][MAX], int n)
{
    double x[MAX];

    /* Initial vector */
    for(int i = 0; i < n; i++)
        x[i] = 1;

    double eigenvalue = 0;

    for(int iteration = 0; iteration < 1000; iteration++)
    {
        double y[MAX];
        double maxValue = 0;

        /* y = A*x */
        for(int i = 0; i < n; i++)
        {
            y[i] = 0;

            for(int j = 0; j < n; j++)
            {
                y[i] += A[i][j] * x[j];
            }

            if(fabs(y[i]) > maxValue)
                maxValue = fabs(y[i]);
        }

        if(maxValue == 0)
        {
            printf("\nEigenvalue = 0\n");
            return;
        }

        /* Normalize */
        for(int i = 0; i < n; i++)
            x[i] = y[i] / maxValue;

        eigenvalue = maxValue;
    }

    printf("\nDominant Eigenvalue = %.4lf\n", eigenvalue);

    printf("Corresponding Eigenvector:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%.4lf\n", x[i]);
    }
}


/* MAIN */
int main()
{
    int n;

    double A[MAX][MAX];
    double B[MAX][MAX];
    double C[MAX][MAX];
    double Z[MAX][MAX];

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("\nEnter Matrix A:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nEnter Matrix B:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%lf", &B[i][j]);
        }
    }

    printf("\n===== QUESTION 2 =====\n");

    /* 1. Addition */
    matrixAddition(A, B, C, n);

    /* 2. Multiplication */
    matrixMultiplication(A, B, C, n);

    /* 3. Zero Matrix */
    zeroMatrix(Z, n);

    /* 4. Symmetric Matrix */
    checkSymmetric(A, n);

    /* 5. Determinant */
    printf("\nDeterminant of Matrix A = %.2lf\n",
           determinant(A, n));

    /* 6. In-place Transpose */
    transpose(A, n);

    /* 7. Eigenvalue and Eigenvector */
    eigenValueVector(A, n);

    return 0;
}