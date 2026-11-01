#include <stdio.h>

#define MAX 1000

int parent[MAX], active[MAX];
int size[MAX];

long long weight[MAX], sum[MAX];
long long answer[MAX];

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

long long getMaximum(int V){
    long long maximum = 0;

    for (int i = 0; i < V; i++){
        if (active[i] && parent[i] == i){
            if (sum[i] > maximum)
                maximum = sum[i];
        }
    }

    return maximum;
}

int main(){
    int V, E;
    int u[MAX], v[MAX];
    int P[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    if (V <= 0 || V > MAX){
        printf("Invalid number of vertices.\n");
        return 0;
    }

    for (int i = 0; i < V; i++){
        printf("Enter weight of vertex %d: ", i);
        scanf("%lld", &weight[i]);

        parent[i] = i;
        size[i] = 1;
        sum[i] = weight[i];
        active[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges:\n");

    for (int i = 0; i < E; i++){
        scanf("%d %d", &u[i], &v[i]);

        if (u[i] < 0 || u[i] >= V ||
            v[i] < 0 || v[i] >= V ||
            u[i] == v[i]){
            printf("Invalid edge.\n");
            return 0;
        }
    }

    printf("Enter deletion order of vertices:\n");

    int seen[MAX] = {0};

    for (int i = 0; i < V; i++){
        scanf("%d", &P[i]);

        if (P[i] < 0 || P[i] >= V || seen[P[i]]){
            printf("Invalid deletion order.\n");
            return 0;
        }

        seen[P[i]] = 1;
    }

    // Process vertices in reverse order

    for (int i = V - 1; i >= 0; i--){
        int x = P[i];

        active[x] = 1;

        // Connect with active neighbours

        for (int j = 0; j < E; j++){
            if (u[j] == x && active[v[j]])
                unite(x, v[j]);

            else if (v[j] == x && active[u[j]])
                unite(x, u[j]);
        }

        answer[i] = getMaximum(V);
    }

    printf("\nMaximum component weight after each deletion:\n");

    for (int i = 1; i < V; i++){
        printf("After deleting %d vertices: %lld\n",
               i, answer[i]);
    }

    printf("After deleting %d vertices: 0\n", V);

    return 0;
}