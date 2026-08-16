#include <stdio.h>
#include <stdlib.h>

/*
   Question 3:
   Find maximum and minimum using Divide and Conquer.

   The algorithm returns both minimum and maximum.
   It uses at most 3n/2 - 2 comparisons for even n.
*/

typedef struct
{
    int min;
    int max;
} MinMax;

long long comparisons = 0;

MinMax findMinMax(int a[], int low, int high)
{
    MinMax result, left, right;

    /* Only one element */
    if (low == high)
    {
        result.min = a[low];
        result.max = a[low];
        return result;
    }

    /* Two elements */
    if (high == low + 1)
    {
        comparisons++;

        if (a[low] < a[high])
        {
            result.min = a[low];
            result.max = a[high];
        }
        else
        {
            result.min = a[high];
            result.max = a[low];
        }

        return result;
    }

    /* Divide */
    int mid = low + (high - low) / 2;

    /* Conquer */
    left = findMinMax(a, low, mid);
    right = findMinMax(a, mid + 1, high);

    /* Combine */

    comparisons++;
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    comparisons++;
    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main()
{
    /*
       Different input sizes are tested to validate the
       comparison bound and running behavior.

       No input file is required.
       The C program creates result.txt automatically.
    */
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating result.txt\n");
        return 1;
    }

    fprintf(fp, "# n comparisons theoretical_3n_over_2\n");

    printf("Maximum and Minimum using Divide and Conquer\n\n");
    printf("%-12s %-20s %-25s\n",
           "n", "Comparisons", "3n/2");
    printf("--------------------------------------------------------\n");

    for (int s = 0; s < numberOfSizes; s++)
    {
        int n = sizes[s];

        int *a = malloc(n * sizeof(int));

        if (a == NULL)
        {
            printf("Memory allocation failed for n = %d\n", n);
            fclose(fp);
            return 1;
        }

        /* Create an array with different values */
        for (int i = 0; i < n; i++)
            a[i] = (i * 37) % (n + 1);

        comparisons = 0;

        MinMax result = findMinMax(a, 0, n - 1);

        long long bound = (3LL * n) / 2;

        printf("%-12d %-20lld %-25lld\n",
               n, comparisons, bound);

        fprintf(fp, "%d %lld %lld\n",
                n, comparisons, bound);

        if (s == 0)
        {
            printf("\nFor n = %d:\n", n);
            printf("Minimum = %d\n", result.min);
            printf("Maximum = %d\n\n", result.max);
        }

        free(a);
    }

    fclose(fp);

    printf("result.txt generated automatically.\n");
    printf("\nDivide and Conquer complexity: O(n)\n");
    printf("Comparison bound: approximately 3n/2 - 2 for even n.\n");

    return 0;
}