#include <stdio.h>
#include <math.h>

#define MAX 1000

int main()
{
    FILE *fp;

    fp = fopen("merge_sort.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "# n MergeSort ModifiedMergeSort\n");

    for(int n = 1; n <= MAX; n++)
    {
        /*
           Ordinary Merge Sort:

           T(n) = 2T(n/2) + O(n)

           Therefore:
           T(n) = O(n log2 n)
        */

        double mergeSort;

        if(n == 1)
            mergeSort = 1;
        else
            mergeSort = n * log2(n);


        /*
           Modified Merge Sort:

           Divide the array into 3 parts.
           Recursively sort each part.
           Three-way merge takes O(n).

           T(n) = 3T(n/3) + O(n)

           Therefore:
           T(n) = O(n log3 n)

           log3(n) = log2(n) / log2(3)
        */

        double modifiedMergeSort;

        if(n == 1)
            modifiedMergeSort = 1;
        else
            modifiedMergeSort = n * (log2(n) / log2(3));


        fprintf(fp,
            "%d %.4lf %.4lf\n",
            n,
            mergeSort,
            modifiedMergeSort);
    }

    fclose(fp);

    printf("merge_sort.txt created successfully.\n");

    return 0;
}