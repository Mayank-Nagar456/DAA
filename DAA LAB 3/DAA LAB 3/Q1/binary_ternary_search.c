#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Binary Search */
int binarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == x)
            return mid;

        if (x < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

/* Ternary Search */
int ternarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int third = (high - low) / 3;

        int mid1 = low + third;
        int mid2 = high - third;

        if (a[mid1] == x)
            return mid1;

        if (a[mid2] == x)
            return mid2;

        if (x < a[mid1])
        {
            high = mid1 - 1;
        }
        else if (x > a[mid2])
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int sizes[] = {1000, 10000, 100000, 1000000, 5000000};
    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    /* Repeat searches so execution time can be measured clearly. */
    int repetitions = 100000;

    /*
       result.txt is automatically created by the C program.
       No separate input.txt or .dat file is required.
    */
    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating result.txt\n");
        return 1;
    }

    fprintf(fp, "# n BinaryTime TernaryTime\n");

    printf("Binary Search vs Ternary Search\n\n");
    printf("%-12s %-20s %-20s\n",
           "n", "Binary Time(ms)", "Ternary Time(ms)");
    printf("------------------------------------------------------\n");

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

        /* Create sorted list: 1, 2, 3, ..., n */
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        /*
           x is not present in the array.
           This makes the search continue until the search space
           becomes empty.
        */
        int x = n + 1;

        clock_t start, end;
        volatile int result;

        /* Binary Search timing */
        start = clock();

        for (int i = 0; i < repetitions; i++)
            result = binarySearch(a, n, x);

        end = clock();

        double binaryTime =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

        /* Ternary Search timing */
        start = clock();

        for (int i = 0; i < repetitions; i++)
            result = ternarySearch(a, n, x);

        end = clock();

        double ternaryTime =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

        printf("%-12d %-20.6f %-20.6f\n",
               n, binaryTime, ternaryTime);

        fprintf(fp, "%d %.6f %.6f\n",
                n, binaryTime, ternaryTime);

        free(a);
    }

    fclose(fp);

    printf("\nresult.txt generated automatically.\n");
    printf("\nTime Complexity:\n");
    printf("Binary Search  : O(log2 n)\n");
    printf("Ternary Search : O(log3 n)\n");

    return 0;
}