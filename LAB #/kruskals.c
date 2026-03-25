#include <stdio.h>
#define MAX 10
#define INF 999

int parent[MAX];
int find(int i);
int unionSet(int i,int j);
void kruskal(int cost[MAX][MAX],int n);

int main(){
    int cost[MAX][MAX];
    int n,i,j;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }
    }
    kruskal(cost,n);
    return 0;
}

int find(int i){
    while(parent[i])
        i=parent[i];
    return i;
}

int unionSet(int i, int j) {
    if(i!=j) {
        parent[j]=i;
        return 1;
    }
    return 0;
}

void kruskal(int cost[MAX][MAX],int n) {
    int i,j,ne=1;
    int min,mincost=0;
    int a,b,u,v;

    printf("\nEdges in MST:\n");

    while(ne<n) {
        min=INF;

        for(i=0;i<n;i++){
            for(j=0;j<n;j++) {
                if(cost[i][j]<min) {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v = find(v);

        if(unionSet(u, v)) {
            printf("Edge %d: (%d - %d) cost = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Minimum Cost = %d\n", mincost);
}
