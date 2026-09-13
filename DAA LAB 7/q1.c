#include <stdio.h>

#define N 4
#define TOTAL 10

typedef struct
{
    int x;
    int y;
} Point;

/* Check whether two points are the same */
int samePoint(Point a, Point b)
{
    return (a.x == b.x && a.y == b.y);
}

int main()
{
    Point original[TOTAL];
    Point final[TOTAL];

    int index = 0;

    

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            original[index].x = 2 * col - row;
            original[index].y = row;

            index++;
        }
    }

    

    index = 0;

    for (int row = 0; row < N; row++)
    {
        int coinsInRow = N - row;

        for (int col = 0; col < coinsInRow; col++)
        {
            final[index].x =
                2 * col - (coinsInRow - 1);

            final[index].y = row + 1;

            index++;
        }
    }

   

    int stay = 0;
    int move = 0;

    printf("Coin status:\n\n");

    for (int i = 0; i < TOTAL; i++)
    {
        int found = 0;

        for (int j = 0; j < TOTAL; j++)
        {
            if (samePoint(original[i], final[j]))
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            printf("Coin %2d -> STAY\n", i + 1);
            stay++;
        }
        else
        {
            printf("Coin %2d -> MOVE\n", i + 1);
            move++;
        }
    }

    printf("\nTotal coins = %d", TOTAL);
    printf("\nCoins that stay = %d", stay);
    printf("\nCoins that move = %d", move);

    printf("\n\nMinimum moves = %d\n", move);

    return 0;
}