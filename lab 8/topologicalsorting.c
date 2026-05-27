 #include <stdio.h>

#define MAX 20

int queue[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear;
}
int main()
{
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);

            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while(!isEmpty())
    {
        int u = dequeue();
        printf("%d ", u);

        for(j = 0; j < n; j++)
        {
            if(adj[u][j] == 1)
            {
                indegree[j]--;

                if(indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    return 0;
}
