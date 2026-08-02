#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    FILE *fp;
    FILE *gp;

    fp = fopen("growth.txt","w");

    fprintf(fp,"# n nlogn 12sqrt(n) 1/n n^(log2n) 100n2+6n n^0.51 n2-324 50sqrt(n) 2n3 3^n 2^32*n log2n\n");

    for(int n=2; n<=32; n++)
    {
        double f1 = n*(log(n)/log(2));              // nlog2n
        double f2 = 12*sqrt(n);                     // 12sqrt(n)
        double f3 = 1.0/n;                          // 1/n
        double f4 = pow(n, log(n)/log(2));          // n^(log2n)
        double f5 = 100*pow(n,2)+6*n;               //100n²+6n
        double f6 = pow(n,0.51);                    //n^0.51
        double f7 = pow(n,2)-324;                   //n²-324
        double f8 = 50*sqrt(n);                     //50n^0.5
        double f9 = 2*pow(n,3);                     //2n³
        double f10 = pow(3,n);                      //3^n
        double f11 = pow(2,32)*n;                   //2^32*n
        double f12 = log(n)/log(2);                 //log2n

        fprintf(fp,"%d %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",
                n,f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12);
    }

    fclose(fp);

    gp = popen("gnuplot growth.gnu","r");

    pclose(gp);

    return 0;
}