#include <stdio.h>

#define MAX 1000

int parent[MAX], size[MAX];
long long sum[MAX];

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

    if (size[ru] < size[rv]){
        int temp = ru;
        ru = rv;
        rv = temp;
    }

    parent[rv] = ru;
    size[ru] += size[rv];
    sum[ru] += sum[rv];
}

long long maximumWeight(int V, int K){
    long long maximum = 0;

    for (int i = 0; i < V; i++){
        if (parent[i] == i && size[i] <= K){
            if (sum[i] > maximum)
                maximum = sum[i];
        }
    }

    return maximum;
}

int main(){
    int V, E, K;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    if (V <= 0 || V > MAX){
        printf("Invalid number of vertices.\n");
        return 0;
    }

    for (int i = 0; i < V; i++){
        parent[i] = i;
        size[i] = 1;

        printf("Enter weight of vertex %d: ", i);
        scanf("%lld", &sum[i]);
    }

    printf("Enter maximum component size K: ");
    scanf("%d", &K);

    if (K < 1 || K > V){
        printf("Invalid K value.\n");
        return 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges one by one:\n");

    for (int i = 0; i < E; i++){
        int u, v;

        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 ||
            v >= V || u == v){
            printf("Invalid edge.\n");
            continue;
        }

        unite(u, v);

        printf("Maximum eligible component weight = %lld\n",
               maximumWeight(V, K));
    }

    return 0;
}