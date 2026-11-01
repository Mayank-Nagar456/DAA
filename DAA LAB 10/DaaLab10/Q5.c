#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int parent[MAX], rankArr[MAX];

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int find(int x){
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int u, int v){
    int ru = find(u);
    int rv = find(v);

    if (ru == rv)
        return;

    if (rankArr[ru] < rankArr[rv])
        parent[ru] = rv;

    else if (rankArr[ru] > rankArr[rv])
        parent[rv] = ru;

    else{
        parent[rv] = ru;
        rankArr[ru]++;
    }
}

int main(){
    int n, E;
    int A[MAX], result[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX){
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter permutation:\n");

    int seen[MAX + 1] = {0};

    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);

        if (A[i] < 1 || A[i] > n || seen[A[i]]){
            printf("Invalid permutation.\n");
            return 0;
        }

        seen[A[i]] = 1;

        parent[i] = i;
        rankArr[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges:\n");

    for (int i = 0; i < E; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 ||
            v >= n || u == v){
            printf("Invalid edge.\n");
            return 0;
        }

        unite(u, v);
    }

    // Initially copy original permutation

    for (int i = 0; i < n; i++)
        result[i] = A[i];

    // Process each connected component

    for (int root = 0; root < n; root++){
        if (find(root) == root){
            int indices[MAX];
            int values[MAX];
            int count = 0;

            // Collect vertices and their values

            for (int i = 0; i < n; i++){
                if (find(i) == root){
                    indices[count] = i;
                    values[count] = A[i];
                    count++;
                }
            }

            // Sort indices and values

            qsort(indices, count, sizeof(int), compare);
            qsort(values, count, sizeof(int), compare);

            // Assign smallest values to smallest indices

            for (int i = 0; i < count; i++)
            {
                result[indices[i]] = values[i];
            }
        }
    }

    printf("\nLexicographically smallest permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
}