#include <stdio.h>
#define MAX 10
#define INF 999

void prims(int cost[MAX][MAX],int n);

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
    prims(cost,n);
    return 0;
}

void prims(int cost[MAX][MAX], int n) {
    int visited[MAX]={0};
    int i,j,ne=1;
    int min,mincost=0;
    int a=0,b=0;

    visited[0]=1;

    printf("\nEdges in MST:\n");

    while(ne<n) {
        min=INF;
        for(i=0;i<n;i++){
            if(visited[i]){
                for(j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        printf("Edge %d: (%d - %d) cost = %d\n",ne++,a,b,min);
        mincost+=min;
        visited[b]=1;
    }

    printf("Minimum Cost= %d\n",mincost);
}
