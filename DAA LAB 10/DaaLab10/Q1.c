#include <stdio.h>

#define MAX 1000

int parent[MAX], rankArr[MAX], parity[MAX];

int find(int x){
    if (parent[x] != x){
        int p = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[p];
    }

    return parent[x];
}

int addEdge(int u, int v){
    int ru = find(u);
    int rv = find(v);

    int pu = parity[u];
    int pv = parity[v];

    if (ru == rv){
        return (pu ^ pv) == 1;
    }

    if (rankArr[ru] < rankArr[rv]){
        parent[ru] = rv;
        parity[ru] = pu ^ pv ^ 1;
    }
    else{
        parent[rv] = ru;
        parity[rv] = pu ^ pv ^ 1;

        if (rankArr[ru] == rankArr[rv])
            rankArr[ru]++;
    }

    return 1;
}

int main(){
    int V, E, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++){
        parent[i] = i;
        rankArr[i] = 0;
        parity[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("\nEnter edges one by one:\n");

    for (int i = 0; i < E; i++){
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V || u == v){
            printf("Invalid edge. Edge skipped.\n");
            continue;
        }

        if (addEdge(u, v)){
            printf("Edge (%d, %d) added successfully.\n", u, v);
        }
        else{
            printf("Edge (%d, %d) rejected: "
                   "Graph is not bipartite.\n", u, v);
        }
    }

    return 0;
}