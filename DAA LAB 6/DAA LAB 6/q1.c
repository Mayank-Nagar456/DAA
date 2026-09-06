#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* Display Array */
void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

/* 1. Find Maximum */
void findMaximum(int a[], int n)
{
    int max = a[0];

    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }

    printf("Maximum = %d\n", max);
}

/* 2. Find First and Second Largest */
void findTwoLargest(int a[], int n)
{
    int largest = INT_MIN;
    int second = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > largest)
        {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second && a[i] != largest)
        {
            second = a[i];
        }
    }

    if(second == INT_MIN)
        printf("Second largest does not exist\n");
    else
    {
        printf("First Largest = %d\n", largest);
        printf("Second Largest = %d\n", second);
    }
}

/* 3. Find Mean */
void findMean(int a[], int n)
{
    double sum = 0;

    for(int i = 0; i < n; i++)
        sum += a[i];

    printf("Mean = %.2lf\n", sum / n);
}

/* Bubble Sort */
void bubbleSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/* 4. Find Median */
void findMedian(int a[], int n)
{
    int *b = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        b[i] = a[i];

    bubbleSort(b, n);

    double median;

    if(n % 2 == 0)
        median = (b[n / 2 - 1] + b[n / 2]) / 2.0;
    else
        median = b[n / 2];

    printf("Median = %.2lf\n", median);

    free(b);
}

/* 5. Standard Deviation */
void findStandardDeviation(int a[], int n)
{
    double sum = 0;
    double mean;
    double variance = 0;

    for(int i = 0; i < n; i++)
        sum += a[i];

    mean = sum / n;

    for(int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance = variance / n;

    printf("Standard Deviation = %.2lf\n", sqrt(variance));
}

/* 6. Find Mode */
void findMode(int a[], int n)
{
    int mode = a[0];
    int maxCount = 1;

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(a[i] == a[j])
                count++;
        }

        if(count > maxCount)
        {
            maxCount = count;
            mode = a[i];
        }
    }

    printf("Mode = %d\n", mode);
}

/* 7. Remove Duplicates */
void removeDuplicates(int a[], int *n)
{
    for(int i = 0; i < *n; i++)
    {
        for(int j = i + 1; j < *n; j++)
        {
            if(a[i] == a[j])
            {
                for(int k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");
    display(a, *n);
}

/* 8. Reverse Array */
void reverseArray(int a[], int n)
{
    int i = 0;
    int j = n - 1;

    while(i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    printf("Reversed Array: ");
    display(a, n);
}

/* 9. Partition around Pivot */
void partitionArray(int a[], int n, int pivot)
{
    int *temp = malloc(n * sizeof(int));
    int k = 0;

    /* Elements >= pivot */
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= pivot)
            temp[k++] = a[i];
    }

    /* Elements < pivot */
    for(int i = 0; i < n; i++)
    {
        if(a[i] < pivot)
            temp[k++] = a[i];
    }

    for(int i = 0; i < n; i++)
        a[i] = temp[i];

    free(temp);

    printf("Array after partition: ");
    display(a, n);
}


/* MAIN */
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));

    printf("Enter array elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n===== QUESTION 1 =====\n\n");

    findMaximum(a, n);

    printf("\n");
    findTwoLargest(a, n);

    printf("\n");
    findMean(a, n);

    printf("\n");
    findMedian(a, n);

    printf("\n");
    findStandardDeviation(a, n);

    printf("\n");
    findMode(a, n);

    printf("\n");
    int newSize = n;
    removeDuplicates(a, &newSize);

    printf("\n");
    reverseArray(a, newSize);

    printf("\n");

    int pivot;
    printf("Enter pivot: ");
    scanf("%d", &pivot);

    partitionArray(a, newSize, pivot);

    free(a);

    return 0;
}