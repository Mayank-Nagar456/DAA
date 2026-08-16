#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long weighings;

int balanceScale(int a[], int leftStart, int rightStart, int count)
{
    int leftWeight = 0;
    int rightWeight = 0;

    for (int i = 0; i < count; i++)
    {
        leftWeight += a[leftStart + i];
        rightWeight += a[rightStart + i];
    }

    weighings++;

    if (leftWeight < rightWeight)
        return -1;
    if (leftWeight > rightWeight)
        return 1;

    return 0;
}


int findDefective(int a[], int left, int n)
{
    if (n == 1)
        return -1;

    int half = n / 2;
    int middle = left + half;

    if (n % 2 == 0)
    {
        int result = balanceScale(a, left, middle, half);

        if (result < 0)
            return findDefective(a, left, half);

        if (result > 0)
            return findDefective(a, middle, half);

        return -1;
    }

    /* Odd number of coins: leave one coin unweighed. */
    int result = balanceScale(a, left, middle, half);

    if (result < 0)
        return findDefective(a, left, half);

    if (result > 0)
        return findDefective(a, middle, half);

    /*
       Both groups are equal, so the only possible defective coin
       is the middle coin. Use the first coin of a balanced group
       as a known normal reference.
    */
    int referenceWeight = a[left];
    weighings++;

    if (a[middle] < referenceWeight)
        return middle;

    return -1;
}

int main()
{
    
    int sizes[] = {8, 16, 32, 64, 128, 256, 512, 1024};
    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    FILE *fp = fopen("result.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating result.txt\n");
        return 1;
    }

    fprintf(fp, "# n Weighings\n");

    printf("Defective Coin - Divide and Conquer\n\n");
    printf("%-12s %-15s %-15s\n",
           "n", "Defective Coin", "Weighings");
    printf("------------------------------------------\n");

    for (int s = 0; s < numberOfSizes; s++)
    {
        int n = sizes[s];

        int *coins = malloc(n * sizeof(int));

        if (coins == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(fp);
            return 1;
        }

        
        for (int i = 0; i < n; i++)
            coins[i] = 10;

        
        coins[n - 1] = 9;

        weighings = 0;

        int defective = findDefective(coins, 0, n);

        printf("%-12d %-15d %-15lld\n",
               n,
               defective + 1,
               weighings);

        fprintf(fp, "%d %lld\n", n, weighings);

        free(coins);
    }

    fclose(fp);

    printf("\nresult.txt generated automatically.\n");
    printf("\nExpected complexity:\n");
    printf("Maximum number of weighings = O(log2 n)\n");

    return 0;
}