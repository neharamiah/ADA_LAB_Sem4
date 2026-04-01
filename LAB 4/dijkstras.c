#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int visited[]) {
    int min=INT_MAX,min_index;

    for (int v=0;v<V;v++) {
        if (visited[v]==0 && dist[v]<=min){
            min=dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int graph[V][V],int src) {
    int dist[V];
    int visited[V];

    for (int i=0;i<V;i++) {
        dist[i]=INT_MAX;
        visited[i]=0;
    }

    dist[src]=0;

    for (int count=0;count<V-1;count++) {
        int u=minDistance(dist, visited);
        visited[u] = 1;

        for (int v=0;v<V;v++) {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u]!=INT_MAX &&
                dist[u]+graph[u][v]<dist[v]) {

                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i=0;i<V;i++) {
        printf("%d \t %d\n",i,dist[i]);
    }
}

int main() {
    int graph[V][V];
    int i, j, src;

    printf("Enter the adjacency matrix (%d x %d):\n",V,V);
    for(i=0;i<V;i++) {
        for(j=0;j<V;j++) {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d",&src);

    dijkstra(graph,src);

    return 0;
}


//{0,10,0,30,100}, {10,0,50,0,0}, {0,50,0,20,10}, {30,0,20,0,60}, {100,0,10,60,0} };
