#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low == high)
        return arr[low];

    int pos = partition(arr, low, high);

    if (k == pos)
        return arr[pos];

    else if (k < pos)
        return quickSelect(arr, low, pos - 1, k);

    else
        return quickSelect(arr, pos + 1, high, k);
} 

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    double median;

    if (n % 2 == 1)
    {
        // Odd number of elements
        median = quickSelect(arr, 0, n - 1, n / 2);
    }
    else
    {
        // Even number of elements
        int left = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int right = quickSelect(arr, 0, n - 1, n / 2);

        median = (left + right) / 2.0;
    }

    printf("Median = %.2f\n", median);

    return 0;
}