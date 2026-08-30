#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move largest element to end
        swap(&arr[0], &arr[i]);

        // Restore heap
        heapify(arr, i, 0);
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

    // Generate and store random elements
    inputFile = fopen("input.txt", "w");

    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    srand(time(NULL));

    printf("\nRandom elements:\n");

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;

        printf("%d ", arr[i]);

        fprintf(inputFile, "%d ", arr[i]);
    }

    fclose(inputFile);

    // Read elements from file
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fclose(inputFile);

    // Heap Sort
    heapSort(arr, n);

    // Store sorted elements
    outputFile = fopen("sorted_heap.txt", "w");

    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    printf("\n\nSorted elements:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);

        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile);

    printf("\n\nData stored in input.txt");
    printf("\nSorted data stored in sorted_heap.txt\n");

    return 0;
}