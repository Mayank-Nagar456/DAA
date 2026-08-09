#include <stdio.h>
#include <math.h>

#define MAX 1000

int main()
{
    FILE *fp;

    fp = fopen("sorted_array.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp,
        "# n Search Insert Delete Maximum Minimum Predecessor Successor\n");

    for(int n = 1; n <= MAX; n++)
    {
        double search = log2(n);        // O(log n)
        double insert = n;              // O(n)
        double delete = n;              // O(n)

        double maximum = 1;             // O(1)
        double minimum = 1;             // O(1)

        /*
           In a sorted array, we first locate
           the key using binary search.

           Therefore:
           Predecessor = O(log n)
           Successor   = O(log n)
        */
        double predecessor = log2(n);   // O(log n)
        double successor = log2(n);     // O(log n)

        fprintf(fp,
            "%d %.4lf %.4lf %.4lf %.4lf %.4lf %.4lf %.4lf\n",
            n,
            search,
            insert,
            delete,
            maximum,
            minimum,
            predecessor,
            successor);
    }

    fclose(fp);

    printf("sorted_array.txt created successfully.\n");

    return 0;
}