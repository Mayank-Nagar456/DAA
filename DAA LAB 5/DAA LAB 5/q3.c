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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    FILE *inputFile;
    FILE *outputFile;

    // Take input from user
    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Store user input in a file
    inputFile = fopen("input.txt", "w");

    if (inputFile == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(inputFile, "%d ", arr[i]);
    }

    fclose(inputFile);

    // Read elements from the file
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fclose(inputFile);

    // Apply Quick Sort
    quickSort(arr, 0, n - 1);

    // Display sorted elements
    printf("\nSorted elements:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Store sorted elements in another file
    outputFile = fopen("sorted.txt", "w");

    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);

    printf("\n\nInput stored in input.txt\n");
    printf("Sorted output stored in sorted.txt\n");

    return 0;
}