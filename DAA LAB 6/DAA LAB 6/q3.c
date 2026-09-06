#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef struct
{
    double real;
    double imag;
} Complex;

/* Complex addition */
Complex add(Complex a, Complex b)
{
    Complex c;

    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;

    return c;
}

/* Complex multiplication */
Complex multiply(Complex a, Complex b)
{
    Complex c;

    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;

    return c;
}

/* FFT
   invert = 0 -> FFT
   invert = 1 -> Inverse FFT
*/
void FFT(Complex a[], int n, int invert)
{
    /* Base case */
    if (n == 1)
        return;

    int half = n / 2;

    Complex *even = malloc(half * sizeof(Complex));
    Complex *odd = malloc(half * sizeof(Complex));

    for (int i = 0; i < half; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    /* Divide */
    FFT(even, half, invert);
    FFT(odd, half, invert);

    double angle = 2 * PI / n;

    if (!invert)
        angle = -angle;

    Complex w;
    w.real = 1;
    w.imag = 0;

    Complex wn;
    wn.real = cos(angle);
    wn.imag = sin(angle);

    /* Combine */
    for (int k = 0; k < half; k++)
    {
        Complex t = multiply(w, odd[k]);

        a[k] = add(even[k], t);

        a[k + half].real =
            even[k].real - t.real;

        a[k + half].imag =
            even[k].imag - t.imag;

        w = multiply(w, wn);
    }

    free(even);
    free(odd);

    /* Scaling for inverse FFT */
    if (invert)
    {
        for (int i = 0; i < n; i++)
        {
            a[i].real /= 2.0;
            a[i].imag /= 2.0;
        }
    }
}

/* Find next power of 2 */
int nextPowerOfTwo(int x)
{
    int n = 1;

    while (n < x)
        n *= 2;

    return n;
}

/* Convolution */
void convolution(int A[], int m,
                 int B[], int n)
{
    int size = m + n - 1;

    int N = nextPowerOfTwo(size);

    Complex *fa = calloc(N, sizeof(Complex));
    Complex *fb = calloc(N, sizeof(Complex));

    if (fa == NULL || fb == NULL)
    {
        printf("Memory allocation failed.\n");
        free(fa);
        free(fb);
        return;
    }

    /* Put A and B into complex arrays */
    for (int i = 0; i < m; i++)
        fa[i].real = A[i];

    for (int i = 0; i < n; i++)
        fb[i].real = B[i];

    /* FFT */
    FFT(fa, N, 0);
    FFT(fb, N, 0);

    /* Point-wise multiplication */
    for (int i = 0; i < N; i++)
        fa[i] = multiply(fa[i], fb[i]);

    /* Inverse FFT */
    FFT(fa, N, 1);

    printf("\nConvolution C:\n");

    for (int i = 0; i < size; i++)
    {
        printf("C[%d] = %.0lf\n",
               i,
               fa[i].real);
    }

    free(fa);
    free(fb);
}

/* MAIN */
int main()
{
    int m, n;

    printf("Enter size of A: ");
    scanf("%d", &m);

    printf("Enter size of B: ");
    scanf("%d", &n);

    if (n < m)
    {
        printf("Condition required: n >= m\n");
        return 0;
    }

    int *A = malloc(m * sizeof(int));
    int *B = malloc(n * sizeof(int));

    if (A == NULL || B == NULL)
    {
        printf("Memory allocation failed.\n");

        free(A);
        free(B);

        return 1;
    }

    printf("Enter A:\n");

    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);

    printf("Enter B:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    convolution(A, m, B, n);

    free(A);
    free(B);

    return 0;
}