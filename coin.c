#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    FILE *fp;
    FILE *gp;

    srand(time(NULL));

    fp = fopen("coin.txt","w");

    fprintf(fp,"#Tosses Fair_Head Biased_Head\n");

    int tests[] = {10,50,100,500,1000,5000,10000,50000,100000};

    int size = sizeof(tests)/sizeof(tests[0]);

    for(int i=0;i<size;i++)
    {
        int tosses = tests[i];

        int fairHeads = 0;
        int biasedHeads = 0;

        /* Fair Coin Simulation */
        for(int j=0;j<tosses;j++)
        {
            if(rand()%2==0)
                fairHeads++;
        }

        /* Biased Coin Simulation (80% Head) */
        for(int j=0;j<tosses;j++)
        {
            if(rand()%100 < 80)
                biasedHeads++;
        }

        double fairProbability = (double)fairHeads/tosses;
        double biasedProbability = (double)biasedHeads/tosses;

        fprintf(fp,"%d %.6lf %.6lf\n",
                tosses,
                fairProbability,
                biasedProbability);
    }

    fclose(fp);

    gp = popen("gnuplot coin.gnu","r");

    pclose(gp);

    return 0;
}