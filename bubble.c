#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000

void bubbleNormal(int a[], int n, long *comparisons)
{
    *comparisons = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            (*comparisons)++;

            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void bubbleOptimized(int a[], int n, long *comparisons)
{
    *comparisons = 0;

    for(int i=0;i<n-1;i++)
    {
        int swapped = 0;

        for(int j=0;j<n-i-1;j++)
        {
            (*comparisons)++;

            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapped = 1;
            }
        }

        if(swapped==0)
            break;
    }
}

int main()
{
    FILE *fp;
    FILE *gp;

    srand(time(NULL));

    fp=fopen("bubble.txt","w");

    fprintf(fp,"#Size Normal Optimized\n");

    for(int n=100;n<=1000;n+=100)
    {
        int a[MAX];
        int b[MAX];

        for(int i=0;i<n;i++)
        {
            a[i]=rand()%10000;
            b[i]=a[i];
        }

        long normalComparisons;
        long optimizedComparisons;

        bubbleNormal(a,n,&normalComparisons);
        bubbleOptimized(b,n,&optimizedComparisons);

        fprintf(fp,"%d %ld %ld\n",
                n,
                normalComparisons,
                optimizedComparisons);
    }

    fclose(fp);

    gp=popen("gnuplot bubble.gnu","r");

    pclose(gp);

    return 0;
}