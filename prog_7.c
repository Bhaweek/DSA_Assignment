#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n;                 // number of vertices
int graph[MAX][MAX];   // adjacency matrix

// Function to find the vertex with minimum distance
int minDistance(int dist[], int visited[])
{
    int min = INF, minIndex = -1, v;

    for (v = 0; v < n; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(int src)
{
    int dist[MAX];
    int visited[MAX];
	int i, count, v;

    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("\nVertex \t Distance from Source\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main()
{
    int src, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    return 0;
}
