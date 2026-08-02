#include<stdio.h>
#include<stdlib.h>

long long moves;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if(n==1)
    {
        moves++;
        return;
    }

    towerOfHanoi(n-1, source, destination, auxiliary);

    moves++;

    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main()
{
    FILE *fp;
    FILE *gp;

    fp = fopen("toh.txt","w");

    fprintf(fp,"#Discs Moves\n");

    for(int n=1; n<=20; n++)
    {
        moves = 0;

        towerOfHanoi(n,'A','B','C');

        fprintf(fp,"%d %lld\n", n, moves);
    }

    fclose(fp);

    gp = popen("gnuplot toh.gnu","r");

    pclose(gp);

    return 0;
}