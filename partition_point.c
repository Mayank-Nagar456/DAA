#include <stdio.h>

int findPartition(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter array elements (0's followed by 1's):\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int partition = findPartition(arr,n);

    if(partition==-1)
        printf("No 1 found in the array.\n");
    else
        printf("Partition Point = %d\n",partition);

    return 0;
}