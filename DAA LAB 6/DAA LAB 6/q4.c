#include <stdio.h>

#define MAX 1000

int p[MAX];
long long totalCost = 0;
long long reversalCount = 0;


void reverseArray(int l, int r)
{
    if (l >= r)
        return;

    printf("reverse(%d, %d)\n", l, r);

    int length = r - l + 1;

    totalCost += length;
    reversalCount++;

    while (l < r)
    {
        int temp = p[l];

        p[l] = p[r];
        p[r] = temp;

        l++;
        r--;
    }
}


void rotateBlocks(int l, int mid, int r)
{
    reverseArray(l, mid);
    reverseArray(mid + 1, r);
    reverseArray(l, r);
}


void stablePartition(int l, int r, int pivot)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    stablePartition(l, mid, pivot);
    stablePartition(mid + 1, r, pivot);

   
    int firstBad = -1;

    for (int i = l; i <= mid; i++)
    {
        if (p[i] > pivot)
        {
            firstBad = i;
            break;
        }
    }

    if (firstBad == -1)
        return;

  
    int firstGood = -1;

    for (int i = mid + 1; i <= r; i++)
    {
        if (p[i] <= pivot)
        {
            firstGood = i;
            break;
        }
    }

    if (firstGood == -1)
        return;

    
    int leftEnd = mid;

    int rightEnd = firstGood;

    while (rightEnd <= r && p[rightEnd] <= pivot)
        rightEnd++;

    rightEnd--;

    
    rotateBlocks(firstBad, leftEnd, rightEnd);

   
    stablePartition(l, rightEnd - (leftEnd - firstBad + 1), pivot);

    stablePartition(
        rightEnd - (leftEnd - firstBad + 1) + 1,
        r,
        pivot
    );
}


void sortPermutation(int l, int r, int low, int high)
{
    if (l >= r || low >= high)
        return;

    int midValue = (low + high) / 2;

    
    stablePartition(l, r, midValue);

    
    int boundary = l;

    while (boundary <= r &&
           p[boundary] <= midValue)
    {
        boundary++;
    }

    
    if (boundary > l)
    {
        sortPermutation(
            l,
            boundary - 1,
            low,
            midValue
        );
    }

    
    if (boundary <= r)
    {
        sortPermutation(
            boundary,
            r,
            midValue + 1,
            high
        );
    }
}


void display(int n)
{
    printf("Permutation: ");

    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);

    printf("\n");
}

/* MAIN */
int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter permutation of 1 to %d:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\nInitial ");
    display(n);

    printf("\nReversals performed:\n");

    sortPermutation(
        0,
        n - 1,
        1,
        n
    );

    printf("\nFinal ");
    display(n);

    printf("\nNumber of reversals = %lld\n",
           reversalCount);

    printf("Total reversal cost = %lld\n",
           totalCost);

    return 0;
}