#include <stdio.h>

#define MAX 10000

int parent[MAX];
int rankArr[MAX];

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int unite(int a, int b){
    int ra = find(a);
    int rb = find(b);

    if (ra == rb)
        return 0;

    if (rankArr[ra] < rankArr[rb])
        parent[ra] = rb;

    else if (rankArr[ra] > rankArr[rb])
        parent[rb] = ra;

    else{
        parent[rb] = ra;
        rankArr[ra]++;
    }

    return 1;
}

int main(){
    int R, C, K;
    int grid[100][100] = {0};
    int islands = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    printf("Enter rows and columns: ");
    scanf("%d %d", &R, &C);

    if (R <= 0 || C <= 0 || R > 100 ||
        C > 100 || R * C > MAX){
        printf("Invalid grid size.\n");
        return 0;
    }

    for (int i = 0; i < R * C; i++){
        parent[i] = i;
        rankArr[i] = 0;
    }

    printf("Enter number of land additions: ");
    scanf("%d", &K);

    printf("\nEnter positions (row column):\n");

    for (int i = 0; i < K; i++){
        int r, c;

        scanf("%d %d", &r, &c);

        if (r < 0 || r >= R || c < 0 || c >= C){
            printf("Invalid position. Islands = %d\n",
                   islands);
            continue;
        }

        if (grid[r][c] == 1){
            printf("Already land. Islands = %d\n", islands);
            continue;
        }

        grid[r][c] = 1;
        islands++;

        int id = r * C + c;

        for (int j = 0; j < 4; j++){
            int nr = r + dr[j];
            int nc = c + dc[j];

            if (nr >= 0 && nr < R &&
                nc >= 0 && nc < C &&
                grid[nr][nc] == 1){
                int nid = nr * C + nc;

                if (unite(id, nid))
                    islands--;
            }
        }

        printf("Number of islands = %d\n", islands);
    }

    return 0;
}